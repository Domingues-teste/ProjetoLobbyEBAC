#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{	
	//Criação de varáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis

	printf("Você escolheu o registro de nomes!\n");
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); // "%s" refere-se a string

	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo,"w"); //Abre o arquivo
	fprintf(file, cpf); //Salva o arquivo e valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file= fopen(arquivo, "a");
	fprintf(file, nome);
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
	
	printf("Digite o cargo a ser registrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	printf("Você escolheu consultar os nomes!\n");
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf(":Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

	char cpf[40];

	printf("Digite o CPF do usúario a ser deletado: ");
	scanf("%s", cpf);

	remove(cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
	{
	printf("O usuário foi deletado do sistema com sucesso!. \n");
	system("pause");
	}

}

int sair()
{
	printf("Obrigado por utilizar nosso sistema!\n");
}
	
int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("* Lobby EBAC *\n\n"); //Inicio do menu
		printf("\tEscolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nome\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d" , &opcao); //Armazenamento a escolha do usuário
		system("cls"); //Responsável por limpar a tela
		
		switch(opcao) //Inicio de seleção do menu
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			sair();
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			break;
			
			
		}//Fim da seleção
	}
}

