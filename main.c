#include <stdio.h>
#include <string.h>
#include "contatos.h"

int main() {
    Contato agenda[100];
    int totalContatos = 0; 
    int opcao;

    do {
        printf("\n --- GERENCIADOR DE CONTATOS --- \n\n");
        printf("1. Cadastrar\n2. Listar\n3. Buscar\n4. Editar\n5. Excluir\n6. Estatisticas (Recursivo)\n7. Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarContato(agenda, &totalContatos);
                break;

            case 2:
                listarContatos(agenda, totalContatos);
                break;

            case 3:
                {
                    char busca[50];
                    printf("Nome para busca: ");
                    scanf(" %[^\n]", busca);
                    int i = buscarContato(agenda, totalContatos, busca);
                    if(i != -1) 
                        printf("Encontrado: %s | %s\n", agenda[i].nome, agenda[i].telefone);
                    else 
                        printf("Nao encontrado.\n");
                }
                break;

            case 4:
                editarContato(agenda, totalContatos);
                break;

            case 5:
                excluirContato(agenda, &totalContatos);
                break;

            case 6:
                printf("Contatos com nomes longos (> 5 letras): %d\n", 
                        contarNomesLongos(agenda, totalContatos, 0, 5));
                break;

            case 7:
                printf("Saindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                printf("______________________________________\n\n\n\n");
        }
    } while (opcao != 7);

    return 0;
}
