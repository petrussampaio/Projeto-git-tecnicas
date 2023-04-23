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

void verifica_comando(header *h, header *branch, header *commits){
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
            f_commit(h, commits);
        }else if(strcmp(h -> primeiro -> proximo -> info, checkout) == 0){
            f_checkout(h, branch);
        }else if(strcmp(h -> primeiro -> proximo -> info, merge) == 0){
            f_merge(h);
        }else if(strcmp(h -> primeiro -> proximo -> info, log) == 0){
            f_log(h, commits, branch);
        }else{
            printf("Comando nao reconhecido!\n");
            return;
        }
    }
}

void f_commit(header *h, header *commits){
    char *err = "-m";

    if(strcmp(h -> ultimo -> info, err) == 0){
        printf("Comando invalido!\n");
    }else{
        guarda_info(commits, h -> ultimo -> info);
        printf("Commit '%s' criado com sucesso!\n", commits -> ultimo -> info);
    }

}

void f_log(header *h, header *commits, header *branch){
    char *log = "log";

    if(strcmp(h -> ultimo -> info, log) == 0){
        printf("Branch: %s\n", branch -> primeiro -> info);
        imprime(commits);
    }else{
        printf("Comando invalido!\n");
    }
}

void f_branch(header *h, header *branch){
    char *branch_cod = "branch";

    if(strcmp(h -> ultimo -> info, branch_cod) == 0){
        printf("Comando invalido!\n");
    }else{
        guarda_info(branch, h -> ultimo -> info);
        printf("Branch '%s' criada com sucesso!\n", branch -> ultimo -> info);
    }
}

void f_checkout(header *h, header *branch){
    char *checkout = "checkout";

    if(strcmp(h -> ultimo -> info, checkout) == 0){
        printf("Comando invalido!\n");
    }else{
        for(encad *p = branch -> primeiro; p != NULL; p = p -> proximo){
            if(strcmp(h -> ultimo -> info, p -> info) == 0){
                char *aux = branch -> primeiro -> info;
                branch -> primeiro -> info = h -> ultimo -> info;
                p -> info = aux;
                return;
            }
        }
        printf("Branch nao existe!\n");
        return;
    }
}

void f_merge(header *h){
    printf("Comando merge!\n");
}

void limpa(header *h){
    encad *p = h -> primeiro;
    encad *aux;

    if(p == NULL){
        printf("\nLista vazia!\n\n");
        return;
    }

    while(p != NULL){
        aux = p -> proximo;
        free(p);
        p = aux;
    }

    free(h);
}

void imprime(header *h){
    for(encad *p = h -> primeiro; p != NULL; p = p -> proximo){
        printf("%p %s\n", p, p -> info);
    }

}



