//Versión secuencial del generador de registros
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


int main(int argc, char* argv[]){
	int total_nomb = 20000;
	int tiempo_inicio = 0;
	char id[10],numero1[10], numero2[10], numero3[10],numero4[10];
	int ids, cal1, cal2,cal3;
	//Tablas de conversión para los puntajes
	int seccion1[51] = {20,24,25,27,28,29,30,31,32,33,34,35,36,37,39,40,40,41,42,43,43,44,44,45,46,46,47,47,48,48,49,49,50,51,51,52,53,54,55,55,56,57,58,59,60,61,61,63,64,66,68};
	int seccion2[41] = {20,21,22,24,25,26,28,29,30,32,34,34,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,54,54,55,56,58,59,60,62,64,66,67,68};
	int seccion3[52] = {21,22,23,23,24,25,26,27,28,28,29,30,31,33,34,35,36,37,38,39,40,41,42,43,43,44,45,46,46,47,48,48,49,50,51,52,52,53,54,54,55,56,57,58,59,60,61,63,65,66,67};
	int contador = 0; // Para controlar el csv
	int datos[4]; //Para guardar los datos del csv y hacer las conversiones
	int calificacion  = 0;

	FILE * calificaciones = fopen("toefl.csv","w");
	FILE * archivo = fopen("registros.csv","r");
	if(archivo == NULL && calificaciones == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		tiempo_inicio = clock();
		//buffer para guardar lo del archivo
		char linea[1024];
		//lee linea por linea del archivo
		while(fgets(linea,1024,archivo)){
			//rompe la cadena con el delimitador y nos brinda el id
			char *token = strtok(linea,",");
			//Solo es null cuando no hay mas en la cadena
			if(token!=NULL){
				while(token!=NULL){
					if(contador==0){
						datos[0] = atoi(token);
						contador++;
						token = strtok(NULL,",");
					}else if(contador==1){
						datos[1] = atoi(token);
						contador++;
						token = strtok(NULL,",");				
					}else if(contador==2){
						datos[2] = atoi(token);
						contador++;
						token = strtok(NULL,",");						
					}else{
						datos[3] = atoi(token);
						contador = 0;
						token = strtok(NULL,",");							
					}
				}
			}
			//printf("ID: %d\n",datos[0] );
			int pf = 0;
			int it1 = datos[1];
			int it2 = datos[2];
			int it3 = datos[3];
			char registros[40];
			ids = datos[0];
			cal1 = seccion1[it1];
			cal2 = seccion2[it2];
			cal3 = seccion3[it3];
			pf = (cal1+cal2+cal3)/3;
			sprintf(id, "%d",ids);
			sprintf(numero1, "%d",cal1);
			sprintf(numero2, "%d", cal2);
			sprintf(numero3, "%d",cal3);
			sprintf(numero4, "%d",pf);
			strcpy(registros,id );
			strcat(registros,", ");
			strcat(registros,numero1);
			strcat(registros,", ");
			strcat(registros,numero2);
			strcat(registros,", ");
			strcat(registros,numero3);
      		strcat(registros,", ");
			strcat(registros,numero4);
			strcat(registros,"\n");
			fputs(registros,calificaciones);		
		}
		fclose(archivo);
		fclose(calificaciones);
		printf("El tiempo que tardo es: %f\n", (clock()-tiempo_inicio)/(double)CLOCKS_PER_SEC);
	}

}