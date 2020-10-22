/*
 * electrodomestico.c
 *
 *  Created on: 15 oct. 2020
 *      Author: samotaiello
 */

#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include <string.h>
#include "string.h"
#include <ctype.h>
#include "cliente.h"

#define RETRY 5
#define TAM 1000


int initArray(electrodomestico* list, int len){

	int i;

	if(list != NULL && len > 0){
		for(i = 0; i<len; i++){

			list[i].id = 0;
			list[i].serie = 0;
			list[i].idMarca = 0;
			list[i].modelo = 0;
		}
	}
	else{
		printf("Array NULL");
	}
 return 0;
}

int elecIsEmpty(electrodomestico* list, int len, int* posicion){

	int retorno = -1;
	int i;
	if(list != NULL && len >= 0 && posicion != NULL){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == 1){
				retorno =0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}


int AltaElec(electrodomestico* list, int len, int serie, int idMarca, int modelo){

	char msgError[50];
	char msg[50];
	int min, max;

		if(list != NULL && len > 0){

				strcpy(msg, "Ingrese numero de serie");
				strcpy(msgError, "ERROR");
				min = 1;
				max = 200000;
				getInt(&serie, msg, msgError, min, max, RETRY);

				printf("1 - Whirpool \n 2 - Sony \n 3 - Liliana \n 4 - Gafa \n 5 - Phillips \n");
				strcpy(msg, "Ingrese ID de Marca");
				strcpy(msgError, "ERROR");
				min = 1;
				max = 5;
				getInt(&idMarca, msg, msgError, min, max, RETRY);

				strcpy(msg, "Ingrese año de faricacion (modelo)");
				strcpy(msgError, "ERROR");
				min = 1900;
				max = 2020;
				getInt(&modelo, msg, msgError, min, max, RETRY);



		}


	return 0;
}



int modificarElec(electrodomestico* list, int len, int id, int* posicion){

	char resp = 's';
	int opcion;
	char msg[50];
	char msgError[50];
	int min, max;

	if(list != NULL && len > 0 && id >= 1 && posicion != NULL){

		if(list[*posicion].isEmpty == 0){

			printf("\n SERIE: %d", list[*posicion].serie);
			printf("\n MODELO: %d", list[*posicion].modelo);
			printf("\n");

			 do{

				printf("\n Que parametro desea modificar?");
				printf("\n 1 - SERIE");
				printf("\n 2 - MODELO");
				strcpy(msg, "Ingrese opcion\n");
				strcpy(msgError, "ERROR\n");
				min =1;
			    max =2;
			    fpurge(stdin);
			    getInt(&opcion, msg, msgError, min, max, RETRY);

		    	switch(opcion){

	    			case 1:
	    				strcpy(msg, "Ingrese numero de serie");
	    				strcpy(msgError, "ERROR");
	    				min = 1;
	    				max = 200000;
	    				getInt(&list[*posicion].serie, msg, msgError, min, max, RETRY);
	    			break;

				    case 2:
						strcpy(msg, "Ingrese año de faricacion (modelo)");
						strcpy(msgError, "ERROR");
						min = 1900;
						max = 2020;
						getInt(&list[*posicion].modelo, msg, msgError, min, max, RETRY);
				    break;

		    	}

				printf("\n Desea modificar otro parametro? s/n" );
				fpurge(stdin);
				scanf("%c", &resp);

			}while(resp == 's');
		}
		else{
			printf("\n El Electrodomestico ha sido dado de BAJA");
		}
	}

	return 0;
}

int bajaElec(electrodomestico* list, int len, int id, int* posicion){

	char resp;
	int retorno = -1;

	if(list != NULL && len > 0 && posicion != NULL && id > 0){

		printf("\n ID: %d", id);
		printf("\n Serie: %d", list[*posicion].serie);
		printf("\n Modelo: %d", list[*posicion].modelo);

		printf("\n Seguro desea dar de BAJA este electrodomestico? s/n");
		fpurge(stdin);
		scanf("%c", &resp);

		if (resp == 's'){

			list[*posicion].serie = 0;
			list[*posicion].modelo = 0;
			list[*posicion].isEmpty = 1;

			printf("\n El electrodomestico a sido eliminado exitosamente");

			retorno = 0;
		}
		else{
			retorno = 0;
		}
	}

	return retorno;
}
int ordenarElec(electrodomestico* list, int len, int order){


	// order == 0 ascendente  , order == 1 descendente

	int i, j;
	int auxModel = 0;
	int auxId =0;
	int auxSerie = 0;
	int auxIdMarca = 0;

	if(list != NULL && len > 0 && (order == 1 || order == 0 )){

		for(i = 0; i<len-1; i++){

			for(j = i+1; j<len; j++){


				if(list[i].modelo < list[j].modelo && order == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0){ // de menor a mayor

					auxModel = list[i].modelo;
					list[i].modelo = list[j].modelo;
					list[j].modelo = auxModel;

					auxId = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxId;

					auxSerie = list[i].serie;
					list[i].serie = list[j].serie;
					list[j].serie = auxSerie;

					auxIdMarca = list[i].idMarca;
					list[i].idMarca = list[j].idMarca;
					list[j].idMarca = auxIdMarca;



				}
				else if(list[i].modelo > list[j].modelo && order == 1 && list[i].isEmpty == 0 && list[j].isEmpty == 0){ // de mayor a menor

					auxModel = list[j].modelo;
					list[j].modelo = list[i].modelo;
					list[i].modelo = auxModel;

					auxId = list[j].id;
					list[j].id = list[i].id;
					list[i].id = auxId;

					auxSerie = list[j].serie;
					list[j].serie = list[i].serie;
					list[i].serie = auxSerie;

					auxIdMarca = list[j].idMarca;
					list[j].idMarca = list[i].idMarca;
					list[i].idMarca = auxIdMarca;

				}
				else if(list[i].modelo == list[j].modelo && list[i].serie > list[j].serie && list[i].isEmpty == 0 && list[j].isEmpty == 0  ){ // por serie (como segundo criterio)


					auxModel = list[i].modelo;
					list[i].modelo = list[j].modelo;
					list[j].modelo = auxModel;

					auxId = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxId;

					auxSerie = list[i].serie;
					list[i].serie = list[j].serie;
					list[j].serie = auxSerie;

					auxIdMarca = list[i].idMarca;
					list[i].idMarca = list[j].idMarca;
					list[j].idMarca = auxIdMarca;

				}
			}
		}
	}


	return 0;
}
int printElec(electrodomestico* list, int len)
{
	//printf("TXT1: %9s TXT2 %9s TXT3 %9s\n", txt1, txt2, txt3)
	/*typedef struct{
		int id, serie, idMarca, modelo, isEmpty;

	}electrodomestico;*/

	int i;

	if(list != NULL && len > 0){

		printf("\n ID   SERIE   MODELO  ");

		for (i = 0; i < len; i++){

			if(list[i].isEmpty == 0){

				printf("\n %4d %6d %8d", list[i].id, list[i].serie ,list[i].modelo);
			}
		}
	}

 return 0;
}

int printMarcas(marca* Marcas, int len)
{
	//printf("TXT1: %9s TXT2 %9s TXT3 %9s\n", txt1, txt2, txt3)
	/*	int id;
	char descripcion[20];*/

	int i;

	if(Marcas != NULL && len > 0){

		printf("\n ID   DESCRIPCION  ");

		for (i = 0; i < len; i++){

				printf("\n %4d %20s", Marcas[i].id, Marcas[i].descripcion);
		}
	}

 return 0;
}

int menuInformes(int* opcion){

	int min, max;
	char msg[20];
	char msgError[20];

    printf("\nMenu de Opciones\n");
    printf("1- ELECTRODOMESTICOS DEL AñO 2020");
    printf("2- ELECTRODOMESTICO DE UNA MARCA ESPECIFICA\n");
    printf("3- REPARACIONES EFECTUADAS A UN ELECTRODOMESTICO EN PARTICULAR \n");
    printf("4- IMPORTE TOTAL DE LAS REPARACIONES REALIZADAS A UN ELECTRODOMESTICO \n");
    printf("5- SERVICIO MAS PEDIDO\n");
    printf("6- RECAUDACION EN UNA FECHA EN PARTICULAR \n");
    printf("7- ELECTRODOMESTICOS QUE REALIZARON GARANTIA EN UNA FECHA ESPECIFICA \n");
    printf("8- TRABAJOS REALIZADOS A ELECTRODOMESTICOS MODELO 2018");
    printf("9- FACTURACION TOTAL POR MANTENIMIENTOS");
    printf("10- LA MARCA CON MAS REPARACIONES");
    printf("11- ELECTRODOMESTICOS QUE FUERON REPARADOS EN UNA FECHA ESPECIFICA");
    strcpy(msg, "Ingrese opcion\n");
    strcpy(msgError, "opcion no contemplada\n");
    min =1;
    max =11;
    fpurge(stdin);
    getInt(opcion, msg, msgError, min, max, RETRY);

    return 0;

}

int idDescripcion(int idMarca, marca* Marcas, int lenMar, char descripcion[]){

	int i;


	if(Marcas != NULL && lenMar >0 && descripcion != NULL){
		for(i= 1; i< 6; i++){

				if(idMarca == Marcas[i].id){

					strcpy(descripcion, Marcas[i].descripcion);
					break;
				}

		}

	}
return 0;

}



int elec2020(electrodomestico* list, int len, marca* Marcas, int lenMar){

	char descripcion[20];

	int i;
	int acum =0;

	if(list != NULL && len > 0){
		for( i =0; i<len; i++){
			if(list[i].modelo == 2020){
				idDescripcion(list[i].id, Marcas, 5, descripcion);
				printf("\n ID   SERIE  MARCA ");
				printf("\n %4d %6d %6s", list[i].id, list[i].serie, descripcion);
				acum++;
			}

		}
		if(acum == 0){
			printf("\n no se encontraron electrodomesticos modelo 2020");
		}
	}
	return 0;

}

int elecPorMarca(electrodomestico* list, int len, marca* Marcas, int lenMar, int idMarca){

	int min, max;
	char msg[20];
	char msgError[20];
	int i;
	int acum =0;

	if(list !=NULL && len > 0 && Marcas != NULL && lenMar > 0){
		printMarcas(Marcas, 5);
		strcpy(msg, "Ingrese ID de marca\n");
		strcpy(msgError, "opcion no contemplada\n");
		min =1;
		max =5;
		fpurge(stdin);
		getInt(&idMarca, msg, msgError, min, max, RETRY);

		for(i=0;i<len;i++){
			if(list[i].idMarca == idMarca){
				printf("\n ID   SERIE   MODELO  ");
				printf("\n %4d %6d %8d", list[i].id, list[i].serie ,list[i].modelo);
				acum++;
			}
		}
		if(acum == 0){
			printf("\n no se encontraron electrodomesticos dados de alta de la marca pedida");
		}
	}

	return 0;
}

int reparacionIdCliente(electrodomestico* list, int lenElec, cliente* Clientes, int len, reparacion* catalogo, int lenCata, marca* Marcas, int lenMarcas){

	int i;
	char msg[20];
	char msgError[20];
	char descripcion[20];
	int idCliente;
	if(Clientes != NULL && len > 0 && catalogo != NULL && lenCata > 0 && Marcas != NULL && lenMarcas > 0){

		strcpy(msg, "Ingrese ID de CLIENTE\n");
		strcpy(msgError, "opcion no contemplada\n");
		fpurge(stdin);
		getInt(&idCliente, msg, msgError, 1, TAM, RETRY);

		for(i=0; i<len; i++){
			if(idCliente == catalogo[i].idCliente && catalogo[i].isEmpty == 0){
				idDescripcion(list[i].id, Marcas, 5, descripcion);
				printf("\n ID   SERIE   MODELO  DESCRIPCION ");
				printf("\n %4d %6d %8d %10s", list[i].id, list[i].serie ,list[i].modelo, descripcion);
				break;
			}
		}

	}

	return 0;
}
