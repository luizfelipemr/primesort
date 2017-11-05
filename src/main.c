/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 int prime_number(int var){

   int cond;
   float aux2, aux;

   if(var==1 || var ==0){
     return 0;
   }

   //Fermat primality test
   //This test have pseudoprimes, like 561

   else{

     aux = (var%2)+1;
     aux2 = var-1;
     cond = (int)pow(aux,aux2);

     if(cond%var==1){
       return 1;
     }

   }

 }

int main() {

  int x;

  FILE *pipe;
  pipe = popen("sort -g -n","w");

  while(1){


    scanf("%d", &x);

    if(x<0){
      break;
    }

    else{
      if(prime_number(x)==0){
        fprintf(pipe, "%d\n",x);
      }
    }
  }

  pclose(pipe);

  return 0;
}
