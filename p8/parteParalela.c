#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
int iterador = 1;
int returnVecinos = 0;
void actualizaVecino(int matriz[8][20], int i, int j,int label){
  matriz[i][j] = label;
}

void vecinos(int matriz[8][20],int i, int j, int it){
  bool bandera = false;
  iterador = it;
  if(i == 0 && j == 0){
      if(matriz[i][j] ==5){
        matriz[i][j] = iterador;
      }
  }else if(j==0 && i==7){
      int arrSuperiores[2];
      arrSuperiores[0] = matriz[i-1][j];
      arrSuperiores[1] = matriz[i-1][j+1];
      if(arrSuperiores[0] == 0 && arrSuperiores[1] == 0){
          iterador++;
          matriz[i][j] = iterador; 
      }else{
          for(int p=0;p<2;p++){
            if(arrSuperiores[p] != 5){
                matriz[i][j] = arrSuperiores[p];
                bandera = true;
            }else if(arrSuperiores[p] == 0){
                continue;
            }else{
                if(bandera != true){
                  matriz[i][j] = iterador;
                }else{
                  continue;
                }
            }
          }    
      }
    }else if(j==0 && (i>0 && i<8)){
    int arrSuperiores[3];
    arrSuperiores[0] = matriz[i-1][j];
    arrSuperiores[1] = matriz[i-1][j+1];
    arrSuperiores[2] = matriz[i][j+1];

    if(arrSuperiores[0] == 0 && arrSuperiores[1] == 0 && arrSuperiores[2] == 0){
      iterador++;
      matriz[i][j] = iterador;
    }else{
      for(int k = 0; k<3; k++){
        if(arrSuperiores[k] == 0){
          continue;
        }else if (arrSuperiores[k] != 5){
          matriz[i][j] = arrSuperiores[k];
        }else if(arrSuperiores[k] == 5){
          matriz[i][j] = iterador;
        }
      }
    }

    }else if(i==7 && j==19){
      int arrVecinos[2];
      int arrSuperiores[2];
      int aux1 = i-1;
      int aux2 = j-1;
      int aux3 = j;
      int aux4 = i;

      arrVecinos[0] = matriz[i-1][j-1];
      arrVecinos[1] = matriz[i][j-1];
      arrSuperiores[0] = matriz[i-1][j-1];
      arrSuperiores[1] = matriz[i-1][j];

      if(arrVecinos[0] == 0 && arrVecinos[1]){
        iterador++;
        matriz[i][j] = iterador;
        for(int k=0; k<2;k++){
          if(arrSuperiores[k] != 0){
            if(k == 0){
              actualizaVecino(matriz,aux1,aux2,iterador);
            }else if(k == 1){
              actualizaVecino(matriz,aux1,aux3, iterador);
            }
          }
        }
      }else{
      for(int k=0;k<2;k++){
        if(arrVecinos[k] == 0){
          continue;
        }else if(arrVecinos[k] != 5){
          matriz[i][j] = arrVecinos[k];
          bandera = true;
        }else if(arrVecinos[k] == 5){
          if(bandera == true){
            continue;
          }else{
            matriz[i][j] = iterador;
            if(k == 0){
              actualizaVecino(matriz,aux1,aux2,iterador);
            }else if(k == 1){
              actualizaVecino(matriz,aux4,aux2,iterador);
            }
          }
        }
      }

      for(int k = 0;k<2;k++){
        if(arrSuperiores[k] != iterador && arrSuperiores[k] !=0){
          if(k == 0){
            actualizaVecino(matriz,aux1,aux2,iterador);
            matriz[i][j] = arrSuperiores[k];
          }else if(k ==1){
            actualizaVecino(matriz,aux1,aux3,iterador);
            matriz[i][j] = arrSuperiores[k];
          }
        }
      } 
      }
    }else if(i==7 && (j>0 && j<19)){
      int arrVecinos[2];
      int arrSuperiores[3];
      int aux1 = i-1;
      int aux2 = j-1;
      int aux3 = j;
      int aux4 = j+1;
      int aux5 = i;
      arrVecinos[0] = matriz[i-1][j-1];
      arrVecinos[1] = matriz[i][j-1];
      arrSuperiores[0] = matriz[i-1][j-1];
      arrSuperiores[1] = matriz[i-1][j];
      arrSuperiores[2] = matriz[i-1][j+1];

      if(arrVecinos[0] == 0 && arrVecinos[1] == 0){
      if(arrSuperiores[0] == 0 && arrSuperiores[1]==0 && arrSuperiores[2]==0){
        iterador++;
        matriz[i][j] = iterador;
        for(int k = 0;k<3;k++){
          if(arrSuperiores[k] != 0){
            if(k ==1){
              actualizaVecino(matriz,aux1,aux2,iterador);
            }else if(k == 2){
              actualizaVecino(matriz,aux1,aux3,iterador);
            }else if(k == 3){
              actualizaVecino(matriz,aux1,aux4,iterador);
            }
          }
        }
      }else{
        for(int k = 0;k<3;k++){
          if(arrSuperiores[k] != 0){
            matriz[i][j] = arrSuperiores[k];
          }
        }       
      }       
      }else{
      for(int k=0;k<2;k++){
        if(arrVecinos[k] == 0){
          continue;
        }else if(arrVecinos[k] != 5){
          matriz[i][j] = arrVecinos[k];
          bandera = true;
        }else if(arrVecinos[k] == 5){
          if(bandera == true){
            continue;
          }else{
            matriz[i][j] = iterador;
            if(k == 0){
              actualizaVecino(matriz,aux1,aux2,iterador);
            }else if(k == 1){
              actualizaVecino(matriz,aux5,aux2,iterador);
            }
          }
        }
      }

      }
    }else if(j==19 && (i>0 && i<7)){
      int arrVecinos[3];
      int arrSuperiores[2];
      int aux1 = i-1;
      int aux2 = j-1;
      int aux3 = j;
      int aux4 = i;

      arrVecinos[0] = matriz[i-1][j-1]; 
      arrVecinos[1] = matriz[i][j-1];
      arrVecinos[2] = matriz[i+1][j-1];
      arrSuperiores[0] = matriz[i-1][j-1];
      arrSuperiores[1] = matriz[i-1][j];

      if(arrVecinos[0] == 0 && arrVecinos[1] == 0 && arrVecinos[2]==0){
        iterador++;
        matriz[i][j] = iterador;
        for(int k=0; k<2;k++){
          if(arrSuperiores[k] != 0){
            if(k == 0){
              actualizaVecino(matriz,aux1,aux2,iterador);
            }else if(k == 1){
              actualizaVecino(matriz,aux1,aux3, iterador);
            }
          }
        }
      }else{
      for(int k=0;k<3;k++){
        if(arrVecinos[k] == 0){
          continue;
        }else if(arrVecinos[k] != 5){
          matriz[i][j] = arrVecinos[k];
          bandera = true;
        }else if(arrVecinos[k] == 5){
          if(bandera == true){
            continue;
          }else{
            matriz[i][j] = iterador;
            if(k == 0){
              actualizaVecino(matriz,aux1,aux2,iterador);
            }else if(k == 1){
              actualizaVecino(matriz,aux4,aux2,iterador);
            }else if(k == 2){
              actualizaVecino(matriz,aux3,aux2, iterador);
            }

          }
        }
      }

      for(int k = 0;k<2;k++){
        if(arrSuperiores[k] != iterador && arrSuperiores[k] !=0){
          if(k == 0){
            actualizaVecino(matriz,aux1,aux2,iterador);
            matriz[i][j] = arrSuperiores[k];
          }else if(k ==1){
            actualizaVecino(matriz,aux1,aux3,iterador);
            matriz[i][j] = arrSuperiores[k];
          }
        }
      }

    }
    }else if((i>0 && i<7) && (j>0 && j<19)){
    int arrVecinos[5] = {0,0,0,0,0};
    int arrSuperiores[5];
    bandera = false;
    int aux1 = i-1;
    int aux2 = j-1;
    int aux3 = i+1;
    int aux4 = i;
    int aux5 = j;
    int aux6 = j+1;
    arrVecinos[0] = matriz[i-1][j-1]; 
      arrVecinos[1] = matriz[i][j-1];
      arrVecinos[2] = matriz[i+1][j-1];
    arrVecinos[3] = matriz[i-1][j+1];
    arrVecinos[4] = matriz[i-1][j];
    arrSuperiores[0] = matriz[i-1][j-1];  
    arrSuperiores[1] = matriz[i-1][j];
    arrSuperiores[2] = matriz[i-1][j+1];
    arrSuperiores[3] = matriz[i][j+1];
    arrSuperiores[4] = matriz[i+1][j+1];

    
    if(arrVecinos[0] == 0 && arrVecinos[1]==0 && arrVecinos[2]==0){
      if(arrSuperiores[0] == 0 && arrSuperiores[1]==0 && arrSuperiores[2]==0){
        
        iterador++;
        matriz[i][j] = iterador;
        for(int k = 1;k<5;k++){
          if(arrSuperiores[k] != 0){
            if(k ==1){
              actualizaVecino(matriz,aux1,aux5,iterador);
            }else if(k == 2){
              actualizaVecino(matriz,aux1,aux6,iterador);
            }else if(k == 3){
              actualizaVecino(matriz,aux4,aux6,iterador);
            }else if(k == 4){
              actualizaVecino(matriz,aux3,aux6,iterador);
            }
          }
        }
      }else{
        for(int k = 0;k<4;k++){
          if(arrSuperiores[k] != 0){
            matriz[i][j] = arrSuperiores[k];
          }
        }       
      }

    }else{
      for(int k=0;k<3;k++){
        if(arrVecinos[k] == 0){
          continue;
        }else if(arrVecinos[k] != 5 && arrVecinos[k] != 0){
          matriz[i][j] = arrVecinos[k];
          bandera = true;
        }else if(arrVecinos[k] == 5){
          if(bandera == true){
            continue;
          }else{
            matriz[i][j] = iterador;
            
            if(k == 0){
              if(arrVecinos[k] == 0){
                continue    ;
              }else{
                actualizaVecino(matriz,aux1,aux2,iterador);
              }
            }else if(k == 1){
              actualizaVecino(matriz,aux4,aux2,iterador);
            }else if(k == 2){
                actualizaVecino(matriz,aux3,aux2, iterador);
            }

          }
        }
      }

    }

    }
}



