#include <stdio.h>
#include <string.h>
#include "contatos.h"

/* -------- 1° ---------- */
void cadastrar(Contato *lista, int *total) {
	
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
        printf("\nContato cadastrado com sucesso!\n");
    } else {
        printf("Erro: Lista cheia!\n");
    }
    
    printf("\nPressione Enter para continuar...");
    getchar(); getchar();
    system("cls");
}

/* -------- 2° ---------- */
void listar(Contato *lista, int total) {
	system("cls");
    int i;
    
    printf("\n --- Lista de Contatos ---\n");
    
    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    
    for (i = 0; i < total; i++) {
        printf("\n%d. Nome: %s\n", i + 1, lista[i].nome);
    	printf("   Telefone: %s\n", lista[i].telefone);
    	printf("   E-mail: %s\n", lista[i].email);
    }
}

/* -------- 3° ---------- */
int buscar(Contato *lista, int total, char *nomeBusca) {
    int i;
    for (i = 0; i < total; i++) {
        if (strcmp(lista[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1;
}

/* -------- 4° ---------- */
void editar(Contato *lista, int total) {
    char nomeBusca[50];
    printf("Digite o nome exato do contato para editar: ");
    scanf(" %[^\n]", nomeBusca);

    int indice = buscar(lista, total, nomeBusca);

    if (indice != -1) {
        printf("Novo Telefone para %s: ", lista[indice].nome);
        scanf(" %[^\n]", lista[indice].telefone);
        printf("Novo E-mail para %s: ", lista[indice].nome);
        scanf(" %[^\n]", lista[indice].email);
        printf("Contato atualizado!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
    
    printf("\nPressione Enter para continuar...");
    getchar(); getchar();
    system("cls");
    
}

/* -------- 5° ---------- */
void excluir(Contato *lista, int *total) {
    char nomeBusca[50];
    int i;
    printf("Digite o nome do contato para excluir: ");
    scanf(" %[^\n]", nomeBusca);

    int indice = buscar(lista, *total, nomeBusca);

    if (indice != -1) {
        for (i = indice; i < (*total) - 1; i++) {
            lista[i] = lista[i + 1];
        }
        (*total)--;
        printf("Contato removido com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
    
    printf("\nPressione Enter para continuar...");
    getchar(); getchar();
    system("cls");
}

/* -------- 6° ---------- */
int contarNomesLongos(Contato *lista, int total, int indice, int n) {
    if (indice == total) {
        return 0;
    }
    
    int atual;
    
    if (strlen(lista[indice].nome) > n) {
        atual = 1;
    } else {
        atual = 0;  
    }
    
    return atual + contarNomesLongos(lista, total, indice + 1, n);
}
