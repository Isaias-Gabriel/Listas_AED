#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

int print_menu();
int get_options();
Lista * case_1(int op1, Lista * ordenada, Lista * desordenada);

int main(void){

    int i, n_mat, op1, op2;
    Lista * ordenada = NULL, * desordenada = NULL;
    struct aluno novo;

    while(1){
        op1 = get_options(), op2 = print_menu();

        switch(op2){
        case 1:
            if(op1 == 0)
                ordenada = criar(ordenada);
            else
                desordenada = criar(desordenada);
        break;
        case 2:

            printf("Digite o numero de matricula.\n");
            scanf("%d",&novo.matricula);
            printf("Digite o nome do aluno.\n");
            scanf(" %s",novo.nome);
            printf("Digite a nota da av1.\n");
            scanf("%f",&novo.av1);
            printf("Digite a nota da av2.\n");
            scanf("%f",&novo.av2);
            printf("Digite a nota da pr.\n");
            scanf("%f",&novo.pr);
            inserirInicio(desordenada, novo);
        break;
        case 3:

            printf("Digite o numero de matricula.\n");
            scanf("%d",&novo.matricula);
            printf("Digite o nome do aluno.\n");
            scanf(" %s",novo.nome);
            printf("Digite a nota da av1.\n");
            scanf("%f",&novo.av1);
            printf("Digite a nota da av2.\n");
            scanf("%f",&novo.av2);
            printf("Digite a nota da pr.\n");
            scanf("%f",&novo.pr);
            inserirFim(desordenada, novo);
        break;
        case 4:

            printf("Digite o numero de matricula.\n");
            scanf("%d",&novo.matricula);
            printf("Digite o nome do aluno.\n");
            scanf(" %s",novo.nome);
            printf("Digite a nota da av1.\n");
            scanf("%f",&novo.av1);
            printf("Digite a nota da av2.\n");
            scanf("%f",&novo.av2);
            printf("Digite a nota da pr.\n");
            scanf("%f",&novo.pr);
            inserirMeio(ordenada, novo);
        break;
        case 5:
            removerInicio(desordenada);
        break;
        case 6:
            removerFim(desordenada);
        break;
        case 7:

            printf("Digite o numero de matricula para exclusao dos dados: ");
            scanf("%d",&n_mat);
            removerMeio(ordenada, n_mat);
        break;
        case 8:

            printf("Digite o numero o indice para acesso dos dados: ");
            scanf("%d",&n_mat);

            if(op1 == 0){
                if(acessarIndice(ordenada, n_mat, &novo) == 0)
                    printf("\nNao foi possivel encontrar os dados\n");
                else{
                    acessarIndice(ordenada, n_mat, &novo);
                    printf("\nmatricula %d aluno %s av1 %f av2 %f pr %f \n", novo.matricula, novo.nome, novo.av1, novo.av2, novo.pr);
                }
            }
            else{
                if(acessarIndice(desordenada, n_mat, &novo) == 0)
                    printf("\nNao foi possivel encontrar os dados\n");
                else{
                    acessarIndice(desordenada, n_mat, &novo);
                    printf("\nmatricula %d aluno %s av1 %f av2 %f pr %f \n", novo.matricula, novo.nome, novo.av1, novo.av2, novo.pr);
                }
            }
        break;
        case 9:

            printf("Digite o numero de matricula para acesso dos dados: ");
            scanf("%d",&n_mat);

            if(op1 == 0){
                if(acessarValor(ordenada, n_mat, &novo) == 0)
                    printf("\nNao foi possivel encontrar os dados\n");
                else{
                    acessarValor(ordenada, n_mat, &novo);
                    printf("\nmatricula %d aluno %s av1 %f av2 %f pr %f \n", novo.matricula, novo.nome, novo.av1, novo.av2, novo.pr);
                }
            }
            else{
                if(acessarValor(desordenada, n_mat, &novo) == 0)
                    printf("\nNao foi possivel encontrar os dados\n");
                else{
                    acessarValor(desordenada, n_mat, &novo);
                    printf("\nmatricula %d aluno %s av1 %f av2 %f pr %f \n", novo.matricula, novo.nome, novo.av1, novo.av2, novo.pr);
                }
            }
        break;
        case 10:
            if(op1 == 0){
                destruir(ordenada);
            }
            else{
                destruir(desordenada);
            }
        break;
        case 11:
            for(i = 0; i < tamanho(desordenada);i++){
                acessarIndice(desordenada, i, &novo);
                printf("\nmatricula %d aluno %s av1 %f av2 %f pr %f \n", novo.matricula, novo.nome, novo.av1, novo.av2, novo.pr);
            }
        break;
        case 12:
            for(i = 0; i < tamanho(ordenada);i++){
                acessarIndice(ordenada, i, &novo);
                printf("\nmatricula %d aluno %s av1 %f av2 %f pr %f \n", novo.matricula, novo.nome, novo.av1, novo.av2, novo.pr);
            }
        break;
        case 13:
            exit(1);
        break;
        default:
            printf("C é demente");
        break;
        }
        //system("cls");
    }

    return 0;
}

