#include "log.h"

void setup_console_logging(plog::Severity sev=plog::debug) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);
    plog::get()->setMaxSeverity(sev);
}
