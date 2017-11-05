/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//Sieve of Eratosthenes
int prime(int var){

  int i, aux, count=0;
  aux = var+1;

  if(var==0 || var==1){
    return 0;
  }

  else{

    for(i=1;i<aux;i++){

      if(var%i==0){
        count++;

        if(count==3){
          return 0;
        }
      }
    }
  }

  if(var == 2){
    return 1;
  }

  return 1;
}


//Implementation of Fermat theorms failed

//Code based from https://www.programminglogic.com/testing-if-a-number-is-prime-efficiently/
//Fermat primality test

// int module(int a, int b, int c){
//     int result = 1;
//
//     while (b>0){
//         result *= a;
//         result %= c;
//         b--;
//     }
//
//     return result;
// }
//
// int prime(int n){
//     int i;
//     int x;
//
//     if (n==2)
//         return 1;
//
//     for (i=0;i<10;i++){
//         x = rand()%n;
//         if (x==0||x==1)
//             x++;
//         if (module(x,n-1,n)!=1)
//             return 0;
//     }
//
//     return 1;
// }


 // int prime_number(int var){
 //
 //   unsigned int cond;
 //   unsigned int aux2, aux;
 //
 //   if(var==1 || var ==0 || var<0){
 //     return 0;
 //   }
 //
 //   //Fermat primality test
 //   //This test have pseudoprimes, like 561
 //
 //   else{
 //
 //    aux = var%2+1;
 //
 //     if((upower(aux,var-1) % var) == 1){
 //       return 1;
 //     }
 //
 //   return 0;
 //
 //   }


int main() {

  int cand;

  FILE *pipe;
  pipe = popen("sort -n -r", "w");

  while(1){

    scanf ("%d\n", &cand);

    if(cand<0){
      break;
    }

    else{

      if(prime(cand)==0){
        fprintf (pipe, "%d\n", cand);
      }
    }
  }

  pclose (pipe);

  return 0;
}
