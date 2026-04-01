#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Para a função sleep()

// Função que será executada pela thread
void* contar_numeros(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Número: %d\n", i);
        sleep(1);// Pausa de 1 segundo
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    printf("Iniciando a thread...\n");

    // Cria a thread:
    // 1. Endereço do ID da thread
    // 2. Atributos (NULL para padrão)
    // 3. Função a ser executada
    // 4. Argumentos para a função (NULL neste caso)
    if (pthread_create(&thread_id, NULL, contar_numeros, NULL) != 0) {
        perror("Falha ao criar a thread");
        return 1;
    }

    // Aguarda a finalização da thread para que o programa principal não feche antes
    pthread_join(thread_id, NULL);

    printf("Thread finalizada.\n");

    return 0;
}
