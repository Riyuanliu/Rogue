# Custom Game Engine

Welcome to the Custom Game Engine! This project is designed to provide a flexible and powerful foundation for game development. It leverages Visual Studio for development and CMake for building the project.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Rendering**: High-performance rendering with support for modern graphics APIs.
- **Physics**: Robust physics engine for realistic object interactions.
- **Audio**: Advanced audio system for immersive sound effects and music.
- **Input**: Comprehensive input handling for keyboard, mouse, and game controllers.
- **Scripting**: Flexible scripting support for game logic.
- **Scene Management**: Efficient scene management for complex game worlds.
- **Networking**: Basic networking capabilities for multiplayer support.

## Installation

To get started with the Custom Game Engine, follow these steps:

### Prerequisites

- [Visual Studio](https://visualstudio.microsoft.com/) (2019 or later)
- [CMake](https://cmake.org/) (3.15 or later)
- [Git](https://git-scm.com/)

### Steps

1. **Clone the repository**:
    ```bash
    git clone https://github.com/yourusername/custom-game-engine.git
    ```
2. **Navigate to the project directory**:
    ```bash
    cd custom-game-engine
    ```
3. **Generate Visual Studio project files with CMake**:
    ```bash
    mkdir build
    cd build
    cmake -G "Visual Studio 16 2019" ..
    ```
4. **Open the generated solution file** (`CustomGameEngine.sln`) in Visual Studio.

5. **Build the project**:
    - Set the build configuration to `Debug` or `Release`.
    - Build the solution (press `F7` or go to `Build > Build Solution`).

## Usage

After building the project, you can run the game engine directly from Visual Studio:

1. **Set the startup project**:
    - Right-click on the project in the Solution Explorer and select `Set as Startup Project`.

2. **Run the engine**:
    - Press `F5` or go to `Debug > Start Debugging`.

### Directory Structure

- `src/`: Source code for the game engine.
- `include/`: Header files for the game engine.
- `assets/`: Assets such as textures, models, and audio files.
- `build/`: Build directory for CMake-generated files.

## Configuration

Configuration options for the engine can be modified in the `config` file located
