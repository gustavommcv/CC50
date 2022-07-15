#include <stdio.h>
#include <string.h>
#include <ctype.h>

//=========================================================================

int contletters();
int contwords();
int contsentences();

//=========================================================================

/*
INCOMPLETE
*/

int main(void){
    int letters = 0, words = 0, sentences = 0;
    float index = 0;
    char text[300] = {'\0'};

    printf("Text: ");
    scanf(" %[^\n]", text);

    printf("\n\n%s\n\n", text);

    letters = contletters(text);
    words = contwords(text);
    sentences = contsentences(text);

    index = 0.0588 * ((letters * 100) / words) - 0.296 * ((sentences * 100) / words) - 15.8;

    printf("\n%d\n", letters);
    printf("\n%d\n", words);
    printf("\n%d\n", sentences);
    printf("\n%d\n", lround(index));
    printf("\n%f\n", index);

    if(lround(index) >= 16){
        printf("\nGrade 16+");
    }else if(lround(index) < 1){
        printf("\nBefore Grade 1");
    }else{
        printf("Grade %ld", lround(index));
    }

    return 0;
}

//=========================================================================

int contletters(char TEXT[]){

    int n = strlen(TEXT), l = 0;

    for (size_t i = 0; i < n; i++){
        if (toupper(TEXT[i]) >= 'A' && toupper(TEXT[i]) <= 'Z'){
            l++;
        }
    }

    return l;
}

int contwords(char TEXT[]){

    int n = strlen(TEXT), w = 0;

    for (size_t i = 0; i < n; i++){
        if(TEXT[i] == ' '){
            w++;
        }
    }

    w++;
    return w;
}

int contsentences(char TEXT[]){

    int n = strlen(TEXT), s = 0;

    for (size_t i = 0; i < n; i++){
        if (TEXT[i] == '!' || TEXT[i] == '.' || TEXT[i] == '?'){
            s += 1;
        }
    }

    return s;
}