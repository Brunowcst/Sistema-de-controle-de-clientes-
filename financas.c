#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "financas.h"


void modulo_financas(void) {
    int op;
    do {
        mod_MenuFinancas();   
        printf("Escolha a opção desejada:\n");
        scanf("%d", &op);
        getchar();
        switch(op){
        case 1 : listar_planos();
            break;
        case 2 : cadastro_planos();
            break;
        case 3 : edit_planos();
            break;
        case 4 : excluir_planos();
            break;
            }
             
        } while (op!=0);
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
    system("clear||cls");
    char titulo[51];
    float preco;
    char beneficios[51];
    //int vitalidade; //tempo de validade do plano;
    
    
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Cadastrar Planos = = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|                     * Insira os dados abaixo *                        |\n");
    printf("|                                                                       |\n");
    printf("|           * Título do plano:                                          |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", titulo);
    getchar();
    printf("|           * Preço em R$: (Apenas números):                            |\n");
    scanf("%f",&preco);
    getchar();
    printf("|           * Benefícios do plano:                                      |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ*0-9]", beneficios);
    getchar();
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
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

void listar_planos(void) {
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Listagem de Planos   = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
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
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}