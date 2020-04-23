//Versión secuencial del generador de nombres
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){
	int total_nomb = 20000;
	int tam,numero;
	clock_t tiempo_inicio;
    //Arreglo con 100 nombres para elegir
    char *nombres[]={"Karina ","Alejandro ","Gabriel ","Gabriela ","Beatriz ","Rene ","Angelica ","Adrian ","Tabata ","Tania ","Tamara ","Jose ","Luis ","Antonio ","Daniel ","Jessica ","Karla ","Andrea ","Veronica ","Diego ","Ulises ","Rodrigo ","Arturo ","Jaqueline ","Fernanda ","Fernando ","Aaron ","Rosa ","María ","Janeth ","Octavio ","Javier ","Jennifer ","Miguel ","Ana ","David ","Jorge ","Josue ","Mariana ","Marisa ","Marlene ","Matías ","Romeo ","Luis ","Gloria ","Juana ","Joaquín ","Julian ","Daniel ","Donovan ","Uriel ","Saúl ","Oscar ","Galileo ","Laura ","Joel ","Eduardo ","Patricia ","Graciela ","Gissele ","Daniela ","Natalia ","Alberto ","Salvador ","Emilio ","Sara ","Rubí ","Esmeralda ","Leonel ","Lenin ","Lina ","Armando ","Alexa ","Carmen ","Rocío ","Yuliana ","Ivan ","Víctor ","Hector ","Alejandra ","Elisa ","Karen ","Norma ","Belen ","Yolanda ","Estela ","Fernando ","Cecilia ","Alan ","Cristina ","Francisco ","Mario ","Martín ","Esperanza ","Enrique ","Jonathan ","Dulce ","Gerardo ","Ricardo ","Daniel "};
    //Arreglo de 100 apellidos para elegir
	char *apellidos[]={"Flores ","García ","Herrera ","Gandarela ","Perez ","Martinez ","Rosales ","Gutierrez ","Gonzalez ","Gomez ","Farias ","Fonseca ","Castillo ","Torres ","Vicencio ","Vives ","Hernandez ","Morales ","Fernandez ","Mora ","Mendoza ","Rodriguez ","Sandoval ","Corona ","Tadeo ","Villalba ","Mejia ","Reynaga ","Ugalde ","Olvera ","Reyes ","Tovar ","Rangel ","Arango ","Vega ","Guzman ","Alvarado ","Alvarez ","Quiroz ","Gallardo ","Iniesta ","Juarez ","Ordaz ","Contreras ","Romero ","Carmona ","Estrada ","Elias ","Rojas ","Rivera ","Serrano ","Aguirre ","Dueñas ","Calderon ","Garibo ","Davila ","Bejarano ","Anzures ","Tagle ","Cortes ","Casas ","Cabrera ","Iriarte ","Duran ","Diaz ","Otero ","Delgado ","Cantillo ","España ","Moreno ","Esperon ","Huerta ","Valdez ","Manrique ","Sotelo ","Castilla ","Mastache ","Ortega ","Bolaños ","Ramos ","Riva ","Ronaldo ","Moysen ","Montes ","Muñoz ","Mora ","Montiel ","Mota ","Maldonado ","Najera ","Nayle ","Navarro ","Novelo ","Nieto ","Neri ","Negrete ","Lopez ","Ponce "," Nava","Saldaña "};
	//Calcula el tamaño de los arreglos
	tam = sizeof(nombres)/sizeof(char *);
	FILE * archivo = fopen("nombres.csv","w");
	if(archivo == NULL){
		perror("Error en la apertura del archivo");
		return 1;
	}else{
		tiempo_inicio = clock();
		//Crea 20000 nombres aleatorios y los guarda en un archivo
		for(int i=0;i<total_nomb;i++){
			char nombreCompl[40];
			numero = rand() % 50;
			strcpy(nombreCompl, nombres[numero+2]);
			strcat(nombreCompl,apellidos[numero+10]);
			strcat(nombreCompl,apellidos[numero-4]);
			strcat(nombreCompl,"\n");
			fputs(nombreCompl,archivo);			
		}
		fclose(archivo);
		printf("El tiempo que tardo es: %f\n", (clock()-tiempo_inicio)/(double)CLOCKS_PER_SEC);
	}
}
