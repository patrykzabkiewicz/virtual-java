
#include "logger.h"

/* init logger */
void logger_init(QUEUE * const log) {
    
}

/* add line to log */
void log(QUEUE * const log, LOGLEVEL lvl, LOGLINE * const logline ) {
    queue_push_back(log);
}
