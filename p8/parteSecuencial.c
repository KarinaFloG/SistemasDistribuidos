#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
int iterador = 1;

void actualizaVecino(int matriz[8][20], int i, int j,int label){
	matriz[i][j] = label;
}

void vecinos(int matriz[8][20],int i, int j){
	bool bandera = false;

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
								continue		;
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
	FILE *archivo = fopen("mapaCalor.txt","w");
	int valor = 0;
	int tiempo_inicio = 0;
	int tablero[8][20]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,5,5,0,0,0,0,0,5,0,0,0,5,5,0,0,0,0,0},
						{5,5,0,0,5,0,0,5,5,0,0,5,5,0,0,5,0,0,5,5},
						{0,0,5,0,0,5,5,0,5,0,0,0,0,5,0,0,5,0,0,5},
						{0,0,0,5,5,0,0,0,5,5,0,0,0,0,5,5,0,0,0,0},
						{5,0,0,0,0,5,5,0,0,0,5,5,0,0,0,0,5,5,0,0},
						{0,5,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0},
						{0,0,5,5,5,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0}};
	
	tiempo_inicio = clock();

	for(int i=0;i<8;i++){
		for(int j=0;j<20;j++){
			valor = tablero[i][j];
   			if(valor!=0){
    			vecinos(tablero, i, j);
  			}
		}
	}
	iterador = 1;
	for(int i=0;i<8;i++){
		for(int j=0;j<20;j++){
			valor = tablero[i][j];
   			if(valor!=0){
    			vecinos(tablero, i, j);
  			}
		}
	}

	printf("\n");
	for(int i=0;i<8;i++){
  		for(int j=0;j<20;j++){
   			printf("%d |", tablero[i][j]);
 		}
		printf("\n");
	}

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

	fclose(archivo);
	printf("El tiempo que tardo es: %f\n", (clock()-tiempo_inicio)/(double)CLOCKS_PER_SEC);

}

