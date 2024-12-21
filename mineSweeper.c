#include "colorPrint.h"
#include "getch.h"
#include "mineSweeper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 //returns true upon success
void clickTile(GameBoard *g, int row, int col);
void flagTile(GameBoard *g, int row, int col);
void populateMines(GameBoard *g, int level);
void markNumbers(GameBoard *g);
void printBoard(GameBoard *g, int cursorCoords[2]);



// Methods:
bool initBoard(GameBoard *g, int rows, int cols, int level){
    
   g->rows = rows;
   g ->cols = cols;
   
    int i;
    int j;
    int m;
    
    g-> board= (Tile**)malloc(sizeof(Tile*) *rows);
    
     for( m = 0; m < rows ; m++){
    g->board[m] = (Tile*)malloc(sizeof(Tile)*cols);}
    
    double metrix=(rows*cols);
    double numOfTails=metrix/100;
    
  
    if (level==1)
        numOfTails=numOfTails*EASY_LEVEL_PERCENT;
    if (level==2)
        numOfTails=numOfTails*(MEDIUM_LEVEL_PERCENT);
    if(level==3)
        numOfTails=numOfTails*(HARD_LEVEL_PERCENT); 
    
    int number=(int)(numOfTails);
    g -> totalMines = number;
    g -> hiddenTiles = metrix;
  for(i=0; i< rows;i++){
        for(j=0; j<cols ;j++){
            g->board[i][j].isVisible=FALSE;
            g->board[i][j].isMine=FALSE;
            g->board[i][j].isFlagged=FALSE;
            g->board[i][j].numOfMines=0;
      }
    }
     populateMines(g,level);
     markNumbers(g);
     if(g->board==NULL)
     return FALSE;
     return TRUE;
    
}

 void clickTile(GameBoard *g, int row, int col){

int i=row;
int j=col;
int k;
int t;


 if(g->board[i][j].isVisible==TRUE )
    return;
    
 else if (g->board[i][j].isVisible==FALSE ){
     if( g->board[i][j].isFlagged==TRUE){
       
     return;
     }
     else if (g->board[i][j].isFlagged==FALSE){
         if( g->board[i][j].isMine==TRUE){
             g->isMineClicked=TRUE;
             return;
         }
         else if ( g->board[i][j].isMine==FALSE){
             if( g-> board[i][j].numOfMines>0){
                 g->board[i][j].isVisible=TRUE;
                 
                   g->hiddenTiles--;
                 return;
             }
             else if(g-> board[i][j].numOfMines==0){
                  g->board[i][j].isVisible=TRUE;
                  
                    g->hiddenTiles--;
               
              if(row==0){
              if(col==0){
                 
                 clickTile(g,row+1,col);
                 clickTile(g,row,col+1);
                 clickTile(g,row+1,col+1);
      }
            else if(col>0 && col<g->cols-1){
             clickTile(g,row+1,col);
             clickTile(g,row,col+1);
             clickTile(g,row,col-1);
             clickTile(g,row+1,col+1);
             clickTile(g,row+1,col-1);

              }
            else if(col==g->cols-1){
            clickTile(g,row+1,col);
            clickTile(g,row,col-1);
            clickTile(g,row+1,col-1);
  
              }
               
          }
           
           
          if(i>0 && i< g->rows-1){
               
          if(j==0){
             clickTile(g,row+1,col);
             clickTile(g,row-1,col);
             clickTile(g,row,col+1);
             clickTile(g,row+1,col+1);
             clickTile(g,row-1,col+1);
          }
    else if(col>0&& col<g->cols-1){
     clickTile(g,row+1,col);
     clickTile(g,row-1,col);
     clickTile(g,row,col+1);
     clickTile(g,row,col-1);
     clickTile(g,row+1,col+1);
     clickTile(g,row-1,col-1);
     clickTile(g,row+1,col-1);
     clickTile(g,row-1,col+1);
              }
    else if(col==g->cols-1){
     clickTile(g,row+1,col);
     clickTile(g,row-1,col);
     clickTile(g,row,col-1);
     clickTile(g,row-1,col-1);
     clickTile(g,row+1,col-1);
 
              }
               
          }
          
          if(row==g->rows-1){
          if(col==0){
             
     clickTile(g,row-1,col);
     clickTile(g,row,col+1);
     clickTile(g,row-1,col+1);

          }
     else if(col>0&& col<g->cols-1){
     clickTile(g,row-1,col);
     clickTile(g,row,col+1);
     clickTile(g,row,col-1);
     clickTile(g,row-1,col-1);
     clickTile(g,row-1,col+1);
                   
              }
              else if(col==g->cols-1){
     clickTile(g,row-1,col);
     clickTile(g,row,col-1);
      clickTile(g,row-1,col-1);
        
        }
              
          }
                 
             }
         }
 }
          }
                  }

    
