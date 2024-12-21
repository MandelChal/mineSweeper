/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "colorPrint.h"
#include "mineSweeper.h"
#include "getch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int row;
    int col;
    int level;
    GameBoard game;
    int i=0;
    int j=0;
    int array[2];
   
    char c;
   
 
    printf("Please enter a row number [4-20]:");
    scanf ("%d",&row);
    
    while (row>20 || row<4){
    printf("Please enter a row number [4-20]:");
    scanf ("%d",&row);
    }
    
    printf("Please enter a col number [4-20]:");
    scanf ("%d",&col);
    
    
    while (col>20 || col<4){
    printf("Please enter a col number [4-20]:");
    scanf ("%d",&col);
    }
   
   while(level>3 || level<1){
    printf("please enter level [1-Easy, 2-Medium, 3-Hard]:");
    scanf ("%d",&level);
   }
   
   initBoard(&game,row,col,level);
  
//בלולאה הוא מייצר בכל לחיצה את הלוח מחדש ובודק איזה אות הקלטה כל פעם אחרי לחצה הוא מצייר את הלוח מחדש ובודק שלא נלחץ על מוקש
while(TRUE){
  clearScreen();
    array[0]=i;
    array[1]=j;
 printBoard(&game,array);
 printf("\n");
 //printf("%d",game.hiddenTiles);
  if(game.hiddenTiles==game.totalMines ){
            printf("You win!");
            return 1;
        }
 
 
 c=getch();
 
  
  if(c==QUIT){
      printf("    \n\n BYE");
      clearScreen();
      return 1;
  }
  
  if(c==DOWN){
      if(i<row-1)
     i++;
}
    if(c==UP){
        if(i>0)    
     i--;
}
    if(c==RIGHT){
        if(j<col-1)
     j++;
}
    if(c==LEFT){
        if(j>0)
     j--;
}

    if(c==FLAG_TILE){
     flagTile(&game,i,j);
}
    if (c==CLICK_TILE){
        clickTile(&game,i,j);
       // printf("%d %d \n",game.totalMines,game.hiddenTiles);
        if (game.board[i][j].isMine==TRUE && game.board[i][j].isFlagged==FALSE){
             printf("you failed");
            return 1;}
        
    }
   

  }
    return 0;
}

