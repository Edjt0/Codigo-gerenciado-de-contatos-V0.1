// pagina destinada a criação de uma "biblioteca" com uma estrutura de contatos e o esquema das tarefas.

#ifndef CONTATO_H
#define CONTATO_H

struct contato{
	char nome[50];
	char telefone[50];
	char email[50];
};

void listarcontato(struct contato amigo[], int total); // tarefa/função que não retorna valores denominada "listar contato" que possui alguns parâmetros/recursos essesciais dentro do ()

void cadastrarcontato(struct contato amigo[], int *total);

void buscarcontato(struct contato amigo[], int total);

void editarcontato(struct contato amigo[], int total);

void removercontato(struct contato amigo[], int *total);

int recursivomaior(struct contato amigo[], int total, int base, int N); // tarefa/função que retorna valor inteiro valores denominada "recursivo maior" que possui alguns parâmetros/recursos essesciais dentro do ()

int emailvalido(struct contato amigo[], int total, int indice);

int telefoneValido(char telefone[]);

int ttelefonesvalidos(struct contato amigo[], int total, int indice);

void paraMinusculo(char texto[]);

#endif
