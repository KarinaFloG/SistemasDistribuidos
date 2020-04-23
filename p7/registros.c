//Versión secuencial del generador de registros
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


int main(int argc, char* argv[]){
	int total_nomb = 20000;
	int tam, numeroReg1,numeroReg2,numeroReg3,reg1,reg2,reg3, ID;
	char ids[10],numero1[10], numero2[10], numero3[10];
	clock_t tiempo_inicio;
    //Calcula el tamaño de los arreglos
	FILE * archivo = fopen("registros.csv","w");
	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		tiempo_inicio = clock();
		//Crea 20000 nombres aleatorios y los guarda en un archivo
		for(int i=1;i<=total_nomb;i++){
			char registros[40];
			ID = i;
			numeroReg1 = rand() % 51;
			numeroReg2 = rand() % 41;
			numeroReg3 = rand() % 51;
			sprintf(ids, "%d", ID);
			sprintf(numero1, "%d", numeroReg1);
			sprintf(numero2, "%d", numeroReg2);
			sprintf(numero3, "%d", numeroReg3);

			strcpy(registros, ids);
			strcat(registros,", ");
			strcat(registros, numero1);
			strcat(registros,", ");
			strcat(registros, numero2);
			strcat(registros,", ");
			strcat(registros, numero3);
			strcat(registros,"\n");
			fputs(registros,archivo);			
		}
		fclose(archivo);
		printf("El tiempo que tardo es: %f\n", (clock()-tiempo_inicio)/(double)CLOCKS_PER_SEC);
		printf("Se generaron %d registros\n", total_nomb);
	}
}

//te amo chicken jiji te extraño
//Y yo a ti mi amor <3