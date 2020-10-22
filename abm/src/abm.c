/*
 ============================================================================
 Name        : abm.c
 Author      : Tomas Aiello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include <string.h>
#include "string.h"
#include <ctype.h>
#include "cliente.h"

#define TAM 1000
#define RETRY 5

int main(void) {
	setbuf(stdout, NULL);

		int flagAltaElec = 0;
		int flagAltaRep = 0;
		int opcion;
		int idElec = 0;
		int posicion = 0;
		int posicionRep = 0;
		char resp;
		char msg[50];
		char msgError[50];
		int min, max;
		int i;
		int auxIdElec =0;
		int order;
		int idRep = 0;

		electrodomestico list[TAM];
		reparacion catalogo[TAM];
		fecha momento[TAM];

		servicio Servicios[] = {{20000, "Garantia", 250}, {20001, "Mantenimiento", 500}, {20002, "Respuesto", 400}, {20003, "Refaccion", 600} };
		marca Marcas[] = {{1, "Whirpool"}, {2, "Sony"}, {3, "Liliana"}, {4, "Gafa"}, {5, "Phillips"}};
		cliente Clientes[] = {{"Jorge", "Lopez", 1000},{"Raul", "Gonzalez", 1001},{"Yanina", "Scudero", 1002},{"Mauricio", "Davila", 1003}};

		initArray(list, TAM);
		initArray2(catalogo, TAM);
		initArray3(momento, TAM);

		opcion = utn_menu(&flagAltaElec, &flagAltaRep);

		switch(utn_menu(&flagAltaElec, &flagAltaRep)){

			case 1:
				do {
						elecIsEmpty(list, TAM, &posicion);

							if (list[posicion].isEmpty == 1) {

								idElec++;
								list[posicion].id = idElec;

								AltaElec(list, TAM, list[posicion].serie, list[posicion].idMarca, list[posicion].modelo);
								list[posicion].isEmpty = 0;

							}
							else {
								printf("\n No hay posiciones libres");
							}

							printf("\nEl alta a sido exitosa! \nQuiere dar de ALTA otro electrodomestico? s/n");
							fpurge(stdin);
							scanf("%c", &resp);

						} while (resp == 's');

						opcion = utn_menu(&flagAltaElec, &flagAltaRep);

						break;
			case 2:

					strcpy(msg, "\nIngrese el numero de ID");
					strcpy(msgError, "\nID inexistente");
					min = 1;
					max = idElec;
					getInt(&auxIdElec, msg, msgError, min, max, RETRY);

						for (i = 1; i < idElec; i++) {
							if (list[i].id == auxIdElec) {
								posicion = i;
								modificarElec(list, TAM, list[posicion].id, &posicion);
								break;
							}
						}

						break;


			case 3:

				strcpy(msg, "\nIngrese el numero de ID");
				strcpy(msgError, "\nID inexistente");
				min = 1;
				max = idElec;
				getInt(&auxIdElec, msg, msgError, min, max, RETRY);

				for (i = 1; i < idElec; i++) {
					if (list[i].id == auxIdElec) {
						posicion = i;
						bajaElec(list, TAM, list[posicion].id, &posicion);
						break;
					}
				}
				break;

			case 4:

				strcpy(msg,
						"\nDesea INFORMAR por modelo - ascendente o descendente (0-1, respectivamente) ? ");
				strcpy(msgError, "\nOpcion no contemplada");
				min = 0;
				max = 1;
				getInt(&order, msg, msgError, min, max, RETRY);

				ordenarElec(list, TAM, order);
				printElec(list, TAM);

				break;

			case 5:
				printMarcas(Marcas, 5);
				break;

			case 6:
				printServicios(Servicios, 4);
				break;

			case 7:

				printServicios(Servicios, 4);
				repaIsEmpty(catalogo, TAM, &posicionRep);

				if (catalogo[posicionRep].isEmpty == 1) {

					idRep++;
					catalogo[posicionRep].id = idRep;

					AltaRep(catalogo, TAM, momento, TAM, Clientes, 3, &posicionRep);
					catalogo[posicionRep].isEmpty = 0;
					flagAltaRep = 1;
					}
				else {
					printf("\n No hay posiciones libres");
					}

				break;
			case 8:
				if (flagAltaRep == 1){

				printRep(catalogo, TAM, momento, TAM);

				}
				else{
					printf("\n primero debe dar de ALTA una reparacion");
				}
				break;

		}

		return 0;
}
