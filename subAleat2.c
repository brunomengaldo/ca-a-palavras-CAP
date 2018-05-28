#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


//typedef
typedef struct{
    int nColunas;
    int nPalavras;
    int nLinhas;
    int indC, indL;
    //int tamPalavras;
    char matriz[100][100];
    char randW[100][100];
    char transposta[100][100];
}inf;



//prototipo
void subAleat();
void subDimencoes();
void subImprimir();
void subPalavras();




//--------------------------MAIN-------------------------------
int main(){

    inf hue;

    subDimencoes(&hue);
    subAleat(&hue);    
    subPalavras(&hue); 
    //subImprimir(&hue);

    return 0;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subDimencoes(inf *p){
    
    //ler tamanho da matriz
    printf("Informe o numero de linhas: ");
    scanf("%d", &p->nLinhas);
    printf("Informe o numero de colunas: ");
    scanf("%d", &p->nColunas);

    //numero de palavras
    printf("Informe o numero de palavras: ");
    scanf("%d", &p->nPalavras);

    return;
}


//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subAleat(inf *p){

    //contadores
    int i, j;

    srand(time(NULL));

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->matriz[i][j]=(rand()%26)+(65);
        }
    }
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            p->transposta[j][i]=p->matriz[i][j];
        }
    }

    return;
}





//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subPalavras(inf *p){

    srand(time(NULL));

    int i, j, entd0[50][50];

    for(i=0; i<p->nPalavras; i++){
        for(j=0; j<p->nPalavras; j++){
            entd0[i][j]=0;
        }
    }

    for(i=0; i<p->nPalavras; i++){
        
        p->indL=(rand()%p->nLinhas)+1;
        p->indC=(rand()%p->nColunas)+1;
        
        for(j=0; j<p->nPalavras; j++){    
            if(i%2==0){
                p->randW[i][j] = p->matriz[i][p->indL];
                entd0[i][j]=p->indL;
                p->indL++;
            }
            else{
                p->randW[i][j] = p->transposta[i][p->indC];
                entd0[i][j]=p->indC;
                p->indC++;
            }
            
            
        }

        //printf("L %d\nC %d\n\n", p->indL, p->indC);
    }

    
    printf("\nentd0\n");
    for(i=0; i<p->nPalavras; i++){
        for(j=0; j<p->nPalavras; j++){
           printf("%d%c", entd0[i][j], j==p->nPalavras-1?'\n':' ');
        }
    }//*/

    return;
}






//Objetivo:
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída)
void subImprimir(inf *p){

    int i, j;

    printf("\n");
    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            printf("%c%c", p->matriz[i][j], j==p->nColunas-1?'\n':' ');
        }
    }
    printf("\n");
    for(i=0; i<p->nColunas; i++){
        for(j=0; j<p->nLinhas; j++){
            printf("%c%c", p->transposta[i][j], j==p->nLinhas-1?'\n':' ');
        }
    }

    printf("\n\nPALAVRAS ALEATORIAS!!!\n");

    for(i=0; i<p->nPalavras + 1; i++){
        printf("%s\n", p->randW[i]);
    }

    
    return;
}

