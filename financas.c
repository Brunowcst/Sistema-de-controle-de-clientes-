#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "financas.h"
#include "bibliotecascc.h"

typedef struct financa financas;

void modulo_financas(void) {
    char op;
    do {
        mod_MenuFinancas();   
        printf("Escolha a opção desejada:\n");
        scanf("%c", &op);
        getchar();
        switch(op){
        case '1' : cadastro_planos();
            break;
        case '2' : pesquisaPlano();
            break;
        case '3' : editar_planos();
            break;
        case '4' : excluir_planos();
            break;
        case '5' : listagem_planos();
        default:
            
            printf("\n\t\t>>> Ops!! escolha uma opção válida...\n");
            sleep(2);
            break;
            }
             
        } while (op!='0');
}


void mod_MenuFinancas(void) {
    system("clear||cls");
    printf("\n");
    printf(" _____________________________________________________________________________\n");
    printf("|                                                                             |\n");
    printf("|              = = = = = = = = = = = = = = = = = = = = = = = =                |/\n");
    printf("|              = = = = = =   Módulo Financeiro   = = = = = = =                |\n");
    printf("|              = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
    printf("|                                                                             |\n");
    printf("|              1. Cadastrar PLanos                                            |\n");
    printf("|              2. Pesquisar Planos                                            |\n");
    printf("|              3. Editar Planos                                               |\n");
    printf("|              4. Excluir Planos                                              |\n");
    printf("|              5. Listar planos                                               |\n");
    printf("|              0. Voltar                                                      |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|_____________________________________________________________________________|\n");
    printf("\n");
}


void cadastro_planos(void) {
    financas* planos;

    planos = cadastrar_fin();
    gravarPlanos(planos);
    free(planos);
}

void gravarPlanos(financas *planos){
    FILE* fp;

    fp = fopen("planos.dat", "ab");
    if (fp == NULL){
        telaErrorArquivofin();
        }
    fwrite(planos, sizeof(financas),1 , fp);
    fclose(fp);
}

void editar_planos(void) {
    financas* planos;
    int cod;

    cod = telaEdit_planos();
    planos = pesquisa_planos(cod);
    if (planos == NULL){
        printf("= = = Cliente não encontrado... = = =\n");
        sleep(2);
    } else {
        planos = cadastrar_fin();
        regravarplanos(planos);
        free(planos);
    }
    
}

void regravarplanos(financas* planos){
    int achou;

    FILE* fp;
    financas* planoLido;

    planoLido = (financas*)malloc(sizeof(financas));
    fp = fopen("planos.dat", "r+b");
    if (fp == NULL){
        telaErrorArquivofin();
        }
    achou = 0;
    while (fread(planoLido, sizeof(financas),1 , fp) && !achou){
        
        if (planoLido->codigo == planos->codigo){
            achou = 1;
            fseek(fp, -1*sizeof(financas), SEEK_CUR);
        fwrite(planos, sizeof(financas), 1, fp);        
        }
        
    }
    fclose(fp);
    free(planoLido);
}

financas* pesquisa_planos(int cod){
    FILE* fp;
    financas* planos;
    
    planos = (financas*)malloc(sizeof(financas));
    fp = fopen("planos.dat", "rb");
    if (fp == NULL){
        telaErrorArquivofin();
    }
    while (fread(planos, sizeof(financas), 1, fp)){    
        if((planos->codigo == cod)){
            fclose(fp);
            return planos;
        }
    }
    fclose(fp);
    return NULL;
}


int telaEdit_planos(void){
    int cod;
    
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =   Editar Planos   = = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o Código do plano:                                     |\n");    
    scanf("%d", &cod);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    return cod;
}

void exibirPlanos(financas* planos) {

	if (planos == NULL) {
		printf("\n= = = Plano não encontrado = = =\n");
        sleep(3);
	} else {
		printf("\n= = = Plano Cadastrado = = =\n");		
		printf("Titulo do plano: %s\n", planos->titulo);
        printf("Código do plano: %d\n", planos->codigo);
		printf("Preço: %.2f\n", planos->preco);
        printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n\n");
	    getchar();
	}
	
}


void pesquisaPlano(void) {
    
    financas* planos;    
    int cod;

    cod = telaPesquisar_planos();
    planos = pesquisa_planos(cod);
    exibirPlanos(planos);
	free(planos);
}


int telaPesquisar_planos(void) {
    int cod;

    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Listagem de Planos   = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|             Digite o código do plano que deseja exibir:               |\n");
    scanf("%d",&cod);
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
    return cod;
}


financas *cadastrar_fin(void) {
    financas* planos;
    planos = (financas*) malloc(sizeof(financas));
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Cadastrar Planos = = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|                     * Insira os dados abaixo *                        |\n");
    printf("|                                                                       |\n");
    do {
    printf("|           * Titulo do plano:                                          |\n");
    scanf("%50[^\n]", planos -> titulo);
    getchar();
    } while (!validarNome(planos -> titulo));
  
    printf("|           * Preço em R$: (Apenas números):                            |\n");
    scanf("%f",&planos -> preco);
    getchar();
    printf("|           * Benefícios do plano:                                      |\n");
    scanf("%50[^\n]", planos -> beneficios);
    getchar();
    do {
    printf("|           * Informe um código de busca:                               |\n");
    scanf("%d", &planos->codigo);
    getchar(); 
    } while(!ehDigito2(planos->codigo));
    planos->status = 1;
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
    
    return planos; 
}

void excluir_planos(void) {
    financas* planos;
    int cod;

    cod = telaExcluir_planos();
    planos = (financas*)malloc(sizeof(financas));
    planos= pesquisa_planos(cod);

    if(planos == NULL){
        printf("= = = Não foi possível encontrar o cliente!!! = = =");
    } else {
        planos->status = 0;
        regravarplanos(planos);
        free(planos);
    }
}

int telaExcluir_planos(void){
    int cod;
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Excluir  planos    = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o código do plano que deseja excluir:                  |\n");
    scanf("%d",&cod);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    return cod;
}

void listagem_planos(void){
    char op;
    do {
        subMod_listar();   
        printf("Escolha a opção desejada: ");
        printf("\n");
        scanf("%c", &op);
        getchar();
        switch(op){
        case '1' : listar_planos();
            break;
        case '2' : listar_todosplanos();
            break;
        default:
            printf("\n\t\t>>> Ops!! escolha uma opção válida...\n");
            sleep(2);
            break;
            }
             
    } while (op!='0');
}
void subMod_listar(void){
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________\n");
    printf("|                                                                       |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
    printf("|           = = = = = = = =  LISTAR PLanos  = = = = = = = =             |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
    printf("|                                                                       |\n");
    printf("|           1. Listar plano específico                                  |\n");
    printf("|           2. Listar todos                                             |\n");
    printf("|           0. Voltar                                                   |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
}

void listar_planos(void) {
    FILE* fp;
    financas* planos;
    int n_lido;

    planos = (financas*) malloc(sizeof(financas));

    fp = fopen("planos.dat","rb");
    if (fp == NULL){
        telaErrorArquivofin();
        return;
    }
    do {
        system("clear||cls");
        printf("\n");
        printf(" _______________________________________________________________________\n");
        printf("|                                                                       |\n");
        printf("|            = = =  Relatório de planos cadastrados = = =               |\n");
        printf("|                                                                       |\n");
        printf("|                                                                       |\n");
        printf("|           1. Plano Família                                            |\n");
        printf("|           2. Plano Individual                                         |\n");
        printf("|           3. Plano Amigos                                             |\n");
        printf("|           4. Plano Premium                                            |\n");
        printf("|           5. Plano Daily                                              |\n");
        printf("|                                                                       |\n");
        printf("|          >>> Informe o Nº do tipo de plano que deseja listar:         |\n");
        printf("|_______________________________________________________________________|\n");
        printf("\t\n");
        scanf("%d", &n_lido);
        getchar();
    } while(!ehDigito2(n_lido));
    

    while(fread(planos, sizeof(financas), 1, fp)) {
        if (planos->codigo == n_lido){
            exibirPlanos(planos);
        } else {printf("\t\t>>> Nenhum plano encontrado\n");
            sleep(2);
        }
    }
    fclose(fp);
    free(planos);
}

void listar_todosplanos(void){
    FILE* fp;
    financas* planos;
    planos = (financas*) malloc(sizeof(financas));

    fp = fopen("planos.dat","rb");
    if (fp == NULL){
        telaErrorArquivofin();
        return;
        }

    printf("\t\t\n= = = Relatório de todos os planos = = =\n");
    while(fread(planos, sizeof(financas), 1, fp)) {        
        exibirPlanos(planos);
        }

    fclose(fp);
    free(planos);
}

void telaErrorArquivofin(void) {
	system("clear||cls");  
	printf("\n");
	printf("_____________________________________________________________________________\n");
	printf("|                                                                            |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|             = = = = = = =  Ops! Ocorreu em erro = = = = = =                |\n");
	printf("|             = = =  Não foi possível acessar o arquivo = = =                |\n");
	printf("|             = = = = com informações sobre os Planos   = = =                |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|____________________________________________________________________________|\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	return;
};
