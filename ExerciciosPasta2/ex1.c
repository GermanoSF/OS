#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

typedef struct{

	float base;
	float altura;

}Area_Perim;

void* calcular_area(void* arg) {
    
    Area_Perim* valores = (Area_Perim*) arg;
    
    printf("Area: %.2f",valores->base*valores->altura);
    
    return NULL;
    
}

void* calcular_perimetro(void* arg){

    Area_Perim* valores = (Area_Perim*) arg;
    
    printf("Perimetro: %.2f",valores->base*2+valores->altura*2);
    
    return NULL;

}

int main() {
    pthread_t thread_area,thread_perim;
    Area_Perim valores;
    
    printf("Area: ");
    scanf("%f",&valores.base);
    printf("\n");
    printf("Perimetro: ");
    scanf("%f",&valores.altura);
    
    // Criando a thread que calcula area
    pthread_create(&thread_area,NULL,calcular_area,&valores);
    // Criando a thread que calcula perimetro 
    pthread_create(&thread_perim,NULL,calcular_perimetro,&valores);
    
    // Esperando terminar
    pthread_join(thread_area, NULL);
    pthread_join(thread_perim, NULL);

    return 0;
}
