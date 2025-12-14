#ifndef SERVICO_H
#define SERVICO_H

typedef struct {
    int id;
    char descricao[100];
    float preco;
} Servico;

void cadastrarServico();
void listarServicos();
void editarServico(int id);
void removerServico(int id);

#endif
