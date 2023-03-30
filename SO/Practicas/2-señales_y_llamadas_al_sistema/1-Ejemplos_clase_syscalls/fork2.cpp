#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>				/*Hay que incluir a wait*/

void jorge(){
	write(1, "Soy Jorge\n", 10);
	sleep(1);
}

void juan(){
	write(1, "Soy Juan\n", 10);
	sleep(1);
	wait(NULL);						/*Acá espera a que uno de los hijos termina, como la única es Jeniffer, la espera a ella*/
	
	pid_t pid = fork();
	if (pid == 0) {
		jorge();						
	} else {}
		
}

void jennifer(){
	write(1, "Soy Jennifer\n", 14);
	sleep(1);
}

void julieta(){
	write(1,"Soy Julieta\n", 12);
	sleep(1);
	pid_t pid = fork();
	if (pid == 0) {
		jennifer();			
	} else {
		wait(NULL);					/*Acá Julieta espera a que termine Jennifer, pero igual no es necesario ya que Juan espera solo a que termine la hija no los nietos*/
	}
}
int main(int argc, char const *argv[]){
  pid_t pid = fork();
  //si no hay error, pid vale 0 para el hijo
  //y el valor del process id del hijo para el padre
  if (pid == -1) exit(EXIT_FAILURE);  
  //si es -1, hubo un error
  if (pid == 0) {
	julieta();
  } else {
	juan();
  }
  exit(EXIT_SUCCESS); //cada uno finaliza su proceso
}
