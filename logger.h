#ifndef LOGGER_H_
#define LOGGER_H_

#include "typedef.h"
#include "queue.h"

typedef enum _loglevel {
    INFO,
    WARRNING,
    ERROR,
    CRITICAL    
} LOGLEVEL;

typedef struct _logline {
    uint32 type;
    uint8 * msg;
} LOGLINE;

QUEUE * lglog;

/* init logger */
void logger_init(QUEUE * const lglog);

/* add line to log */
void putlog(QUEUE * const log, LOGLEVEL lvl, LOGLINE * const logline );

#endif // LOGGER_H_
