#include <stdio.h>
#include <stdlib.h>

/* ============================================================
   DECLARAÇÃO DOS SUB-MENUS
   ============================================================ */

void menuClientes();       // Clientes
void menuServicos();       // Serviços
void menuAgendamentos();   // Agendamentos
void menuFinanceiro();     // Financeiro

/* ============================================================
   DEFINIÇÕES TEMPORÁRIAS
   ============================================================ */

void menuClientes() {
    printf("\n[SUBMENU CLIENTES AQUI]\n");
    printf("[SUBMENU CLIENTES AQUI]\n\n");
    system("pause");
}

void menuServicos() {
    printf("\n[SUBMENU SERVIÇOS AQUI]\n");
    printf("[SUBMENU SERVIÇOS AQUI]\n\n");
    system("pause");
}

void menuAgendamentos() {
    printf("\n[SUBMENU AGENDAMENTOS AQUI]\n");
    printf("[SUBMENU AGENDAMENTOS AQUI]\n\n");
    system("pause");
}

void menuFinanceiro() {
    printf("\n[SUBMENU FINANCEIRO AQUI]\n");
    printf("[SUBMENU FINANCEIRO AQUI]\n\n");
    system("pause");
}

/* ============================================================
   MENU PRINCIPAL
   ============================================================ */

void menuPrincipal() {
    int opcao;

    do {
        system("cls || clear");
        printf("========== SISTEMA DE GESTÃO ==========\n");
        printf("1 - Clientes\n");
        printf("2 - Serviços\n");
        printf("3 - Agendamentos\n");
        printf("4 - Financeiro\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuServicos();
                break;
            case 3:
                menuAgendamentos();
                break;
            case 4:
                menuFinanceiro();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                system("pause");
        }

    } while(opcao != 5);
}

/* ============================================================
   FUNÇÃO PRINCIPAL
   ============================================================ */

int main() {
    menuPrincipal();
    return 0;
}