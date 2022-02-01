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
        case '1' : listar_planos();
            break;
        case '2' : cadastro_planos();
            break;
        case '3' : edit_planos();
            break;
        case '4' : excluir_planos();
            break;
        default:
            sleep(2);
            printf("Escolha uma opção válida...\n");
            break;
            }
             
        } while (op!='0');
}


void mod_MenuFinancas(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = =   Módulo Financeiro   = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Listar Planos                                            ///\n");
    printf("///           2. Cadastrar PLanos                                         ///\n");
    printf("///           3. Editar Planos                                            ///\n");
    printf("///           4. Excluir Planos                                           ///\n");
    printf("///           0. Voltar                                                   ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
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

    fp = fopen("planos.txt", "ab");
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
    } else {
        planos = cadastrar_fin();
        regravarplanos(planos);
        free(planos);
    }
    // free(cod);
}

void regravarplanos(financas* planos){
    int achou;

    FILE* fp;
    financas* planoLido;

    planoLido = (financas*)malloc(sizeof(financas));
    fp = fopen("planos.txt", "r+b");
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
    fp = fopen("planos.txt", "rb");
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
    // cod = (int*)malloc(sizeof(int));
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

void edit_planos(void) {
    int op;
    
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =   Editar Planos   = = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|              Informe o plano que deseja editar :                      |\n");
    scanf("%d",&op);
    //Aqui printaria os planos pra escolher qual deseja editar
    printf("|                                                                       |\n");
    printf("|           1. Plano Família                                            |\n");
    // mostrar beneficios
    printf("|           2. Plano Individual                                         |\n");
    // mostrar beneficios
    printf("|           3. Plano Amigos                                             |\n");
    // mostrar beneficios
    printf("|           4. Plano Premium                                            |\n");
    // mostrar beneficios
    printf("|           5. Plano Daily                                              |\n");
    // mostrar beneficios
    printf("|                                                                       |\n");
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void excluir_planos(void) {
    int op;
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =   Excluir Planos  = = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o plano que deseja excluir:                            |\n");
    scanf("%d", &op);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void exibirPlanos(financas* planos) {

	if (planos == NULL) {
		printf("\n= = = Plano não encontrado = = =\n");
	} else {
		printf("\n= = = Plano Cadastrado = = =\n");		
		printf("Titulo do plano: %s\n", planos->titulo);
        printf("Código do plano: %d\n", planos->codigo);
		printf("Preço: %.2f\n", planos->preco);
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


void pesquisarPlano(void) {
    
    financas* planos;    
    int cod;

    cod = listar_planos();
    planos = pesquisa_planos(cod);
    exibirPlanos(planos);
	free(planos);
   // free(cod);
}


int listar_planos(void) {
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
   /* printf("|                                                                       |\n");
    printf("|           1. Plano Família                                            |\n");
    // mostrar beneficios
    printf("|           2. Plano Individual                                         |\n");
    // mostrar beneficios
    printf("|           3. Plano Amigos                                             |\n");
    // mostrar beneficios
    printf("|           4. Plano Premium                                            |\n");
    // mostrar beneficios
    printf("|           5. Plano Daily                                              |\n");
    // mostrar beneficios
    */
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
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
    
    
    return planos; 

}

void telaErrorArquivofin(void) {
	system("clear||cls");  
	printf("\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("///                                                                       ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = = = = = = =  Ops! Ocorreu em erro = = = = = =             ///\n");
	printf("///           = = =  Não foi possível acessar o arquivo = = =             ///\n");
	printf("///           = = = = com informações sobre os planos = = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///           = =  Pedimos desculpas pelos inconvenientes = =             ///\n");
	printf("///           = = =  mas este programa será finalizado! = = =             ///\n");
	printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
	printf("///                                                                       ///\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
};
