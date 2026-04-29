#include <pthread.h>
#define NUM_THREADS 5
void* calcular_soma(void *matriz){
	
	for (int i=0;i<*matriz[0][0][0]){
	
		for (int j=0;j<*matriz[0][0][1];j++){
			
			for (int k=0;k<*matriz[0][0][2];k++){
				
				
				
			}
			
		}
		
	}
	
}

int main(){
	
	int ***matriz;
	int linhas,colunas,matrizes = 2;
	pthread_t thread[NUM_THREADS];
	
	printf("Digite o numero de linhas das matrizes: ");
	scanf("%i",&linhas);
	
	printf("Digite o numero de colunas das matrizes: ");
	scanf("%i",&colunas);
	
	if (colunas<3){
		
		printf("Colunas devem ter tamanho minimo de 3");
		
		return 0;
		
	}
	
	**matriz = (int ***)malloc(matrizes * sizeof(int **));
	
	for (int i = 0; i < matrizes; i++) {
        matriz[i] = (int **)malloc(linhas * sizeof(int *));
        for(int j=0;j<linhas;j++){
        	
        	matriz[i][j] = (int *)malloc(colunas * sizeof(int));
        	
        }
    }   
    
    matriz[0][0][0] = matrizes;
    matriz[0][0][1] = linhas;
    matriz[0][0][2] = colunas;

    
    for (int i=0;i<NUM_THREADS;i++){
    	
    	ids[i] = i;
    	pthread_create(&thread,NULL,calcular_soma,&matriz);
    	
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }    
	
	return 0;
	
}
