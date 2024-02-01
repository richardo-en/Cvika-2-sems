#include <stdio.h>

int NacitajZnakPismeno(char N, char M, char V)
{
    if (N > M || N == M)
    {
        //Vrati jedna ak je zly interval
        printf("Neuspesne nacitanie!\n");
        return 1;
    }

    if (V >= N && V <= M)
    {
        return V;
    }
    else
    {
        //Vrati nula kvoli zlemu vstupu
        return 0;
    }
}

int Vykreslenie_ZC(int a, int space)
{
    for (int i = 0; i < a; i++)
    {
        if (i == 0 || i == (a - 1))
        {
            if (space != 0)
            {
                //Vykresli medzeri
                for (int sp = 0; sp < space; sp++)
                {
                    printf(" ");
                }
            }
            //Vykresli horny rad
            for (int c = 0; c < a; c++)
            {
                printf("+");
            }
            printf("\n");
        }
        else
        {
            if (space != 0)
            {
                //Vykresli medzeri
                for (int sp = 0; sp < space; sp++)
                {
                    printf(" ");
                }
            }
            for (int z = 0; z < a; z++)
            {
                //Vykresli stredny rad
                if (z == 0 || z == (a - 1))
                {
                    printf("+");
                }else{
                    printf("-");
                }
            }
            printf("\n");
        }
    }
    printf("\n\n");
    if (a <= 2)
    {
        //funkcia sa ukonci
        return 1;
    }else{
        //Rekurzia funkcie
        Vykreslenie_ZC((a-2) , (space+1));
    }
}

int main(int argc, char const *argv[])
{
    char a = 'c', b = 'i', c;
    int x = 0,num;

    printf("Zadaj maly znak z intervalu <%c, %c>:\n", a, b);

    while (x == 0)
    {
        scanf(" %c", &c);
        x = NacitajZnakPismeno(a, b, c);
    }

    if (x != 1 )
    {
        printf("Nacitanie prebehlo uspesne, z interval <%c, %c> vyberam maly/velky znak: %c\n\n", a, b, x);
    }
    
    scanf(" %d", &num);
    if (num <= 0 || num % 2 == 0)
    {
        printf("Nesupesne vykreslenie\n");
    }else{
        Vykreslenie_ZC(num, 0);
        printf("\nVykreslenie prebehlo uspesne\n");
    }
    return 0;
}