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
 * param 1: array de electrodomesticos por puntero
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

int menuInformes(int* opcion);
/*
 * BRIEF: menu de opciones
 * param 1: opcion elegida (por puntero)
 */
int elec2020(electrodomestico* list, int len, marca* Marcas, int lenMar);
/*
 * BRIEF: electrodomesticos modelo 2020
 * param 1: array de electrodomesticos
 * param 2: largo de array electrodomesticos
 * param 3: array de marcas
 * param 4: largo array marcas
 */
int idDescripcion(int idMarca, marca* Marcas, int lenMar, char descripcion[]);
/*
 * BRIEF: devuelve descripcion de marca por id
 * param 1: id de la marca
 * param 2: array marcas
 * param 3: largo array de marcas
 * param 4: descripcion de la marca
 */
int elecPorMarca(electrodomestico* list, int len, marca* Marcas, int lenMar, int idMarca);
/*
 * BRIEF: electrodomesticos de una marca especifica
 * param 1: array de electrodomesticos
 * param 2: largo de array electrodomesticos
 * param 3: array de marcas
 * param 4: largo array de marcas
 * param 5: id de la marca
 */
int reparacionIdCliente(electrodomestico* list, int lenElec, cliente* Clientes, int len, reparacion* catalogo, int lenCata, marca* Marcas, int lenMarcas);
/*
 * BRIEF: reparaciones por id del cliente
 * param 1: array de electrodomesticos
 * param 2: largo de array electrodomesticos
 * param 3: array de clientes
 * param 4: largo array de clientes
 * param 5: array reparaciones
 * param 6: largo array de reparaciones
 * param 7: array marcas
 * param 8: largo array de marcas
 */
#endif /* ELECTRODOMESTICO_H_ */
