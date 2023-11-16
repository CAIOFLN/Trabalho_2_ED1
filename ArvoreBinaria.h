//  Arquivo ArvBinaria.h
//  TAD: ProjArvoreBinaria-V2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef int Tipo_Dado2;
typedef char Tipo_Dado1[10];

//Definição do tipo Arvore
struct NO{
    Tipo_Dado2 status;
    Tipo_Dado1 ID;
    struct NO *esq;
    struct NO *dir;
};
struct elemento{
    struct elemento *ant;
    Tipo_Dado2 status;
    Tipo_Dado1 ID;
    struct elemento *prox;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

typedef struct elemento Elem;
typedef struct elemento* Lista;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Tipo_Dado1 ID, Tipo_Dado2 Status);
// int remove_ArvBin(ArvBin *raiz, Tipo_Dado1 ID, Tipo_Dado2 Status);
int totalNO_ArvBin(ArvBin *raiz);
// int consulta_ArvBin(ArvBin *raiz, Tipo_Dado1 ID, Tipo_Dado2 Status);
void preOrdem_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, Tipo_Dado1 ID, int* pos_consultadas);
Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenada(Lista* li, Tipo_Dado1 ID, Tipo_Dado2 Status);
void imprime_lista(Lista* li);
int tamanho_lista(Lista* li);
int consulta_lista_dado(Lista* li, Tipo_Dado1 ID, int* pos_consultadas);