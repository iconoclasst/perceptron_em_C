#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

#define N 4
#define FEATURES 3
#define EPOCHS 50

int main (void)
{

    float X[N][FEATURES] = {{15,50, 130}, {17, 55, 145}, {30, 80, 160}, {35, 90, 170}};

    int y_train[N] = {0, 0, 1, 1};
    float *X_train[N];
    
    int i;
    for(i = 0; i<N; i++) {
        X_train[i] = X[i];
    }

    Perceptron *p = criar_percep(FEATURES, 0.0001);

    train(p, X_train, y_train, N, EPOCHS);
    
    printf("Pesos finais: \n");
    
    int j;
    for(j = 0; j<FEATURES; j++) {
        printf("w%d = %.2f\n", j, p->w[i]);
    }

    printf("b = %.2f\n", p->b);
    
    float teste[FEATURES] = {20, 60, 150};
    int classe = predict(p, teste);

    printf("Classe prevista: %d\n", classe);

   
    free_percep(p);
 
return 0;
}

