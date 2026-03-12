#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

Perceptron *criar_percep(int n_features, float lr) {
    Perceptron *p = malloc(sizeof(Perceptron));
    p->n_features = n_features;
    p->lr = lr;
    p->b = 0.0;
    p->w = malloc(sizeof(float) * n_features);
    
    int i;
    for (i = 0; i<n_features; i++) {
        p->w[i] = 0.0;
    }

    return p;
}

void free_percep(Perceptron *p) {
    free(p->w);
    free(p);
}

int predict(Perceptron *p, float *x) {
    float result = 0.0;
    int i;
    
    for(i = 0; i<p->n_features; i++) {
        result += p->w[i] * x[i];
    }

    result += p->b;

    if (result >= 0)
        return 1;
    else
        return 0;
}

void train(Perceptron *p, float **X, int *y, int samples, int epochs) {
    int e, i, j;

    for (e=0; e<epochs; e++){
        for(i = 0; i<samples; i++) {
            int y_pred = predict(p, X[i]);
            int erro = y[i] - y_pred;
            
            for (j = 0; j<p->n_features; j++) {
                p->w[j] += p->lr * erro * X[i][j];
            } 
            p->b += p->lr * erro;
        }
    }
    
}


