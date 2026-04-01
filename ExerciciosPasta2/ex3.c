#include <stdio.h>
#include <pthread.h>

#define Numero_T 8
#define N 1000000

// Variável global compartilhada
int contador = 0;

void* incrementar(void* arg) {
    for (int i = 0; i < N; i++) {
        contador++; 
    }
    return NULL;
}

int main() {
    pthread_t threads[Numero_T];
    
    for(int i=0;i<Numero_T;i++){
    
    	pthread_create(&threads[i],NULL,incrementar,NULL);
    
    }
    
    for(int i=0;i<Numero_T;i++){
    
    	pthread_join(threads[i], NULL);
    
    }
    
    printf("Valor esperado: %i\nValor real: %i",Numero_T*N,contador);

    return 0;
}
