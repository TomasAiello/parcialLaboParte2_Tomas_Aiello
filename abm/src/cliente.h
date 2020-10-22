/*
 * cliente.h
 *
 *  Created on: 22 oct. 2020
 *      Author: samotaiello
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include <string.h>
#include "string.h"
#include <ctype.h>
#include "cliente.h"

typedef struct{
	char nombre[20];
	char apellido[20];
	int idCliente;
}cliente;

int printClientes(cliente* Clientes, int len);





#endif /* CLIENTE_H_ */
