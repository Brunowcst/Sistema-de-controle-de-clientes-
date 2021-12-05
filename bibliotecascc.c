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

int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}


// Valida e-mail:

int validEmail(char *email1){
  int tam = strlen(email1);
  char *em = email1;
  for (int i=0; i < tam; i++){
    if ( em == "[a-zA-Z@._0-9^\n]"){
      return 1;
    } else {
      return 0;
    }
  }
}


//Valida nomes:

int validaNomes(char *onome){
int tam = strlen(onome);
char nom;
if (tam > 50){
    return 0;
}
for (int i=0; i < tam; i++){

  nom = onome[i];
  if (nom == "[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ^\n]"){
    return 1;
  } else{
    return 0;
  }

}
}
