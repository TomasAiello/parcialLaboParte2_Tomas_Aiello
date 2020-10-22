/*
 * servicio.h
 *
 *  Created on: 15 oct. 2020
 *      Author: samotaiello
 */

#ifndef REPARACION_H_
#define REPARACION_H_

#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include <string.h>
#include "string.h"
#include <ctype.h>
#include "cliente.h"



typedef struct{
	int dia, mes, anio;
}fecha;


typedef struct{
	int id;
	char descripcion[25];
	int precio;
}servicio;


typedef struct{
	int id, serie, idServicio, isEmpty, idCliente;
	fecha fechaReparacion;

}reparacion;


int initArray2(reparacion* list, int len);
/*
 * BRIEF: inicializa un array
 * param 1: array de reparaciones por puntero
 * param 2: largo del array
 */
int initArray3(fecha* list, int len);
/*
 * BRIEF: inicializa un array
 * param 1: array de fecha por puntero
 * param 2: largo del array
 */
int getInt(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
/*
 * BRIEF: devuelve un numero entero por puntero, validado y con cantidad de intentos limitadas
 * param 1: punto del numero a obtener
 * param 2: mensaje 1
 * param 3: mensaje de error
 * param 4: minimo numero a obtener
 * param 5: maximo numero a obtener
 * param 6: cantidad de reintentos
 */
int getFloat(float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
/*
 * BRIEF: devuelve un numero flotante por puntero, validado y con cantidad de intentos limitadas
 * param 1: punto del numero a obtener
 * param 2: mensaje 1
 * param 3: mensaje de error
 * param 4: minimo numero a obtener
 * param 5: maximo numero a obtener
 * param 6: cantidad de reintentos
 */
int utn_menu(int* flagAltaElec, int* flagAltaRep);
/*
 * BRIEF: menu de opciones validadas
 * param 1: bandera de alta de electrodomestico
 * param 2: bandera de alta de reparacion
 */
int printServicios(servicio* Servicios, int len);
/*
 * BRIEF: listar servicios disponibles
 * param 1: puntero del array Servicios
 * param 2: largo del array
 */

int repaIsEmpty(reparacion* catalogo, int len, int* posicionRep);
/*
 * BRIEF: busca posiciones libres en el array
 * param 1: largo del array
 * param 2: posicion del array en la que escribira la funcion
 */
int AltaRep(reparacion* catalogo, int len, fecha* fechaReparacion, int lenFecha, cliente* Clientes, int lenListado, int* posicionRep);
/*
 * BRIEF: dar de alta una reparacion
 * param 1: array de reparacion
 * param 2: largo del array reparacion
 * param 3: array de fecha
 * param 4: largo del array fecha
 * param 5: array clientes
 * param 6: largo del array clientes
 * param 7: posicion en la que escribira la funcion
 */
int printRep(reparacion* catalogo, int len, fecha* momento, int lenMomento);
/*
 * BRIEF: listado de reparaciones dadas de alta
 * param 1: largo del array
 * param 2: array fecha
 * param 3: largo del array fecha
 */

#endif /* REPARACION_H_ */
