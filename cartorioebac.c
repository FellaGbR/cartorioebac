#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respns�vel por cuidar das strings

int registro () // Fun��o para cadastrar usu�rios
{ 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// In�cio da cria��o das variav�is / strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o das variav�is / strings
	 
	printf("Digite o CPF a ser cadastrado: "); // Perguntando ao usu�rio
	scanf("%s", cpf); // Captando a resposta do usu�rio. Nesse caso o %s � referente a strings.
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings. Essa fun��o copia o CPF para o arquivo (direita para a esquerda)
	
	FILE *file; // Cria o arquivo no banco de dados (PC)
	file = fopen(arquivo, "w"); // Cria o arquivo e escreve (w)
	fprintf(file,cpf); // Salvo o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
		file = fopen(arquivo, "a"); // Atualiza o arquivo (a)
		fprintf(file,", "); // Adicionando a v�rgula para separar um dado do outro
		fclose(file); // Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Perguntando ao usu�rio
	scanf("%s", nome); // Captando o valor que o usu�rio colocou
	
	file = fopen(arquivo, "a"); // Fun��o que abre o file e atualiza com os dados passados abaixo (a)
	fprintf(file,nome); // Adicionando uma nova vari�vel ao file para guardar as informa��es coletadas
	fclose(file); // Fechando o arquivo
	
		file = fopen(arquivo, "a");
		fprintf(file,", "); // Criando uma v�rgula para poder separar uma info da outra
		fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // Captando o valor que o usu�rio colocou
	
	file = fopen(arquivo, "a"); // Fun��o que abre o file e atualiza com os dados passados abaixo (a)
	fprintf(file, sobrenome); // Adicionando uma nova vari�vel ao file para guardar as informa��es coletadas
	fclose(file);
	
		file = fopen(arquivo, "a"); // Fun��o que abre o file e atualiza com os dados passados abaixo (a)
		fprintf(file,", "); // Criando uma v�rgula para poder separar uma info da outra
		fclose(file); // Fechando o arquivo
	
	printf("Digite o seu cargo: ");
	scanf("%s", cargo); // Captando o valor que o usu�rio colocou
	
	file = fopen(arquivo, "a"); // Fun��o que abre o file e atualiza com os dados passados abaixo (a)
	fprintf(file, cargo); // Adicionando uma nova vari�vel ao file para guardar as informa��es coletadas
	fclose(file); // Fechando o arquivo
   
	system("pause"); // Pausando os c�digos para poder aparecer na tela
	
}

int consultar () // Fun��o para consultar os dados coletados
{ 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// Definindo as variav�is
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Pergunta ao usu�rio
	scanf("%s", cpf); // Captando a resposta do usu�rio
	
	FILE *file; // Cria o arquivo no banco de dados (PC)
	file = fopen(cpf, "r"); // Abrindo e lendo o que est� no file (r)
	
	if(file == NULL) // Se o aqruivo de dentro do file n�o existir.
	{
		printf("\nUsu�rio n�o localizado!\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) // No while � feito um looping com as informa��es do arquivo e elas ser�o guardadas na vari�vel conte�do para ser exibida na tela.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); // Comando que aparece a informa��o que o usu�rio colocou na tela.
		printf("\n\n");
	}
	
	fclose(file);
	system("pause"); // Pausa a tela
	
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file; // Criando um arquivo para armazenar a resposta do usu�rio, no caso, o CPF
	file = fopen(cpf,"r"); // Abrindo o file referente ao cpf (%s) e lendo o qu est� l� (r)
	
	if(file == NULL) // Em caso o n�mero digitado n�o esteja no arquivo.
	{
		fclose(file);
		printf("\nO usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	else if(file != NULL) // Condi��o caso o n�mero inserido estava no sistema e foi deletado com sucesso.
	{
		fclose(file);
		printf("\nUsu�rio deletado com sucesso!.\n"); 
		system("pause");
		remove(cpf); // Fun��o que acessa a pasta e deleta o arquivo CPF e confere se deu certo (remove)
	}
	
	fclose(file);
}

int main ()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; // Definindo as variav�is
	int repeticao=1; // Definindo uma vari�vel para o operador de repeti��o
	char senhadigitada[]="a"; // Vari�vel para a senha. O "a" � que estamos atribuindo umv valor a ela.
	int comparacao; // Vari�vel para comparar se a senha que o usu�rio coloca � a correta (admin). 
	
	printf("	Cart�rio da EBAC   \n\n"); // T�tulo
	printf("Login de administrador.\n\nDigite a sua senha: "); // Perguntando a senha
	scanf("%s", senhadigitada); // Resposta do user
	
	comparacao = strcmp(senhadigitada, "admin"); // Compara��o entre as strings. Os valores colocados pelo user, ficam alocados na mem�ria. A "senhadigitada" fica com o mesmo valor de "admin".
	
	if(comparacao == 0) // Esse 0 � caso a compara��o seja igual ao valor da senhadigitada (admin). Se fosse um valor diferente, daria erro, ele salvaria um valor diferente na mem�ria.
	{
	
		for(repeticao=1;repeticao=1;) // Operador de repeti��o. As inform��o dentro do {} v�o se repetir.
		{ 
	
			system("cls"); // Limpa a tela
		    setlocale(LC_ALL, "Portuguese"); // Definido a linguagem
		
	        printf("   Cart�rio da EBAC   \n\n"); // In�cio do menu
		    printf("Escolha a Op��o Desejada do Menu:\n\n");
		    printf("\t1 - Registrar Nomes\n");
		    printf("\t2 - Consultar Nomes\n");
		    printf("\t3 - Deletar Nomes\n"); 
		    printf("\t4 - Sair do sistema\n\n");
		    printf("Op��o: "); // Fim do menu
	
	        scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	    
	        system("cls"); // Limpa a tela
        
	        switch(opcao) // In�cio da sele��o no menu
			{ 
	           	case 1:	
	            registro(); // Chamando a fun��o
	            break;
	            
	            case 2:
	            consultar(); // Chamando a fun��o
		        break;
		            
		        case 3:
		        deletar(); // Chamando a fun��o
	            break;
	            
	            case 4:
	            printf("Obrigado por utilizar o sistema!\n"); 
	            return 0; // Retorna o valor 0, quebra todas as fun��es e sai do sistema.
	            break;
	        
	            default: // Caso n�o seja colocado nenhuma das fun��es acima, as intru��es abaixo aparecem.
	            printf("Essa op��o n�o est� dispon�vel!\n");
	    	    system("pause");
	    	    break; // Fim da sele��o
			}
		
		}	
	}	
	else // Caso o valor seja colocado errado (!= admin), dar� erro.
		printf("\nSenha incorreta.");
	
}
