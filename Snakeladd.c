#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

int dice;
int checkPosition();
int Position, newPosition, above;
int choice;

int checkPosition()
{    
     switch(Position)
     {
         case 13:
              return newPosition = 65;
              break;
                             
         case 28:
              return newPosition = 57;
              break;
         
         case 35:
              return newPosition =12;
              break;
              
         case 37:
              return newPosition =81;
              break;
              
         case 47:
              return newPosition =18;
              break;
              
         case 48:
              return newPosition =75;
              break;
              
         case 55:
              return newPosition =89;
              break;
              
         case 62:
              return newPosition =87;
              break;
              
         case 66:
              return newPosition =42;
              break;
              
         case 77:
              return newPosition =93;
              break;
              
         case 78:
              return newPosition =53;
              break;
              
         case 83:
              return newPosition =33;
              break;
              
         case 92:
              return newPosition =72;
              break;
         case 97:
              return newPosition =2;
              break;
         default:
                return newPosition = Position;
     }
}

int solve(int n,int player_position){
               printf("Turn for %d player ",(player_position+1));
               Position=n;
        
               printf("\nPlease press enter to roll\n");
               
               char ch=getchar(); 
               dice=((rand()%6)+1);
               printf("You have rolled a %d.\n", dice);
               newPosition=Position;
               Position+=dice;
               
               if(Position >100)
                    Position-=dice;
               printf("You have landed on space %d.\n", Position);
               checkPosition();
               if (Position<newPosition)
                    printf("Well done, you have landed on a ladder. You are now on space %d.", Position);
               
               else if (Position>newPosition)
                    printf("Unlucky, you have landed on a snake. You are now on space %d.", Position);
               
               // Position = newPosition;        
               return Position; 
}
int start(){
     int t=((rand()%6)+1);
     if (t==1)
          return 1;
          
     else
     {
          return -1;
     }
     
}
int main()
{
      
	srand(time(NULL));
            
     printf("Would you like to:\n    1)Read the rules\n    2)Play the game\n\n");
     scanf("%d", &choice);
      
     if (choice==1)  //prints the rules
	{     
          printf("\nThe rules are simple:");
          printf("\nYou press enter to roll the die");
          printf("\nYou are then told which space you have landed on");
          printf("\nIf you land on a snake you will move down the board");
          printf("\nIf you land on a ladder then you will move up it");
          printf("\nIn order to win you have to land on 100");
          return 0;
	   
	}
     else if (choice==2){
      
      
          printf("\nWelcome to Snakes and Ladders.\n");
          printf(" 1=Start           13=Ladder to 65\n");// snakes and ladders
          printf("28=Ladder to 57    97=Snake  to 2\n");
          printf("37=Ladder to 81    92=Snake  to 72\n");
          printf("83=Snake  to 33     48=Ladder to 75\n");
          printf("55=Ladder to 89    78=Snake  to 53\n");
          printf("66=Snake  to 42    47=Snake  to 18\n");
          printf(" 35=Snake  to 12     100=End\n");
          printf("62=Ladder to 87      77=Ladder to 93\n");                       
          int pos=1;
          char x;
          int n;
          printf("Enter the number of players (1-4):");
          scanf("%d",&n);
          int ar[4]={-1,-1,-1,-1};//initiating the score of all players with -1 
          do
          {
               for (int i=0;i<n;i++){
                    if (ar[i]==-1){
                         ar[i]=start();} // game starts when you get 1
                         printf("%d ",ar[i]);
               }
               printf("\n");
               for (int i=0;i<n;i++)
               {
                    if (ar[i]>0)
                    {
                         
                         ar[i]=solve(ar[i],i);
                    }
                    for (int i=0;i<n;i++)
                    {
                         if (ar[i]==100)
                         {
                              printf("Player %d has won the game",(i+1));
                              return 0;

                         }
                    }
               }

               // pos = solve(pos);
               
          
          } while(0<2);
          printf("Congratulations, you have won!!!");// if a player reaches 100 he wins
     }
           
     getch();
     return 0;
}

