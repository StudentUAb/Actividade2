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
        /* utilização do operador *= em vez da atribuição e multiplicação */
        produto *= i;
        /* utilização do operador de incremento ++, em vez da atribuição
        e soma com a unidade. */
        i++;
    }

    // resultado
    printf("%d", produto);
}
