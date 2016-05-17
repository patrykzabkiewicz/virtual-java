#ifndef LOGGER_H_
#define LOGGER_H_

typedef enum {
    INFO,
    WARRNING,
    ERROR,
    CRITICAL    
} LOGLEVEL;

typedef struct {
    uint32 type;
    uint8 * msg;
} LOGLINE;

QUEUE * log;

/* init logger */
void logger_init(QUEUE * const log);

/* add line to log */
void log(QUEUE * const log, LOGLEVEL lvl, LOGLINE * const logline );

#endif // LOGGER_H_