void flagTile(GameBoard *g, int row, int col){
    
    if(g->board[row][col].isVisible==TRUE)
    return;
    
    if(g->board[row][col].isFlagged==TRUE && g->board[row][col].isVisible==FALSE){
        g->board[row][col].isFlagged=FALSE;
       // if (g->board[row][col].isMine==TRUE){
       // g->hiddenTiles--;}
        
   // }
        return;
    }
    
    if(g->board[row][col].isFlagged==FALSE && g->board[row][col].isVisible==FALSE){
        g->board[row][col].isFlagged=TRUE;
      //  if(g->board[row][col].isMine==TRUE){
      //  g->hiddenTiles++;}
        return;
    }
}

void populateMines(GameBoard *g, int level){
  
    int m;
    int rows= g -> rows;
    int cols= g -> cols;
    
  
    double metrix=(rows*cols);
    double numOfTails=metrix/100;
  
    
    if (level==1)
        numOfTails=numOfTails*EASY_LEVEL_PERCENT;
    if (level==2)
        numOfTails=numOfTails*(MEDIUM_LEVEL_PERCENT);
    if(level==3)
        numOfTails=numOfTails*(HARD_LEVEL_PERCENT); 
        
        int number=(int)(numOfTails);
     
      
    srand(2*time(NULL));
    if(g== NULL){
    printf("malloc failed");
    exit(1);
 }
     for (m=0 ; m<number ; m++ ){
      
      int i = rand()%rows;
      int j = rand()%cols;
      
      if (g-> board[i][j].isMine==FALSE){
      g-> board[i][j].isMine=TRUE;
      g-> board[i][j].numOfMines=-1;
  
      }
      }
  }
