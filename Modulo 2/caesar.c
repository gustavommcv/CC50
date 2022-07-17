#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    if(argc == 2){

        //checking if the user has entered a number
    	for(int i = 0, n = strlen(argv[1]), h = 0; i < n; i++ ){
            if(!isdigit(argv[1][i])){
                printf("\nUsage: .\\caesar key\n\n");
                return 2;
            }
        }

            char text[300] = {'\0'};
            int key = atoi(argv[1]);

            printf("Plaintext: ");
            scanf(" %[^\n]", text);

            //encrypting
            for (size_t i = 0, n = strlen(text); i < n; i++){
                if (isalpha(text[i])){
                    if (isupper(text[i])){
                        text[i] = (text[i] - 'A' + key) % 26 + 'A';
                    }else{
                        text[i] = (text[i] - 'a' + key) % 26 + 'a';
                    }
                }
            }

            printf("Ciphertext: %s", text);

            return 0;

    }else{
        printf("\nUsage: .\\caesar key\n\n");
        return 1;
    }
}
