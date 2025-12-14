#include <stdio.h>
#include "agendamento.h"

#define ARQ_AGENDAMENTOS "dados/agendamentos.txt"

void cadastrarAgendamento() {
    Agendamento a;

    FILE *file = fopen(ARQ_AGENDAMENTOS, "a");

    printf("ID: ");
    scanf("%d", &a.id);

    printf("ID do cliente: ");
    scanf("%d", &a.id_cliente);

    printf("ID do servico: ");
    scanf("%d", &a.id_servico);

    printf("Data (DD/MM/AAAA): ");
    scanf("%s", a.data);

    printf("Horario (HH:MM): ");
    scanf("%s", a.horario);

    fprintf(file, "%d;%d;%d;%s;%s\n",
            a.id, a.id_cliente, a.id_servico, a.data, a.horario);

    fclose(file);

    printf("Agendamento realizado!\n");
}

void listarAgendamentos() {
    Agendamento a;
    FILE *file = fopen(ARQ_AGENDAMENTOS, "r");

    printf("\n--- AGENDAMENTOS ---\n");

    while (fscanf(file, "%d;%d;%d;%[^;];%s\n",
                  &a.id, &a.id_cliente, &a.id_servico, a.data, a.horario) != EOF) {
        printf("\nID: %d | Cliente: %d | Servico: %d | Data: %s | Hora: %s",
               a.id, a.id_cliente, a.id_servico, a.data, a.horario);
    }

    fclose(file);
}
