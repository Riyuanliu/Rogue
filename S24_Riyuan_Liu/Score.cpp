#include "Score.h"

score::score()
{
    point = 0;
    filepath.push_back("../Assets/Textures/Number/0.png");
	filepath.push_back("../Assets/Textures/Number/1.png");
	filepath.push_back("../Assets/Textures/Number/2.png");
	filepath.push_back("../Assets/Textures/Number/3.png");
	filepath.push_back("../Assets/Textures/Number/4.png");
	filepath.push_back("../Assets/Textures/Number/5.png");
	filepath.push_back("../Assets/Textures/Number/6.png");
	filepath.push_back("../Assets/Textures/Number/7.png");
	filepath.push_back("../Assets/Textures/Number/8.png");
	filepath.push_back("../Assets/Textures/Number/9.png");
}
void score::Render(int x, int y)
{
	std::string ScoreStr = std::to_string(point);
	int xPos = x;
	for (char digit : ScoreStr) {
		// Convert char to integer
		int digitValue = digit - '0';

		// Draw the digit image at the calculated position
		Rogue::Image image{ filepath[digitValue] };
		Rogue::Renderer::Draw(image, xPos, y);

		// Increase the x position for the next digit
		xPos += 10;/* Adjust this value based on the width of each digit */
	}
}


void score::addPoint(int x)
{
    point += x;
}
