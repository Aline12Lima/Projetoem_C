#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARQ_SERVICOS "servicos.txt"


typedef struct {
    int id;
    char descricao[50];
    float preco;
} Servico;


int servicoIdExiste(int id) {
    FILE *f = fopen(ARQ_SERVICOS, "r");
    if (!f) return 0;


    Servico s;
    while (fscanf(f, "%d;%49[^;];%f\n",
                  &s.id, s.descricao, &s.preco) == 3)
    {
        if (s.id == id) {
            fclose(f);
            return 1;
        }
    }


    fclose(f);
    return 0;
}


int servicoDescricaoExiste(char desc[]) {
    FILE *f = fopen(ARQ_SERVICOS, "r");
    if (!f) return 0;


    Servico s;
    while (fscanf(f, "%d;%49[^;];%f\n",
                  &s.id, s.descricao, &s.preco) == 3)
    {
        if (strcmp(s.descricao, desc) == 0) {
            fclose(f);
            return 1;
        }
    }


    fclose(f);
    return 0;
}
void cadastrarServico() {
    Servico s;


    printf("\n--- CADASTRAR SERVIÇO ---\n");


    printf("ID do serviço: ");
    scanf("%d", &s.id);


    if (servicoIdExiste(s.id)) {
        printf("Erro: ID já cadastrado.\n");
        return;
    }
    getchar();
    printf("Descrição: ");
    fgets(s.descricao, 50, stdin);
    s.descricao[strcspn(s.descricao, "\n")] = '\0';
    if (servicoDescricaoExiste(s.descricao)) {
        printf("Erro: já existe um serviço com essa descrição.\n");
        return;
    }
    printf("Preço: R$ ");
    scanf("%f", &s.preco);


    if (s.preco <= 0) {
        printf("Erro: preço deve ser positivo.\n");
        return;
    }


    FILE *f = fopen(ARQ_SERVICOS, "a");
    if (!f) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }


    fprintf(f, "%d;%s;%.2f\n", s.id, s.descricao, s.preco);
    fclose(f);


    printf("Serviço cadastrado com sucesso!\n");
}
void listarServicos() {
    printf("\n--- LISTA DE SERVIÇOS ---\n");


    FILE *f = fopen(ARQ_SERVICOS, "r");
    if (!f) {
        printf("Nenhum serviço cadastrado.\n");
        return;
    }
    Servico s;
    int encontrou = 0;


    while (fscanf(f, "%d;%49[^;];%f\n",
                  &s.id, s.descricao, &s.preco) == 3)
    {
        printf("ID: %d | %s | R$ %.2f\n",
               s.id, s.descricao, s.preco);
        encontrou = 1;
    }
    if (!encontrou)
        printf("Nenhum serviço encontrado.\n");


    fclose(f);
}
void editarServico(int id) {


    if (!servicoIdExiste(id)) {
        printf("Erro: serviço não encontrado.\n");
        return;
    }
    FILE *f = fopen(ARQ_SERVICOS, "r");
    FILE *temp = fopen("temp_servicos.txt", "w");
    if (!f || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }


    Servico s;
    char novaDesc[50];
    float novoPreco;
    getchar();
    printf("Nova descrição: ");
    fgets(novaDesc, 50, stdin);
    novaDesc[strcspn(novaDesc, "\n")] = '\0';
    printf("Novo preço: R$ ");
    scanf("%f", &novoPreco);
    if (novoPreco <= 0) {
        printf("Erro: preço deve ser positivo.\n");
        fclose(f);
        fclose(temp);
        return;
    }
    while (fscanf(f, "%d;%49[^;];%f\n",
                  &s.id, s.descricao, &s.preco) == 3)
    {
        if (s.id == id)
            fprintf(temp, "%d;%s;%.2f\n", id, novaDesc, novoPreco);
        else
            fprintf(temp, "%d;%s;%.2f\n", s.id, s.descricao, s.preco);
    }
    fclose(f);
    fclose(temp);
    remove(ARQ_SERVICOS);
    rename("temp_servicos.txt", ARQ_SERVICOS);
    printf("Serviço editado com sucesso!\n");
}
void removerServico(int id) {
    if (!servicoIdExiste(id)) {
        printf("Erro: serviço não encontrado.\n");
        return;
    }
    FILE *f = fopen(ARQ_SERVICOS, "r");
    FILE *temp = fopen("temp_servicos.txt", "w");


    if (!f || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }
    Servico s;


    while (fscanf(f, "%d;%49[^;];%f\n",
                  &s.id, s.descricao, &s.preco) == 3)
    {
        if (s.id != id)
            fprintf(temp, "%d;%s;%.2f\n",
                    s.id, s.descricao, s.preco);
    }
    fclose(f);
    fclose(temp);
    remove(ARQ_SERVICOS);
    rename("temp_servicos.txt", ARQ_SERVICOS);
    printf("Serviço removido com sucesso!\n");
}