#include <stdio.h>
#include <string.h>
#include "contatos.h"

int main() {
    Contato agenda[100];
    int totalContatos = 0, opcao, verifi;
    
    do {
        printf("\n --- GERENCIADOR DE CONTATOS --- \n\n");
        printf("1. Cadastrar\n2. Listar\n3. Buscar\n4. Editar\n5. Excluir\n6. Estatisticas (Recursivo)\n7. Sair\n\n");
        printf("Escolha: ");
        
        verifi = scanf("%d", &opcao);
        
		if (verifi != 1) {
		    printf("\nERRO: Digite apenas NUMEROS!\n");
		    while (getchar() != '\n');
		    continue;
		}
		
        switch(opcao) {
            case 1:
                cadastrar(agenda, &totalContatos);
                printf("\n\n");
                break;

            case 2:
                listar(agenda, totalContatos);
                printf("\n\n");
                break;

            case 3:
                {
                    char busca[50];
                    printf("Nome para busca: ");
                    scanf(" %[^\n]", busca);
                    int i = buscar(agenda, totalContatos, busca);
                    if(i != -1) {
					    printf("\n--- Busca de Contato ---\n\n");
					    printf("Nome: %s\n", agenda[i].nome);
					    printf("Telefone: %s\n", agenda[i].telefone);
					    printf("E-mail: %s\n", agenda[i].email);
					} else {
					    printf("Contato '%s' nao encontrado.\n", busca);
					}
                }
                printf("\n\n");
                break;

            case 4:
                editar(agenda, totalContatos);
                printf("\n\n");
                break;

            case 5:
                excluir(agenda, &totalContatos);
                printf("\n\n");
                break;

            case 6:
                printf("Contatos com nomes longos (> 5 letras): %d\n", contarNomesLongos(agenda, totalContatos, 0, 5));
                printf("\n\n");
                break;

            case 7:
            	system("cls");
                printf("Saindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                printf("\n______________________________________\n\n\n\n");
        }
    } while (opcao != 7);

    return 0;
}
