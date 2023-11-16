#include "ArvoreBinaria.h" //inclui os Protótipos

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, Tipo_Dado1 ID, Tipo_Dado2 Status){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    strcpy(novo->ID, ID);
    novo->status = Status;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(strcmp(ID, atual->ID)==0){ //Aqui tem como por dado igual
                free(novo);
                return 0;//elemento já existe
            }
            //printf("estou comparando %s com %s\n", ID, atual->ID);
            if(strcmp(atual->ID, ID)>0){
                atual = atual->esq;
               // printf("entrei\n");
            }
            else{
                atual = atual->dir;
               // printf("nao entrei\n");
            }
        }
        //printf("!estou comparando %s com %s\n", ant->ID, ID);
        if((strcmp(ID, ant->ID)>0)){
            ant->dir = novo;
         //   printf("meti na direita do %s\n", ant->ID);
        }
        else{
            ant->esq = novo;
          //  printf("meti na esquerda do %s\n", ant->ID);
        }
    }
    return 1;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, Tipo_Dado1 ID, int* pos_consultadas){
    *pos_consultadas = 0;
    if(raiz == NULL)
        return -1;
    struct NO* atual = *raiz;
    while((atual != NULL)){   
        if(strcmp(ID, atual->ID)==0){
            *pos_consultadas = *pos_consultadas + 1;
            return 1;
        }
        if(strcmp(ID, atual->ID)>0)
            atual = atual->dir;
        else
            atual = atual->esq;
        *pos_consultadas = *pos_consultadas + 1;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%s %d\n",(*raiz)->ID, (*raiz)->status);          // Info é Int
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

int insere_lista_ordenada(Lista* li, Tipo_Dado1 ID, Tipo_Dado2 Status)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    no->status = Status;
    strcpy(no->ID, ID);
    if ((*li) == NULL)
	{  //lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *ante, *atual = *li;
        while (atual != NULL && strcmp(atual->ID, ID)<0)
		{
            ante = atual;
            atual = atual->prox;
        }
        if (atual == *li)
		{   //insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}
void imprime_lista(Lista* li)
{
    Elem* no = *li;

    if (li == NULL)
        return;
    while (no != NULL) 
    {
        printf("%s %d\n",no->ID, no->status);
        no = no->prox;
    }
}

int tamanho_lista(Lista* li)
{
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int consulta_lista_dado(Lista* li, Tipo_Dado1 ID, int* pos_consultadas){
    *pos_consultadas = 0;
    if (li == NULL)
       return -1;
    Elem *no = *li;
    while (no != NULL && (strcmp(no->ID, ID)<0)){
        *pos_consultadas =  *pos_consultadas + 1;
        no = no->prox;
    }
    if ((strcmp(no->ID, ID)>0) == 0){
        *pos_consultadas =  *pos_consultadas + 1;
       return 0;
    }
    else
    {
        *pos_consultadas =  *pos_consultadas + 1;
        return -1;
    }
}

void libera_lista(Lista* li){
    if (li != NULL){
        Elem* NO;
        while (*li != NULL){
            NO = *li;
            *li = (*li)->prox;
            free(NO);

        }
        free(li);
    }
}

