#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
INCOMPLETE
*/

int main(int argc, char *argv[]){

    if(argc == 2){

        int status = 0;

    	for(int i = 0, n = strlen(argv[1]); i < n; i++ ){
            if(!isdigit(argv[1][i])){
                status = 1;
            }
        }

        printf("\n\n%d\n\n", status);

        if(status == 0){
        char text[300] = {'\0'};

        int key = atoi(argv[1]);

        printf("Plaintext: ");
        scanf(" %[^\n]", text);

        for (size_t i = 0, n = strlen(text); i < n; i++){
            if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
                text[i] += key;
            }
        }

        printf("Ciphertext: %s", text);

        return 0;

        }else{
            printf("Usage: .\\caesar key\n");
            return 2;
        }

    }else{
        printf("Usage: .\\caesar key\n");
        return 1;
    }
}
