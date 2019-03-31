#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(int lower, int upper)
{
        int num = (rand() % (upper - lower + 1)) + lower;
        return num;
    }

int main()
{
    int p1=0, p2=0, a=0,b=0;
     int turnscore;
    int lower = -1, upper = 2, count = 1;
    srand(time(0));
    while(p1<9 && p2<9)
    {
        if(a!=0)
            a=a-1;

        else{
        printf("player1 turn\n");
        char s1;
        scanf("%c", &s1);
    turnscore = dice(lower, upper);
    printf("player 1 dice %d\n", turnscore);
    p1=p1+turnscore;
    if(p1>9)
    {p1=p1-turnscore;}
    printf("player 1 score is %d\n\n", p1);

    if(p1==5)
    {
        printf("Player1 again turn\n");
        char s1;
        scanf("%c", &s1);
        turnscore = dice(lower, upper);
        printf("player 1 dice %d\n", turnscore);
        switch(turnscore)
        {
        case -1:
            a=1;
            printf("player1 loose 1 turn\n");
            break;
        case 0:
            p1=p1-1;
            printf("player1 loose 1 point\n");
            printf("player 1 score is %d\n\n", p1);
            break;
        case 1:
            a=2;
            printf("player1 loose 2 turn\n");
            break;
        case 2:
            p1=p1-2;
            printf("player1 loose 2 point\n");
            printf("player 1 score is %d\n\n", p1);
            break;
        }
    }

if(p1==9)
        {printf("Player 1 is win!!!\n");
         break;}
        }


        if(b!=0)
            b=b-1;

        else{
        printf("player2 turn\n");
        char s2;
        scanf("%c", &s2);
    turnscore = dice(lower, upper);
    printf("player 2 dice %d\n", turnscore);
    p2 = p2+turnscore;
    if(p2>9)
    {p2=p2-turnscore;}
    printf("player 2 score is %d\n\n", p2);

    if(p2==5)
    {
        printf("Player2 again turn\n");
        char s2;
        scanf("%c", &s2);
        turnscore = dice(lower, upper);
        printf("player 2 dice %d\n", turnscore);
        switch(turnscore)
        {
        case -1:
            b=1;
            printf("player2 loose 1 turn\n");
            break;
        case 0:
            p2=p2-1;
            printf("player2 loose 1 point\n");
            printf("player 2 score is %d\n\n", p2);
            break;
        case 1:
            b=2;
            printf("player2 loose 2 turn\n");
            break;
        case 2:
            p2=p2-2;
            printf("player2 loose 2 point\n");
            printf("player 2 score is %d\n\n", p2);
            break;
        }
    }
    if(p2==9)
         {printf("Player 2 is win!!!\n");
          break;}

    }
    }




    return 0;
}
