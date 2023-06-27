#include <signal.h> /* constantes como SIGINT*/
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int contador = 0;

void signalURG_handler1(int sig){
	printf("ya va!\n");
	contador++;
}

void signalINT_handler1(int sig){
wait(NULL);	//espera a que el hijo termine, en realidad que mande una señal, q puede ser que termine
}

int main(int argc, char* argv[]) {
	/*Imprimo argumentos pasados*/
	printf("%s", argv[0]);
	printf("%s", argv[1]);
	printf("%s", argv[2]);

	/*Hijo*/
  	pid_t pid_hijo = fork();
	if (pid_hijo != 0) { //Proceso padre
		//Redefino señal padre
		signal(SIGINT, signalINT_handler1);

		//For de 0 a 4
		for (int i = 0; i < 5; i++)
		{
			sleep(1);			//duerme 1 para darle tiempo al padre
			printf("sup!\n");	//imprime
			kill(pid_hijo, SIGURG);	//manda señal SIRURG
		}
		
	} else { //Proceso hijo
		//Redefino señal hijo
		signal(SIGURG, signalURG_handler1);

		while(contador < 5);		//en while si contador<5 --> para salir se debe llamar 5 veces a SIGURG
		kill(getppid(), SIGINT);	//una vez afuera envía SIGINT del padre, por eso la doble P
		
		execvp(argv[1], argv + 1);	//Ejecuta lo de arg1 con parametro argv +1	**********DUDA**********
	}
	return 0;
}

/*EJEMPLO

	./hai64 ls 
sup!
ya va!
sup!
ya va!
sup!
ya va!
sup!
ya va!
sup!
ya va!
Enunciado.pdf  hai  hai64  hai.c  Makefile


*/