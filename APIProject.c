#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 4294967295

typedef struct
{
    unsigned long int somma_cammini;
    int indice;
} grafo;

void addToVet(grafo topk[], unsigned long int somma, int k, int count);
void stampa_topk(grafo topk[], int k);
unsigned int dijkstra(unsigned int **mat, int n);
void sortmax(grafo topk[], int k);

int main()
{
    int d, k, count, i = 0, numero;
    char str_letta[15];
    char *stringa;
    int ch;
    unsigned int **mat;
    unsigned long int somma;

    i = scanf("%d %d\n", &d, &k); //salva parametri d e k

    grafo topk[k]; //vettore di struct classifica

    mat = malloc(d * sizeof(unsigned int *));
    for (int i = 0; i < d; i++)
        mat[i] = malloc(d * sizeof(unsigned int));

    count = 0;
    while ((stringa = fgets(str_letta, sizeof(str_letta), stdin)) != NULL)
    {
        if (str_letta[0] == 'A') //se il comando è "AggiungiGrafo", entra in if
        {
            for (i = 0; i < d; i++)
            {
                ch = getchar_unlocked();
                int l = 0;
                numero = 0;
                while (ch != '\n')
                {
                    if (ch <= '9' && ch >= '0')
                        numero = numero * 10 + (ch - 48);

                    else if (ch == ',')
                    {
                        if (numero == 0)
                            mat[i][l] = INFINITY;
                        else
                            mat[i][l] = numero;

                        l++;
                        numero = 0;
                    }
                    ch = getchar_unlocked();
                }
                if (numero == 0)
                    mat[i][l] = INFINITY;
                else
                    mat[i][l] = numero;
            }

            if (count < k)
            {
                topk[count].indice = count;
                topk[count].somma_cammini = dijkstra(mat, d);
                if (count == k - 1)
                    sortmax(topk, k);
            }
            else
            {
                somma = dijkstra(mat, d);
                addToVet(topk, somma, k, count);
            }
            count++;
        }

        else if (str_letta[0] == 'T')
        {
            if (count < k)
                stampa_topk(topk, count);
            else
                stampa_topk(topk, k);
        }
    }

    return 0;
}

void addToVet(grafo topk[], unsigned long int somma, int k, int count)
{
    //confronta primo elemento e ordina topk
    if (somma < topk[0].somma_cammini)
    {
        topk[0].somma_cammini = somma;
        topk[0].indice = count;
        //riordina topk
        sortmax(topk, k);
    }
}

void sortmax(grafo topk[], int k)
{
    int index = 0;
    grafo max = topk[0];

    for (int i = 0; i < k; i++)
        if (topk[i].somma_cammini > max.somma_cammini)
        {
            max = topk[i];
            index = i;
        }

    topk[index] = topk[0];
    topk[0] = max;
}

void stampa_topk(grafo topk[], int k)
{
    for (int i = 0; i < k - 1; i++)
        printf("%d ", topk[i].indice);

    if (k > 0)
        printf("%d", topk[k - 1].indice);
    printf("\n");
}

unsigned int dijkstra(unsigned int **mat, int n)
{
    unsigned long int dist[n];
    unsigned long int min_sum = 0, mindistance;
    unsigned short int check[n];
    int count, nextnode = 0, i;

    for (i = 0; i < n; i++) //inizializzazione vettori
    {
        dist[i] = mat[0][i];
        check[i] = 0;
    }

    dist[0] = 0; //inizializzazione nodo sorgente
    check[0] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (dist[i] < mindistance && !check[i])
            {
                mindistance = dist[i];
                nextnode = i;
            }

        check[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!check[i] && (mindistance + mat[nextnode][i]) < dist[i])
                dist[i] = mindistance + mat[nextnode][i];

        count++;
    }

    for (i = 0; i < n; i++)
    {
        if (dist[i] != INFINITY)
            min_sum = min_sum + dist[i];
    }

    return min_sum;
}
