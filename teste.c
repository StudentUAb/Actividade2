/*
** UC: 21111 - Sistemas Operativos
** e-fólio A 2021-22 (teste.c)
**
** Aluno: 2100927 - Ivo Baptista 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAXSTR 255

void compila(char *arquivo)
{
  pid_t pid;
  if ((pid = fork()) < 0)
  {
       perror("Erro no fork da compilação");
       
       exit(1);
  }
 
  if (pid == 0)
    // processo filho
    /* pid=0, codigo para o processo filho */
  {
    //primeiro processo filho seria a compilação
    printf("Processo PID = %5d  PPID = %5d [compilacao].\n", \
           (int) getpid(), (int) getppid());   
    //compila argv[1] que é o argumento 1 que neste caso é o produto.c 
    //que colocamos na execução do teste como primeiro argumento ./teste agrumento1 argumento2
    execlp("gcc", "gcc", "-o", "compilado", arquivo, NULL);

    // Esse exit() nunca será executado (provavelmente!)
    exit(-1);
  }
  else
  {
    // processo pai            
    /* pid>0, codigo para o processo pai */
    wait(NULL);
    // com o wait() acima, essa função só retornará
    // quando o compilador terminar seu trabalho.
    /* codigo abrir fichiero com fopen
    coparar strings com fgets
    ultilizar o strcmp 
    e fechar o ficheiro
    iria colocado aqui nesta parte
    nao deu tempo de continuar com o programa*/
  }
}

int main(int argc, char **argv)
{
  pid_t pid;
  FILE *f;
  char frase[MAXSTR];
  int i,j;
  printf("Processo PID = %5d  PPID = %5d [principal].\n", \
   (int) getpid(), (int) getppid());

  f = fopen(argv[2], "r");    // abre o ficheiro em modo so de leitura

  i = 0;
  compila(argv[1]);

  //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente
  // fprintf(stderr, "compilei.\n");
  //ciclo while
  j = 0;
  while( fgets(frase, MAXSTR, f) )
  {
  //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente
    //fprintf(stderr, "No while, i = %d.\n", i);
    i++;
    j++;
    if (j%2 == 0)
      continue;
    //ler linha dos resultados esperados
    if ((pid = fork()) < 0)
    {
      perror("fork deu erro");
      
      exit(1);
    }

    if (pid == 0)
        // processo filho
        /* pid=0, codigo para o processo filho */
    {
  //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente
  //fprintf(stderr, "Filho executando.\n");
  // processos dos filhos em execução dos casos aqui executa todos os que nao seja i==0
  char ficheiro[40] = {""};

  //convertimos a variavel numero para inteiro e fazemos 
  //o calculo do indicador -1 para começar com o ficheiro out0.txt
  // concatenamos o nome da saida dos ficheiros do cilclo  de 1 a 20 mas como i-1 fica 0
  // entao os ficheiros criados seria a começar no out0.txt 
  snprintf(ficheiro, 40, "out%02d.txt", i-1);
  //perror("");   // mostra erro

  //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente 
  // fprintf(stderr, "Ficheiro: '%s'\n", ficheiro);
  // fprintf(stderr, "frase: '%s'\n", frase);
  

  // FILE *fOut; 
  // fOut = fopen(file, "w+");

  //aqui visualizamos os pid e ppid dos processos filhos
  printf("Processo PID = %5d  PPID = %5d [execucao caso %d].\n", (int) getpid(), (int) getppid(), i);

  //aqui como indicado no enunciado executamos a intrução stdout para para redirecionar o output para um ficheiro
  if( (stdout = freopen(ficheiro, "w", stdout)) == NULL )
    perror("Não consegui redirecionar stdout");
  // aqui já fizemos o redirecionamento de stdout
  

  //strtok(str, " ");
  //printf("->%s\n", str);

  execlp("./compilado", "compilado", frase, NULL);
  exit(0);
      }
      else
      {
  //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente
  // fprintf(stderr, "Processo filho %d começou.\n", pid);
        wait(NULL);
  //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente
  // fprintf(stderr, "Processo filho %d terminou.\n", pid);
      }
   }
   //AVISO remover comentario da linha de baixo para outra visualização do resultado diferente
   // printf("Aqui é para ser executado por todos os processos pais e filhos\n\n");
   // exit(0);

  fclose(f);

  // Espera que os filhos terminem
  // Isso sõ seria necessário se vc não colocasse o wait() no loop
  // while( wait(NULL) > 0 )
    // ;

  return 0;

}
