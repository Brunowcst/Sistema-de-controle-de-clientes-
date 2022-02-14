#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funcionario.h"
#include "bibliotecascc.h"

typedef struct func funcionario;

void mod_MenuFuncionarios(void) {
    system("clear||cls");
    printf("\n");
    printf(" _____________________________________________________________________________\n");
    printf("|                                                                             |\n");
    printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                 |\n");
    printf("|             = = = = = = = = MENU FUNCIONÁRIOS = = = = = = =                 |\n");
    printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                 |\n");
    printf("|                                                                             |\n");
    printf("|             1. Cadastrar funcionários                                       |\n");
    printf("|             2. Editar funcionários                                          |\n");
    printf("|             3. Pesquisar funcionários                                       |\n");
    printf("|             4. Excluir funcionários                                         |\n");
    printf("|             5. Listar funcionários                                          |\n");
    printf("|             0. Voltar                                                       |\n");
    printf("|                                                                             |\n");
    printf("|                                                                             |\n");
    printf("|_____________________________________________________________________________|\n");
    printf("\n");
}


void modulo_funcionario(void) {
    char op;
    do {
        mod_MenuFuncionarios();   
        printf("Escolha a opção desejada:\n");
        scanf("%c", &op);
        getchar();
        switch(op){
            case '1' : cadastrar_func();
                break;
            case '2' : edit_func();
                break;
            case '3' : pesquisar_func();
                break;
            case '4' : excluir_func();
                break;
            case '5' : listar_func();
                break;
            default:
                printf("Escolha uma opção válida...\n");
                sleep(2);
                break;
            } 
        } while (op!='0');
}

void cadastrar_func(void) {
    funcionario* fc;

    fc = cadastro_func();
    gravarFuncionario(fc);
    free(fc);
}

void gravarFuncionario(funcionario *fc) {
    FILE* fp;

    fp = fopen("func.dat", "ab");
    if (fp == NULL){
        telaErrorArquivofc();
        }
    fwrite(fc, sizeof(funcionario),1 , fp);
    fclose(fp);
}

void pesquisar_func(void) {
    
    funcionario* fc;    
    char* cpf;

    cpf = telaPesquisarFunc();
    fc = pesquisa_func(cpf);
    exibirFuncionario(fc);
	free(fc); 
	free(cpf);
}

funcionario *pesquisa_func(char* cpf){
    FILE* fp;
    funcionario* fc;
    
    fc = (funcionario*)malloc(sizeof(funcionario));
    fp = fopen("func.dat", "rb");
    if (fp == NULL){
        telaErrorArquivofc();
    }
    while(fread(fc, sizeof(funcionario), 1, fp)){
        
        if((strcmp(fc->cpf, cpf) == 0) && (fc->status == 1)){
            fclose(fp);
            return fc;
        }
    }
    fclose(fp);
    return NULL;
}

void exibirFuncionario(funcionario* fc) {

	if (fc == NULL) {
		printf("\n= = = Funcionário não encontrado = = =\n");
	} else {
		printf("\n= = = FUNCIONÁRIO CADASTRADO = = =\n");		
		printf("Nome do funcionário: %s\n", fc->nome);
        printf("CPF: %s\n", fc->cpf);
		printf("Endereço eletrônico: %s\n", fc->email);
		printf("Data de Nasc: %d/%d/%d\n", fc->dia, fc->mes, fc->ano);
		printf("Celular: %s\n", fc->cell);
		printf("Status: %d\n", fc->status);
        printf("Cargo: ");
        if (fc->cargo=='1'){
             printf("Administrativo\n");
        }else{ printf("Atendente\n");}
	}
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
}


char* telaPesquisarFunc(void) {
	char* cpf;

	cpf = (char*) malloc(12*sizeof(char));
	system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = =   PESQUISAR FUNCIONÁRIOS    = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|    Informe o CPF(Apenas números) do funcionário que deseja encontrar: |\n");
	scanf("%[0-9]", cpf);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|_______________________________________________________________________|\n");
	printf("\n");
	sleep(2);
  	return cpf;
}


void regravarfunc(funcionario* fc){
    int ok;

    FILE* fp;
    funcionario* fc_Read;

    fc_Read = (funcionario*)malloc(sizeof(funcionario));
    fp = fopen("func.dat", "r+b");
    if (fp == NULL){
        telaErrorArquivofc();
        }
    ok = 0;
    while (fread(fc_Read, sizeof(funcionario),1 , fp) && !ok){
        
        if (strcmp(fc_Read->cpf, fc->cpf)== 0){
            ok = 1;
            fseek(fp, -1*sizeof(funcionario), SEEK_CUR);
        fwrite(fc, sizeof(funcionario), 1, fp);        
        }
        
    }
    fclose(fp);
    free(fc_Read);
}


