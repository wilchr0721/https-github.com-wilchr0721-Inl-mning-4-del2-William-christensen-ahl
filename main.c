
#include "car_header.h"


/************************************************************************
*
*	main: deklarerar 2 filpekare varav en anv�nds f�r att skriva till cars.txt
*		  den andra filpekaren anv�nds f�r att l�sa av cars.txt
*
*		  tre car struktar deklareras med dynamiskt minne som anv�nds f�r att f�rvara specefikationen av
*		  tre olika bilar.
*		  specifikationerna f�r bilarna skrivs sedan ut i commando promtern med hj�pl
*		  av en array ineh�lande car struct pekare.
*		  f�rgen f�r car1 �ndars till gr�nn och skrivs sedan utt igen.
*
*		  bilspecifikationerna skrivs sedan utt till filen cars.txt f�r
*		  att sedan l�sas av och skrivas utt igen fr�n ext filen.
*
*		  sist s� frig�rs minet d�r car objekten lagras.
*
************************************************************************/

void main(void)
{
	
	FILE* ostream = fopen("cars.txt", "w");
	FILE* car_file_ptr = fopen("cars.txt", "r");
	
	struct car* car1 = car_new("Volvo", "v70", "red", 1995, CAR_TRANSMISSION_MANUAL);
	struct car* car2 = car_new("BMW", "z3", "Blue", 2001, CAR_TRANSMISSION_AUTOMATIC);
	struct car* car3 = car_new("Skoda", "oktavia RS", "White", 2003, CAR_TRANSMISSION_MANUAL);
	

	car1->print_car(car1, 0);
	car2->print_car(car2, 0);
	car3->print_car(car3, 0);
	
	
	car1->change_transmission(car1);
	car1->change_color(car1, "Yellow");
	car1->print_car(car1, 0);

	car1->print_car(car1, ostream);
	car2->print_car(car2, ostream);
	car3->print_car(car3, ostream);

	fclose(ostream);

	file_read(stdout, car_file_ptr);

	free(car1);
	free(car2);
	free(car3);

	
}