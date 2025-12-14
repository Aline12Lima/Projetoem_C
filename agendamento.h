#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

typedef struct {
    int id;
    int id_cliente;
    int id_servico;
    char data[11];
    char horario[6];
} Agendamento;

void cadastrarAgendamento();
void listarAgendamentos();
void editarAgendamento(int id);
void removerAgendamento(int id);

#endif
