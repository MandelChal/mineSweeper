# mineSweeper
A console-based implementation of the classic Minesweeper game, written in C. This project provides a fun and interactive way to play Minesweeper while showcasing foundational programming concepts like arrays, recursion, and user interaction in a terminal environment

Minesweeper in C
A console-based implementation of the classic Minesweeper game, written in C. This project provides a fun and interactive way to play Minesweeper while showcasing foundational programming concepts like arrays, recursion, and user interaction in a terminal environment.

Features
Customizable Board Sizes: Adjust the grid dimensions and number of mines.
Recursive Cell Uncovering: Automatically reveals adjacent cells when safe, mimicking the classic game's mechanics.
Flagging Functionality: Mark suspected mine locations.
Dynamic Gameplay: Updates the board in real time as players uncover cells.
Error Handling: Prevents invalid moves and ensures robust input validation.
Files
minesweeper.h: Header file containing definitions, constants, and function prototypes.
minesweeper.c: Main implementation file with game logic and functions.
main.c: Entry point for the program, containing the game loop and user interface.
How to Play
Objective: Uncover all safe cells without detonating a mine.
Controls:
Enter the row and column indices to uncover a cell.
Use the flag command to mark a cell as a suspected mine.
Win Condition: Successfully uncover all non-mine cells.
Lose Condition: Uncover a cell containing a mine.
Usage
Compilation
To compile the game, use a C compiler like gcc:

bash
Copy code
gcc -o minesweeper main.c minesweeper.c -lm  
Running the Game
Execute the compiled program in the terminal:

bash
Copy code
./minesweeper  
Follow the on-screen instructions to start playing.

Example
mathematica
Copy code
Enter command (u for uncover, f for flag): u  
Enter row and column: 1 2  

   0  1  2  3  
0  .  .  .  .  
1  .  1  1  .  
2  .  1  *  .  
3  .  .  .  .  

Congratulations! You uncovered a safe cell.  
Contributions
Contributions are welcome! Feel free to open issues or submit pull requests to improve the game.
