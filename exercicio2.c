#include<unistd.h>
#include<stdio.h>

int main(){

	pid_t procID,procID2;
	int meu_valor;
	
	procID = fork();
	
	if (procID == 0){
		
		meu_valor = 1;
	
	}
	else{
		
		procID2 = fork();
		
		if (procID2 == 0){
		
			meu_valor = 2;
		
		}
		else{
		
			meu_valor = 0;
		
		}
	
	}

	
	for (int i=0; i < 50; i++){
	
		if (meu_valor == 0){
		
			printf("Pai\n");
		
		}
		
		if (meu_valor == 1){
		
			printf("Filho1\n");
		
		}
		
		if (meu_valor == 2){
		
			printf("Filho2\n");
		
		}
	
	}
	
}

