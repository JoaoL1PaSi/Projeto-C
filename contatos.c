#include <stdio.h>
#include <string.h>
#include "contatos.h"

/* -------- 1° ---------- */
void cadastrarContato(Contato *lista, int *total) {
    if (*total < 100) {
    	printf("\n --- Cadastre seu contato ---\n\n");
        printf("Nome: ");
        scanf(" %[^\n]", lista[*total].nome);
        printf("Telefone: ");
        scanf(" %[^\n]", lista[*total].telefone);
        
        do {
            printf("E-mail: ");
            scanf(" %[^\n]", lista[*total].email);
            if (strchr(lista[*total].email, '@') == NULL) {
                printf("E-mail invalido! Deve conter '@'.\n");
            } else {
                break;
            }
        } while(1);

        (*total)++;
        printf("Contato cadastrado com sucesso!\n");
    } else {
        printf("Erro: Lista cheia!\n");
    }
}

/* -------- 2° ---------- */
void listarContatos(Contato *lista, int total) {
    int i;
    
    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;  // Removido o 'return 0' porque a função é void
    }
    for (i = 0; i < total; i++) {
        printf("\nContato %d:\n - Nome: %s\n - Telefone: %s\n - E-mail: %s\n", 
                i + 1, lista[i].nome, lista[i].telefone, lista[i].email);
    }
}

/* -------- 3° ---------- */
int buscarContato(Contato *lista, int total, char *nomeBusca) {
    int i;
    for (i = 0; i < total; i++) {
        if (strcmp(lista[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1;
}

/* -------- 4° ---------- */
void editarContato(Contato *lista, int total) {
    char nomeBusca[50];
    printf("Digite o nome exato do contato para editar: ");
    scanf(" %[^\n]", nomeBusca);

    int indice = buscarContato(lista, total, nomeBusca);

    if (indice != -1) {
        printf("Novo Telefone para %s: ", lista[indice].nome);
        scanf(" %[^\n]", lista[indice].telefone);
        printf("Novo E-mail para %s: ", lista[indice].nome);
        scanf(" %[^\n]", lista[indice].email);
        printf("Contato atualizado!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

/* -------- 5° ---------- */
void excluirContato(Contato *lista, int *total) {
    char nomeBusca[50];
    int i;
    printf("Digite o nome do contato para excluir: ");
    scanf(" %[^\n]", nomeBusca);

    int indice = buscarContato(lista, *total, nomeBusca);

    if (indice != -1) {
        for (i = indice; i < (*total) - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*total)--;
        printf("Contato removido com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

/* -------- 6° ---------- */
int contarNomesLongos(Contato *lista, int total, int indice, int n) {
    if (indice == total){
    	return 0;
	}
    int atual = (strlen(lista[indice].nome) > n) ? 1 : 0;
    return atual + contarNomesLongos(lista, total, indice + 1, n);
}
