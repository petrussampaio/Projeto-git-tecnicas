#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Git.h"

int main(){
    char *quit = "quit";
    int cond = 1;
    header *branch = cria_header();
    guarda_info(branch, "main");

    while(cond == 1){
        char *comando = (char*) malloc(50 * sizeof(char));
        printf("User@PC:$ ");
        gets(comando);
        if(strcmp(comando, quit) == 0){
            break;
        }

        header *main = separa_string(comando);

        verifica_comando(main, branch);

        limpa(main);
    }

    printf("Finalizando programa...\n");
    return 0;
}