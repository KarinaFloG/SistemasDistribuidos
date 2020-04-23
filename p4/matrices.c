#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    int pid, size, origen, destino, tag;
    MPI_Status info;
    MPI_Datatype stype;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    int n = size;
    int val = n*n;
    int arreglo1[val];
    int arreglo2[val];
    int matrizA[n][n], matrizB[n][n],matrizC[n][n];
    int i,j,k = 0;
    double tiempo_inicio, tiempo_fin, tiempo_total;
    //El proceso 0 genera el contenido de las matrices y lo distribuye a los demás
    if(pid==0){
      //Llenando matrices A y B
      tiempo_inicio = MPI_Wtime();
      for(i=0;i<j;++i){
        for(j=0;j<n;++j)
        {
            matrizA[i][j] = rand() % 6;
            matrizB[i][j] = rand() % 6;
         }
      }
      //Imprimiendo matriz A
      printf("Matriz A en pid=0\n");
      for(int i = 0; i<size; i++){
        for(int j= 0;j<size;j++){
          printf("%d|", matrizA[i][j]);
      
        }
        printf("\n");
      }

      //Imprimiendo matriz B
      printf("Matriz B en pid=0\n");
      for(int i = 0; i<size; i++){
        for(int j= 0;j<size;j++){
          printf("%d|", matrizB[i][j]);
        }
        printf("\n");
      }

	  for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        	matrizC[i][j] = matrizA[i][j]+matrizB[i][j]; 
        }
      }  
      printf("Matriz C en pid=0\n");
      for(int i = 0; i<size; i++){
        for(int j= 0;j<size;j++){
          printf("%d|", matrizC[i][j]);
        }
        printf("\n");
      } 
    }
    
    //Se coloca una barrera para que todos se sincronizen
    MPI_Barrier(MPI_COMM_WORLD);
    //Se hace el envio de la matrizA y matrizB a todos los procesos
    MPI_Bcast(&matrizA,val,MPI_INT,0,MPI_COMM_WORLD);  
    MPI_Bcast(&matrizB,val,MPI_INT,0,MPI_COMM_WORLD); 
    //Se hace la suma de matrices
    for(i=0;i<j;++i){
      for(j=0;j<n;++j)
      {
          arreglo1[k]= matrizA[i][j]+matrizB[i][j];
          k++;
      }
    }
    //Se envian los datos del resultdo de la suma
    MPI_Gather(arreglo1,val,MPI_INT,arreglo2,val,MPI_INT,0,MPI_COMM_WORLD);

    if(pid==0){
      printf("\n-------------------------------------\n");
      printf("Recibiendo datos despues del gather\n");
      printf("Matriz recibida de los procesos\n");
      //El arreglo que se envia se le da formato de matriz
      for(int l=0; l<val;l++){ 
        if((l)%n==0){
          printf("\n");
        }  
        printf("%d|",arreglo2[l]);
      }
      printf("\n");
      tiempo_fin = MPI_Wtime();
      tiempo_total = tiempo_fin - tiempo_inicio;
      printf("Tiempo total de ejecucion: %f\n", tiempo_total);
    }

    MPI_Finalize();
    return 0;
}


