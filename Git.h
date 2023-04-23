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
void imprime(header *h);
header *separa_string(char *c);
void guarda_info(header *h, char *info);
void verifica_comando(header *h, header *branch, header *commits);
void f_commit(header *h, header *commits);
void f_branch(header *h, header *branch);
void f_checkout(header *h, header *branch);
void f_merge(header *h);
void f_log(header *h, header *commits, header *branch);