int main(int argc, char* argv[]){
    int pid, size, origen, destino, tag;
    int tablero[8][20]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,5,5,0,0,0,0,0,5,0,0,0,5,5,0,0,0,0,0},
                        {5,5,0,0,5,0,0,5,5,0,0,5,5,0,0,5,0,0,5,5},
                        {0,0,5,0,0,5,5,0,5,0,0,0,0,5,0,0,5,0,0,5},
                        {0,0,0,5,5,0,0,0,5,5,0,0,0,0,5,5,0,0,0,0},
                        {5,0,0,0,0,5,5,0,0,0,5,5,0,0,0,0,5,5,0,0},
                        {0,5,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0},
                        {0,0,5,5,5,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0}};
    int tamanio = 20*8;
    int indicesFilas[2];
    double tiempo_inicio, tiempo_fin, tiempo_total;
    MPI_Status info;
    MPI_Datatype stype;
    FILE * archivo = fopen("tableroParalelo.txt","w");
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    int frontera  = 8/size; //Hasta 
    int ultimo = size-1;

    tiempo_inicio = MPI_Wtime();
    if(pid==0){
      tag = 0;
      for(int i=1; i<size; i++){
          indicesFilas[0] = frontera*i; //donde va iniciar
          indicesFilas[1] = indicesFilas[0] + frontera; //hasta donde va terminar
          MPI_Send(&indicesFilas,sizeof(indicesFilas),MPI_INT,i, tag, MPI_COMM_WORLD);
      } 
      int iniFila = frontera * pid;
      int finFila = iniFila + frontera;
      int valor = 0;
      for(int i=iniFila;i<finFila;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j,iterador);
          }
        }
      }
      MPI_Send(&tablero,tamanio,MPI_INT,1, tag, MPI_COMM_WORLD);
    }


    if(pid==ultimo){
      tag = 0;
      int valor = 0;
      MPI_Recv(&indicesFilas,sizeof(indicesFilas),MPI_INT,0, tag, MPI_COMM_WORLD, &info); 
      MPI_Recv(&tablero,tamanio,MPI_INT,pid-1, tag, MPI_COMM_WORLD, &info); 
      int inicio = indicesFilas[0];
      int fin = indicesFilas[1];
      for(int i=inicio;i<fin;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j,iterador);
          }
        }
      }

      //-----------TODA LA OPERACIÓN-------
      iterador = 1;
      for(int i=0;i<8;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j, iterador);
          }
        }
      }

      MPI_Send(&tablero,tamanio,MPI_INT,0, tag, MPI_COMM_WORLD);

    }else if(pid==1){
      MPI_Recv(&indicesFilas,sizeof(indicesFilas),MPI_INT,0, tag, MPI_COMM_WORLD, &info); 
      MPI_Recv(&tablero,tamanio,MPI_INT,pid-1, tag, MPI_COMM_WORLD, &info);   
      int inicio = indicesFilas[0];
      int fin = indicesFilas[1];
      int valor = 0;
      for(int i=inicio;i<fin;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j,iterador);
          }
        }
      }
      MPI_Send(&tablero,tamanio,MPI_INT,pid+1, tag, MPI_COMM_WORLD);
    }else if(pid == 2){
      MPI_Recv(&indicesFilas,sizeof(indicesFilas),MPI_INT,0, tag, MPI_COMM_WORLD, &info); 
      MPI_Recv(&tablero,tamanio,MPI_INT,pid-1, tag, MPI_COMM_WORLD, &info);   
      int inicio = indicesFilas[0];
      int fin = indicesFilas[1];
      int valor = 0;
      for(int i=inicio;i<fin;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j,iterador);
          }
        }
      }
      MPI_Send(&tablero,tamanio,MPI_INT,pid+1, tag, MPI_COMM_WORLD);
    }else if(pid == 3){
      MPI_Recv(&indicesFilas,sizeof(indicesFilas),MPI_INT,0, tag, MPI_COMM_WORLD, &info); 
      MPI_Recv(&tablero,tamanio,MPI_INT,pid-1, tag, MPI_COMM_WORLD, &info);   
      int inicio = indicesFilas[0];
      int fin = indicesFilas[1];
      int valor = 0;
      for(int i=inicio;i<fin;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j,iterador);
          }
        }
      }
      MPI_Send(&tablero,tamanio,MPI_INT,pid+1, tag, MPI_COMM_WORLD);
    }else if(pid == 4){
      MPI_Recv(&indicesFilas,sizeof(indicesFilas),MPI_INT,0, tag, MPI_COMM_WORLD, &info); 
      MPI_Recv(&tablero,tamanio,MPI_INT,pid-1, tag, MPI_COMM_WORLD, &info);   
      int inicio = indicesFilas[0];
      int fin = indicesFilas[1];
      int valor = 0;
      for(int i=inicio;i<fin;i++){
        for(int j=0;j<20;j++){
          valor = tablero[i][j];
          if(valor!=0){
            vecinos(tablero, i, j,iterador);
          }
        }
      }
      MPI_Send(&tablero,tamanio,MPI_INT,pid+1, tag, MPI_COMM_WORLD);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    if(pid == 0){
      tag = 0;
      int ultimoPid = size - 1;
      MPI_Recv(&tablero,tamanio,MPI_INT,ultimoPid, tag, MPI_COMM_WORLD, &info);   
      printf("\n");
      for(int i=0;i<8;i++){
        for(int j=0;j<20;j++){
          printf("%d |", tablero[i][j]);
        }
        printf("\n");
      }
//------------------------------
      if(archivo == NULL){
        printf("Error en la apertura del archivo\n");
      }else{
        char linea[80];
        for(int i=0;i<8;i++){
          linea[0] = '\0';
          for(int j =0; j<20;j++){
            char buffer[10];
            sprintf(buffer,"%d ", tablero[i][j]);
            strcat(linea,buffer);
          }
        int len = strlen(linea);
        linea[len-1] = '\n';
        fputs(linea,archivo);
      }
    }

    tiempo_fin = MPI_Wtime();
    tiempo_total = tiempo_fin - tiempo_inicio;
    printf("El tiempo de ejecución es: %f\n", tiempo_total);

    fclose(archivo);

    }
  
  MPI_Finalize();
  return 0;
}