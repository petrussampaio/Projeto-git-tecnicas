#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Git.h"

int main(){
    char *quit = "quit";
    int cond = 1;
    
    while(cond == 1){
        char *comando = (char*) malloc(50 * sizeof(char));
        printf("User@PC:$ ");
        gets(comando);
        if(strcmp(comando, quit) == 0){
            break;
        }
        separa_string(comando);
    }

    printf("Finalizando programa...\n");
    return 0;
}