#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
INCOMPLETE
*/

int main(int argc, char *argv[]){
    
    if(argc == 2){
        int n = strlen(argv[1]);
        char text[300] = {'\0'}, ciphertext[300] = {'\0'}, abc[26] = {"abcdefghijklmnopqrstuvwxyz"}, key[26];


        for (size_t i = 0; i < n; i++){
            key[i] = argv[1][i];
        }

        //Checking if argv is an alpha and contains 26 characters
        if (n != 26){
            printf("\nThe key must contain 26 characters.\n\n");
            return 2;
        }else{
            for (size_t i = 0; i < n; i++){
                if (isdigit(argv[1][i])){
                    printf("\nUsage: a .\\substitution key(letters)\n\n");
                    return 3;
                }
            }
        }

        printf("\n\n%d\n\n", n);

/*
        int h = 0;
        Checking whether argv contains repeated characters
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (isupper(argv[1][i]) == isupper(argv[1][j])){
                    h++;
                    printf("The key must not contain repeated characters %d", h);
                    return 4;
                }
            }
        }
*/

        printf("Plaintext: ");
        scanf(" %[^\n]", text);

        for (int i = 0; i < n; i++){
                if (isupper(text[i]) != 0){
                    for (int j = 0; j < 26; j++){
                        if(abc[j] == tolower(text[i])){
                            ciphertext[i] = toupper(key[j]);
                            break;
                        }
                    }

                }else if (islower(text[i]) != 0){
                    for (int j = 0; j < 26; j++){
                        if(abc[j] == text[i]){
                            ciphertext[i] = tolower(key[j]);
                            break;
                        }
                    }
                    
                }else{
                    ciphertext[i] = text[i];
                }
            }

        printf("ciphertext: %s\n",ciphertext);

        return 0;

    }else{
        printf("\nUsage: b .\\substitution key\n\n");
        return 1;
    }
    
    return 0;
}