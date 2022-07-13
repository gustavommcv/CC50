#include <stdio.h>
#include <stdlib.h>

int main(void){

    int population, population2, sum;

    do{
        printf("Start size: ");
        scanf("%d", &population);
    }while(population <= 0);

    do{
        printf("End size: ");
        scanf("%d", &population2);
    }while(population2 <= population);


    int i = 0;
    while(population < population2){
        population = population + (population / 3 - population / 4);
        i++;
    }

    printf("Number of years: %d", i);

    system("pause");
    
    return 0;
}
