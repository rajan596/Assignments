/*
* Rajan Kasodariya                  *
* U13CO050                          *
* AI Assignment                     *
*************************************.
Computer    : X
You         : O  ( First your turn )
*/

#include<stdio.h>
#include<stdlib.h>

int filled=0;  // Stores no. of filled Boxes

void printMatrix(char box[]) {
     printf("\n");
     printf(" |  %c  |  %c  |  %c  |\n",box[1],box[2],box[3]);
     printf(" |  %c  |  %c  |  %c  |\n",box[4],box[5],box[6]);
     printf(" |  %c  |  %c  |  %c  |\n",box[7],box[8],box[9]);

}

/*Checks game stats
Returns -1 if game is not over
Returns 0 if DRAW
Returns 10 if Computer 'X' wins
Returns -10 if You win 'O'
*/
int gameOver(char box[]) {

    /*checking rows*/
    if(box[1]==box[2] && box[2]==box[3] && box[2]!=' ')
        return box[2]=='X'? 10 : -10 ;

    if(box[4]==box[5] && box[5]==box[6] && box[4]!=' ')
        return box[4]=='X'? 10 : -10 ;

    if(box[7]==box[8] && box[8]==box[9] && box[8]!=' ')
        return box[8]=='X'? 10 : -10 ;

    /*checking columns*/
    if(box[1]==box[4] && box[4]==box[7] && box[1]!=' ')
        return box[1]=='X'? 10 : -10 ;

    if(box[2]==box[5] && box[5]==box[8] && box[2]!=' ')
        return box[2]=='X'? 10 : -10 ;

    if(box[3]==box[6] && box[6]==box[9] && box[3]!=' ')
        return box[3]=='X'? 10 : -10 ;

    /*checking diagonals*/
    if(box[1]==box[5] && box[5]==box[9] && box[1]!=' ')
            return box[1]=='X'? 10 : -10 ;

    if(box[3]==box[5] && box[5]==box[7] && box[3]!=' ')
            return box[3]=='X'? 10 : -10 ;

    /* If DRAW return 0*/
    if(filled==9)
        return 0;

    /* If game is not over then return -1*/
    return -1;
}

/* Game Result*/
void displayResult(char box[]) {
    int x=gameOver(box);
    if(x==10) {
        printf("Player X won\n");
    } else if(x==-10) {
        printf("Player O won\n");
    } else {
        printf("....DRAW...\n");
    }
    printMatrix(box);
    system("pause");
}

/* Returns Array={index , benifit } */
int* miniMax(char box[] , bool player) {

    int a[2];
    int x=gameOver(box);
    int i,j,k,l,index;

    /* Base case */
    if(x!=-1) {
        a[0]=-1;
        a[1]=x;
        return a;
    }

    /* Main Part*/
    if(player==true) {
        int mx=-100;    // Max. possible score of 'X'

        /*Check all possible moves*/
        for(i=1;i<10;i++) {
            if(box[i]==' ') {
                /* Fill this box*/
                box[i]='X';
                filled++;

                int *a;
                a=miniMax(box , !player);
                if(mx < a[1]) {
                    mx=a[1];
                    index=i;
                }
                /* Unfill this box*/
                box[i]=' ';
                filled--;
            }
        }
        a[0]=index;
        a[1]=mx;
        return a;
    }
    else {

        int mn=+100;   // Min. possible score of 'O'

        for(i=1;i<10;i++) {
            if(box[i]==' ') {
                box[i]='O';
                filled++;
                int *a;
                a=miniMax(box , !player);
                if(mn > a[1]) {
                    mn=a[1];
                    index=i;
                }

                box[i]=' ';
                filled--;
            }
        }
        a[0]=index;
        a[1]=mn;
        return a;
    }
}

int main() {

        char box[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',};
        char currentPlayer='O';
        int index,i,j,x;

        /* Choose first move */
        printf("You are Mr. O\n");
        printf("Who will start game ? ( Enter 'O' or 'X') : ");
        scanf("%c",&currentPlayer);

        /* Continue game until result declares */
        while(gameOver(box)==-1 && filled<9) {
            printMatrix(box);

            /* If all the boxes are filled then game is over */
            if(filled == 9) {
                printf("...DRAW...\n");
                printMatrix(box);
                return 0;
            }

            printf("Player %c :: ",currentPlayer=='O'?'O':'X');

            if(currentPlayer=='X') {  // Computer 'X'
                    int *a;

                    /* Check immediate state if winning is possible or not ? */
                    for(i=1;i<10;i++) {
                       if(box[i]==' ') {
                           box[i]='X';
                           x=gameOver(box);
                           if(x==10) {
                               box[i]='X';
                               system("cls");
                               displayResult(box);
                               system("pause");
                               return 0;
                           }
                           box[i]=' ';
                       }
                    }

                    a=miniMax(box , true);
                    index=a[0];
            }
            else {                    // You  'O'
                while(1) {
                    scanf("%d",&index);
                    if(box[index]!=' ')
                        printf("Enter valid index : ");
                    else
                        break;
                }
            }

            /* Fill the BOX */
            box[index]=(currentPlayer=='O'?'O':'X');
            filled++;

            currentPlayer= (currentPlayer=='O'?'X':'O') ;

            system("cls");
        }

        displayResult(box);

    return 0;
}
