#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int H;

    do{
        printf("Height: ");
        scanf("%d", &H);
    }while(H < 1 || H > 8);

    for(size_t i = 0; i < H; i++){
        for (size_t j = H - i; j > 1; j--){
            printf(" ");
        }
        for (size_t k = 0; k < i + 1; k++){
            printf("#");
        }
        printf("\n");
    }

    system("pause");

    return 0;
}
