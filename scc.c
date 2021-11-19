///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema Controle de Clientes                   ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////
// Assinatura das funções
void sobre(void);
void equipe(void);
void menuPrincipal(void);

//Módulo Funcionarios

void mod_MenuFuncionarios(void);

//Criar as funções de CRUD do módulo funcionários...

//Módulo clientes

void mod_MenuClientes(void); 

void pesquisar_clientes(void);
void cadastro_clientes(void);
void edit_clientes(void);
void excluir_clientes(void);

//Módulo Finanças

void mod_MenuFinancas(void);

void cadastro_planos(void);
void edit_planos(void);
void excluir_planos(void);
void listar_planos(void);

//Módulo funcionários
void cadastro_func(void);
void pesquisar_func(void);
void edit_func(void);
void excluir_func(void);


/////
// Programa principal

int main(void) {
    sobre();
    equipe();
    menuPrincipal();
    
    mod_MenuFuncionarios();
     cadastro_func();
     pesquisar_func();
     edit_func();
     excluir_func();

    mod_MenuClientes();
     pesquisar_clientes();
     cadastro_clientes();
     edit_clientes();
     excluir_clientes();  
    
    mod_MenuFinancas();
     listar_planos();
     cadastro_planos();
     edit_planos();
     excluir_planos();
    

      
    
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
    equipe();
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
    menuPrincipal();
    printf("\n");
}

void menuPrincipal(void) {
    system("clear||cls");
    int op;
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
    printf("///           0. Sair                                                     ///\n");
    printf("///           Escolha a opção desejada:                                   ///\n");
    scanf("%d", &op);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

switch(op){
case 1 : mod_MenuFuncionarios();
    break;
case 2 : mod_MenuClientes();
    break;
case 3 : mod_MenuFinancas();
    break;
case 0 : sobre();
    break;
default : menuPrincipal();
        break;
    }
}

void mod_MenuFuncionarios(void) {
    system("clear||cls");
    int op;
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = Menu Funcionários = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar Funcionarios                                   ///\n");
    printf("///           2. Editar Funcionarios                                      ///\n");
    printf("///           3. Pesquisar Funcionarios                                   ///\n");
    printf("///           4. Excluir Funcionarios                                     ///\n");
    printf("///           0. Sair                                                     ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada:                                   ///\n");
    scanf("%d", &op);
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    switch(op){
    case 1 : cadastro_func();
        break;
    case 2 : edit_func();
        break;
    case 3 : pesquisar_func();
        break;
    case 4 : excluir_func();
        break;
    case 0 : menuPrincipal();
        break;
    default : mod_MenuFuncionarios();
        break;
        }
}

void cadastro_func(void) {
    system("clear||cls");
    char nome[51];
    char cpf[12];
    char nasc[11];
    char cell[12];
    char email[51];
    //int category;


    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = =  Cadastrar Funcionário  = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|                     * Insira os dados abaixo *                        |\n");
    printf("|                                                                       |\n");
    printf("|           * Nome Completo:                                            |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|           * Data de Nascimento (dd/mm/aa):                            |\n");
    scanf("%[0-9]/", nasc);
    getchar();
    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%[0-9]()", cell);
    getchar();
    printf("|           * E-mail:                                                   |\n");
    scanf("%[A-Za-z@._0-9]", email);
    getchar();
   /*printf("|           * Informe o plano desejado:                                 |\n");
    printf("|               1. Cliente comum.                                       |\n");
    printf("|               2. Cliente Premium.                                     |\n");
    scanf("%d", &category);                                      */
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

}

