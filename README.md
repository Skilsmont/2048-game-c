# 🕹️ 2048 Game in C

Welcome to the **2048 Game in C** repository! This is a console-based version of the popular 2048 game, implemented in C using pointer arithmetic and a modular file structure. You can download the latest release [here](https://github.com/Skilsmont/2048-game-c/releases) and execute the game in your terminal.

## 📚 Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Code Structure](#code-structure)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## 🎮 Introduction

The 2048 game challenges players to combine tiles with the same number until they reach the tile with the number 2048. This project serves as an educational tool to understand C programming concepts, including pointer arithmetic and modular programming. 

## 🚀 Features

- **Console-Based**: Play directly in your terminal.
- **Modular Design**: The code is organized into multiple files for easier management.
- **Pointer Arithmetic**: Learn and apply pointer concepts in C.
- **Educational**: Ideal for those looking to improve their C programming skills.
- **Cross-Platform**: Runs on any system with a C compiler.

## 📥 Installation

To get started, download the latest release from [here](https://github.com/Skilsmont/2048-game-c/releases). Follow these steps to install:

1. **Download the Release**: Go to the releases section and download the appropriate file for your operating system.
2. **Extract the Files**: Unzip the downloaded file to your desired location.
3. **Compile the Code**: Open your terminal, navigate to the extracted folder, and run the following command:
   ```bash
   make
   ```
4. **Run the Game**: After compilation, execute the game using:
   ```bash
   ./2048
   ```

## 🕹️ Usage

Once the game is running, you can use the arrow keys to move the tiles. The goal is to combine tiles with the same number to reach the 2048 tile. Here are the controls:

- **Up Arrow**: Move tiles up.
- **Down Arrow**: Move tiles down.
- **Left Arrow**: Move tiles left.
- **Right Arrow**: Move tiles right.

## 📜 Game Rules

- Combine tiles with the same number to create a new tile with their sum.
- Each move generates a new tile with the value of 2 or 4.
- The game ends when there are no valid moves left.
- Try to reach the 2048 tile for victory!

## 📂 Code Structure

The project follows a modular programming approach. Here's a brief overview of the file structure:

```
/2048-game-c
│
├── src/
│   ├── main.c          # Main game loop
│   ├── game.c          # Game logic
│   ├── display.c       # Rendering the game board
│   ├── input.c         # Handling user input
│   └── utils.c         # Utility functions
│
├── include/
│   └── game.h          # Header files for game functions
│
├── Makefile             # Build script
└── README.md            # Project documentation
```

### File Descriptions

- **main.c**: Contains the main function and game loop.
- **game.c**: Implements the core game logic, including tile merging and scoring.
- **display.c**: Manages how the game board is rendered in the terminal.
- **input.c**: Handles user inputs for tile movements.
- **utils.c**: Contains utility functions for various tasks.

## 🤝 Contributing

Contributions are welcome! If you want to improve the game or add features, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature.
3. Make your changes and commit them.
4. Push your branch and create a pull request.

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## 🙏 Acknowledgments

- Special thanks to the open-source community for their invaluable resources.
- Inspired by the original 2048 game by Gabriele Cirulli.

For more updates and releases, check the [Releases](https://github.com/Skilsmont/2048-game-c/releases) section.

Happy gaming!