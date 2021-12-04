///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema Controle de Clientes                   ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funcionario.h"
#include "clientes.h"
#include "financas.h"
#include "bibliotecascc.h"


/////
// Assinatura das funções
void sobre(void);
void equipe(void);
void menuPrincipal(void);


//////
// Programa principal

int main(void) {
    int op;
    do {
        menuPrincipal();
        printf("Escolha a opção desejada:\n");
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1 : 
                modulo_funcionario();
                break;
            case 2 :
                modulo_clientes();
                break;
            case 3 :
                modulo_financas();
                break;
            case 4 :
                sobre();
                equipe();
                break;
            }
    
    } while (op != 0);      
    
    return 0;
}

/////
// Funções

void sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Controle de Clientes                ///\n");
    printf("///                   Adapted from @flgorgonio - 2021.2                     ///\n");
    printf("///                     https://github.com/flgorgonio                       ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Sistema de Controle de Clientes = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa exemplo utilizado na disciplina DCT1106 - Programação, para   ///\n");
    printf("///  fins didáticos de ilustração. O programa contém os principais módulos  ///\n");
    printf("///  e funcionalidades que serão exigidos na avaliação dos projetos a serem ///\n");
    printf("///  desenvolvidos pelos alunos ao longo da disciplina. Serve como um guia  ///\n");
    printf("///  de consulta e referência para o desenvolvidos dos demais projetos.     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Sistema de Controle de Clientes                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = Sistema de Controle de Clientes= = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///     Este projeto exemplo foi desenvolvido por:                          ///\n");
    printf("///     Aluno: Bruno Costa                                                  ///\n");
    printf("///     E-mail: bruno.costa.079@ufrn.edu.br                                 ///\n");
    printf("///     Aluno: David Emanoel                                                ///\n");
    printf("///     E-mail: david.emanoel.706@ufrn.edu.br                               ///\n");
    printf("///     Link: https://github.com/Brunowcst/Sistema-de-controle-de-clientes- ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void menuPrincipal(void) {
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///          ===================================================          ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///          = = = =  Sistema de controle de clientes  = = = = =          ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///          ===================================================          ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =  Menu Principal = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Módulo Funcionários                                      ///\n");
    printf("///           2. Módulo Clientes                                          ///\n");
    printf("///           3. Módulo Finanças                                          ///\n");
    printf("///           4. Sobre                                                    ///\n");
    printf("///           0. Sair                                                     ///\n");
    printf("///                                                                       ///\n");
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

}
