#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista * criar(){
    Lista * lse;
    lse = (Lista *) malloc(sizeof(Lista));
    if(lse != NULL){
        lse->qtd = 0;
    }
    else{printf("erro na criacao");}
    return lse;
}

void destruir(Lista *lse){
    free(lse);
}

int tamanho(Lista *lse){
    if(lse == NULL)
        return -1;
    else
        return lse->qtd;
}

int cheia(Lista *lse){
    if (lse == NULL)
        return -1;
    else if (lse->qtd == MAX)
        return 1;
    else
        return 0;
}

int vazia(Lista *lse){
    if (lse == NULL)
        return -1;
    else if (lse->qtd == 0)
        return 1;
    else
        return 0;
}

int inserirInicio(Lista *lse, struct aluno novo) {
    if (lse == NULL)
        return 0;
    else if (cheia(lse))
        return 0;
    else {
        int i;
        for (i = (lse->qtd)-1 ; i >= 0 ; i--) {
            lse->dados[i+1] = lse->dados[i];
        }
        lse->dados[0] = novo;
        lse->qtd++;
        return 1;
    }
}


int inserirFim(Lista *lse, struct aluno novo){
    if (lse == NULL)
        return 0;
    else if (cheia(lse))
        return 0;
    else {
        lse->dados[lse->qtd] = novo;
        lse->qtd++;
        return 1;
    }
}

int inserirMeio(Lista * lse, struct aluno novo){
    if(lse == NULL)
        return 0;
    else if(cheia(lse))
        return 0;
    else if(vazia(lse)){
        lse->dados[0] = novo;
        lse->qtd++;
        return 1;
    }
    else{
        int pos = lse->qtd, i;

        while(lse->dados[pos-1].matricula > novo.matricula && pos > 0){
            pos--;
        }

        for(i = (lse->qtd)-1; i >= pos;i--){
            lse->dados[i+1] = lse->dados[i];
        }
        lse->dados[pos] = novo;
        lse->qtd++;
        return 1;
    }
}

int removerFim(Lista * lse){
    if (lse == NULL)
        return 0;
    else if (vazia(lse))
        return 0;
    else {
        lse->qtd--;
        return 1;
    }
}

int removerInicio(Lista * lse){
    if (lse == NULL)
        return 0;
    else if (vazia(lse))
        return 0;
    else {
        int i;
        for(i=0;i<=lse->qtd;i++)
            lse->dados[i] = lse->dados[i+1];
            lse->qtd--;
        return 1;
    }
}

int removerMeio(Lista * lse, int x){
        if(lse == NULL)
        return 0;
    else if(cheia(lse))
        return 0;

    else{
        int i=0;
        while(lse->dados[i].matricula!=x && i < lse->qtd){
            i += 1;
        }
        if(i==lse->qtd)
            return 0;
        for(i = (lse->qtd)-1;lse->dados[i].matricula >= x;i--){
            lse->dados[i] = lse->dados[i+1];
        }
        lse->qtd--;
        return 1;
    }
}

int acessarIndice(Lista *lse, int pos, struct aluno * a){
    if(lse == NULL)
        return 0;
    else if(pos > lse->qtd-1 || pos<0)
        return 0;
    else{
        *a = lse->dados[pos];
        return 1;
    }
}

int acessarValor(Lista *lse, int x, struct aluno * a){
    if(lse == NULL)
        return 0;
    else if(x > lse->dados[(lse->qtd)-1].matricula || x < lse->dados[0].matricula){
        return 0;
    }
    else{
        int i = 0;
        while(lse->dados[i].matricula!=x && i < lse->qtd){
            i += 1;
        }
        if(i==lse->qtd)
            return 0;
        *a = lse->dados[i];
        return 1;
    }
}











