#ifndef CONTATOS_H 
#define CONTATOS_H

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void cadastrarContato(Contato *listaContato, int *total);
void listarContatos(Contato *lista, int total);
int buscarContato(Contato *lista, int total, char *nomeBusca);
void editarContato(Contato *lista, int total);
void excluirContato(Contato *lista, int *total);
int contarNomesLongos(Contato *lista, int total, int indice, int n);

#endif
