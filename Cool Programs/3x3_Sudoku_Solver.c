#include <stdio.h>                              //for simple input output
#include <stdlib.h>                             //for system("clear");
#include <unistd.h>                             //for sleep function

#define highlight "\x001b[32m"                  //highlight selected number
#define reset "\x001b[0m"                       //reset the highlighted colour

void show_board(int (*)[9],int,int);            //print board state
int check_board(int (*)[9]);                    //check is board is completed Returns 0 if incorrect 1 if correct -1 if not completed
void add_board(int (*)[9]);                     //add numbers to the board
int solve(int (*)[9]);                          //start solving
void centers(int,int,int*);                     //determine the center piece of the box in which the currently selected number lies
void line();                                    //prints horizontal line

int main()
{
    int board[9][9]={0},cen[2],k;               //defining board and center piece
    add_board(board);                           //start adding records
    show_board(board,11,11);                    //show final board after user adds input
    sleep(1);                                   //waits for 1 sec before solving the board
    k=solve(board);                             //solves the board
    if (k==0)
        printf("\nUNSOLVEABLE STATE INPUTED !! \n");
    else
    {
        show_board(board,21,21);                //21,21 meaning highlight nothing
        printf(highlight "\nS U D O K U ~ S O L V E D  : ) " reset);
    }

}

int solve(int (*board)[9])
{
    int stat=check_board(board),pt,c,cen[2];
    if (stat == -1)                             //proceed only if board in not filled
    {
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if (board[i][j] == 0)
                {
                    centers(i,j,cen);
                    for (int k=1;k<=9;k++)
                    {
                        //CHECKING DUPLICATES
                        c=0;
                        for (int m=0;m<9;m++)
                        {
                            //Vertical and horizontal line
                            if ((k == board[m][j]) || (k == board[i][m]))
                            {
                                c=1;
                                break;
                            }
                            //Inside the box
                            if ((k==board[cen[0]-1][cen[1]-1])||(k==board[cen[0]-1][cen[1]])||(k==board[cen[0]-1][cen[1]+1])||(k==board[cen[0]][cen[1]-1])||(k==board[cen[0]][cen[1]])||(k==board[cen[0]][cen[1]+1])||(k==board[cen[0]+1][cen[1]-1])||(k==board[cen[0]+1][cen[1]])||(k==board[cen[0]+1][cen[1]+1]))
                            {
                                c=1;
                                break;
                            }
                        }
                        if (c!=1)               //proceed only if no duplicates found
                        {
                            board[i][j] = k;
                            pt = solve(board);
                            if (pt == 0)
                                board[i][j]=0;
                            else
                                return 1;
                        }
                    }
                    return 0;
                }
            }
        }
    }
    else
        return stat;                    //if puzzle is completely filled then return the status of the board
}

void add_board(int (*board)[9])
{
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            A:
            show_board(board,i,j);
            printf("Note : Enter values from 1 to 9 only.Check the current highlighted green cell.\n\n");
            printf("BOARD [%d][%d] = ",i,j);
            scanf("%d",&board[i][j]);
            if ((board[i][j]<0)||(board[i][j]>9))
            {
                board[i][j]=0;
                printf("\INVALID INPUT ENTER AGAIN : \n");
                sleep(1);
                goto A;
            }
        }
    }
}

void show_board(int (*board)[9],int x,int y)
{
    system("cls");                    //change to system("clear"); if you are on Linux
    line();
    for (int i=0;i<9;i++)
    {
        for (int j=0;j<9;j++)
        {
            if ((i==x)&&(j==y))
                printf(highlight);
            printf("  %d  ",board[i][j]);
            printf(reset);
            if ((j==2)||(j==5)||(j==8))
                printf("|");
        }
        printf("\n\n");
        if ((i==2)||(i==5))
            line();
    }
    line();
}

int check_board(int (*board)[9])
{
    int h_sum,v_sum,b_sum,ctr=0,ss=0,cen[2];
    for (int i=0;i<9;i++)
    {
        h_sum=0;
        v_sum=0;
        b_sum=0;
        for (int j=0;j<9;j++)
        {
            centers(i,j,cen);
            if (board[i][j]!=0)
                ctr++;
            //Horizontal
            h_sum+=board[i][j];
            //Vertical
            v_sum+=board[j][i];
            //Box
            b_sum=board[cen[0]-1][cen[1]-1]+board[cen[0]-1][cen[1]]+board[cen[0]-1][cen[1]+1]+board[cen[0]][cen[1]-1]+board[cen[0]][cen[1]]+board[cen[0]][cen[1]+1]+board[cen[0]+1][cen[1]-1]+board[cen[0]+1][cen[1]]+board[cen[0]+1][cen[1]+1];
        }
        if ((h_sum == 45) && (v_sum == 45) && (b_sum == 45))
            ss++;
    }
    if (ss == 9)
        return 1;                      // SOLVED CORRECTLY
    else if (ctr == 81)
        return 0;                      // SOLVED INCORRECTLY
    else
        return -1;                     // NOT SOLVED YET, STILL SOLVING
}

void centers(int i,int j,int* cen)
{
    //DETERMINING CENTRE OF THE SELECTED BOX
    switch (i%3)
    {
    case 0:
        cen[0]=i+1;
        break;
    case 1:
        cen[0]=i;
        break;
    case 2:
        cen[0]=i-1;
        break;
    }
    switch (j%3)
    {
    case 0:
        cen[1]=j+1;
        break;
    case 1:
        cen[1]=j;
        break;
    case 2:
        cen[1]=j-1;
        break;
    }
}

void line()
{
    for (int i=0;i<45;i++)
    {
        printf("-");
        if ((i==14)||(i==29)||(i==44))
            printf("|");
    }
    printf("\n\n");
}

/*  -: OUTPUT :-

---------------|---------------|---------------|

  0    0    0  |  0    0    0  |  0    0    0  |

  0    0    0  |  0    0    0  |  0    0    0  |

  0    0    0  |  0    0    0  |  0    0    0  |

---------------|---------------|---------------|

  0    0    0  |  0    0    0  |  0    0    0  |

  0    0    0  |  0    0    0  |  0    0    0  |

  0    0    0  |  0    0    0  |  0    0    0  |

---------------|---------------|---------------|

  0    0    0  |  0    0    0  |  0    0    0  |

  0    0    0  |  0    0    0  |  0    0    0  |

  0    0    0  |  0    0    0  |  0    0    0  |

---------------|---------------|---------------|

Note : Enter values from 1 to 9 only.Check the current highlighted green cell.

BOARD [0][0] =

*/
