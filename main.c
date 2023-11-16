#include "ArvoreBinaria.h" //inclui os Protótipos


void le_arquivo(FILE* nome_arquivo, ArvBin* raiz, Lista* li){
    Tipo_Dado1 Leitura_CPF;
    Tipo_Dado2 Leitura_Status;
    while (1){
        fscanf(nome_arquivo, "%s", Leitura_CPF);
        if (strcmp(Leitura_CPF, "x")==0) break;
        fscanf(nome_arquivo, "%d", &Leitura_Status);
        insere_ArvBin(raiz, Leitura_CPF, Leitura_Status);
        insere_lista_ordenada(li, Leitura_CPF, Leitura_Status);

    }
}
/**/


int main(){
    ArvBin* raiz = cria_ArvBin();
    Lista* li = cria_lista();  
    FILE *arquivo;
    arquivo = fopen("arq.txt", "r");
    if (arquivo)
        le_arquivo(arquivo, raiz, li);
    //preOrdem_ArvBin(raiz);
    //imprime_lista(li);
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 0){
        int NL = tamanho_lista(li);
        int NA = totalNO_ArvBin(raiz);
        printf("NL:%d NA:%d", NL, NA);
    }
    else if (opcao == 1){

        Tipo_Dado1 dado_procurado;
        scanf("%s", dado_procurado);
        int caminho_lista;
        int achou_lista;
        int caminho_arvore;
        achou_lista = consulta_lista_dado(li, dado_procurado, &caminho_lista);
        consulta_ArvBin(raiz, dado_procurado, &caminho_arvore);
        printf("S:%d NL:%d NA:%d", achou_lista, caminho_lista, caminho_arvore);
    }
    else if (opcao == 2){
        imprime_lista(li);
    }
    else if (opcao == 3){
        preOrdem_ArvBin(raiz);
    }
    
    libera_ArvBin(raiz);
    libera_lista(li);


    return 0;
}