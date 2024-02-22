#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // Biblioteca respnsável por cuidar das strings

int registro () // Função para cadastrar usuários
{ 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// Início da criação das variavéis / strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das variavéis / strings
	 
	printf("Digite o CPF a ser cadastrado: "); // Perguntando ao usuário
	scanf("%s", cpf); // Captando a resposta do usuário. Nesse caso o %s é referente a strings.
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings. Essa função copia o CPF para o arquivo (direita para a esquerda)
	
	FILE *file; // Cria o arquivo no banco de dados (PC)
	file = fopen(arquivo, "w"); // Cria o arquivo e escreve (w)
	fprintf(file,cpf); // Salvo o valor da variável
	fclose(file); // Fecha o arquivo
	
		file = fopen(arquivo, "a"); // Atualiza o arquivo (a)
		fprintf(file,", "); // Adicionando a vírgula para separar um dado do outro
		fclose(file); // Fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Perguntando ao usuário
	scanf("%s", nome); // Captando o valor que o usuário colocou
	
	file = fopen(arquivo, "a"); // Função que abre o file e atualiza com os dados passados abaixo (a)
	fprintf(file,nome); // Adicionando uma nova variável ao file para guardar as informações coletadas
	fclose(file); // Fechando o arquivo
	
		file = fopen(arquivo, "a");
		fprintf(file,", "); // Criando uma vírgula para poder separar uma info da outra
		fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); // Captando o valor que o usuário colocou
	
	file = fopen(arquivo, "a"); // Função que abre o file e atualiza com os dados passados abaixo (a)
	fprintf(file, sobrenome); // Adicionando uma nova variável ao file para guardar as informações coletadas
	fclose(file);
	
		file = fopen(arquivo, "a"); // Função que abre o file e atualiza com os dados passados abaixo (a)
		fprintf(file,", "); // Criando uma vírgula para poder separar uma info da outra
		fclose(file); // Fechando o arquivo
	
	printf("Digite o seu cargo: ");
	scanf("%s", cargo); // Captando o valor que o usuário colocou
	
	file = fopen(arquivo, "a"); // Função que abre o file e atualiza com os dados passados abaixo (a)
	fprintf(file, cargo); // Adicionando uma nova variável ao file para guardar as informações coletadas
	fclose(file); // Fechando o arquivo
   
	system("pause"); // Pausando os códigos para poder aparecer na tela
	
}

int consultar () // Função para consultar os dados coletados
{ 
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	// Definindo as variavéis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Pergunta ao usuário
	scanf("%s", cpf); // Captando a resposta do usuário
	
	FILE *file; // Cria o arquivo no banco de dados (PC)
	file = fopen(cpf, "r"); // Abrindo e lendo o que está no file (r)
	
	if(file == NULL) // Se o aqruivo de dentro do file não existir.
	{
		printf("\nUsuário não localizado!\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) // No while é feito um looping com as informações do arquivo e elas serão guardadas na variável conteúdo para ser exibida na tela.
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); // Comando que aparece a informação que o usuário colocou na tela.
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
	
	FILE *file; // Criando um arquivo para armazenar a resposta do usuário, no caso, o CPF
	file = fopen(cpf,"r"); // Abrindo o file referente ao cpf (%s) e lendo o qu está lá (r)
	
	if(file == NULL) // Em caso o número digitado não esteja no arquivo.
	{
		fclose(file);
		printf("\nO usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	else if(file != NULL) // Condição caso o número inserido estava no sistema e foi deletado com sucesso.
	{
		fclose(file);
		printf("\nUsuário deletado com sucesso!.\n"); 
		system("pause");
		remove(cpf); // Função que acessa a pasta e deleta o arquivo CPF e confere se deu certo (remove)
	}
	
	fclose(file);
}

int main ()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao=0; // Definindo as variavéis
	int repeticao=1; // Definindo uma variável para o operador de repetição
	char senhadigitada[]="a"; // Variável para a senha. O "a" é que estamos atribuindo umv valor a ela.
	int comparacao; // Variável para comparar se a senha que o usuário coloca é a correta (admin). 
	
	printf("	Cartório da EBAC   \n\n"); // Título
	printf("Login de administrador.\n\nDigite a sua senha: "); // Perguntando a senha
	scanf("%s", senhadigitada); // Resposta do user
	
	comparacao = strcmp(senhadigitada, "admin"); // Comparação entre as strings. Os valores colocados pelo user, ficam alocados na memória. A "senhadigitada" fica com o mesmo valor de "admin".
	
	if(comparacao == 0) // Esse 0 é caso a comparação seja igual ao valor da senhadigitada (admin). Se fosse um valor diferente, daria erro, ele salvaria um valor diferente na memória.
	{
	
		for(repeticao=1;repeticao=1;) // Operador de repetição. As informção dentro do {} vão se repetir.
		{ 
	
			system("cls"); // Limpa a tela
		    setlocale(LC_ALL, "Portuguese"); // Definido a linguagem
		
	        printf("   Cartório da EBAC   \n\n"); // Início do menu
		    printf("Escolha a Opção Desejada do Menu:\n\n");
		    printf("\t1 - Registrar Nomes\n");
		    printf("\t2 - Consultar Nomes\n");
		    printf("\t3 - Deletar Nomes\n"); 
		    printf("\t4 - Sair do sistema\n\n");
		    printf("Opção: "); // Fim do menu
	
	        scanf("%d", &opcao); // Armazenando a escolha do usuário
	    
	        system("cls"); // Limpa a tela
        
	        switch(opcao) // Início da seleção no menu
			{ 
	           	case 1:	
	            registro(); // Chamando a função
	            break;
	            
	            case 2:
	            consultar(); // Chamando a função
		        break;
		            
		        case 3:
		        deletar(); // Chamando a função
	            break;
	            
	            case 4:
	            printf("Obrigado por utilizar o sistema!\n"); 
	            return 0; // Retorna o valor 0, quebra todas as funções e sai do sistema.
	            break;
	        
	            default: // Caso não seja colocado nenhuma das funções acima, as intruções abaixo aparecem.
	            printf("Essa opção não está disponível!\n");
	    	    system("pause");
	    	    break; // Fim da seleção
			}
		
		}	
	}	
	else // Caso o valor seja colocado errado (!= admin), dará erro.
		printf("\nSenha incorreta.");
	
}