int print_menu(){
    printf("01) Criar lista\n");
    printf("02) Inserir no comeco da lista\n");
    printf("03) Inserir no final da lista\n");
    printf("04) Inserir na lista ordenada\n");
    printf("05) Remover no comeco da lista\n");
    printf("06) Remover no final da lista\n");
    printf("07) Remover um elemento especifico\n");
    printf("08) Acessar elemento por indice\n");
    printf("09) Acessar elemento por valor\n");
    printf("10) Destruir lista\n");
    printf("11) Imprimir lista completa\n");
    printf("12) Imprimir lista ordenada completa\n");
    printf("13) Sair\n");
    printf("Opcao: ");
    int op;
    scanf("%d",&op);
    return op;
}

int get_options(){
    int op;
    printf("Ordenada (0) ou desordenada(cc): ");
    scanf("%d",&op);
    return op;
}




































/*




int main(void){
    Lista * ordenada = NULL, * nao_ordenada = NULL;
    ordenada = criar(), nao_ordenada = criar();
    int n;
    printf("1 - CRIAR LISTA ORDENADA\n2 - CRIAR LISTA DESORDENADA\n");
    printf("1 - CADASTRA ALUNO\n2 - CONSULTA ALUNO\n3 - REMOVE ALUNO\n");
    scanf("%d",&n);
    printf("%d",tamanho(ordenada));
    //cadastra os dados do aluno

    switch(n){
    case 1:

    case 2:

    }

    {
        struct aluno novo;
        printf("Digite o numero de matricula.\n");
        scanf("%d",&novo.matricula);
        printf("Digite o nome do aluno.\n");
        scanf(" %s",novo.nome);
        printf("Digite a nota da av1.\n");
        scanf("%f",&novo.av1);
        printf("Digite a nota da av2.\n");
        scanf("%f",&novo.av2);
        printf("Digite a nota da pr.\n");
        scanf("%f",&novo.pr);
        inserirMeio(ordenada, novo);
    }


}


void menu_ord(Lista ** lse){
int n;
printf("1 - CADASTRA ALUNO\n2 - CONSULTA ALUNO\n3 - REMOVE ALUNO\n\n");
scanf("%d",&n);

//cadastra os dados do aluno
if(n==1){

    struct aluno{
        int matricula;
        char nome[50];
        float av1;
        float av2;
        float pr;
    };

    struct aluno novo;

    printf("Digite o numero de matricula.\n");
    scanf("%d",&novo.matricula);
    printf("Digite o nome do aluno.\n");
    scanf("%s",novo.nome);
    printf("Digite a nota da av1.\n");
    scanf("%f",&novo.av1);
    printf("Digite a nota da av2.\n");
    scanf("%f",&novo.av2);
    printf("Digite a nota da pr.\n");
    scanf("%f",&novo.pr);

    struct aluno * p;

    inserirMeio(*lse,novo);

}
else if(n==2){

}
else if(n==3){

}
else{
    printf("valor incorreto, digite novamente.");
    menu_ord(lse);
}
}




*/

























