#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"

#define ARQ_AGENDAMENTOS "dados/agendamentos.txt"
#define ARQ_CLIENTES "dados/clientes.txt"
#define ARQ_SERVICOS "dados/servicos.txt"

// Função auxiliar para contar linhas de um arquivo
int contarRegistros(char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) return 0;

    int total = 0;
    char linha[200]; // Buffer temporario para ler a linha

    // Enquanto conseguir ler uma linha, aumenta o contador
    while (fgets(linha, sizeof(linha), file)) {
        total++;
    }

    fclose(file);
    return total;
}

void gerarRelatorioMensal() {
    printf("\n--- RELATORIO GERAL ---\n");

    int qtdClientes = contarRegistros(ARQ_CLIENTES);
    int qtdServicos = contarRegistros(ARQ_SERVICOS);
    int qtdAgendamentos = contarRegistros(ARQ_AGENDAMENTOS);

    printf("Total de Clientes cadastrados: %d\n", qtdClientes);
    printf("Total de Servicos disponiveis: %d\n", qtdServicos);
    printf("Total de Agendamentos realizados: %d\n", qtdAgendamentos);
    
    printf("-----------------------\n");
}