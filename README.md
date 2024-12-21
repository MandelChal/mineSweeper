# mineSweeper
A console-based implementation of the classic Minesweeper game, written in C. This project provides a fun and interactive way to play Minesweeper while showcasing foundational programming concepts like arrays, recursion, and user interaction in a terminal environment

# Minesweeper in C

A terminal-based implementation of the classic **Minesweeper** game, written in C. This project provides an engaging way to play Minesweeper while demonstrating the use of arrays, recursion, and user interaction in a command-line interface.

## Features

- **Customizable Game Settings**: Adjust grid size and the number of mines to suit your preference.
- **Recursive Uncovering**: Automatically reveals adjacent cells when safe.
- **Flagging System**: Mark cells that you suspect contain mines.
- **Real-Time Updates**: Board updates dynamically as the game progresses.
- **Robust Input Validation**: Handles invalid inputs and ensures smooth gameplay.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC).
- A terminal environment to run the program.

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/minesweeperc.git
   cd minesweeper
Compile the code:

bash
Copy code
gcc -o minesweeper main.c minesweeper.c -lm
Run the game:

bash
Copy code
./minesweeper

How to Play
Objective: Uncover all cells that do not contain mines.
Game Commands:
Uncover a cell: u <row> <col>
Flag a cell: f <row> <col>
Winning: Successfully uncover all non-mine cells.
Losing: Uncover a mine.
Example Gameplay
plaintext
Copy code
Enter command (u for uncover, f for flag): u 1 2

   0  1  2  3  
0  .  .  .  .  
1  .  1  1  .  
2  .  1  *  .  
3  .  .  .  .  

Congratulations! You uncovered a safe cell.
File Structure
main.c: The main entry point for the game, handling the game loop and user input.
minesweeper.c: Contains the core game logic, including board generation, uncovering cells, and flagging.
minesweeper.h: Header file with function declarations and global definitions.
Future Enhancements
Add a graphical user interface (GUI).
Implement difficulty levels.
Save and load game progress.
Contributing
Contributions are welcome! Feel free to open an issue or submit a pull request to suggest improvements or add new features.

License
This project is licensed under the MIT License. See the LICENSE file for details.

