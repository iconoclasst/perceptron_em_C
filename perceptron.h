#define PERCEPTRON_H

typedef struct {
    float *w;
    float b;
    float lr;
    int n_features;
} Perceptron;

Perceptron *criar_percep(int n_features, float lr);
void free_percep(Perceptron *p);

int predict(Perceptron *p, float *x);
void train(Perceptron *p, float **x, int *y, int samples, int epochs);

