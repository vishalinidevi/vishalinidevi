#include <stdio.h>
#include <stdlib.h>

void print_game(char arr[7][7])
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }

}
int main()
{
    char game[7][7],input_char,br_strength;
    int pos_x,pos_y,count;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            game[i][j]='-';
        }
    }
    printf("\n Before initialization\n");
     print_game(game);
     printf("\n");
    //position of wall
    int i,j;
    for(int i=0;i<7;i++)
    {
        game[i][0]='W';
    }
    for(int j=0;j<7;j++)
    {
        game[0][j]='W';
    }
    for(int i=0;i<7;i++)
    {
        game[i][6]='W';
    }
     i=6,j=3;
    game[i][j]='o';
    for(j=1;j<3;j++)
    {
        game[6][j]='G';
    }
    for(j=4;j<6;j++)
    {
        game[6][j]='G';
    }

    printf("\n After wall initialization\n");
     print_game(game);

     printf("Enter the brick position and brick type: ");
     scanf("%d %d %c",&pos_x,&pos_y,&br_strength);
     if(br_strength=='1')
     {
        br_strength=49;
        game[pos_x][pos_y]=br_strength;
        //printf("\n x pos \n");
     }
     else if(br_strength=='e')
     {
        game[pos_x][pos_y]=br_strength;
        //printf("\n y pos \n");
     }
     else if(br_strength=='s')
     {
         game[pos_x][pos_y]=br_strength;
         //printf("\n brick \n");
     }
     printf("Do you want to continue:\n");

     scanf(" %c",&input_char);

     while(input_char=='y')
     {

        printf("\nEnter the brick position and brick type: ");
        scanf("%d %d %c",&pos_x,&pos_y,&br_strength);
        if(br_strength=='1')
        {
            br_strength=49;
            game[pos_x][pos_y]=br_strength;
            //printf("\n x pos \n");
        }
        else if(br_strength=='e')
        {
            game[pos_x][pos_y]=br_strength;
           // printf("\n y pod \n");
        }
        else if(br_strength=='s')
        {
            game[pos_x][pos_y]=br_strength;
            //printf("\n brick \n");
        }
        printf("Do you want to continue:");
        scanf(" %c",&input_char);
     }
     printf("enter the ball count:");
     scanf("%d",&count);
    printf("\n after getting input:\n");
    print_game(game);
    printf("ball count is %d",count);
    int current_ball_posx=6;
    int current_ball_posy=3;
    int current_ballcount=1;
    int user_ballcount=count;
    while(current_ballcount<user_ballcount)
    {
        char ball_dirction;
        printf("\nenter the ball direction:");
        scanf(" %c",&ball_dirction);
        current_ballcount++;
        int next_box_posx,next_box_posy;
            next_box_posx=current_ball_posx-1;
            next_box_posy=current_ball_posy;
        switch(ball_dirction)
        {
        case 's':
            while(game[next_box_posx][next_box_posy]=='-'){
                next_box_posx--;
                if (game[next_box_posx][next_box_posy]=='e')
                {
                    for(next_box_posy=1;next_box_posy<6;next_box_posy++)
                    {
                        game[next_box_posx][next_box_posy]='-';
                    }
                }
                else if(game[next_box_posx][next_box_posy]=='s')
                {
                    printf("\n %d \n",next_box_posx);
                    while(next_box_posx>=2)
                    {
                        printf("\n x position \n");
                        for(next_box_posy=2;next_box_posy<6;next_box_posy++)
                        {
                            game[next_box_posx][next_box_posy]='-';
                        }
                        next_box_posx--;
                    }
                }
            }
            print_game(game);

            printf("\n You win HURRAY.!!\n");
        }
    }

    return 0;
}
