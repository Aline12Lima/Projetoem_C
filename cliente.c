#include <stdio.h>
#include <string.h>
#include "cliente.h"

// Definição do caminho do arquivo para manter padrão do projeto
#define ARQ_CLIENTES "dados/clientes.txt"

/* Definição das variáveis globais */
Cliente clientes[100];
int totalClientes = 0;

void carregarClientes() {
    FILE *file = fopen(ARQ_CLIENTES, "r");
    if (!file) return; // Se não existir, apenas retorna

    totalClientes = 0;
    // O fscanf lê até o fim do arquivo
    while (fscanf(file, "%d;%49[^;];%14[^;];%49[^\n]\n",
                  &clientes[totalClientes].id,
                  clientes[totalClientes].nome,
                  clientes[totalClientes].telefone,
                  clientes[totalClientes].email) != EOF) {
        totalClientes++;
    }
    fclose(file);
}

void salvarClientes() {
    FILE *file = fopen(ARQ_CLIENTES, "w");
    if (!file) {
        printf("Erro ao salvar arquivo de clientes!\n");
        return;
    }
    for (int i = 0; i < totalClientes; i++) {
        fprintf(file, "%d;%s;%s;%s\n",
                clientes[i].id,
                clientes[i].nome,
                clientes[i].telefone,
                clientes[i].email);
    }
    fclose(file);
}

void cadastrarCliente() {
    if (totalClientes >= 100) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente novo;

    printf("\n--- Cadastro de Cliente ---\n");
    // O ID agora é automático baseado na posição ou contador
    // Se quiser IDs unicos que não repetem ao apagar, precisaria de logica extra,
    // mas para este exercicio:
    novo.id = (totalClientes == 0) ? 1 : clientes[totalClientes-1].id + 1;

    printf("Nome: ");
    getchar(); // Limpar buffer caso necessário
    scanf("%49[^\n]", novo.nome);

    printf("Telefone: ");
    scanf(" %14[^\n]", novo.telefone);

    printf("Email: ");
    scanf(" %49[^\n]", novo.email);

    clientes[totalClientes] = novo;
    totalClientes++;

    salvarClientes();
    printf("\nCliente cadastrado com sucesso! ID: %d\n", novo.id);
}

void listarClientes() {
    printf("\n--- Lista de Clientes ---\n");

    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        printf("ID: %d | Nome: %s | Telefone: %s | Email: %s\n",
               clientes[i].id,
               clientes[i].nome,
               clientes[i].telefone,
               clientes[i].email);
    }
}

void editarCliente() {
    int id, encontrado = 0;
    listarClientes(); // Mostra a lista antes para ajudar
    printf("\nDigite o ID do cliente que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            printf("Editando Cliente: %s\n", clientes[i].nome);
            
            printf("Novo nome: ");
            scanf(" %49[^\n]", clientes[i].nome);

            printf("Novo telefone: ");
            scanf(" %14[^\n]", clientes[i].telefone);

            printf("Novo email: ");
            scanf(" %49[^\n]", clientes[i].email);
            
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        salvarClientes();
        printf("\nCliente atualizado com sucesso!\n");
    } else {
        printf("\nCliente ID %d nao encontrado.\n", id);
    }
}

void removerCliente() {
    int id, pos = -1;
    listarClientes();
    printf("\nDigite o ID do cliente a remover: ");
    scanf("%d", &id);

    // Procura a posição do cliente no array
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Erro: Cliente nao encontrado.\n");
        return;
    }

    // Move todos os clientes da frente uma casa para trás
    for (int i = pos; i < totalClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    totalClientes--;
    salvarClientes();
    printf("Cliente removido com sucesso!\n");
}

void menuClientes() {
    int opcao;
    do {
        printf("\n--- Menu Clientes ---\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Editar\n");
        printf("4. Remover\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarCliente(); break;
            case 2: listarClientes(); break;
            case 3: editarCliente(); break;
            case 4: removerCliente(); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}