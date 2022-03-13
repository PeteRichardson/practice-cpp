#include "log.h"

void setup_console_logging(plog::Severity sev=plog::debug) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender(plog::streamStdErr);
    plog::init(sev, &consoleAppender);
}
