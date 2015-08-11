#include<stdio.h>
#include<stdlib.h>

int filled=0;  // filled Boxes

void printMatrix(char mat[3][3]) {
     for(int i=0;i<3;i++) {
                 for(int j=0;j<3;j++) {
                     printf("| %c |",mat[i][j]);
             }
             printf("\n");
     }
}
/* Game Result*/
void displayResult(char mat[3][3],char winner) {
    printf("\nPlayer %c WON\n",winner);
    printMatrix(mat);
    system("pause");
}

/*Checks game stats*/
bool gameOver(char mat[3][3]) {

    /*checking rows*/
    for(int i=0;i<3;i++) {
        if(mat[i][0]==mat[i][1] && mat[i][1]==mat[i][2] && (mat[i][1]=='X' || mat[i][1]=='O')) {
            displayResult(mat,mat[i][1]);
            return true;
        }
    }
    /*checking columns*/
    for(int i=0;i<3;i++) {
        if(mat[0][i]==mat[1][i] && mat[1][i]==mat[2][i] && (mat[1][i]=='X' || mat[1][i]=='O')) {
            displayResult(mat,mat[1][i]);
            return true;
        }
    }
    /*checking diagonals*/
    if(mat[0][0]==mat[1][1] && mat[1][1]==mat[2][2] && (mat[1][1]=='X' || mat[1][1]=='O')) {
            displayResult(mat,mat[1][1]);
            return true;
        }
    if(mat[0][2]==mat[1][1] && mat[1][1]==mat[2][0] && (mat[1][1]=='X' || mat[1][1]=='O')) {
            displayResult(mat,mat[1][1]);
            return true;
    }

    return false;
}

/*Assigning i and j for matrix from index*/
void assignIndex(int *i,int *j,int index) {
    switch(index) {
        case 1:*i=0;*j=0;break;
        case 2:*i=0;*j=1;break;
        case 3:*i=0;*j=2;break;
        case 4:*i=1;*j=0;break;
        case 5:*i=1;*j=1;break;
        case 6:*i=1;*j=2;break;
        case 7:*i=2;*j=0;break;
        case 8:*i=2;*j=1;break;
        case 9:*i=2;*j=2;break;
    }
}

int main() {

        char mat[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
        char currentPlayer='O';
        int index,i,j;
        time_t t;
        srand((unsigned)(&t));

        while(!gameOver(mat) && filled<9) {
            printf("**** CURRENT STATS *****\n");
            printMatrix(mat);

            if(filled == 9) {
                printf("...DRAW...\n");
                break;
            }


            printf("\nValid moves : \n");
            for(int i=0;i<3;i++) {
                for(int j=0;j<3;j++) {
                    if(mat[i][j]==' ') {
                        mat[i][j]=currentPlayer;
                        printMatrix(mat);
                        printf("---------------------\n");
                        mat[i][j]=' ';
                    }
                }
            }

            printf("Player %c :: ",currentPlayer=='O'?'O':'X');

            if(currentPlayer=='X') {  // Computer
                while(1) {
                    scanf("%d",&index);
                    assignIndex(&i,&j,index);
                    if(mat[i][j]!=' ')
                        printf("Enter valid index : ");
                    else break;
                }
            }
            else {                    // You
                while(1) {
                    scanf("%d",&index);
                    assignIndex(&i,&j,index);
                    if(mat[i][j]!=' ')
                        printf("Enter valid index : ");
                    else break;
                }
            }

            mat[i][j]=(currentPlayer=='O'?'O':'X');
            filled++;

            currentPlayer= (currentPlayer=='O'?'X':'O') ;

            system("cls");
        }

    return 0;
}
