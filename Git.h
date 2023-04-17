#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct header{
    struct Encad *primeiro;
    struct Encad *ultimo;
}header;

typedef struct Encad{
    struct Encad *proximo;
    struct Encad *anterior;
    char *info;
    
}encad;

header *cria_header(void);
void limpa(header *h);
void separa_string(char *c);
void guarda_info(header *h, char *info);
void verifica_comando(header *h);
void f_commit(header *h);
void f_branch(header *h);
void f_checkout(header *h);
void f_merge(header *h);


