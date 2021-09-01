#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char creed[13][110] = {
    "I am an American Soldier.",
    "I am a Warrior and a member of a team.",
    "I serve the people of the United States and live the Army Values.",
    "I will always place the mission first.",
    "I will never accept defeat.",
    "I will never quit.",
    "I will never leave a fallen comrade.",
    "I am disciplined, physically and mentally tough, trained and proficient in my Warrior tasks and drills.",
    "I always maintain my arms, my equipment and myself.",
    "I am an expert and I am a professional.",
    "I stand ready to deploy, engage, and destroy the enemies of the United States of America in close combat.",
    "I am a guardian of freedom and the American way of life.",
    "I am an American Soldier."
};

int creed_length = 13;

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        char input[110];
        int i = 0;
        while (i < creed_length)
        {
            system("clear");
            printf("\t\t#########\n\t\t#       #\n\t\t# ORDER #\n\t\t#       #\n\t\t#########\n\n");
            for (int j = 0; j < i; j++)
                printf("%d. %s\n",j + 1,creed[j]);
            printf("\n\nEnter line:\n");
            fflush(stdout);
            fgets(input,sizeof input,stdin);
            fflush(stdin);
            int len = strlen(input);
            if (len > 1 && input[len-1] == '\n')
                input[len-1] = '\0';
            if (strcmp(input,creed[i]) == 0)
                i++;
        }
    }
    else if (argc > 1 && strcmp(argv[1],"repeat") == 0)
    {
        char input[110];
        int i = 0;
        while (i < creed_length)
        {
            system("clear");
            printf("\t\t##########\n\t\t#        #\n\t\t# REPEAT #\n\t\t#        #\n\t\t##########\n\n");
            printf("%s\n",creed[i]);
            fflush(stdout);
            fgets(input,sizeof input,stdin);
            fflush(stdin);
            int len = strlen(input);
            if (len > 1 && input[len-1] == '\n')
                input[len-1] = '\0';
            if (strcmp(input,creed[i]) != 0)
                continue;
            i++;
        }
    }
    else if (argc > 1 && strcmp(argv[1],"quiz") == 0)
    {
        srand(time(NULL));
        int random_number;
        int correct;
        int incorrect;
        char input[110];
        while (1)
        {
            system("clear");
            random_number = rand() % 12;
            printf("\t\t########\n\t\t#      #\n\t\t# QUIZ #\n\t\t#      #\n\t\t########\n\n");
            printf("%s\nenter the next line:\n",creed[random_number]);
            fflush(stdout);
            fgets(input,sizeof input,stdin);
            fflush(stdin);
            int len = strlen(input);
            if (len > 1 && input[len-1] == '\n')
                input[len-1] = '\0';
            if (strcmp(input,"exit") == 0)
                break;
            else if (strcmp(input,creed[random_number + 1]) == 0)
            {
                correct++;
                printf("\n\nCORRECT!\n");
            }
            else
            {
                incorrect++;
                printf("\n\nINCORRECT!\n%s",creed[random_number + 1]);
            }
            printf("\nPress enter to continue...");
            fflush(stdout);

            getchar();
        }
        system("clear");
        printf("\ncorrect answers:  \t%d\n---------------------\nincorrect answers:\t%d",correct,incorrect);
    }
    else
        printf("Invalid parameter:\n\tuse 'quiz', 'repeat' or none.");
    return 0;
}