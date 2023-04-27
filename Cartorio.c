#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função registrar
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: \n"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo (importante)
	
	file = fopen(arquivo, "a"); //"a" = atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Informe o seu cargo: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta() //Função consultar
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n"); //Recebendo qual usuário vai ser consultado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" é ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não encontrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //Função deletar
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado no sistema! \n");
		system("pause");
	}
	
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("Usuário deletado com sucesso.\n");
			system("pause");
		}
	}
	fclose(file);
	
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n"); //Login do admin
	printf("Login de Administrador\n");
	printf("Senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp nesse caso ta comparando se o valor que foi concedido a "senhadigitada" é o mesmo que "admin"
												//se os valores forem iguais, "comparacao" vai receber o valor de 0 ja que não ha diferença
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

			printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //Fim do Menu
	
			scanf("%d", &opcao); //Input do usuário (Armazenando a escolha do usuário) / "%d" é para inteiros
	
			system("cls"); //Limpar a tela depois da escolha do usuário
		
			switch(opcao)
			{
				case 1:
				registro(); //chamada de função
				break;
			
				case 2:
				consulta(); //chamada de função
				break;
			
				case 3:
				deletar(); //chamada de função
				break;
			
				case 4:
				printf("Obrigado por usar nosso sistema!\n");
				return 0; //retorna valor 0 para o laço quebrando o loop
				break;
			
				default:
				printf("### Essa opção não esta disponível! ###\n\n");
				system("pause");
				break;
			}
	
		}
	}
	
	else
		printf("Senha incorreta");
	
}
