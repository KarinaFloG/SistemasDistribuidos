#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[]){
    int pid, size, origen, destino, tag;
    MPI_Status info;
    MPI_Datatype stype;
    FILE * archivo = fopen("nombres.csv","a+");
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    int numero,chicken,suma,tam = 100;
    int datos = 20000/(size-1);
    double tiempo_inicio, tiempo_fin, tiempo_total;

    if(pid==0){
      tiempo_inicio = MPI_Wtime();
        int datos = 20000/(size-1);
        tag = 0;
        for(int i =1; i<=size-1;i++){
          MPI_Send(&datos, 1,MPI_INT, i, tag, MPI_COMM_WORLD);
        }   
    }else{
      tag = 0;
      MPI_Recv(&datos, 1,MPI_INT, 0, tag, MPI_COMM_WORLD, &info); 
    	char *nombres[]={"Karina ","Alejandro ","Gabriel ","Gabriela ","Beatriz ","Rene ","Angelica ","Adrian ","Tabata ","Tania ","Tamara ","Jose ","Luis ","Antonio ","Daniel ","Jessica ","Karla ","Andrea ","Veronica ","Diego ","Ulises ","Rodrigo ","Arturo ","Jaqueline ","Fernanda ","Fernando ","Aaron ","Rosa ","María ","Janeth ","Octavio ","Javier ","Jennifer ","Miguel ","Ana ","David ","Jorge ","Josue ","Mariana ","Marisa ","Marlene ","Matías ","Romeo ","Luis ","Gloria ","Juana ","Joaquín ","Julian ","Daniel ","Donovan ","Uriel ","Saúl ","Oscar ","Galileo ","Laura ","Joel ","Eduardo ","Patricia ","Graciela ","Gissele ","Daniela ","Natalia ","Alberto ","Salvador ","Emilio ","Sara ","Rubí ","Esmeralda ","Leonel ","Lenin ","Lina ","Armando ","Alexa ","Carmen ","Rocío ","Yuliana ","Ivan ","Víctor ","Hector ","Alejandra ","Elisa ","Karen ","Norma ","Belen ","Yolanda ","Estela ","Fernando ","Cecilia ","Alan ","Cristina ","Francisco ","Mario ","Martín ","Esperanza ","Enrique ","Jonathan ","Dulce ","Gerardo ","Ricardo ","Daniel "};
      //Arreglo de 100 apellidos para elegir
	    char *apellidos[]={"Flores ","García ","Herrera ","Gandarela ","Perez ","Martinez ","Rosales ","Gutierrez ","Gonzalez ","Gomez ","Farias ","Fonseca ","Castillo ","Torres ","Vicencio ","Vives ","Hernandez ","Morales ","Fernandez ","Mora ","Mendoza ","Rodriguez ","Sandoval ","Corona ","Tadeo ","Villalba ","Mejia ","Reynaga ","Ugalde ","Olvera ","Reyes ","Tovar ","Rangel ","Arango ","Vega ","Guzman ","Alvarado ","Alvarez ","Quiroz ","Gallardo ","Iniesta ","Juarez ","Ordaz ","Contreras ","Romero ","Carmona ","Estrada ","Elias ","Rojas ","Rivera ","Serrano ","Aguirre ","Dueñas ","Calderon ","Garibo ","Davila ","Bejarano ","Anzures ","Tagle ","Cortes ","Casas ","Cabrera ","Iriarte ","Duran ","Diaz ","Otero ","Delgado ","Cantillo ","España ","Moreno ","Esperon ","Huerta ","Valdez ","Manrique ","Sotelo ","Castilla ","Mastache ","Ortega ","Bolaños ","Ramos ","Riva ","Ronaldo ","Moysen ","Montes ","Muñoz ","Mora ","Montiel ","Mota ","Maldonado ","Najera ","Nayle ","Navarro ","Novelo ","Nieto ","Neri ","Negrete ","Lopez ","Ponce "," Nava","Saldaña "};
      if(archivo == NULL){
        perror("Error en la apertura del archivo");
		    return 1;
      }else{
		    for(int i=0;i<datos;i++){
          char nombreCompl[40];
          numero = rand() % 50;
          strcpy(nombreCompl, nombres[numero+2]);
          strcat(nombreCompl,apellidos[numero+10]);
          strcat(nombreCompl,apellidos[numero-4]);
          strcat(nombreCompl,"\n");
          fputs(nombreCompl,archivo);		
        }
      }
      chicken = 1;
      MPI_Send(&chicken,1,MPI_INT,0,tag,MPI_COMM_WORLD);
  }

  if(pid==0){
    suma = 0;
    for(int i =1; i<=size-1;i++){
      MPI_Recv(&chicken, 1,MPI_INT, i, tag, MPI_COMM_WORLD, &info);
      suma = suma + chicken;
      if(suma==(size-1)){ 
        tiempo_fin = MPI_Wtime();
        tiempo_total = tiempo_fin - tiempo_inicio;
        printf("El tiempo de ejecución es: %f\n", tiempo_total);
      }  
    }    
  }
	fclose(archivo);
  MPI_Finalize();
  return 0;
}