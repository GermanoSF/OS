#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define Numero_T 3
#define N 100

void* imprimir_id(void* arg) {

    int valor = *(int*)arg;
    
    for(int i=0;i<N;i++){
    
    	printf("ID: %i\n",valor);
    	
    }
    
    return NULL;
    
}

int main() {
    pthread_t threads[Numero_T];
    int ids[Numero_T];
    
    for (int i=0;i<Numero_T;i++){
    
    	ids[i]=i;
    
    }
    
    for(int i=0;i<Numero_T;i++){
    
    	pthread_create(&threads[i],NULL,imprimir_id,&ids[i]);
    
    }
    
    for(int i=0;i<Numero_T;i++){
    
    	pthread_join(threads[i], NULL);
    
    }

    return 0;
}
