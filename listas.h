#include <stdlib.h>
#include <stdio.h>
#define MAX 50

struct aluno{
int matricula;
char nome[50];
float av1;
float av2;
float pr;
};

typedef struct lista Lista;

Lista * criar();
void destruir(Lista *);
int tamanho(Lista *);
int cheia(Lista *);
int vazia(Lista *);
int inserirFim(Lista * lse, struct aluno novo);
int inserirInicio(Lista * lse, struct aluno novo);
int inserirMeio(Lista * lse, struct aluno novo);
int removerFim(Lista *);
int removerInicio(Lista *);
int removerMeio(Lista *, int);
int acessarIndice(Lista *lse, int pos, struct aluno *a);
int acessarValor(Lista *lse, int x, struct aluno *a);

