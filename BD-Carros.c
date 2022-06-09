
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura cadastro carro
typedef struct {
       int codigo;
       char placa[20];
       char cidade [35];
       char modelo [20];
       char cor [20];
}Automoveis;

Automoveis automoveis[MAX];

//Procedimentos
void inicializar(){
    int i;

    for(i = 2; i < MAX; i++){
        automoveis[i].codigo = i;
        strcpy(automoveis[i].placa, " ");
        strcpy(automoveis[i].cidade, " ");
        strcpy(automoveis[i].modelo, " ");
        strcpy(automoveis[i].cor, " ");
    }
};

void inserir(){

    int i;

    for(i = 0; i < MAX; i++){
        if(strcmp(automoveis[i].placa, " ") == 0){
            printf ("Entre com os Dados:\n");
            printf ("Placa do Veiculo.: ");
            scanf("%s", automoveis[i].placa);
            fflush(stdin);
            printf ("Cidade...........: ");
            scanf("%s", automoveis[i].cidade);
            fflush(stdin);
            printf ("Modelo...........: ");
            scanf("%s", automoveis[i].modelo);
            fflush(stdin);
            printf ("Cor do Veículo...:");
            scanf("%s", automoveis[i].cor);
            fflush(stdin);
            return;
        }
    }
};

void alterar(){
    int i, codigo;

    system("cls");

    printf("Escolha qual cadastro deseja alterar:\n");

    for(i = 0; i < MAX; i++){
        if(strcmp(automoveis[i].placa, " ") != 0){
            printf("\nCodigo do veiculo: %d\n Placa: %s\n Modelo: %s\n Cor: %s\n Cidade: %s\n\n",
               automoveis[i].codigo, automoveis[i].placa, automoveis[i].modelo, automoveis[i].cor, automoveis[i].cidade);
        }
    }

    printf("Informe o codigo do veiculo a ser alterado: ");
    scanf("%d", &codigo);

    if(strcmp(automoveis[codigo].placa, " ") == 0){
        printf("\nCodigo incorreto. Veiculo nao registrado!\n\n");
    }
    else{
        printf ("Placa do Veiculo.: ");
        scanf("%s", automoveis[codigo].placa);
        fflush(stdin);
        printf ("Cidade...........: ");
        scanf("%s", automoveis[codigo].cidade);
        fflush(stdin);
        printf ("Modelo...........: ");
        scanf("%s", automoveis[codigo].modelo);
        fflush(stdin);
        printf ("Cor do Veiculo...:");
        scanf("%s", automoveis[codigo].cor);
        fflush(stdin);
        printf("\nRegistro alterado!\n\n");
    }
};

void pesquisar(){
    int i, consultcod;
    system("cls");
    printf("\nQual o codigo do veiculo que deseja consultar? ");
    scanf("%d",&consultcod);

    if(strcmp(automoveis[consultcod].placa, " ") == 0){
        printf("\nCodigo incorreto. Veiculo nao registrado!\n\n");
    }
    else{
        printf("\nCodigo do veiculo: %d\n Placa: %s\n Modelo: %s\n Cor: %s\n Cidade: %s\n\n",
               automoveis[consultcod].codigo, automoveis[consultcod].placa, automoveis[consultcod].modelo, automoveis[consultcod].cor, automoveis[consultcod].cidade);
    }
};

void excluir(){
    int i, codigoexc;
    system("cls");

    printf("Escolha qual cadastro deseja excluir: ");

    for(i = 0; i < MAX; i++){
        if(strcmp(automoveis[i].placa, " ") != 0){
            printf("\nCodigo do veiculo: %d\n Placa: %s\n Modelo: %s\n Cor: %s\n Cidade: %s\n\n",
               automoveis[i].codigo, automoveis[i].placa, automoveis[i].modelo, automoveis[i].cor, automoveis[i].cidade);
        }
    }

    printf("Informe o codigo do veiculo a ser excluido do cadastro: ");
    scanf("%d", &codigoexc);

    if(strcmp(automoveis[codigoexc].placa, " ") == 0){
        printf("\nCodigo incorreto. Veiculo nao registrado!\n\n");
    }
    else{
        automoveis[codigoexc].codigo = codigoexc;
        strcpy(automoveis[codigoexc].placa, " ");
        strcpy(automoveis[codigoexc].cidade, " ");
        strcpy(automoveis[codigoexc].modelo, " ");
        strcpy(automoveis[codigoexc].cor, " ");
        printf("Cadastro excluido!\n\n");
    }
};

// Função sobre 
void sobre(){
     system ("cls");
     printf ("Ramon Medeiros\n");
     printf ("Aperte uma tecla para voltar ao MENU...\n\n");
     getchar();
};

// Veículos pré cadastrados na base
void cad_base(){
    automoveis[0].codigo = 1;
    strcpy(automoveis[0].placa, "ABX-4258");
    strcpy(automoveis[0].cidade, "Curitiba");
    strcpy(automoveis[0].modelo, "Ford");
    strcpy(automoveis[0].cor, "Branca");

    automoveis[1].codigo = 2;
    strcpy(automoveis[1].placa, "CFD-8974");
    strcpy(automoveis[1].cidade, "Sao Paulo");
    strcpy(automoveis[1].modelo, "Fiat");
    strcpy(automoveis[1].cor, "Preta");
};

// Programa principal

int main(){
    //Opções de escolha
    int opcao;

    cad_base();
    inicializar();

    do{

        printf("================= MENU PRINCIPAL =================\n");
        printf ("|      Sistema para Cadastramento de Automoveis    |\n");
        printf ("----------------------------------------------------\n");
        printf ("|    1 - Incluir novos registros                   |\n");
        printf ("|    2 - Alterar um registro existente             |\n");
        printf ("|    3 - Pesquisar por codigo                      |\n");
        printf ("|    4 - Excluir um registro existente             |\n");
        printf ("|    5 - Sobre este sistema                        |\n");
        printf ("|    9 - Sair do Programa                          |\n");
        printf ("----------------------------------------------------\n");
        printf ("Sua Opcao: ");
        scanf ("%d", &opcao);
        printf ("------------------------------------------------------\n");

        switch (opcao) {
            case 1:
                inserir();
            break;
            case 2:
                alterar();
            break;
            case 3:
                pesquisar();
            break;
            case 4:
                 excluir();
            break;
            case 5:
                 sobre();
            break;
            case 9:
                printf ("Saindo...\n");
            break;
            default:
                printf ("Opçao invalida!!!\n");
                printf ("Aperte uma tecla para continuar...\n\n");
        }
    }while(opcao != 9);

return 0;
}