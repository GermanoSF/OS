#include <stdio.h>
#include <pthread.h>

// Variável global compartilhada
int contador = 0;

void* incrementar(void* arg) {
    for (int i = 0; i < 1000; i++) {
        contador++; 
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Criação das duas threads
    pthread_create(&t1, NULL, incrementar, NULL);
    pthread_create(&t2, NULL, incrementar, NULL);

    // Aguarda a conclusão
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Valor final do contador: %d\n", contador);
    printf("Valor esperado: 2000\n");

    return 0;
}
