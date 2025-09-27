//implementação de vetor de forma simples:

int *vetor;
int tam, i;

int main()
{
tam =100;

vetor = malloc(sizeof(int)*tam);

for (i = 0; i < tam ; i++)
{
    *vetor=0;
    vetor++;
}
free (vetor);

return 0;

}