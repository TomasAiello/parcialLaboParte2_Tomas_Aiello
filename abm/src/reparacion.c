/*
 * servicio.c
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

#define RETRY 5
#define TAM 1000

int initArray2(reparacion* list, int len){


	int i;

	if(list != NULL && len > 0){
		for(i = 0; i<len; i++){

			list[i].id = 0;
			list[i].serie = 0;
			list[i].idServicio = 0;
			list[i].isEmpty = 1;
		}
	}
	else{
		printf("Array NULL");
	}
 return 0;
}

int initArray3(fecha* list, int len){


	int i;

	if(list != NULL && len > 0){
		for(i = 0; i<len; i++){

			list[i].dia = 0;
			list[i].mes = 0;
			list[i].anio = 0;
		}
	}
	else{
		printf("Array NULL");
	}
 return 0;
}

int getInt(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int bufferInt;
	if(pResultado !=NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s", mensaje);
			fpurge(stdin);
			scanf("%d",&bufferInt);

				if(bufferInt >= minimo && bufferInt <= maximo){
					*pResultado=bufferInt;
					retorno=0;
				break;
				}
				else{
					printf("%s", mensajeError);
					reintentos--;
				}
		}while(reintentos >=0);

	}
	return retorno;
}
int getFloat(float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	float bufferInt;
	if(pResultado !=NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s", mensaje);
			fpurge(stdin);
			scanf("%f",&bufferInt);

				if(bufferInt >= minimo && bufferInt <= maximo){
					*pResultado=bufferInt;
					retorno=0;
				break;
				}
				else{
					printf("%s", mensajeError);
					reintentos--;
				}
		}while(reintentos >=0);

	}
	return retorno;
}
int utn_menu(int* flagAltaElec, int* flagAltaRep){

	int opcion;
	char msgError[50];
	char msg[50];
	int min, max;

    printf("\nMenu de Opciones\n");
    printf("1- ALTAS ELECTRODOMESTICO\n");
    printf("2- MODIFICAR ELECTRODOMESTICO \n");
    printf("3- BAJA ELECTRODOMESTICO \n");
    printf("4- LISTAR ELECTRODOMESTICOS \n");
    printf("5- LISTAR MARCAS \n");
    printf("6- LISTAR SERVICIOS \n");
    printf("7- ALTA REPARACION \n");
    printf("8- LISTAR REPARACIONES \n");
    printf("9- INFORMES");
    strcpy(msg, "Ingrese opcion\n");
    strcpy(msgError, "opcion no contemplada\n");
    min =1;
    max =8;
    fpurge(stdin);
    getInt(&opcion, msg, msgError, min, max, RETRY);

    if(flagAltaElec != NULL && flagAltaRep != NULL){

    	do{
    		switch(opcion){
    			case 1:
    				*flagAltaElec = 1;
    				break;
    			case 2:
    				if(*flagAltaElec == 0){
    					printf("Para MODIFICAR primero debe dar de ALTA \n");
    					fpurge(stdin);
    					getInt(&opcion, msg, msgError, min, max, RETRY);
    				}
    				break;
    			case 3:
    				if(*flagAltaElec == 0){
    					printf("Para dar de BAJA primero debe dar de ALTA \n");
    					fpurge(stdin);
    					getInt(&opcion, msg, msgError, min, max, RETRY);
    				}
    				break;
    			case 4:
    				if(*flagAltaElec == 0){
    					printf("Para LISTAR primero debe dar de ALTA \n");
    					fpurge(stdin);
    					getInt(&opcion, msg, msgError, min, max, RETRY);
    				}
    				break;
    			case 7:
    				if(*flagAltaElec == 0){
    				    printf("Para dar de ALTA una reparacion primero debe dar de ALTA un electrodomestico \n");
    				    fpurge(stdin);
    				    getInt(&opcion, msg, msgError, min, max, RETRY);
    				    }

    				break;
    			case 8:
    				if(*flagAltaElec == 0){
    				    printf("Para LISTAR primero debe dar de ALTA \n");
    				    fpurge(stdin);
    				    getInt(&opcion, msg, msgError, min, max, RETRY);
    				   }
    				break;
    			case 9:
    				if(*flagAltaElec == 0){
    				   printf("Para INFORMAR primero debe dar de ALTA \n");
    				   fpurge(stdin);
    				   getInt(&opcion, msg, msgError, min, max, RETRY);
    				   }
    			}

    	}while(*flagAltaElec == 0);
    }
   return opcion;
}

int printServicios(servicio* Servicios, int len)
{
	//printf("TXT1: %9s TXT2 %9s TXT3 %9s\n", txt1, txt2, txt3)
	/*	typedef struct{
	int id;
	char descripcion[25];
	int precio;
}servicio;*/

	int i;

	if(Servicios != NULL && len > 0){

		printf("\n ID   DESCRIPCION   PRECIO ");

		for (i = 0; i < len; i++){

				printf("\n %4d %20s %4d", Servicios[i].id, Servicios[i].descripcion, Servicios[i].precio);
		}
	}

 return 0;
}
int repaIsEmpty(reparacion* catalogo, int len, int* posicionRep){

	int retorno = -1;
	int i;
	if(catalogo != NULL && len >= 0 && posicionRep != NULL){
		for(i=0; i<len; i++){
			if(catalogo[i].isEmpty == 1){
				retorno =0;
				*posicionRep = i;
				break;
			}
		}
	}
	return retorno;
}

