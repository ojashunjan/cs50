#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        printf("Enter Height: ");

        scanf("%d", &height);
    }
    while (height <= 0);

    // Print the pyramid
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
