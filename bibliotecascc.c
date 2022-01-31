#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "bibliotecascc.h"



/*
Baseado no código de:
flgorgonio
https://github.com/flgorgonio/linguasolta_2020.2
*/

int bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}


int validaData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (bissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || 
             mm == 9 || mm == 11) {
               maiorDia = 30;
  } else
    maiorDia = 31;

  if (dd < 1 || dd > maiorDia)
    return 0;

  return 1;
}

//  Valida celular
/*
Baseado no código de:
flgorgonio
https://github.com/flgorgonio/linguasolta_2020.2
*/

int validacell(char* fone){
  
  int tam;
  tam = strlen(fone);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i])) {
        return 0;
    }
  }
  return 1;
}

//validação de digitos: Baseado no código de:flgorgonio

int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}

int ehDigito2(int c) {
  if (c >= 0 && c <= 9) {
    return 1;
  } else {
    return 0;
  }
}


// Valida e-mail:



// int validEmail(const char *email1){
//   int tam = strlen(email1);
//   for (int i=0; i <tam; i++){
//     if (email1[i] != "[azAz0-9]@[azAz0-9].[azAZ]"){
//       return 0;
//     }
//   }
//   return 1;
// }
//[A-Za-z0-9._@A-Za-z.] ou [azAz0-9]@[azAz0-9].[azAZ]


int validEmail(const char *email1){
  int tam = strlen(email1);
  //char *em = email1;
  for (int i=0; i <tam ; i++){
    if (ehCharemail(email1[i])){    
    return 1;
    }
  }
  return 0;
}

//Valida nomes:Baseado no código de:flgorgonio


int testeLetra(char c) {
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;  
  } else {
    return 0;
    }
}



int ehChar(char c){

if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else if (c == ' '){
    return 1;
  } else {
    return 0;
  }
}

int ehCharemail(char c){

if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
    return 1;
  // } else if (c == ' '){
  //   return 1;
  } else if (c > '0' && c < '9'){
    return 1;
  } else if ( c == '@' || c == '.' || c == '_'){
    return 1; 
  }
  else {
    return 0;
  }
}

int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!ehChar(nome[i])) {
      return 0;
    }
  } 
	return 1;
}

// Valida navegação

int validNaveg(char *op){
  int tam = strlen(op);
  if (tam!=2){
    return 0;
  }
  if (ehDigito(op[0])){
    return 1; 
  }   
  return 1;
}

//valida cpf : Código de:
//https://gist.github.com/eduardoedson/

int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; 
    else
    {
        ///digito 1 
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--)
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0;
        else
        ///digito 2
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--)
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0;
        }
    }
    return 1;
}