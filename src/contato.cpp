// pagina destinada a construção das atividades de cada tarefa/função

#include <iostream>
#include <stdio.h>
#include "contato.h"
#include <windows.h>
#include <string.h>
#include <ctype.h>
// codigo para cadastro dos contatos/amigos

void cadastrarcontato(struct contato amigo[], int *total) {


	printf("Cadastrando user\n");
	printf("nome: ");
	fgets(amigo[*total].nome, 50, stdin);
	printf("telefone: ");
	fgets(amigo[*total].telefone, 50, stdin);
	printf("E-mail: ");
	fgets(amigo[*total].email, 50, stdin);
	(*total)++;	


	printf("\n Amigo cadastrado com Sucesso!");
	Sleep(500);
};

// codigo para listar os contatos/amigos existentes
void listarcontato(struct contato amigo[], int total) {

	if (total==0){
	
	printf("Sem cadastros!\n");
	printf("Digite qualquer tecla para continuar.");
	std::cin.get();
	return;
	}
	
	for (int i = 0; i < total; i++)
	{
	printf("----------Amigo %d----------\n", i + 1);
	printf("Nome: %s", amigo[i].nome);
    printf("Telefone: %s", amigo[i].telefone);
    printf("Email: %s", amigo[i].email);
	printf("----------------------------\n");
	}
	printf("Digite qualquer tecla para continuar.");
	std::cin.get();
};

// codigo para converter texto em minusculo
void min(char texto[]){
	int i = 0;
	
	while(texto[i] != '\0'){
		texto[i] = tolower(texto[i]);
		i++;
	}
}

// codigo para buscar os contatos/amigos (letra maiusculas ou minusculas)
void buscarcontato(struct contato amigo[], int total) {

	char busca[50];
	int resultado = 0;
	
	printf("Quem deseja buscar? ");
	fgets(busca, 50, stdin);
	
	for(int i = 0; i < total; i++){ 
		char tnome[50];
		
		strcpy(tnome, amigo[i].nome);//aproveita o loop para pegar o nome buscado e copiar em uma variavel "tnome"
		min(tnome); //converte o nome buscado para minusculo
		min(busca); //converte o nome digitado para minusculo
		
		if (strcmp(busca, tnome) == 0){
			printf("--------Amigo encontrado: %dº contato--------\n", i + 1);
			printf("Nome: %s", amigo[i].nome);
			printf("Telefone: %s", amigo[i].telefone);
			printf("Email: %s", amigo[i].email);
			printf("---------------------------------------------\n");
			
			resultado = 1;
		}
	}
	if(resultado == 0){
		printf("Nenhum contato encontrado.");
		Sleep(500);
	}
	printf("Digite qualquer tecla para continuar.");
	std::cin.get(); 
}

// codigo para editar dados de um contato/amigo cadatrado
void editarcontato(struct contato amigo[], int total) {
	
	char busca[50];
	int resultado = 0;
	
	printf("Qual nome do contato a ser alterado?");
	fgets(busca, 50, stdin);
	
	for(int i=0; i<total; i++){
		if(strcmp(busca, amigo[i].nome) == 0){
			
			printf("------Amigo encontrado!!-----\n");
			printf("-----------------------------\n");
			printf("Nome: %s\n", amigo[i].nome);
			printf("Telefone: %s\n", amigo[i].telefone);
			printf("E-mail: %s\n", amigo[i].email);
			printf("-----------------------------\n\n");
			
			printf("Altando dados...\n");
			printf("Qual será o novo nome? ");
			fgets(amigo[i].nome, 50, stdin);
			printf("Qual será o novo telefone? ");
			fgets(amigo[i].telefone, 50, stdin);
			printf("Qual será o novo E-mail? ");
			fgets(amigo[i].email, 50, stdin);
			printf("\n");	
			
			printf("Dados atualizados com sucesso!");
			
			resultado = 1;
			Sleep(500);
			
		}
	}
	if(resultado==0){
		printf("contato não encontrado.\n");
		Sleep(500);
	}
}

// codigo para remover um dos contatos/amigos cadatrados e atualizar a lista
void removercontato(struct contato amigo[], int *total) {
	
	char busca[50];
	int ramigo = -1; // variavel remover amigo(ramigo)
	
	printf("qual amigo deseja remover?");
	fgets(busca, 50, stdin);
	
	for (int i=0; i<*total; i++){
		if(strcmp(busca, amigo[i].nome) == 0){
			ramigo = i;
			break;
		}
	}
	
	if (ramigo == -1){
		printf("Contato de amigo não cadastrado!");
		printf("Digite qualquer tecla para continuar.");
		std::cin.get(); 
		return;
	}
	
	for (int i = ramigo ; i < *total - 1; i++){
			amigo[i] = amigo[i + 1];
	}
	
	(*total)--;
	
	printf("Amigo removido com suce...sso...\n");
	Sleep(250);
	printf("Quer conversar?...\n");
	printf("Conversa ainda em desenvolvimento!\n");
	printf("Digite qualquer tecla para continuar.");
	std::cin.get(); 
	
}

// codigo para apresentar os contatos/amigos cadastrados mediante validações, usando recursivo/chamado a si mesmo
int recursivomaior(struct contato amigo[], int total, int base, int N) {
	if(base == total){
		return 0;
	}
	
	int contador = 0;
	
	if(strlen(amigo[base].nome) > N){
		contador = 1;
	}
	
	return contador + recursivomaior(amigo, total, base + 1, N);
}

// codigo usado junto ao recursivo no main para validar emails
int emailvalido(struct contato amigo[], int total, int base){
	if (base == total){ //função para para o loop
		return 0;
	}
	int contador = 0;
	
	if (strchr(amigo[base].email, '@') && strchr(amigo[base].email, '.')){ //validar a presença dos caracteres @ e . para verificar se é e-mail
		contador = 1;
	}
	return contador + emailvalido(amigo, total, base + 1);
}

// codigo usado junto ao recursivo no main para validar numeros
int telefonevalido(char telefone[]){
	int i = 0;
	
	while (telefone[i] != '\0'){ //Percorre todo o texto até o fim
		if (!isdigit(telefone[i])){ // verificar se existe letra entre os numeros 
			return 0 ;
		}
		i++;
	}
	if(i == 11){
		return 1;
	}
	return 0;
}

// codigo usado junto ao recursivo no main para validar telefones
int ttelefonesvalidos(struct contato amigo[], int total, int base){
	if (base = total){
		return 0;
	}
	int contador = 0;
	
	if(telefonevalido(amigo[base].telefone)){
		contador = 1;
	}
	
	return contador + ttelefonesvalidos(amigo, total, base + 1);
	
}
