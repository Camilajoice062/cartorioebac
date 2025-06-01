#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função  responsável por registrar os dados
{
  //inicio da criação de variáveis/strings
  char arquivo[40]; 
  char cpf[40]; 
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //fim da criação de variáveis/strings

  printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
  scanf("%s", cpf); //%s referente a string

  strcpy(arquivo, cpf); //copiando o CPF para o nome do arquivo

  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //abrindo o arquivo para escrita "w" = write = escrita
  fprintf(file,cpf); //salva o valor da variável 
  fclose(file); //fechando o arquivo

  file = fopen(arquivo, "a"); //atualizando o arquivo
  fprintf(file, ","); //para separar os dados
  fclose(file); //fechando o arquivo  

  printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
  scanf("%s", nome); //%s referente a string

  file = fopen(arquivo, "a"); //atualizando o arquivo
  fprintf(file, nome); //salva o valor da variável 
  fclose(file); //fechando o arquivo

  file = fopen(arquivo, "a"); //atualizando o arquivo
  fprintf(file, ","); //para separar os dados
  fclose(file); //fechando o arquivo

  printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
  scanf("%s", sobrenome); //%s referente a string

  file = fopen(arquivo, "a"); //atualizando o arquivo
  fprintf(file,sobrenome); //salva o valor da variável
  fclose(file); //fechando o arquivo

  file = fopen(arquivo, "a"); //atualizando o arquivo
  fprintf(file, ","); //para separar os dados
  fclose(file); //fechando o arquivo

  printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
  scanf("%s", cargo); //%s referente a string

  file = fopen(arquivo, "a"); //atualizando o arquivo
  fprintf(file, cargo); //salva o valor da variável
  fclose(file); //fechando o arquivo

  system ("pause"); //pausa para o usuário
   
}
int consulta() //função responsável por consultar os dados
{
  //inicio da criação de variáveis/strings
  char cpf[40];
  char conteudo[200];
  //fim da criação de variáveis/strings
  printf("Digite o CPF a ser consultado: ");
  scanf("%s", cpf);

  FILE *file; //cria o arquivo
  file = fopen(cpf, "r"); //abrindo o arquivo para leitura "r" = read = leitura

  if (file == NULL) //verifica se o arquivo existe
  {
    printf("Arquivo não localizado!\n"); //se não existir, imprime a mensagem
  }
  while(fgets(conteudo, 200, file) != NULL) //enquanto o arquivo não for nulo
  {
    printf("\nEssas são as informações do usuário:"); //imprime as informações
    printf("%s", conteudo); //imprime o conteúdo do arquivo
    printf("\n\n"); //imprime uma linha em branco
  }
  system("pause"); //pausa para o usuário
}
int deletar() //função responsável por deletar os dados
{
  char cpf[40]; //variável para armazenar o CPF
    printf("Digite o CPF a ser deletado: "); //coletando informações do usuário
    scanf("%s", cpf); //%s referente a string

    // Verifica se o arquivo foi removido com sucesso
    if (remove(cpf) == 0)
    {
        printf("Arquivo deletado com sucesso!\n"); // Mensagem de sucesso
    }
    else
    {
        printf("Erro ao deletar o arquivo. Arquivo não encontrado!\n"); // Mensagem de erro
    }

    system("pause"); // Pausa para o usuário
}  

int main() //função principal
{  
 setlocale(LC_ALL, "Portuguese"); //definindo o idioma
 int opcao=0; //variável para armazenar a opção do usuário
 int laco=1; //variável para armazenar o laço de repetição

 for (laco=1;laco==1) // Laço de repetição
 {
    printf("### Cartório da EBAC ###\n\n"); //imprime o cabeçalho
    printf("\t1 - Registrar nomes\n"); //opção de registrar
    printf("\t2 - Consultar nomes\n"); //opção de consultar
    printf("\t3 - Deletar nomes\n"); //opção de deletar
    printf("\t4 - Sair do sistema\n"); //opção de sair
    printf("opcao: "); //fim do menu
    
    scanf("%d", &opcao); //armazenando a escolha do usuário
    system("cls"); //limpando a tela
    
    switch(opcao) //início da seleção do menu 
    {
        case 1: 
        registro(); //chama a função de registro
        break; //fechando o case

        case 2:
        consulta(); //chama a função de consulta
        break; //fechando o case

        case 3:
        deletar(); //chama a função de deletar
        break; //fechando o case

        case 4: //opção de sair
        printf("Obrigado por utilizar o sistema.\n"); //imprime a mensagem de saída
        return 0; //retorna 0 para o sistema
        break; //fechando o case

        default: //se escolher uma opção inválida
        printf("Essa opção não está disponivel!\n"); //imprime a mensagem
        system("pause"); //pausa para o usuário
        break; //fechando o switch

    }
 }
 return 0;
}