#include <stdio.h>
#include <stdlib.h>

int main(void){

    long long int number;
    int i = 0, l = 0, digit[16] = {0}, aux[16] = {0}, aux2[16] = {0}, c = 0;

    printf("Number: ");
    scanf("%lld", &number);

    //Separating the digits
    while(number > 0){
        digit[i] = number % 10;
        number /= 10;
        i++;
    }

    //Discovering the card's flag
    if(digit[i - 1] == 3 && digit[i - 2] == 4 || digit[i - 2] == 7 && i == 15){
        c = 1; //American Express
    }else if(digit[i - 1] == 5 && digit[i - 2] == 1 || digit[i - 2] == 2 || digit[i - 2] == 3 || digit[i - 2] == 4 || digit[i - 2] == 5 && i == 16){
        c = 2; //Master Card
    }else if(digit[i - 1] == 4 && i == 13 || i == 16){
        c = 3; //Visa
    }else{
        c = 0;
    }

    //Assigning the digits that have not been multiplied to another variable
    int h = 0;
    for (int s = i - 2; s >= 0; s-=2){
        aux2[h] = digit[s];
        h++;
    }

    //Multiplying by 2 
    for (int s = i - 1; s >= 0; s-=2){
        digit[s] *= 2;
    }

    //Separating the product digits
    l = 0;
    for (int s = i - 1; s >= 0; s-=2){
        if(digit[s] >= 10){
            aux[l] = 1;
            aux[l + 1] = digit[s] % 10;
            l += 2;
        }else{
            aux[l] = digit[s];
            l++;
        }
    }

    //Taking the sum value
    int sum = 0;
    for (size_t j = 0; j < l; j++){
        sum += aux[j] + aux2[j];
    }

    if(sum % 10 == 0){
        if(c == 1){
            printf("\nAmerican Express\n\n");
        }else if(c == 2){
            printf("\nMastercard\n\n");
        }else if(c == 3){
            printf("\nVisa\n\n");
        }else{
            printf("\nInvalid card\n\n");
        }
    }else{
        printf("\nInvalid card\n\n");
    }

    system("pause");

    return 0;
}
