#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]){
  //Variables para MPI
	int pid, size, origen, destino, tag;
	MPI_Status info;
	MPI_Datatype stype;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	//Variables para el problema
	int total_nomb = 20000;
	char id[10],numero1[10], numero2[10], numero3[10], numero4[10];
	int ids, cal1, cal2,cal3;
	//Tablas de conversión para los puntajes
	int contador = 0; // Para controlar el csv
	int datos[4]; //Para guardar los datos del csv y hacer las conversiones
	int arrPuntaje[5];
	int calificacion  = 0;
	int identificador = 0;
	double tiempo_inicio, tiempo_fin, tiempo_total;
	FILE * archivo = fopen("registros.csv","r");
	FILE * calificaciones = fopen("toefl.csv","w");

	
	tiempo_inicio = MPI_Wtime();

	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		char linea[1024];
		while(fgets(linea,1024,archivo)){
			if(pid==0){
				char *token = strtok(linea,",");
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
				tag = 0;
				for(int i=1;i<size;i++){
					MPI_Send(&datos, 5,MPI_INT, i, tag, MPI_COMM_WORLD);
				}  
			}else if(pid==1){
				tag = 0;
				int seccion1[51] = {20,24,25,27,28,29,30,31,32,33,34,35,36,37,39,40,40,41,42,43,43,44,44,45,46,46,47,47,48,48,49,49,50,51,51,52,53,54,55,55,56,57,58,59,60,61,61,63,64,66,68};
				int puntaje = 0;
				MPI_Recv(&datos,5,MPI_INT, 0, tag, MPI_COMM_WORLD, &info); 
				int conversion = seccion1[datos[1]];
				arrPuntaje[1] = conversion;
				MPI_Send(&arrPuntaje, 5,MPI_INT, 2, tag, MPI_COMM_WORLD);
			}else if(pid==2){
				tag = 0;
				int seccion2[41] = {20,21,22,24,25,26,28,29,30,32,34,34,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,54,54,55,56,58,59,60,62,64,66,67,68};
				MPI_Recv(&arrPuntaje, 5,MPI_INT, 1, tag, MPI_COMM_WORLD, &info);
				int puntaje = 0;
				MPI_Recv(&datos, 5,MPI_INT, 0, tag, MPI_COMM_WORLD, &info); 
				int conversion = seccion2[datos[2]];
				arrPuntaje[2] = conversion;
				MPI_Send(&arrPuntaje,5,MPI_INT, 3, tag, MPI_COMM_WORLD);
			}else if(pid==3){
				tag = 0;
				int seccion3[52] = {21,22,23,23,24,25,26,27,28,28,29,30,31,33,34,35,36,37,38,39,40,41,42,43,43,44,45,46,46,47,48,48,49,50,51,52,52,53,54,54,55,56,57,58,59,60,61,63,65,66,67};
				MPI_Recv(&arrPuntaje, 5,MPI_INT, 2, tag, MPI_COMM_WORLD, &info);
				MPI_Recv(&datos,5,MPI_INT, 0, tag, MPI_COMM_WORLD, &info); 
				int puntaje = 0;
				int total = 0;
				int conversion = seccion3[datos[3]];
				arrPuntaje[3] = conversion;
				arrPuntaje[0] = datos[0];
				for(int i=1;i<4;i++){
					total = total + arrPuntaje[i];
				}
				total = total/3;
				arrPuntaje[4] = total;
				MPI_Send(&arrPuntaje, 5,MPI_INT,0,tag, MPI_COMM_WORLD);
			}
			MPI_Barrier(MPI_COMM_WORLD);
			if(pid==0){
				tag = 0;
				MPI_Recv(&arrPuntaje,5  ,MPI_INT, 3, tag, MPI_COMM_WORLD, &info); 
				if(calificaciones == NULL){
					perror("Error en la apertura del archivo");
					return 1;  			
				}else{
					char registros[40];
					sprintf(id, "%d",arrPuntaje[0]);
					sprintf(numero1, "%d",arrPuntaje[1]);
					sprintf(numero2, "%d", arrPuntaje[2]);
					sprintf(numero3, "%d", arrPuntaje[3]);
					sprintf(numero4, "%d",arrPuntaje[4]);
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
			}
		}
		tiempo_fin = MPI_Wtime();
		tiempo_total = tiempo_fin - tiempo_inicio;
		printf("El tiempo de ejecución es: %f\n", tiempo_total);
	}

	fclose(archivo);
	fclose(calificaciones);
	MPI_Finalize();

	return 0;
}
