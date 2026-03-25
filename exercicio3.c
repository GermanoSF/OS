#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t f1;

    printf("Processo Pai PID = %d\n", getpid());

    for (int i = 0; i < 50; i++) {
        sleep(2);
        printf("Pai: %d\n", i);
    }

    printf("Processo Pai Terminou\n");

    f1 = fork();

    if (f1 == 0) {
      
        printf("Filho 1 PID = %d\n", getpid());

        for (int i = 100; i < 200; i++) {
            sleep(1);
            printf("Filho 1: %d\n", i);
        }

        printf("Processo Filho 1 Terminou\n");

        pid_t f2 = fork();

        if (f2 == 0) {
            
            printf("Filho 2 PID = %d\n", getpid());

            for (int i = 250; i < 350; i++) {
                sleep(1);
                printf("Filho 2: %d\n", i);
            }

            printf("Processo Filho 2 Terminou\n");
        }
    }

    return 0;
}
