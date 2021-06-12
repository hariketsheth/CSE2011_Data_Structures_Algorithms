/*Snakes and Ladders
Snakes and Ladders is an ancient Indian board game. It is played between two or more players on a gameboard having numbered, gridded squares (which is in the form a matrix). The board has a  number of  pictures of the "ladders" and "snakes"  on the board, each connecting two specific board squares. The object of the game is to navigate one's game piece, according to die rolls, from the start (bottom square) to the finish (top square), helped or hindered by ladders and snakes respectively.

Given an m X n board, details of snakes and ladders in the board, current position of coin of player1 and sequence of dice rolls by player1, design an algorithm and write a C++ code to find the new position of coin of player1. The grids of the board are numbered from 1 to m*n. After a die roll, if the coin ends up in a square with snake / ladder start position then update position to end position of snake / ladder. Each grid in the board is given a number ‘g’ which is computed as (r-1)*n + c, where ‘r’ and ‘c’ are the row and column position of the grid.

 

Understand the template code and implement the functions appropriately

Input Format

Value for ‘m’

Value for ‘n’

Number of snakes in board k

Start Grid position of snake1

End Grid position of snake1

Start Grid position of snake2

End Grid position of snake2

....

Start Grid position of snake-k

End Grid position of snake-k

Number of ladders in board t

Start Grid position of ladder1

End Grid position of ladder1

Start Grid position of ladder2

End Grid position of ladder2

....

Start Grid position of ladder-t

End Grid position of ladder-t

Current row position of coin of player1

Current column position of coin of player1

Number of dice rolls

Value of roll1

Value of roll2

...

Value of roll-n

Output Format

Final row position of player1

Final column position of player1

Boundary Conditions

Assume that there will be only a maximum of ten ladders and ten snakes

The position will never go out of the board
*/

/*
Name: Hariket Sukeshkumar Sheth
Topic: CPP Practice Problems
*/
