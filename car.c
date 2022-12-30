
/********************************************************************************
* car.c: Inneh�ller funktionalitet f�r hantering av en car struct inh�llande
*		 Funtioner som behandlar en car obejt ineh�llande:
*		 namn,model,f�rg,�rg�ng och v�xel�da.
********************************************************************************/

#include "car_header.h"

static void car_change_color(struct car* self, char* new_color);
static void car_print(struct car* self, FILE* ostream);
static void car_change_transmission(struct car* self);


/************************************************************************
*
* car_init: tar emot specifikationer f�r en bil och placerar in dom i en car struct.
*
*       *	self:	pekare till car strukt d�r bilens specifikationer skall placeras in.
*		*	name:	char pekare som ineh�ller namnet p� bilen, sparas i car strukten self.
*		*	model:	char pekare som ineh�ller model p� bilen. sparas i car strukten self.
*		*	color:	char pekare som ineh�ller bilens f�rg. sparas i car strukten self.
*		*	year:	�ret d� bilen tilv�rkades. sparas i car strukten self.
*		*	transmisson: variabel som anger bilens v�xel. sparas i car strukten self.
*
************************************************************************/

void car_init(struct car* self, char* name, char* model, char* color, uint16_t year, enum car_transmisson transmisson)
{
	self->name = name;
	self->model = model;
	self->color = color;
	self->year_of_launch = year;
	self->transmission = transmisson;
	self->change_color = car_change_color;
	self->change_transmission = car_change_transmission;
	self->print_car = car_print;
	return;
}

/************************************************************************
*
* car_print: tar emot en car struct pekare och skriver ut ineh�llet.
*			 ostream anger vart car strukten skall skrivas ut. om ostream
*			 �r 0 s� skrivs ineh�llet ut till commandopromten.
*
*       *   self:	pekare till car strukt d�r bilens specifikationer skall placeras in.
*		* ostream:	filpekare som anger vad bilspecefikationerna skall skrivas ut.
************************************************************************/
static void car_print(struct car* self, FILE* ostream)
{
	
	if (!ostream) ostream = stdout;

	fprintf(ostream, "-----------------------------------------------------\n");

	fprintf(ostream, "name: %s\n", self->name);
	fprintf(ostream, "model: %s\n", self->model);
	fprintf(ostream, "color: %s\n", self->color);
	fprintf(ostream, "year of launch: %d\n", self->year_of_launch);

	if (self->transmission == CAR_TRANSMISSION_MANUAL) fprintf(ostream, "transmission: Manual\n");
	else fprintf(ostream, "transmission: Automatic\n");

	fprintf(ostream, "-----------------------------------------------------\n");

	return;
}

/************************************************************************
*
* car_delete: tar emot en car struct pekare pekare.
*			  frig�r minet som car strukten uptar.
*			  och s�tter car strukt pekaren till 0.
*
*       *   self:	pekare till car strukt som skall raderas.
*
************************************************************************/
void car_delete(struct car** self)
{
	free(*self);
	*self = 0;
	return;
}

/************************************************************************
*
* car_change_color: �ndrar f�rgen i en car struckt.
*
*       *  self: pekare till car objektet d�r f�rgen skall �ndras.
*		* new_color: pekare till en char array inh�llande den nya f�rgen.
*
************************************************************************/
static void car_change_color(struct car* self, char* new_color)
{
	self->color = new_color;
	return;
}

/************************************************************************
*
* car_change_transmission: �ndrar v�xel i en car struckt.
*
*       *  self: pekare till car objektet d�r v�xeln skall �ndras.
*
************************************************************************/
static void car_change_transmission(struct car* self)
{
	self->transmission = !self->transmission;
	return;
}

/************************************************************************
*
* cars_prin: tar emot en array med car objekt. itererar genom arrayen
*			 och skriver utt varje objekt med funtionen car_print.
*
*       *  car_array: pekare till arrayen med car objekt som skall skrivas ut.
*		*  size_of:array: storleken f�r arayen.
*		*  ostream: filpekare som anger vart car obejkten skall skrivar ut.
*
************************************************************************/
static void cars_print(struct cars* car_array[], uint8_t size_of_array, FILE* ostream)
{
	for (uint8_t i = 0; i < size_of_array; i++)
	{
		car_print(car_array[i], ostream);
	}
	return;
}


/************************************************************************
*
*	cars_clear: nollst�ller samtliga variabler i ett car objekt.
*
*       *  self: pekare till a car objektet som skall nollst�llas.
*
************************************************************************/
void car_clear(struct car* self)
{
	self->name = 0;
	self->model = 0;
	self->color = 0;
	self->year_of_launch = 0;
	self->transmission = 0;
	return;
}

/************************************************************************
*
* car_new: tar emot specifikationer f�r en bil.  skapar och allokerar mine f�r en car struckt.
*		   fyller sedan car struckten med specifikationerna med hj�lp av funtionen car_init.
*		   returnerar sedan car structen.
*
*		*	name:	char pekare som ineh�ller namnet p� bilen,
*		*	model:	char pekare som ineh�ller model p� bilen.
*		*	color:	char pekare som ineh�ller bilens f�rg.
*		*	year:	�ret d� bilen tilv�rkades.
*		*	transmisson: variabel som anger bilens v�xel.
*
************************************************************************/
struct car* car_new(const char* name, const char* model, const char* color, uint16_t year_of_launch, enum car_transmission transmission)
{
	struct car* self = (struct car*)malloc(sizeof(struct car));
	if (!self) return;
	car_init(self, name, model, color, year_of_launch, transmission);
	return self;
}

/************************************************************************
*
*	file_read: l�ser av en text fil och skriver utt den till angiven fill pekare.
*			   anv�nder fgets f�r att l�sa en textfill som sparas i en till f�lig array
*			   skriver ut den till ostream.
*
*       *  self: pekare till a car objektet som skall nollst�llas.
*
************************************************************************/
void file_read(FILE* ostream, FILE* file_read)
{
	if (!ostream) ostream = stdout;
	char s[100] = { '\0' };

	while (fgets(s, (int)sizeof(s), file_read))
	{
		fprintf(ostream, "%s", s);
	}
	return;
}