void pesquisar_func(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = =  Pesquise Funcionários  = = = = = =               |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja encontrar:                 |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void edit_func(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Editar funcionários  = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja alterar os dados:          |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}
void excluir_func(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Excluir funcionários = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do funcionário que deseja escluir:               |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}

void mod_MenuClientes(void) {
    system("clear||cls");
    int op;
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                       ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =   Menu Clientes   = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                       ///\n");
    printf("///           1. Cadastrar Clientes                                       ///\n");
    printf("///           2. Editar Clientes                                          ///\n");
    printf("///           3. Pesquisar Clientes                                       ///\n");
    printf("///           4. Excluir clientes                                         ///\n");
    printf("///           0. Sair                                                     ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada:                                   ///\n");
    scanf("%d", &op);
    getchar();   
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n"); 

    switch(op){
    case 1 : cadastro_clientes();
        break;
    case 2 : edit_clientes();
        break;
    case 3 : pesquisar_clientes();
        break;
    case 4 : excluir_clientes();
        break;
    case 0 : menuPrincipal();
        break;
    default : mod_MenuClientes();
        break;
    }   
}


void mod_MenuFinancas(void) {
    system("clear||cls");
    int op;
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
    printf("///           0. Sair                                                     ///\n");
    printf("///                                                                       ///\n");
    printf("///           Escolha a opção desejada:                                   ///\n");
    scanf("%d", &op); 
    getchar();
    printf("///                                                                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
    
    switch(op){
    case 1 : listar_planos();
        break;
    case 2 : cadastro_planos();
        break;
    case 3 : edit_planos();
        break;
    case 4 : excluir_planos();
        break;
    case 0 : menuPrincipal();
        break;
    default : mod_MenuFinancas();
        break;
    }
}


/*

Essa função de cadastro de planos está estranho.
Deveríamos cadastrar um tipo de plano e, no módulo de funcionários vip, chamaria
esse plano como função...
Cadastrar planos seria algo em relação aos benefícios e informações.
O cadastro com informações pessoais(atual) não faz sentido com o cadastro de um plano...

Oque faria sentido é associar, em outro módulo, um plano X a um cliente X...

As outras funções abaixo, Como editar e excluir, também se aplicam a essa lógica. 
Ao invés de pesquisar planos por CPF (Coisa que não tem sentido), poderíamos pesquisar
utilizando outra coisa...

*/

void cadastro_planos(void) {
    system("clear||cls");
    char titulo[51];
    float preco;
    char beneficios[51];
    //int vitalidade[11]; //tempo de validade do plano;
    
    
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
    printf("|           * Preço: (Apenas números):                                     |\n");
    scanf("%f",&preco);
    getchar();
    printf("|           * Benefícios do plano:                                      |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ*0-9]", beneficios);
    getchar();
    /*printf("|           * Informe o período:                                      |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ*0-9]", vitalidade);
    */
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

/*

Pensar melhor sobre essa opção de pesquisa de planos. 
Há sentido em pesquisar planos? 
Poderia ser só um "Listar planos" disponíveis...
Visto que não há lógica pesquisar planos por CPF, por exemplo...

*/

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

void cadastro_clientes(void) {
    system("clear||cls");
    char nome[51];
    char cpf[12];
    char nasc[11];
    char cell[12];
    char email[51];
    int category;


    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = Cadastrar clientes  = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|                     * Insira os dados abaixo *                        |\n");
    printf("|                                                                       |\n");
    printf("|           * Nome Completo:                                            |\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|           * Data de Nascimento (dd/mm/aa):                            |\n");
    scanf("%[0-9]/", nasc);
    getchar();
    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%[0-9]()", cell);
    getchar();
    printf("|           * E-mail:                                                   |\n");
    scanf("%[A-Za-z@._0-9]", email);
    getchar();
    printf("|           * Informe o plano desejado:                                 |\n");
    printf("|               1. Cliente comum.                                       |\n");
    printf("|               2. Cliente Premium.                                     |\n");
    scanf("%d", &category);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}


void edit_clientes(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =   Editar clientes   = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja alterar os dados:          |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}


void pesquisar_clientes(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = = Pesquise por clientes = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja encontrar:                 |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}


void excluir_clientes(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  Excluir  clientes  = = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do cliente que deseja excluir:                   |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");
}