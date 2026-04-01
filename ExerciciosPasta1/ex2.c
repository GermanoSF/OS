#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Estrutura para passar dados para a thread
typedef struct {
    char nome;
} ThreadData;

void* contar(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    for (int i = 1; i <= 5; i++) {
        printf("Thread %c: %d\n", data->nome, i);
        sleep(1); // Pausa de 1 segundo
    }
    
    return NULL;
}

int main() {
    pthread_t tA, tB;
    ThreadData d1 = {'A'}, d2 = {'B'};

    // Criando as duas threads
    pthread_create(&tA, NULL, contar, &d1);
    pthread_create(&tB, NULL, contar, &d2);

    // Esperando ambas terminarem
    pthread_join(tA, NULL);
    pthread_join(tB, NULL);

    printf("Execução finalizada.\n");
    return 0;
}
