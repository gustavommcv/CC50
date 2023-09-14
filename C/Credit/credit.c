#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, 
// and then add those products’ digits together.
// 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
// 3. If the total’s last digit is 0 
// (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

bool authenticate(int *cardDigits, int cardLength);

int step1(int *cardDigits, int cardLength);
int step2(int *cardDigits, int cardLength);
bool step3(int sum);

char* brandName(int *cardDigits, int cardLength);

int main(void)
{

    printf("Number: . . .\n");

    char *creditCard;
    creditCard = "5502093065836527"; // TODO (Ler do teclado)

    int cardLength = strlen(creditCard);

    int *cardDigits = malloc(cardLength * sizeof(int)); // Alocando memória suficiente para o array de inteiros

    if (cardDigits == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return 1;
    }

    // Armazenando os digitos da string em um array de inteiros para poder realizar as operacoes
    for (int i = 0; i < cardLength; i++)
    {
        if (creditCard[i] >= '0' && creditCard[i] <= '9')
        {
            cardDigits[i] = creditCard[i] - '0';
        }
        else
        {
            fprintf(stderr, "Caractere inválido no número do cartão.\n");
            free(cardDigits);
            return 2;
        }
    }

    if (authenticate(cardDigits, cardLength))
        printf("%s\n", brandName(cardDigits, cardLength));
    else
        printf("INVALID\n");


    free(cardDigits);

    return 0;
}

bool authenticate(int *cardDigits, int cardLength)
{
    int *copyCardDigits = malloc(cardLength * sizeof(int)); // Cria uma cópia do array

    if (copyCardDigits == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return false;
    }

    // Copia os valores do array original para a cópia
    for (int i = 0; i < cardLength; i++)
    {
        copyCardDigits[i] = cardDigits[i];
    }

    int sum = step1(copyCardDigits, cardLength);

    free(copyCardDigits); // Libera a memória da cópia

    return step3(sum);
}

int step1(int *cardDigits, int cardLength)
{
    int sum = 0;

    for (int i = cardLength - 2; i >= 0; i-=2)
    {
        sum = sum + (cardDigits[i] * 2 > 9 ? ((cardDigits[i] * 2) % 10 + (cardDigits[i] * 2) / 10) : cardDigits[i] * 2);
    }

    sum += step2(cardDigits, cardLength);

    return sum;
}

int step2(int *cardDigits, int cardLength)
{
    int sum = 0;

    for (int i = cardLength - 1; i >= 0; i-=2)
    {
        sum += cardDigits[i];
    }

    return sum;
}

bool step3(int sum) {
    sum % 10 == 0 ? true : false;
}

// American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, 
// and Visa uses 13 and 16-digit numbers.

// All American Express numbers start with 34 or 37; 
// most MasterCard numbers start with 51, 52, 53, 54, or 55 
// and all Visa numbers start with 4.

char* brandName(int *cardDigits, int cardLength) {

    char* brandName = NULL;

    if (cardLength == 15) 
    {
        if ((cardDigits[0] == 3 && cardDigits[1] == 4) || (cardDigits[0] == 3 && cardDigits[1] == 7)) 
            brandName = "American Express";
        
    } 
    else if (cardLength == 16) 
    {
        if (cardDigits[0] == 4) 
            brandName = "Visa";
        else if (cardDigits[0] == 5 && (cardDigits[1] >= 1 && cardDigits[1] <= 5))
            brandName = "MasterCard";
        else
            brandName = "Unknown brand";

    } else if (cardLength == 13) {

        if (cardDigits[0] == 4) 
            brandName = "Visa";

    } else
        brandName = "Unknown brand";

    return brandName;
}