void markNumbers(GameBoard *g){
 
    int i;
    int j;
    int numOfRows= g -> rows;
    int numOfCols= g -> cols;
     int counterOfTails=0;
     

 for(i=0 ; i < numOfRows ; i++){
    for(j=0 ; j< numOfCols ; j++){

       if(g->board[i][j].isMine==FALSE) {
        
    if (i==0){
       if (j==0) { //first row and first col-->3 
           
           if(g->board[i+1][j].isMine==TRUE )
                     counterOfTails++;
                     
             if(g->board[i+1][j+1].isMine==TRUE )
                     counterOfTails++;
                    
             if(g->board[i][j+1].isMine==TRUE )
                     counterOfTails++;
           
       }
       else if(j>0 && j<numOfCols-1){ //first row and between first and last col
       
            if(g->board[i][j-1].isMine==TRUE )
                     counterOfTails++;
                     
             if(g->board[i][j+1].isMine==TRUE )
                     counterOfTails++;
                    
             if(g->board[i+1][j+1].isMine==TRUE )
                     counterOfTails++;
                
            if(g->board[i+1][j].isMine==TRUE )
                     counterOfTails++;
            
            if(g->board[i+1][j-1].isMine==TRUE )
                     counterOfTails++;         
           
       }
       
       else if (j== numOfCols-1){
           
           if(g->board[i][j-1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i+1][j+1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i+1][j-1].isMine==TRUE )
                     counterOfTails++;         
       }
    }
    
   else if (i>0 && i<numOfRows-1){
        if(j==0){
            if(g->board[i-1][j+1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i-1][j].isMine==TRUE )
                     counterOfTails++; 
                    
            if(g->board[i][j+1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i+1][j].isMine==TRUE )
                     counterOfTails++; 
                     
            if(g->board[i+1][j+1].isMine==TRUE )
                     counterOfTails++;         
                      
            
    }
        else if (j>0 && j<numOfCols-1){
            
            if(g->board[i+1][j].isMine==TRUE )
                     counterOfTails++;
            
            if(g->board[i-1][j].isMine==TRUE )
                     counterOfTails++;         
                     
            if(g->board[i][j+1].isMine==TRUE )
                     counterOfTails++; 
                    
            if(g->board[i][j-1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i-1][j-1].isMine==TRUE )
                     counterOfTails++; 
                     
            if(g->board[i+1][j+1].isMine==TRUE )
                     counterOfTails++;
                    
            if(g->board[i+1][j-1].isMine==TRUE )
                     counterOfTails++; 
                     
            if(g->board[i-1][j+1].isMine==TRUE )
                     counterOfTails++;         
            
        }
        else if (j==numOfCols-1){
            
            if(g->board[i+1][j].isMine==TRUE )
                     counterOfTails++;
            
            if(g->board[i-1][j].isMine==TRUE )
                     counterOfTails++;         
                     
            if(g->board[i][j-1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i-1][j-1].isMine==TRUE )
                     counterOfTails++; 
                     
            if(g->board[i+1][j-1].isMine==TRUE )
                     counterOfTails++; 
                     
            }
    }
    
   else if (i==numOfRows-1){
        if(j==0){
            
            if(g->board[i-1][j].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i-1][j+1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i][j+1].isMine==TRUE )
                     counterOfTails++;         
        
        }
        else if (j==numOfCols-1){
            
            if(g->board[i-1][j].isMine==TRUE )
                     counterOfTails++;
            
            if(g->board[i][j-1].isMine==TRUE )
                     counterOfTails++; 
                     
            if(g->board[i-1][j-1].isMine==TRUE )
                     counterOfTails++;         
            
            
        }
        else if(j>0 && j< numOfCols-1){
            
            if(g->board[i-1][j].isMine==TRUE )
                     counterOfTails++;         
                     
            if(g->board[i][j+1].isMine==TRUE )
                     counterOfTails++; 
                    
            if(g->board[i][j-1].isMine==TRUE )
                     counterOfTails++;
                     
            if(g->board[i-1][j-1].isMine==TRUE )
                     counterOfTails++; 
                     
            if(g->board[i-1][j+1].isMine==TRUE )
                     counterOfTails++;
        }
    }
    
    g->board[i][j].numOfMines=counterOfTails;
      counterOfTails=0;
            
       }      
    }
      }
 
  return;
}
  


void printBoard(GameBoard *g, int cursorCoords[2]){
    int x= cursorCoords[0];
    int y= cursorCoords[1];
  
  
   for (int i=0; i< g->rows ;i++){
      printf("\n");
       for(int j=0; j< g->cols; j++){
           
       if(g->board[i][j].isFlagged==TRUE && g->board[i][j].isVisible==FALSE){
           colorPrint( FG_Yellow,  BG_White,  ATT_Def, " ?");
}
           
        if(g->board[i][j].isVisible==FALSE && g->board[i][j].isFlagged==FALSE ){
         if(x==i && y==j)
            colorPrint(  BG_White,  BG_Yellow,  ATT_Def, " *");
          else   colorPrint(  FG_Cyan, BG_White ,  ATT_Def, "  ");
        }
        if(g->board[i][j].isVisible==TRUE && g->board[i][j].isFlagged==FALSE && g->board[i][j].isMine==FALSE){
            
          if(g->board[i][j].numOfMines==0){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 0");}
                    
         else if(g->board[i][j].numOfMines==1){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 1");
                }
                else if(g->board[i][j].numOfMines==2){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 2");
                }
               else if(g->board[i][j].numOfMines==3){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 3");
                }
                else if(g->board[i][j].numOfMines==4){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 4");
                }
                else if(g->board[i][j].numOfMines==5){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 5");
                }
                else if(g->board[i][j].numOfMines==6){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 6");
                }
                else if(g->board[i][j].numOfMines==7){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 7");
                }
                else if(g->board[i][j].numOfMines==8){
                    colorPrint(FG_Black, BG_Cyan, ATT_Def, " 8");
                }
        
         
       }}
   }   
}
