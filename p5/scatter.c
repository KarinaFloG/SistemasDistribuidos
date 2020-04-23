#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    //Datos para MPI
    int pid, size, origen, destino, tag;
    MPI_Status info;
    MPI_Datatype stype;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    //Datos para los calculos
    int n = size;
    int val = n*n;
    int vectorA[val], vectorB[val];
    int productoSec = 0;
    int productoParal = 0;
    int i,j,k = 0;
    double tiempo_inicio, tiempo_fin, tiempo_total;
    int datoA, datoB , total= 0;

    //El proceso 0 genera el contenido de los arreglos y lo distribuye a los demás
    if(pid==0){
      //Llenando vectores A y B
      tiempo_inicio = MPI_Wtime();
      for(i=0;i<val;i++){
        vectorA[i] = rand() % 6;
        vectorB[i] = rand() % 6;
      }

      //Imprimiendo vectorA
      for(i=0;i<val;i++){
        printf("%d|",vectorA[i]);
      }
      printf("\n");

      //Imprimiendo vectorB
      for(i=0;i<val;i++){
        printf("%d|",vectorB[i]);
      }
      printf("\n");

      //Producto escalar calculado secuencialmente
      for(i=0;i<val;i++){
        productoSec += vectorA[i] * vectorB[i]; 
      }

      //Impresion del producto calculado secuencialmente
      printf("----------------------------------------");
      printf("\nProducto calculado secuencialmente: %d", productoSec);
    }
    
    //Se coloca una barrera para que todos se sincronizen
    MPI_Barrier(MPI_COMM_WORLD);
    //Se hace el envio del vectorA y vectorB
    MPI_Scatter(&vectorA,1,MPI_INT,&datoA,1,MPI_INT,0,MPI_COMM_WORLD);  
    MPI_Scatter(&vectorB,1,MPI_INT,&datoB,1,MPI_INT,0,MPI_COMM_WORLD); 


    //Se hace el calculo del producto escalar
    for(i=0;i<val;i++){
      productoParal += datoA * datoB;
    }

    //Se envian los datos del resultdo de la suma
    MPI_Reduce(&productoParal,&total,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

    if(pid==0){
      printf("\n-------------------------------------\n");
      printf("Recibiendo datos en pid=0\n");
      printf("Producto calculado paralelamente: %d", total);
      //Calculo del tiempo total
      tiempo_fin = MPI_Wtime();
      tiempo_total = tiempo_fin - tiempo_inicio;
      printf("\nTiempo total: %f\n", tiempo_total);

    }

    MPI_Finalize();
    return 0;
}

