
#include "logger.h"

/* init logger */
void logger_init(QUEUE * const log) {
    queue_init(log, sizeof(LOGLINE));
}

/* add line to log */
void putlog(QUEUE * const log, LOGLEVEL lvl, LOGLINE * const logline ) {
    queue_append_back(log, logline);
}
