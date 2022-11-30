#include <stdio.h>
#include <stdlib.h>
void mario(height)
{
    // i holds the rows,j holds columns,s holds spaces.

    for (int i = 0; i <= height; i++)
    {
        for (int s = 0; s <= height - i - 1; s++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
            printf("\n");
        }

        printf("\n");
    

    return height;
}

int main()
{
    int height;
    printf("Height: ");
    scanf("%d", &height);
    if (height <= 0 || height>=9)
    {
        printf("please enter a integer 1 to 8!");
    }
    else
    {
        mario(height);
        return 0;
    }
}