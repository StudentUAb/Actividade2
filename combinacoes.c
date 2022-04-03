#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i, n=0, r=0, combinacoes;

    if (argc == 3) {
        n = atoi(argv[1]);
        r = atoi(argv[2]);
    }

    if (n < r || r < 1)
        printf("Erro: N tem de ser maior que R e este maior que 0.");
    else
    {
        i = 1;
        combinacoes = 1;
        while (i <= r)
        {
            combinacoes *= (n - r + i);
            combinacoes /= i;
            i++;
        }
        printf("%d", combinacoes);
    }
}