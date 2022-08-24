#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char **mapa;
int linhas, colunas;

void lemapa()
{
 FILE *f;
 f = fopen("mapa.txt", "r");
 if (f == NULL)
 {
  printf("Erro ao abrir o arquivo");
  exit(1);
 }

 fscanf(f, "%d %d", &linhas, &colunas);
 alocamapa();

 for (int i = 0; i < 5; i++)
 {
  fscanf(f, "%s", mapa[i]);
 }
 fclose(f);
}

void alocamapa()
{
 mapa = malloc(sizeof(char *) * linhas);

 for (int i = 0; i < linhas; i++)
 {
  mapa[i] = malloc(sizeof(char) * colunas);
 }
}

void desalocamapa()
{
 for(int i = 0; i < linhas; i++){
  free(mapa[i]);
 }
 free(mapa);
}

int main()
{
 lemapa();

 for (int i = 0; i < linhas; i++)
 {
   printf("%s\n", mapa[i]);
 }

 desalocamapa();

 return 0;
}