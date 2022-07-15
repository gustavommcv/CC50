#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

    if(argc > 2 || argc < 2){
        printf("Usage: .\\caesar key");
    }else{
        char text[300] = {'\0'};
        int key = 0;

        key = atoi(argv[1]);
    
        printf("\n\n%d\n\n", argc);

        printf("Text: ");
        scanf(" %[^\n]", text);

        for (size_t i = 0, n = strlen(text); i < n; i++){
            if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')){
                text[i] += key;
            }
        }

        printf("%s", text);

        }
    return 0;
}
