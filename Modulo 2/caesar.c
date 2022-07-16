#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
INCOMPLETE
*/

int main(int argc, char *argv[]){

	int status = 0;

	for(int i = 0; argv[i] != '\0'; i++)
	{
		if (status==1){
            break;
        }
		while(isdigit(argv[i])){
			printf("%c", argv[i]);
			
			if(isdigit(argv[i + 1])){
				status = 1;
			}
			i++;
		}
	}

    printf("%d", status);

    if(argc > 2 || argc < 2){
        printf("Usage: .\\caesar key");

    }else if(status == 1){
        printf("Usage: .\\caesar key");

    }else{
        char text[300] = {'\0'};
        int key = 0;

        key = atoi(argv[1]);

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
