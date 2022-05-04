/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RHORA_H_RPCGEN
#define _RHORA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


enum horastat {
	HORA_OK = 0,
	HORA_NOK = 1,
};
typedef enum horastat horastat;

struct segactual {
	horastat status;
	union {
		long segundos;
	} segactual_u;
};
typedef struct segactual segactual;

#define HORA_PROGRAM 0x30
#define HORA_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define OBTEN_SEGUNDOS 1
extern  segactual * obten_segundos_1(void *, CLIENT *);
extern  segactual * obten_segundos_1_svc(void *, struct svc_req *);
extern int hora_program_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define OBTEN_SEGUNDOS 1
extern  segactual * obten_segundos_1();
extern  segactual * obten_segundos_1_svc();
extern int hora_program_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_horastat (XDR *, horastat*);
extern  bool_t xdr_segactual (XDR *, segactual*);

#else /* K&R C */
extern bool_t xdr_horastat ();
extern bool_t xdr_segactual ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RHORA_H_RPCGEN */