//Run it on your console to try

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* First we ask if he wants to play solo or duo, second we ask to select the difficulty between 1 and 3. If Solo, the player have 5 attempts to guess the
the number, if 2 players , each player have 3 attempts with each one playing when his name is mentionned */


int main()
{
    int mode, level = 1, max = 0, min = 0;
    int wannaPlay = 1;

    //Selecting the number of players 1 for solo and 0 for 2 players
    printf("Select the mode of the game \n 1- Solo \n 0- 2 players \n");
    scanf("%d", &mode);

    // if solo mode
    if(mode){
    // First Choose the level of difficulty between 1 and 3
        printf("Select the level of difficulty 1 , 2 or 3 \n");
        scanf("%d", &level);
        switch(level){
            case 1:
                max = 10;
                 min = 1;
                 printf("Range between 1 and 10 \n");
                 break;
            case 2:
                max = 50;
                 min = 1;
                 printf("Range between 1 and 50 \n");
                 break;
            case 3:
                max = 100;
                 min = 1;
                 printf("Range between 1 and 100 \n");
                 break;

            default: // handle invalid level input
                printf("Invalid level input. Using default range 1-10.\n");
                max = 10;
                min = 1;
                break;
        }


        while(wannaPlay){
            //Second Generate a random number
            int numToFind, answer, compteur = 0;
            srand(time(NULL));
            numToFind = (rand() % (max - min + 1)) + min;


            do{
                // While he's under 5 attempts
                if(compteur < 5){
                //Donner un nombre
                printf(" What is the number ?");
                scanf("%d", &answer);
                //Comparer avec le numéro à trouver
                if(answer == numToFind){
                    printf("Good Job You won !!! \n");
                }
                else if (answer <= numToFind){printf("It's more ! \n");}
                else if (answer > numToFind){printf("it's less ! \n");}
                else {
                        printf("put a real number");
                        printf("What is the number ? ");
                        scanf("%d", &answer);
                }
                //augmenter le compteur
                compteur++;
                }
                // If he did acheive 5 attempts break the loop print that he loose and ask hil if he wanna play again
                else {
                    answer = numToFind;
                    printf("You looses \n");
                    }
            }
            while(numToFind != answer);

            //Ask if he wanna play again or break the wannaPlay loop
            printf("Do you want to play again ? \n 1- yes \n 0-No \n");
            scanf("%d", &wannaPlay);

        }
    }
    else if (mode == 0 ){


        printf("Select the level of difficulty 1 , 2 or 3 \n");
        scanf("%d", &level);
        switch(level){
            case 1:
                max = 10;
                 min = 1;
                 printf("Range between 1 and 10 \n");
                 break;
            case 2:
                max = 50;
                 min = 1;
                 printf("Range between 1 and 50 \n");
                 break;
            case 3:
                max = 100;
                 min = 1;
                 printf("Range between 1 and 100 \n");
                 break;
            default: // handle invalid level input
                printf("Invalid level input. Using default range 1-10.\n");
                max = 10;
                min = 1;
                break;
        }

            while(wannaPlay){
            //Second Generate a random number
            int numToFind, answer, compteur = 1;
            // to differentiate between players
            srand(time(NULL));
            numToFind = (rand() % (max - min + 1)) + min;


            do{

                char player[50];
                // While he's under 5 attempts
                if(compteur < 7){
                //Donner un nombre
                if (compteur % 2 == 1){
                    char player[50] = "Player1";
                }
                else{
                    char player[50] = "player2";
                }


                printf(" %s \n Quel est le nombre ? ", player);
                scanf("%d", &answer);
                //Comparer avec le numéro à trouver
                if(answer == numToFind){
                    printf("%s won \n Congratulations !! \n\n\n", player);
                }
                else if (answer <= numToFind){printf("C'est plus ! \n");}
                else if (answer > numToFind){printf("C'est moins ! \n");}
                else {
                        printf("Put a real Number");
                        printf("Quel est le nombre ? ");
                        scanf("%d", &answer);
                }
                //augmenter le compteur
                compteur++;
                }
                // If he did acheive 5 attempts break the loop print that he loose and ask hil if he wanna play again
                else {
                    answer = numToFind;
                    printf("You looses \n");
                    }
            }
            while(numToFind != answer);

            //Ask if he wanna play again or break the wannaPlay loop
            printf("Do you want to play. \n 1- yes \n 0-No \n");
            scanf("%d", &wannaPlay);

            }

        }


    return 0;
}

