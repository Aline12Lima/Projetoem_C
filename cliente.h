#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int id;
    char nome[50];
    char telefone[15];
    char email[50];
} Cliente;

// Variáveis globais compartilhadas (extern)
extern Cliente clientes[100];
extern int totalClientes;

void carregarClientes();
void salvarClientes();
void cadastrarCliente();
void listarClientes();
void editarCliente();   
void removerCliente();  
void menuClientes();    

#endif