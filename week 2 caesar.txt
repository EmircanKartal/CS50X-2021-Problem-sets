#include <stdio.h>
#include <stdlib.h>

int encrypt(int str, int shiftKey)
{
    if (str >= 'a' && str <= 'z')
    {
        return 'a' + ((str - 'a' + shiftKey) % 26);
    }
    else if (str >= 'A' && shiftKey <= 'Z')
    {
        return 'A' + ((str - 'A' + shiftKey) % 26);
    }
    else
    {
        return str;
    }
}

int main(int argc, char *argv[])
{
    int ch, key;
    char end;
    while (1)
    {
        continueloop:
        printf("$ ./Caesar ");
        scanf("%d", &key);
        if (argc == 2)
        {
            key = atoi(argv[1]);
        }
                printf("plaintext: ");

        while ((ch = getchar()) != EOF)
        {
            printf("%c", encrypt(ch, key));
        }
    printf("Do you want to end the program?(y/n?)");
    scanf("%c",&end);
    if(end=='y')
    goto endloop;

    if(end=='n')
    goto continueloop;
    }
endloop:
printf("Programme has been ended");
return 0;
}