void edit_func(void) {
    funcionario* fc;
    char* cpf;

    cpf = telaEdit_func();
    fc = pesquisa_func(cpf);
    if (fc == NULL){
        printf("= = = Funcionário não encontrado... = = =\n");
    } else {
        fc = cadastro_func();
        regravarfunc(fc);
        free(fc);
    }
    free(cpf);
}


char* telaEdit_func(void) {
 	char* cpf;

	cpf = (char*) malloc(12*sizeof(char));
	system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|      = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =      |\n");
    printf("|      = PESQUISE PELO FUNCIONÁRIO QUE DESEJA ALTERAR OS DADOS:  =      |\n");
    printf("|      = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =      |\n");
    printf("|                                                                       |\n");
    printf("|    Informe o CPF(Apenas números) do funcionário que deseja encontrar: |\n");
	scanf("%[0-9]", cpf);
	getchar();
	printf("|                                                                       |\n");
	printf("|                                                                       |\n");
	printf("|_______________________________________________________________________|\n");
	printf("\n");
	sleep(2);
  	return cpf;
}


void excluir_func(void) {
    funcionario* fc;
    char* cpf;

    cpf = telaExcluir_func();
    fc = (funcionario*)malloc(sizeof(funcionario));
    fc= pesquisa_func(cpf);

    if(fc == NULL){
        printf("= = = Não foi possível encontrar o funcionário!!! = = =");
    } else {
        fc->status = 0;
        regravarfunc(fc);
        free(fc);
    }
    free(cpf);
}






