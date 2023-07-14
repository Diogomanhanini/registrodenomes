#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca para alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/ strings
	char arquivo[100];
	char cpf[100];
	char nome[100];
	char sobrenome[100];
	char cargo[100];
	//final da criação de variáveis/ strings	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a salvamento de strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o programa
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" é escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //w seria para criar, a é para atualizar o arquivo
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" , nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	printf("\n\nO usuário foi adicionado com sucesso!\n\n\n\n");
	
	system("pause");
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[100];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" indica leitura do arquivo, de read
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[100];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n\nO usuário não se encontra no sistem. \n\n\n\n");
		system("pause");
	}
		
}

int main()
	{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("##### - Registro de Pessoas - #####\n\n\n"); //início do menu
		printf("Escolha a opção desejada no menu a seguir: \n\n");
		printf("\t1 - Registro de nome\n");
		printf("\t2 - Cunsultar nome\n");
		printf("\t3 - Deletar nome\n"); 
		printf("\t4 - Sair do sistema\n\n\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //deleta as mensagens anteriores, limpar a tela
		
		switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada de função
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
			
			default:
			printf("Atenção, esta opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
