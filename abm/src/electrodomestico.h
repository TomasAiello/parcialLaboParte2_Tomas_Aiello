/*
 * electrodomestico.h
 *
 *  Created on: 15 oct. 2020
 *      Author: samotaiello
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include <string.h>
#include "string.h"
#include <ctype.h>



typedef struct{
	int id;
	char descripcion[20];
}marca;


typedef struct{
	int id, serie, idMarca, modelo, isEmpty;

}electrodomestico;


int initArray(electrodomestico* list, int len);
/*
 * BRIEF: inicializa un array
 * param 1: array de reparaciones por puntero
 * param 2: largo del array
 */
int elecIsEmpty(electrodomestico* list, int len, int* posicion);
/*
 * BRIEF: busca posiciones libres del array
 * param 1: array de electrodomesticos por puntero
 * param 2: largo del array
 * param 3: posicion del array en la que se escribira posteriormente la informacion
 */
int AltaElec(electrodomestico* list, int len, int serie, int idMarca, int modelo);
/*
 * BRIEF: dar de alta un electrodomestico
 * param 1: largo del array
 * param 2: campo numero de serie
 * param 3: campo id de marca (validado)
 * param 4: campo año de fabricacion
 */
int modificarElec(electrodomestico* list, int len, int id, int* posicion);
/*
 * BRIEF: modificar un electrodomestico
 * param 1: largo del array
 * param 2: campo id autoincremental y unico
 * param 3: posicion del array donde se escribira la informacion
 */
int bajaElec(electrodomestico* list, int len, int id, int* posicion);
/*
 * BRIEF: dar de baja un electrodomestico
 * param 1: largo del array
 * param 2: campo id autoincremental y unico
 * param 3: posicion del array donde se escribira la informacion
 */
int ordenarElec(electrodomestico* list, int len, int order);
/*
 * BRIEF: ordenamiento por modelo y numero de serie, order = 0 menor a mayor, order = 1 mayor a menor
 * param 1: largo del array
 * param 2: campo id autoincremental y unico
 * param 3: posicion del array donde se escribira la informacion
 */
int printElec(electrodomestico* list, int len);
/*
 * BRIEF: listar electrodomesticos dados de alta
 * param 1: array electrodomesticos (puntero)
 * param 2: largo del array
 */
int printMarcas(marca* Marcas, int len);
/*
 * BRIEF: listar marcas harcodeadas
 * param 1: array marcas (puntero)
 * param 2: largo del array
 */

#endif /* ELECTRODOMESTICO_H_ */
