#include <stdio.h>
#include <string.h>



typedef struct{
    int nColunas, nPalavras, nLinhas;
    char matriz[100][100], lista[100][100];
}inf;

void subLeitura();
void subNomenclatura();


int main(){

    int i, j;

    inf kkk;
    subLeitura(&kkk);

    printf("linhas %d\ncolunas %d\npalavras %d\n\n", kkk.nLinhas, kkk.nColunas, kkk.nPalavras);

    for(i=0; i<kkk.nLinhas; i++){
        for(j=0; j<kkk.nColunas; j++){
            printf("%c", kkk.matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(i=0; i<kkk.nPalavras; i++){
        printf("%s\n", kkk.lista[i]);
    }
    

    return 0;
}


//Objetivo: Ler a matriz e as palavras a partir de arquivos de texto.
//Parâmetros formais
//-nome1:(função do parametro; entrada e/ou saída);
void subLeitura(inf *p){

    //contadores
    int i, j;

    char nome[2][1000];
    
    printf("Insira o nome do arquivo da matriz (com .txt):\n");
    gets(nome[0]);
    printf("Insira o nome do arquivo da lista de palavras (com .txt):\n");
    gets(nome[1]);
    
        
    //ler matriz
    FILE *arquivoX;

    arquivoX = fopen(nome[0], "r");

    fscanf(arquivoX, "%d", &p->nLinhas);
    
    fscanf(arquivoX, "%d", &p->nColunas);

    fgetc(arquivoX);

    for(i=0; i<p->nLinhas; i++){
        for(j=0; j<p->nColunas; j++){
            fscanf(arquivoX ,"%c ", &p->matriz[i][j]);
        }
    }
    fclose(arquivoX);


    //ler lista de palavras
    arquivoX = fopen(nome[1], "r");

    fscanf(arquivoX, "%d", &p->nPalavras);
    
    for(i=0; i<(*p).nPalavras; i++){
        fscanf(arquivoX, "%s", &p->lista[i]);
    }
    fclose(arquivoX);
    
    return;
}

