#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int mochila(int itens, int capacidade,int objetos[itens][2]){
    int resultado[itens+1][capacidade+1];
    int a, b;
    int aux1, aux2;
    for( aux1 = 0; aux1 <= capacidade;aux1++){
        resultado[0][aux1] = 0;
        for( aux2 = 1; aux2 <= itens; aux2++){
            a = resultado[aux2-1][aux1];
            if(objetos[aux2][1] > aux1){
                b = 0;
            }
            else{
                b = (resultado[aux2-1][aux1-objetos[aux2][1]] + objetos[aux2][0]);
            }
            if(a>b){
                resultado[aux2][aux1] = a;
            }
            else{
                resultado[aux2][aux1] = b;
            }
        }
    }
    return resultado[itens][capacidade];
}