int AltaRep(reparacion* catalogo, int len, fecha* fechaReparacion, int lenFecha, cliente* Clientes, int lenListado, int* posicionRep){



	char msgError[50];
	char msg[50];
	int min, max;

		if(catalogo != NULL && len > 0 && fechaReparacion != NULL && lenFecha > 0 && Clientes != NULL && lenListado > 0){

				strcpy(msg, "Ingrese ID de servicio");
				strcpy(msgError, "ERROR");
				min = 1;
				max = 200000;
				getInt(&catalogo[*posicionRep].idServicio, msg, msgError, min, max, RETRY);

				strcpy(msg, "Ingrese dia de alta de reparacion");
				strcpy(msgError, "ERROR");
				min = 1;
				max = 31;
				getInt(&fechaReparacion[*posicionRep].dia, msg, msgError, min, max, RETRY);

				strcpy(msg, "Ingrese mes de alta de reparacion");
				strcpy(msgError, "ERROR");
				min = 1;
				max = 12;
				getInt(&fechaReparacion[*posicionRep].mes, msg, msgError, min, max, RETRY);

				strcpy(msg, "Ingrese año de alta de reparacion");
				strcpy(msgError, "ERROR");
				min = 2019;
				max = 2020;
				getInt(&fechaReparacion[*posicionRep].anio, msg, msgError, min, max, RETRY);

				strcpy(msg, "Ingrese año de fabricacion del electrodomestico (modelo)");
				strcpy(msgError, "ERROR");
				min = 1900;
				max = 2020;
				getInt(&catalogo[*posicionRep].serie, msg, msgError, min, max, RETRY);

				printClientes(Clientes, 3);

				strcpy(msg, "Ingrese su ID");
				strcpy(msgError, "ERROR");
				min = 1000;
				max = 1003;
				getInt(&catalogo[*posicionRep].idCliente, msg, msgError, min, max, RETRY);

		}

	return 0;
}


int printRep(reparacion* catalogo, int len, fecha* momento, int lenMomento)
{


	int i;

	if(catalogo != NULL && len > 0 && momento != NULL && lenMomento > 0){

		printf("\n ID   SERIE   DIA    MES  AñO ");

		for (i = 0; i < len; i++){

			if(catalogo[i].isEmpty == 0){

				printf("\n %4d %6d %2d %2d %2d", catalogo[i].id, catalogo[i].serie , momento[i].dia, momento[i].mes, momento[i].anio );
			}
		}
	}

 return 0;
}
int listar0Rep(){

	int i;

	for(i = 0; i<len; i++){





	}




	return 0;
}
