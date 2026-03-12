#include <iostream>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include "contato.h"
#include <windows.h>
#include <ctype.h>

// Inicialição e acesso ao Menu principal

int main(int argc, char** argv) {
	
	
setlocale(LC_ALL, "portuguese"); //definir linguagem e caracteres do português
int menu;

struct contato amigo[150]; //definir quantidade de estruturas do tipo contato com o nome amigo
int total = 0;

do{

std::cout << "\033[2J\033[H"; //limpar tela
	printf("------------\033[1;5;31mBem-vindo ao menu\033[0m------------\n\n");
	printf("    Qual atividade deseja executar?\n\n");
	printf("\033[34m1)\033[0m Cadastrar\n");
	printf("\033[34m2)\033[0m Listar\n");
	printf("\033[34m3)\033[0m Buscar por nome\n");
	printf("\033[34m4)\033[0m Editar\n");
	printf("\033[34m5)\033[0m Excluir\n");
	printf("\033[34m6)\033[0m Estatísticas (recursivo)\n");
	printf("\033[34m7)\033[0m Sair\n\n");
	
	printf("---------------------------------------\n");
	printf("Contatos Cadastrados: %d\n", total); //apresentar contatos cadastrados
	printf("---------------------------------------\n");
	printf("Opção(escolha o numero referente): ");

	scanf("%d", &menu);
	int c;
	while ((c = getchar()) != '\n' && c != EOF); // procurar entre cada caractere respobndido e limpar o enter
	
	switch(menu){
		case 1: 
		std::cout << "\033[2J\033[H";
			cadastrarcontato(amigo, &total); // chamando determinada tarefa
			break;
			
		case 2: 
		std::cout << "\033[2J\033[H";
			listarcontato(amigo, total);
			break;
		
		case 3:
		std::cout << "\033[2J\033[H";
			buscarcontato(amigo, total);
			break;
			
		case 4: 
		std::cout << "\033[2J\033[H";
			editarcontato(amigo, total);
			break;
		
		case 5: 
		std::cout << "\033[2J\033[H";
			removercontato(amigo, &total);
			break;
		
		case 6: 
		{
		std::cout << "\033[2J\033[H";
		
printf("------------\033[1;31msub-menu recursivo\033[0m------------\n\n"); //menu com tentativa de personalização invalida no dispositivo primário
		printf("    Qual atividade deseja executar?\n\n");
		printf("\033[34m1)\033[0m Contar nomes com mais de N caracteres\n");
		printf("\033[34m2)\033[0m Ver quantidade de e-mails validos\n");
		printf("\033[34m3)\033[0m Ver quantidade de telefones validos\n");		
		printf("---------------------------------------\n");
		scanf("Digite o valor: %d", &menu);
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
			switch(menu)
			{
			
				case 1:
					{
					std::cout << "\033[2J\033[H";
					int N;
					
					printf("Contar nomes com mais de quantos caracteres? ");
					scanf("%d", &N);
					
					int resultado = recursivomaior(amigo, total, 0, N);
					printf("Foram encontradas um total de: %d\n", resultado);
					std::cin.ignore(); //ignorar o enter
					printf("Digite qualquer tecla para continuar.");
					std::cin.ignore();
					std::cin.get();
					break; 
					}
				case 2:
					{
					std::cout << "\033[2J\033[H";
					int resultado = emailvalido(amigo, total, 0);
					printf("Emails validos encontrados: %d\n", resultado);
					printf("Digite qualquer tecla para continuar.");
					std::cin.get();
					break;
				}
				
				case 3:
					int resultado = ttelefonesvalidos(amigo, total, 0);

   					printf("O total de telefones validos são: %d\n", resultado);
					printf("Digite qualquer tecla para continuar.");
					std::cin.ignore();
					std::cin.get();
					break;
			}
		}
		
		default:
			printf("Finalizando sistema...");
		
		
		
		
	}

} while(menu != 7);
	return 0;
}
