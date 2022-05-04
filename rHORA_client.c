#include "rHORA.h"
#include <time.h>
#define Rmaquina "localhost"
static CLIENT *clte_rhora;

//se definen las variables globales del tiempo
struct fecha_t {int anio, mes, dia, hora, minutos;};


int obten_segundos(time_t *s)
{
struct segactual *segundos;
	//se crea un cliente del servicio de hora
	clte_rhora = clnt_create(Rmaquina, HORA_PROGRAM, HORA_VERSION, "udp");
	if(clte_rhora == NULL)
	return -1;
	segundos = (struct segactual*) malloc (sizeof(struct segactual));
	//se realiza la rpc
	segundos = obten_segundos_1(NULL, clte_rhora);
	if(segundos == NULL) //error de comunicación con el servidor
	return -1;
	else if (segundos->status == HORA_NOK) //error de ejecución
	return -1;
	else // se recogen los segundo devueltos
	*s = (time_t)segundos->segactual_u.segundos;
}

struct fecha_t * obten_fecha(time_t * s)
{
struct fecha_t * fecha;
//Declaración de un puntero a un objeto con la información del tiempo
struct tm *puntero_estructura_tiempo;
fecha = (struct fecha_t*) malloc (sizeof(struct fecha_t));
//Actualización del objeto estructura de tiempo con los segundos
puntero_estructura_tiempo = localtime(s);
//Estracción de la información desde la estructura tiempo
fecha->hora = puntero_estructura_tiempo->tm_hour;
fecha->minutos = puntero_estructura_tiempo->tm_min;
return fecha;
}

void escribe_hora(struct fecha_t * fecha)
{
printf("LA HORA ES: %i:%s%i \n", fecha->hora, fecha->minutos <10 ?"0": " ", fecha->minutos);
}

void
hora_program_1(char *host)
{
	CLIENT *clnt;
	int  result_1;
	time_t s;
	//char *obten_segundos_1_arg;
	struct fecha_t * fechactual;

#ifndef	DEBUG
	clnt = clnt_create (host, HORA_PROGRAM, HORA_VERSION, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	clte_rhora = clnt;	
	result_1 = obten_segundos(&s);
	if (result_1 == -1) {
		clnt_perror (clnt, "call failed");
	}else{
		 fechactual = obten_fecha(&s);
		escribe_hora(fechactual);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
        hora_program_1 (host);
        exit (0);
 }