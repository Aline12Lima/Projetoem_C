#include <stdio.h>
#include "cliente.h"
#include "servico.h"
#include "agendamento.h"
#include "relatorio.h"

void menu() {
    int op;

    do {
        printf("\n--- SALON SYSTEM ---\n");
        printf("1 - Gestao de Clientes\n"); // Alterado aqui
        printf("3 - Cadastrar Servico\n");
        printf("4 - Listar Servicos\n");
        printf("5 - Realizar Agendamento\n");
        printf("6 - Listar Agendamentos\n");
        printf("7 - Relatorio Mensal\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1: menuClientes(); break; // Chama o menu completo do seu novo codigo
            case 2: menuClientes(); break; // Mantive caso voce digite 2 por habito
            case 3: cadastrarServico(); break;
            case 4: listarServicos(); break;
            case 5: cadastrarAgendamento(); break;
            case 6: listarAgendamentos(); break;
            case 7: gerarRelatorioMensal(); break;
        }

    } while (op != 0);
}

int main() {
    // IMPORTANTE: Carrega os dados do arquivo para a memoria RAM ao iniciar
    carregarClientes(); 
    
    menu();
    return 0;
}