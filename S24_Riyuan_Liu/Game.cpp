	#include "Game.h"
	#include "Bullets.h"
	#include <random>
	#include <chrono> // For time tracking

MyGame::MyGame() {
	mState = State::stopped;
	SetKeyPressedCallback([this](const Rogue::KeyPressed& e) { OnKeyPress(e); });
	SetKeyReleasedCallback([this](const Rogue::KeyReleased& e) { OnKeyRelease(e); });
	lastSpawnTime = std::chrono::steady_clock::now();

	const char* bulletImagePaths[10][4] = {
		{ "../Assets/Textures/Bullet/Bullet1.png", "../Assets/Textures/Bullet/Bullet1.png", "../Assets/Textures/Bullet/Bullet1.png", "../Assets/Textures/Bullet/Bullet1.png" },
		{ "../Assets/Textures/Bullet/Bullet2.png", "../Assets/Textures/Bullet/Bullet2.png", "../Assets/Textures/Bullet/Bullet2.png", "../Assets/Textures/Bullet/Bullet2.png" },
		{ "../Assets/Textures/Bullet/Bullet3.png", "../Assets/Textures/Bullet/Bullet3.png", "../Assets/Textures/Bullet/Bullet3.png", "../Assets/Textures/Bullet/Bullet3.png" },
		{ "../Assets/Textures/Bullet/Bullet4Left.png", "../Assets/Textures/Bullet/Bullet4Right.png", "../Assets/Textures/Bullet/Bullet4Up.png", "../Assets/Textures/Bullet/Bullet4Down.png" },
		{ "../Assets/Textures/Bullet/Bullet5Left.png", "../Assets/Textures/Bullet/Bullet5Right.png", "../Assets/Textures/Bullet/Bullet5Up.png", "../Assets/Textures/Bullet/Bullet5Down.png" },
		{ "../Assets/Textures/Bullet/Bullet6Left.png", "../Assets/Textures/Bullet/Bullet6Right.png", "../Assets/Textures/Bullet/Bullet6Up.png", "../Assets/Textures/Bullet/Bullet6Down.png" },
		{ "../Assets/Textures/Bullet/Bullet7Left.png", "../Assets/Textures/Bullet/Bullet7Right.png", "../Assets/Textures/Bullet/Bullet7Up.png", "../Assets/Textures/Bullet/Bullet7Down.png" },
		{ "../Assets/Textures/Bullet/Bullet8Left.png", "../Assets/Textures/Bullet/Bullet8Right.png", "../Assets/Textures/Bullet/Bullet8Up.png", "../Assets/Textures/Bullet/Bullet8Down.png" },
		{ "../Assets/Textures/Bullet/Bullet9Left.png", "../Assets/Textures/Bullet/Bullet9Right.png", "../Assets/Textures/Bullet/Bullet9Up.png", "../Assets/Textures/Bullet/Bullet9Down.png" },
		{ "../Assets/Textures/Bullet/Bullet10Left.png", "../Assets/Textures/Bullet/Bullet10Right.png", "../Assets/Textures/Bullet/Bullet10Up.png", "../Assets/Textures/Bullet/Bullet10Down.png" }
	};

	// Initialize bullets_image vector with 10 sub-vectors
	bullets_image.resize(10);
	for (int i = 0; i < 10; ++i) {
		bullets_image[i].assign(bulletImagePaths[i], bulletImagePaths[i] + 4);
	}

	// Initialize bullet damage values
	bullet_damage = { 5, 10, 20, 40, 60, 80, 100, 120, 140, 160 ,180};

	// Initialize bullet speed values
	bullet_speed = { 8, 10, 14, 20, 25, 30, 35, 40, 45, 50 ,60};
}


	void MyGame::Initialize() {
		main_character.setX(500);
		main_character.setY(500);

		// Render the background only if it hasn't been rendered yet
		if (!isBackgroundRendered) {
			Rogue::Renderer::Draw(background, 0, 0);
			isBackgroundRendered = true;
		}
		gameStartTime = std::chrono::steady_clock::now();




	}

	void renderHealthOnScreen(int health, int x, int y) {
		std::vector<std::string> filepath = {
			"../Assets/Textures/Number/0.png",
			"../Assets/Textures/Number/1.png",
			"../Assets/Textures/Number/2.png",
			"../Assets/Textures/Number/3.png",
			"../Assets/Textures/Number/4.png",
			"../Assets/Textures/Number/5.png",
			"../Assets/Textures/Number/6.png",
			"../Assets/Textures/Number/7.png",
			"../Assets/Textures/Number/8.png",
			"../Assets/Textures/Number/9.png"
		};
		Rogue::Image image1{"../Assets/Textures/Health/Health.png"};
		Rogue::Renderer::Draw(image1, x, y);
		// Convert health to string
		std::string healthStr = std::to_string(health);

		// Calculate starting position
		int xPos = x+23;

		// Loop through each digit in the health string
		for (char digit : healthStr) {
			// Convert char to integer
			int digitValue = digit - '0';

			// Draw the digit image at the calculated position
			Rogue::Image image{ filepath[digitValue] };
			Rogue::Renderer::Draw(image, xPos, y);

			// Increase the x position for the next digit
			xPos += 10;/* Adjust this value based on the width of each digit */
		}
	}

	void MyGame::OnUpdate() {
		if (gameStatus == 0) {
			Rogue::Image screen{ "../Assets/Textures/Starting_screen.png" };
			Rogue::Renderer::Draw(screen, 0, 0);
			return;
		}
		if (main_character.getHealth() == 0) {
			Rogue::Image tScore{ "../Assets/Textures/losing_screen.png" };
			Rogue::Renderer::Draw(tScore, 0, 0);
			score.Render(370, 500);
			return;
		}
		Rogue::Renderer::Draw(background, 0, 0);

		
		Rogue::Image tScore{ "../Assets/Textures/score.png" };
		Rogue::Renderer::Draw(tScore, 380, 1020);
		score.Render(500, 1020);
		renderHealthOnScreen(main_character.getHealth(),100,1020);
		spawnItem();
		checkItemCollisions();

		// Render items
		for (const auto& item : items) {
			item->render();
		}
		UpdateMovement();
		main_character.render(); // Render the character

		bulletRenderAndRemove(); // Checking bullet

		// Spawn enemies if enough time has passed
		spawnEnemy();

		// Render enemies and remove any that should be removed
		renderAndRemoveEnemies();

		// remove enemy and bullet by checking collision
	}


	void MyGame::Shutdown() {
		std::cout << "Window width: " << Rogue::RogueWindow::GetWindow()->GetWidth() << std::endl;
	}


	void MyGame::OnKeyPress(const Rogue::KeyPressed& e) {
		
		if (e.GetKeyCode() == ROGUE_KEY_ENTER) {
			gameStatus = 1;
		}
		keyStates[e.GetKeyCode()] = true;

	}

	void MyGame::OnKeyRelease(const Rogue::KeyReleased& e) {
		keyStates[e.GetKeyCode()] = false;
	}

	void MyGame::UpdateMovement() {
		if (keyStates[ROGUE_KEY_RIGHT]) {
			main_character.setX(main_character.getXLocation() + main_character.getSpeed());
			main_character.setAction(Action::GoingRight);
			main_character.setDirection(Direction::right);
			mState = State::moving;
		}
		if (keyStates[ROGUE_KEY_LEFT]) {
			main_character.setX(main_character.getXLocation() - main_character.getSpeed());
			main_character.setAction(Action::GoingLeft);
			main_character.setDirection(Direction::Left);
			mState = State::moving;
		}
		if (keyStates[ROGUE_KEY_UP]) {
			main_character.setY(main_character.getYLocation() + main_character.getSpeed());
			main_character.setDirection(Direction::up);
			if (main_character.getDirection() == Direction::Left) {

				main_character.setAction(Action::GoingUpL);
			}
			else {
				main_character.setAction(Action::GoingUpR);
			}
			mState = State::moving;
		}
		if (keyStates[ROGUE_KEY_DOWN]) {
			main_character.setY(main_character.getYLocation() - main_character.getSpeed());
			main_character.setDirection(Direction::down);
			if (main_character.getDirection() == Direction::down) {
				main_character.setAction(Action::GoingDownL);
			}
			else {
				main_character.setAction(Action::GoingDownR);
			}
			mState = State::moving;
		}
		if (keyStates[ROGUE_KEY_SPACE]) {
			// Adjust bullet spawn based on current bullet speed
			auto currentTime = std::chrono::steady_clock::now();
			auto timeSinceLastSpawn = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastBulletSpawnTime);

			BulletSpawnCooldown = std::chrono::milliseconds{main_character.getCurrentBulletSpawn()};
			if (timeSinceLastSpawn >= BulletSpawnCooldown) {
				bullets.push_back({ main_character.getXLocation() + 20, main_character.getYLocation() + 30,main_character.getDirection(), bullets_image[main_character.getCurrentBullet()][static_cast<int>(main_character.getDirection())], bullet_speed[main_character.getCurrentBullet()], bullet_damage[main_character.getCurrentBullet()] });
				lastBulletSpawnTime = currentTime;
			}
		}
	}

	void MyGame::bulletRenderAndRemove()
	{
		for (int i = 0; i < bullets.size(); i++) {
			bullets[i].render();
			bullets[i].bulletMove();
		}
		bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullets& bullet) {
			return (bullet.getX() < 0 || bullet.getX() > Rogue::RogueWindow::GetWindow()->GetWidth() || bullet.getY() < 0 || bullet.getY() > Rogue::RogueWindow::GetWindow()->GetHeight());
			}), bullets.end());
	}
	void MyGame::spawnEnemy() {
		auto now = std::chrono::steady_clock::now();
		if (now - lastSpawnTime >= spawnCooldown && enemies.size() < 10) {
			lastSpawnTime = now;

			// Randomly choose the edge and position
			std::uniform_int_distribution<int> edgeDist(0, 3); // 0 = top, 1 = right, 2 = bottom, 3 = left
			std::uniform_int_distribution<int> xDist(0, Rogue::RogueWindow::GetWindow()->GetWidth());
			std::uniform_int_distribution<int> yDist(0, Rogue::RogueWindow::GetWindow()->GetHeight());

			int x = 0, y = 0;
			int edge = edgeDist(rng);

			switch (edge) {
			case 0: // Top edge
				x = xDist(rng);
				y = 0;
				break;
			case 1: // Right edge
				x = Rogue::RogueWindow::GetWindow()->GetWidth();
				y = yDist(rng);
				break;
			case 2: // Bottom edge
				x = xDist(rng);
				y = Rogue::RogueWindow::GetWindow()->GetHeight();
				break;
			case 3: // Left edge
				x = 0;
				y = yDist(rng);
				break;
			}

			// Randomly choose the difficulty
			auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(now - gameStartTime);

			std::uniform_int_distribution<int> difficultyDist(0, 100); // Adjusted to 100 for simplicity
			Enemy::Difficulty difficulty;
			int randNum = difficultyDist(rng);

			if (elapsedTime.count() < 30) { // First 30 seconds
				if (randNum < 80) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l2;
				else difficulty = Enemy::Difficulty::l3;
			}
			else if (elapsedTime.count() < 60) { // 30-59 seconds
				if (randNum < 70) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 85) difficulty = Enemy::Difficulty::l2;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l3;
				else difficulty = Enemy::Difficulty::l4;
			}
			else if (elapsedTime.count() < 90) { // 60-89 seconds
				if (randNum < 60) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 75) difficulty = Enemy::Difficulty::l2;
				else if (randNum < 85) difficulty = Enemy::Difficulty::l3;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l4;
				else difficulty = Enemy::Difficulty::l5;
			}
			else if (elapsedTime.count() < 120) { // 90-119 seconds
				if (randNum < 50) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 65) difficulty = Enemy::Difficulty::l2;
				else if (randNum < 75) difficulty = Enemy::Difficulty::l3;
				else if (randNum < 85) difficulty = Enemy::Difficulty::l4;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l5;
				else difficulty = Enemy::Difficulty::l6;
			}
			else if (elapsedTime.count() < 150) { // 120-149 seconds
				if (randNum < 40) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 55) difficulty = Enemy::Difficulty::l2;
				else if (randNum < 65) difficulty = Enemy::Difficulty::l3;
				else if (randNum < 75) difficulty = Enemy::Difficulty::l4;
				else if (randNum < 85) difficulty = Enemy::Difficulty::l5;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l6;
				else difficulty = Enemy::Difficulty::l7;
			}
			else if (elapsedTime.count() < 180) { // 150-179 seconds
				if (randNum < 30) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 45) difficulty = Enemy::Difficulty::l2;
				else if (randNum < 55) difficulty = Enemy::Difficulty::l3;
				else if (randNum < 65) difficulty = Enemy::Difficulty::l4;
				else if (randNum < 75) difficulty = Enemy::Difficulty::l5;
				else if (randNum < 85) difficulty = Enemy::Difficulty::l6;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l7;
				else difficulty = Enemy::Difficulty::l8;
			}
			else { // After 180 seconds
				if (randNum < 20) difficulty = Enemy::Difficulty::l1;
				else if (randNum < 35) difficulty = Enemy::Difficulty::l2;
				else if (randNum < 45) difficulty = Enemy::Difficulty::l3;
				else if (randNum < 55) difficulty = Enemy::Difficulty::l4;
				else if (randNum < 65) difficulty = Enemy::Difficulty::l5;
				else if (randNum < 75) difficulty = Enemy::Difficulty::l6;
				else if (randNum < 85) difficulty = Enemy::Difficulty::l7;
				else if (randNum < 95) difficulty = Enemy::Difficulty::l8;
				else {
					difficulty = Enemy::Difficulty::l9;
					enemies.emplace_back(Enemy::Difficulty::l10, x, y);
					enemies.emplace_back(Enemy::Difficulty::l10, x, y);
				}
			}

			// Create and add the enemy
			enemies.emplace_back(difficulty, x, y);
		}
	}

	void MyGame::renderAndRemoveEnemies() {
		for (auto it = enemies.begin(); it != enemies.end();) {
			it->render();
			it->update(main_character.getXLocation(), main_character.getYLocation()); // Assuming you have an update logic

			// Add logic to remove enemies if needed (e.g., when off screen or defeated)
			// Example: if enemy health is 0, remove it
			if (it->getHealth() <= 0) {
				score.addPoint(it->getPoint());
				it = enemies.erase(it);
				
			}
			else {
				++it;
			}
		}
		checkCollisions();
	}
	void MyGame::checkCollisions() {
		for (auto bulletIt = bullets.begin(); bulletIt != bullets.end();) {
			bool bulletRemoved = false;
			for (auto enemyIt = enemies.begin(); enemyIt != enemies.end();) {
				if (bulletIt->collidesWith(*enemyIt)) {
					enemyIt->takeDamage(bulletIt->getDamage());
					if (bulletIt->getdirection() == Direction::Left) {
						enemyIt->update(-1, 0);
					}
					else if (bulletIt->getdirection() == Direction::right) {
						enemyIt->update(1, 0);
					}
					else if (bulletIt->getdirection() == Direction::up) {
						enemyIt->update(0, 1);
					}
					else if (bulletIt->getdirection() == Direction::down) {
						enemyIt->update(0, -1);
					}
					++enemyIt;
					bulletIt = bullets.erase(bulletIt);
					bulletRemoved = true;
					break;
				}
				else {
					++enemyIt;
				}
			}
			if (!bulletRemoved) {
				++bulletIt;
			}
		}
		for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ++enemyIt) {
			// Check collision with character
			if (main_character.collidesWith(*enemyIt)) {
				// Handle collision between character and enemy
				// For example, reduce character health or perform other actions
				main_character.takeDamage(enemyIt->getDamage());
				enemyIt->takeDamage(enemyIt->getDamage() / 3);
				break;
			}
		}
	}

	void MyGame::spawnItem() {
		auto now = std::chrono::steady_clock::now();
		if (now - lastItemSpawnTime >= itemSpawnCooldown && items.size() < 5) {
			lastItemSpawnTime = now;

			// Randomly generate item position
			std::uniform_int_distribution<int> xDist(0, Rogue::RogueWindow::GetWindow()->GetWidth());
			std::uniform_int_distribution<int> yDist(0, Rogue::RogueWindow::GetWindow()->GetHeight());

			int x = xDist(rng);
			int y = yDist(rng);

			// Randomly choose the item type
			std::uniform_int_distribution<int> itemDist(0, 3); // Assuming 3 types of items
			std::unique_ptr<Item> item;
			int level = main_character.getCurrentBullet();
			std::string filepath = "../Assets/Textures/Item/Gun_" + std::to_string(level) + ".png";
			switch (itemDist(rng)) {
			case 0:
				item = std::make_unique<HealthBooster>(x, y, "path_to_health_booster_sprite.png");
				break;
			case 1:
				item = std::make_unique<SpeedUpgrade>(x, y, "path_to_speed_upgrade_sprite.png");
				break;
			case 2:
				item = std::make_unique<BulletUpgrade1>(x, y, filepath);
				break;
			case 3:
				item = std::make_unique<BSpawnUpgrade>(x, y, "../Assets/Textures/Item/BulletSpawnUpgrade.png");
				break;
			}


			items.push_back(std::move(item));
		}
	}

	void MyGame::checkItemCollisions()
	{
		for (auto it = items.begin(); it != items.end();) {
			if ((*it)->collidesWith(main_character)) {
				(*it)->applyEffect(main_character);
				it = items.erase(it); // Remove the item after applying the effect
			}
			else {
				++it;
			}
		}
	}
