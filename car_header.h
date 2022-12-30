
/********************************************************************************
* car.h: Innehåller funktionalitet för hantering av en car struct inhållande
*		 Funtioner som behandlar en car obejt inehållande:
*		 namn,model,färg,årgång och växelåda.
********************************************************************************/

/* includeringsdirektiv */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#ifndef CAR_HEADER_H_
#define CAR_HEADER_H_

/* enum car_transmission använd som variabel för att beskriva bilens växelåda. */
enum car_transmission
{
	CAR_TRANSMISSION_MANUAL,
	CAR_TRANSMISSION_AUTOMATIC
};

/********************************************************************************************
* 
*  car strukten:  inehåler specifikationer för en bil och funtionspekare för 
*				  utskrift av bilens specifikationer. den inehåller även två 
*				  funtioner som kan användas för att ändra färg eller typ av växellåda. 
* 
*********************************************************************************************/
struct car
{
	const char* name;
	char* model;
	char* color;
	uint16_t year_of_launch;
	enum car_transmission transmission;
	void (*print_car)(struct car* self, FILE* ostream);
	void (*change_color)(struct cars* self, char* new_color);
	void (*change_transmission)(struct cars* self);
};



/************************************************************************
*
* car_init: tar emot specifikationer för en bil och placerar in dom i en car struct.
*
*       *	self:	pekare till car strukt där bilens specifikationer skall placeras in.
*		*	name:	char pekare som inehåller namnet på bilen, sparas i car strukten self.
*		*	model:	char pekare som inehåller model på bilen. sparas i car strukten self.
*		*	color:	char pekare som inehåller bilens färg. sparas i car strukten self.
*		*	year:	året då bilen tilvärkades. sparas i car strukten self.
*		*	transmisson: variabel som anger bilens växel. sparas i car strukten self.
*
************************************************************************/
void car_init(struct car* self,
	char* name,
	char* model,
	char* color,
	uint16_t year,
	enum car_transmisson transmisson);

/************************************************************************
*
* cars_prin: tar emot en array med car objekt. itererar genom arrayen
*			 och skriver utt varje objekt med funtionen car_print.
*
*       *  car_array: pekare till arrayen med car objekt som skall skrivas ut.
*		*  size_of:array: storleken för arayen.
*		*  ostream: filpekare som anger vart car obejkten skall skrivar ut.
*
************************************************************************/
void cars_print(struct cars* car_array[], uint8_t  size_of_array, FILE* ostream);

/************************************************************************
*
*	cars_clear: nollställer samtliga variabler i ett car objekt.
*
*       *  self: pekare till a car objektet som skall nollställas.
*
************************************************************************/
void car_clear(struct car* self);

/************************************************************************
*
* car_delete: tar emot en car struct pekare pekare.
*			  frigör minet som car strukten uptar.
*			  och sätter car strukt pekaren till 0.
*
*       *   self:	pekare till car strukt som skall raderas.
*
************************************************************************/
void car_delete(struct car** delete_car);


/************************************************************************
*
*	file_read: läser av en text fil och skriver utt den till angiven fill pekare.
*			   använder fgets för att läsa en textfill som sparas i en till fälig array
*			   skriver ut den till ostream.
*
*       *  self: pekare till a car objektet som skall nollställas.
*
************************************************************************/
void file_read(FILE* ostream, FILE* file_read);

/************************************************************************
*
* car_new: tar emot specifikationer för en bil.  skapar och allokerar mine för en car struckt.
*		   fyller sedan car struckten med specifikationerna med hjälp av funtionen car_init.
*		   returnerar sedan car structen.
*
*		*	name:	char pekare som inehåller namnet på bilen,
*		*	model:	char pekare som inehåller model på bilen.
*		*	color:	char pekare som inehåller bilens färg.
*		*	year:	året då bilen tilvärkades.
*		*	transmisson: variabel som anger bilens växel.
*
************************************************************************/
struct car* car_new(const char* brand,
	const char* model,
	const char* color,
	uint16_t year_of_launch,
	enum car_transmission transmission);

#endif /* CAR_HEADER_H_ */
