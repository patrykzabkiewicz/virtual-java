
#include "logger.h"

/* init logger */
void logger_init(QUEUE * const log) {
    queue_init(log, sizeof(LOGLINE));
}

/* add line to log */
void putlog(QUEUE * const log, LOGLEVEL lvl, const int8 * const msg ) {
    LOGLINE * logline;
    QUEUE_ELEM * qe;

    logline = (LOGLINE *) mmalloc(sizeof(LOGLINE));
    qe = (QUEUE_ELEM *) mmalloc(sizeof(QUEUE_ELEM));

    logline->lvl = lvl;
    logline->msg = (uint8 *)msg;
    qe->data = (void *)logline;

    queue_append_back(log, qe);
}
