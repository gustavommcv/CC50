#include <stdio.h>

int main (void) 
{
    int height = 0;

    do {
        printf("Height: ");
        scanf("%d", &height);
    } while(height > 8 || height < 1);


    printf("\n");

    for(int i = 0; i < height; i++) 
    {
        // First pyramid ⬇️
        for(int j = 0; j < height - i - 1; j++)
            printf(".");

        for(int k = 0; k <= i; k++) 
            printf("#");

        printf(".."); 

        // Second pyramid ⬇️
        for(int l = 0; l <= i; l++) 
            printf("#");

        printf("\n");
    }

    return 0;
}
