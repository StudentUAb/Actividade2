#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n, i, produto;

    //printf("Calculo do produto dos primeiros N numeros.\nIndique N:");
    //scanf("%d", &n);

    n = atoi(argv[1]);

    produto = 1;
    i = 1;
    while (i <= n)
    {
        /* utiliza��o do operador *= em vez da atribui��o e multiplica��o */
        produto *= i;
        /* utiliza��o do operador de incremento ++, em vez da atribui��o
        e soma com a unidade. */
        i++;
    }

    // resultado
    printf("%d", produto);
}
