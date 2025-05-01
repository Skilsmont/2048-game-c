# 🧩 2048 Game in C (Console Version)

This project is a console-based implementation of the 2048 game, developed entirely in C as part of a university assignment in a systems programming course.

The game supports variable board sizes, score tracking, and dynamic memory handling using pointer arithmetic without any 2D arrays.

---

## 🎯 Objectives

- Simulate the original 2048 game using only C.
- Implement logic using a flat 1D array and pointer arithmetic.
- Allow playing multiple rounds with different board sizes and winning values.
- Handle user input and game state management via clean modular code.

---

## 📚 Features

- 🟦 Dynamic board sizes: supports 2×2, 3×3, and 4×4 (as seen in `main.c`)
- 🧠 Win condition can be adjusted (e.g., 16, 32, 2048)
- 🔁 Multiple games can run one after the other
- 🎲 Random tile generation (value 2 with 70% chance, 4 with 30%)
- 🎯 Game ends when:
  - No valid moves are left
  - A tile reaches the target value (e.g., 2048)
- 🎮 Console-based interface:
  - `n/N` = New game  
  - `r/R`, `l/L`, `u/U`, `d/D` = Movement  
  - `e/E` = Exit

---

## 🗂️ File Structure

- `main.c` – Runs 3 games with different board sizes and goals  
- `game.c / game.h` – Game logic, input handling, move validation  
- `board.c / board.h` – Board rendering, initialization, random tile generation  
- `Makefile` – For compiling and cleaning the project  

---

## 🛠️ Compilation & Execution

This project is built to run in a Linux environment (e.g., Ubuntu) and includes a `Makefile` for simple build and cleanup.

## 🔧 Build & Run

To compile and execute the game:

```bash
make        # Compile all source files
./a.out     # Run the compiled game
make clean  # Delete all object files and the executable

---

## 📷 Example Output

Score 0 Best 0
--------------------------
|      |   2  |      |
|      |      |      |
|   4  |      |      |
--------------------------
Please choose one of the following options:
N/n - New Game
R/r - Move Right
L/l - Move Left
U/u - Move Up
D/d - Move Down
E/e - Exit

---

## 🧠 What I Learned

- Working with pointer arithmetic to simulate 2D grids in a 1D array
- Writing modular code using .c and .h file separation
- Handling random tile generation with controlled probability
- Managing user input and real-time game state
- Creating a flexible and dynamic C program that complies with strict standards

---

## 👤 Author
**Itamar Hadad**  
B.Sc. Computer Science Student – Afeka College  
📧 hzitamar4@gmail.com  
[LinkedIn](https://www.linkedin.com/in/itamar-hadad)

