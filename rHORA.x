/*rhora.x*/
enum horastat{
HORA_OK = 0, /*no error*/
HORA_NOK = 1 /*error*/
};
/*valor de la hora*/
union segactual switch(horastat status){
case HORA_OK:
long segundos;
default:
void;
};
/*Procedimiento remoto de la hora*/
program HORA_PROGRAM{
version HORA_VERSION{
segactual OBTEN_SEGUNDOS(void) = 1;
}=1;
}=0x30; /*Aquí se pone un valor distinto por el alumno*/
