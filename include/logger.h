#ifndef LOGGER_H_
#define LOGGER_H_

#include "typedef.h"
#include "queue.h"
#include "mmalloc.h"

typedef enum _loglevel {
    INFO,
    WARRNING,
    ERRORS,
    CRITICAL    
} LOGLEVEL;

typedef struct _logline {
    LOGLEVEL lvl;
    uint8 * msg;
} LOGLINE;

QUEUE * lglog;

/* init logger */
void logger_init(QUEUE * const lglog);

/* add line to log */
void putlog(QUEUE * const log, LOGLEVEL lvl, const int8 * const msg );

#endif // LOGGER_H_
