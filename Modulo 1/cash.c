#include <stdio.h>
#include <stdlib.h>

int main(void){

    float change;
    int c25 = 0, c10 = 0, c5 = 0, c1 = 0, coins = 0, cents;

    //forcing the user to type a float
    do{
        printf("Change owed: $0.00: ");
        scanf("%f", &change);
    }while(change < 0);


    //dollars to cents conversion
        change *= 100; 
        cents = round(change);

    while (cents != 0){
        if(cents >= 25){
            cents -= 25;
            c25 += 1;
        }else if(cents >= 10){
            cents -= 10;
            c10 += 1;
        }else if(cents >= 5){
            cents -= 5;
            c5 += 1;
        }else{
            cents -= 1;
            c1 += 1;
        }
    }

    coins += c25 + c10 + c5 + c1;

    printf("Total of coins: %i\n\n25: %i\n10: %i\n5: %i\n1: %i", coins, c25, c10, c5, c1);

    system("pause");
    
    return 0;
}
