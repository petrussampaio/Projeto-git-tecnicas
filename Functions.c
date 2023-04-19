#include "Git.h"

header *cria_header(void){
    header *x = (header*) malloc(sizeof(header));

    x -> primeiro = NULL;
    x -> ultimo = NULL;

    return x;
}

header *separa_string(char *comando){
    int inicio = 0, fim = 0;
    int elementos = 0;
    header *h = cria_header();

    for(int i = 0; strlen(comando) > i; i++){
        if(comando == NULL){
            continue;
        }
        while(comando[i] == ' ')
            i++;  
        
        if(comando[i] == '\0'){
            break;
        } 
        inicio = i;

        while(comando[i] != ' ' && i < comando[i] != '\0')
            i++;
        fim = i;

        char *buffer = (char*) malloc(30 * sizeof(char));
        strncpy(buffer, comando + inicio, fim - inicio);
        buffer[fim - inicio] = '\0';
        guarda_info(h, buffer);
    }
    
    return h;

}

void guarda_info(header *h, char *info){
    encad *x = (encad*) malloc(sizeof(encad));
    
    if(h -> primeiro == NULL){
        h -> primeiro = x;
        h -> ultimo = x;
        x -> proximo = NULL;
        x -> anterior = NULL;
        x -> info = info;
    }else{
        h -> ultimo -> proximo = x;
        x -> anterior = h -> ultimo;
        x -> proximo = NULL;
        h -> ultimo = x;
        x -> info = info;
    }
}

void verifica_comando(header *h, header *branch){
    char *git = "git";
    char *branch_cod = "branch";
    char *commit = "commit";
    char *checkout = "checkout";
    char *merge = "merge";
    char *log = "log";


    if(strcmp(h -> primeiro -> info, git) != 0 || h -> ultimo == h -> primeiro){
        printf("Comando nao reconhecido!\n");
        return;
    }else{
        if(strcmp(h -> primeiro -> proximo -> info, branch_cod) == 0){
            f_branch(h, branch);
        }else if(strcmp(h -> primeiro -> proximo -> info, commit) == 0){
            f_commit(h);
        }else if(strcmp(h -> primeiro -> proximo -> info, checkout) == 0){
            f_checkout(h);
        }else if(strcmp(h -> primeiro -> proximo -> info, merge) == 0){
            f_merge(h);
        }else if(strcmp(h -> primeiro -> proximo -> info, log) == 0){
            f_log(h);
        }else{
            printf("Comando nao reconhecido!\n");
            return;
        }
    }
}

void f_commit(header *h){
    printf("Comando commit!\n");
}

void f_log(header *h){
    printf("Comando log!\n");
}

void f_branch(header *h, header *branch){
    char *branch_cod = "branch";

    if(strcmp(h -> ultimo -> info, branch_cod) == 0){
        printf("Atualmente na branch %s\n", branch -> primeiro -> info);
    }else{
        guarda_info(branch, h -> ultimo -> info);
        printf("Branch '%s' criada com sucesso!\n", branch -> ultimo -> info);
    }
}

void f_checkout(header *h){
    printf("Comando checkout!\n");
}

void f_merge(header *h){
    printf("Comando merge!\n");
}

void limpa(header *h){
    encad *p = h -> primeiro;
    encad *aux;

    if(p == NULL){
        printf("\nLista vazia!\n\n");
        return 0;
    }

    while(p != NULL){
        aux = p -> proximo;
        free(p);
        p = aux;
    }

    free(h);
}



