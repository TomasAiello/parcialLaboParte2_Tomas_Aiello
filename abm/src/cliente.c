/*
 * cliente.c
 *
 *  Created on: 22 oct. 2020
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

int printClientes(cliente* Clientes, int len)
{
	//printf("TXT1: %9s TXT2 %9s TXT3 %9s\n", txt1, txt2, txt3)
	/*	typedef struct{
	int id;
	char descripcion[25];
	int precio;
}servicio;*/

	int i;

	if(Clientes != NULL && len > 0){

		printf("\n ID   NOMBRE   APELLIDO ");

		for (i = 0; i < len; i++){

				printf("\n %4d %20s %20s",Clientes[i].idCliente, Clientes[i].nombre, Clientes[i].apellido );
		}
	}

 return 0;
}
