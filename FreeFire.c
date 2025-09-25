#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
#define MAX_ITENS 10            // Capacidade máxima da mochila


// Estrut. Item

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;


// Funções

void inserirItem(Item mochila[], int *contador);
void removerItem(Item mochila[], int *contador);
void listarItens(Item mochila[], int contador);
void buscarItem(Item mochila[],  int contador);

int main() {

    Item mochila[MAX_ITENS];
    int contador = 0;                  //contador
    int opcao;

       // Menu principal com opções:
    do {
        printf("\n=== Sistema de Inventário ===\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
    // Adicionar um item
        switch(opcao) {
            case 1:
                inserirItem(mochila, &contador);
                break;
            case 2:
                removerItem(mochila, &contador);
                break;
            case 3:
                listarItens(mochila, contador);
                break;
            case 4:
                buscarItem(mochila, contador);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}


// Inserindo itens

void inserirItem(Item mochila[], int *contador) {
    if (*contador >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novoItem;
    printf("Digite o nome do item: ");
    fgets(novoItem.nome, sizeof(novoItem.nome), stdin);
    novoItem.nome[strcspn(novoItem.nome, "\n")] = '\0';
// Remove o \n do final

    printf("Digite o tipo do item (arma, munição, cura, ferramenta): ");
    fgets(novoItem.tipo, sizeof(novoItem.tipo), stdin);
    novoItem.tipo[strcspn(novoItem.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    getchar();
    

    mochila[*contador] = novoItem;
    (*contador)++;

    printf("Item inserido com sucesso!\n");
    listarItens(mochila, *contador);
}
 

// Remover um item

void removerItem(Item mochila[], int *contador) {
    if (*contador == 0) {
        printf("Mochila vazia! Nada para remover.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a remover: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < *contador; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = 1;
// Move os itens da frente um p tras
            for (int j = i; j < *contador - 1; j++) {
                mochila[j] = mochila[j+1];
            }
            (*contador)--;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }

    listarItens(mochila, *contador);
}

// Listar itens

void listarItens(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Mochila vazia.\n");
        return;
    }
    // Listar todos os itens
    printf("\nItens na mochila:\n");
    for (int i = 0; i < contador; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Busca de item (busca sequencial)
// Realizar busca binária por nome
void buscarItem(Item mochila[], int contador) {
    if (contador == 0) {
        printf("Mochila vazia.\n");
    return 0;
    }
}