char* telaExcluir_func(void) {

    char* cpf;
    cpf = (char*)malloc(12*sizeof(char));
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________ \n");
    printf("|                                                                       |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|          = = = = = = =  EXCLUIR FUNCIONÁRIOS = = = = = =              |\n");
    printf("|          = = = = = = = = = = = = = = = = = = = = = = = =              |\n");
    printf("|                                                                       |\n");
    printf("|        Informe o CPF do funcionário que deseja excluir:               |\n");
    scanf("%[0-9]",cpf);
    getchar();
    printf("|                                                                       |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    printf("\n");

    return cpf;
}


funcionario *cadastro_func(void) {
    funcionario* fc;

    fc = (funcionario*) malloc(sizeof(funcionario));
    system("clear||cls");
    printf("\n");
    do {
    printf("|           * Nome completo:                                            |\n");
    scanf("%50[^\n]", fc->nome);
    getchar();
    } while (!validarNome(fc->nome));
    
    do {
    printf("|           * CPF (Apenas números):                                     |\n");
    scanf("%11[^\n]",fc->cpf);
    getchar();
    } while(!validarCPF(fc->cpf));
    
    do{
    printf("|           * Data sua data de nascimento:                              |\n");
    printf("| Informe o dia:                                                        |\n");
    scanf("%d", &fc->dia); 
    printf("| Informe o mês:                                                        |\n");
    scanf("%d", &fc->mes);
    printf("| Informe o ano:                                                        |\n");
    scanf("%d", &fc->ano);
    getchar();
    } while(!validaData(fc->dia, fc->mes, fc->ano));

    do{
    printf("|           * Celular ((DDD)número):                                    |\n");
    scanf("%11[^\n]", fc->cell);
    getchar();
    } while (!validacell(fc->cell));

    do{
    printf("|           * E-mail:                                                   |\n");
    scanf("%50[^\n]", fc->email);
    getchar();
    } while (!validEmail(fc->email));

    do{
    printf("|           * Cargo:                                                    |\n");
    printf("|           1. Administrativo                                           |\n");
    printf("|           2. Atendente                                                |\n");
    scanf("%c",&fc->cargo);
    getchar();
    }while(!ehDigito(fc->cargo));

    fc->status = 1;

    return fc;
};

void telaErrorArquivofc(void) {
	system("clear||cls");  
	printf("\n");
	printf("_____________________________________________________________________________\n");
	printf("|                                                                            |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|             = = = = = = =  Ops! Ocorreu em erro = = = = = =                |\n");
	printf("|             = = =  Não foi possível acessar o arquivo = = =                |\n");
	printf("|             = = = com informações sobre os funcionarios = =                |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|             = =  Pedimos desculpas pelos inconvenientes = =                |\n");
	printf("|             = = =  mas este programa será finalizado! = = =                |\n");
	printf("|             = = = = = = = = = = = = = = = = = = = = = = = =                |\n");
	printf("|____________________________________________________________________________|\n");
	printf("\n\nTecle ENTER para continuar!\n\n");
	getchar();
	exit(1);
};


//LISTAGEM


void listar_func(void) {

    char op;
    do {
        subMod_listarFunc();
        printf("\t\t>>> Escolha a opção desejada: \n");
        scanf("%c", &op);
        getchar();

        switch(op){
            case '1' : listar_todosFunc();
                break;
            case '2' : listar_pcargo();
                break;
            case '3' : listar_ordemalphaFunc();
                break;
            default:
                printf("Escolha uma opção válida...\n");
                sleep(2);
                break;
        }
    } while (op != '0');
}

void subMod_listarFunc(void){
    system("clear||cls");
    printf("\n");
    printf(" _______________________________________________________________________\n");
    printf("|                                                                       |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
    printf("|           = = = = = = = LISTAR FUNCIONÁRIOS = = = = = = =             |\n");
    printf("|           = = = = = = = = = = = = = = = = = = = = = = = =             |\n");
    printf("|                                                                       |\n");
    printf("|           1. Listar todos                                             |\n");
    printf("|           2. Listar por cargo                                         |\n");
    printf("|           3. Listar por ordem alfabética                              |\n");
    printf("|           0. Voltar                                                   |\n");
    printf("|                                                                       |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
}

void listar_todosFunc(void){
    FILE* fp;
    funcionario* fc;
    fc = ( funcionario*) malloc(sizeof(funcionario));

    fp = fopen("func.dat","rb");
    if (fp == NULL){
        printf("Erro na abertura do arquivo\n!");
        exit(1);
        }

    printf("\n= = = Relatório de todos os funcionários = = =\n");
    while(fread(fc, sizeof(funcionario), 1, fp)) {        
        exibirlistaFunc(fc);
        }

    fclose(fp);
    free(fc);
}


void exibirlistaFunc(funcionario* fc) {

	if (fc == NULL) {
		printf("\n= = = Funcionário não encontrado = = =\n");
	} else {
		printf("\n= = = FUNCIONÁRIO CADASTRADO = = =\n");		
		printf("Nome do funcionário: %s\n", fc->nome);
        printf("CPF: %s\n", fc->cpf);
		printf("Endereço eletrônico: %s\n", fc->email);
		printf("Data de Nasc: %d/%d/%d\n", fc->dia, fc->mes, fc->ano);
		printf("Celular: %s\n", fc->cell);
		printf("Status: %d\n", fc->status);
        printf("Cargo: ");
        if (fc->cargo=='1'){
            printf("Administrativo\n");
        }else{ printf("Atendente\n");}

        printf("\t\t >>> Tecle enter para exibir o próximo:\n");
        getchar();
	}
	
}


void listar_pcargo(void) {
    FILE* fp;
    funcionario* fc;
    char n_lido;

    fc = (funcionario*) malloc(sizeof(funcionario));

    fp = fopen("func.dat","rb");
    if (fp == NULL){
        printf("\t\tErro na abertura do arquivo!\n");
        exit(1);
    }
    do {
        system("clear||cls");
        printf("\n");
        printf(" _______________________________________________________________________\n");
        printf("|                                                                       |\n");
        printf("|                Relatório de funcionários por cargo:                   |\n");
        printf("|                                                                       |\n");
        printf("|                                                                       |\n");
        printf("|               1. Administrativo.                                      |\n");
        printf("|               2. Atendente.                                           |\n");
        printf("|                                                                       |\n");
        printf("|                                                                       |\n");
        printf("|        >>> Informe o Nº do tipo de funcionário que deseja listar:     |\n");
        printf("|_______________________________________________________________________|\n");
        printf("\t\n");
        scanf("%c", &n_lido);
        getchar();
    } while(!ehDigito(n_lido));
    

    while(fread(fc, sizeof(funcionario), 1, fp)) {
        if (fc->cargo == n_lido){
            exibirlistaFunc(fc);
        }
    }
    fclose(fp);
    free(fc);
}




void listar_ordemalphaFunc(void) {

    FILE* fp;
    //int tam;
    char linhaFc[256];
    funcionario* novoFc;
    funcionario* listFc;

    fp = fopen("func.dat","rb");
    if (fp == NULL){
        printf("\t\t>>> Erro na abertura do arquivo!\n");
        exit(1);
    }

    listFc = NULL;
    while(fgets(linhaFc,256,fp)){
		novoFc = (funcionario*) malloc(sizeof(funcionario));
		strcpy(novoFc->nome, linhaFc);
      if (listFc == NULL) {
		listFc = novoFc;
        novoFc->proxFc = NULL;
	  }else if (strcmp(novoFc->nome,listFc->nome) < 0) {
        novoFc->proxFc = listFc;
        listFc = novoFc;
      
      }else {
        funcionario* anterFc = listFc;
        funcionario* atualFc = listFc->proxFc;
        while ((atualFc != NULL) && strcmp(atualFc->nome,novoFc->nome) < 0) {
            anterFc = atualFc;
            atualFc = atualFc->proxFc;
        }
        anterFc->proxFc = novoFc;
        novoFc->proxFc = atualFc;
        }
	}
	fclose(fp);

    // Listagem de clientes ordem alfabética
   	novoFc = listFc;
	while (novoFc != NULL) {
		exibirlistaFunc(novoFc);
		novoFc = novoFc->proxFc;	
	}

    // Liberar memória
	novoFc = listFc;
	while (listFc != NULL) {
		listFc = listFc->proxFc;
		free(novoFc->nome);
		free(novoFc);
		novoFc = listFc;
    }
}
