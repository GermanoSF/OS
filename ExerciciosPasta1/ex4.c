#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* simular_download(void* arg) {
    printf("Iniciando download...\n");
    
    for (int i = 0; i <= 100; i += 10) {
        printf("Progresso: [%d%%]\n", i);
        
        usleep(500000); 
    }
    
    printf("Download concluído com sucesso!\n");
    return NULL;
}

int main() {
    pthread_t thread_download;

    // Criando a thread de download
    if (pthread_create(&thread_download, NULL, simular_download, NULL) != 0) {
        perror("Erro ao criar thread");
        return 1;
    }

    // O main espera o download terminar
    pthread_join(thread_download, NULL);

    return 0;
}
