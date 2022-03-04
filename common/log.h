#ifndef LOG_H
#define LOG_H

#include <plog/Log.h>
#include <plog/Init.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Appenders/ColorConsoleAppender.h>

void setup_console_logging(plog::Severity sev=plog::debug) {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, &consoleAppender);
    plog::get()->setMaxSeverity(sev);
}

#endif