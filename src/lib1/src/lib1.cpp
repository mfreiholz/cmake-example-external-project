#include "lib1/api.h"
#include <stdio.h>
#include "humblelogging/api.h"

using namespace humble::logging;

HUMBLE_LOGGER(HL, "lib1");

void lib1func()
{
  // Initialize humble logging.
  Factory &fac = Factory::getInstance();

  // Change the default LogLevel, which every NEW Logger will have.
  fac.setDefaultLogLevel(LogLevel::All);
  
  // Change the default Formatter (optional).
  fac.setDefaultFormatter(new PatternFormatter("[%date] [%lls] [line=%line] [file=%filename] %m\n"));
  
  // Add Appender which doesn't log anywhere.
  fac.registerAppender(new NullAppender());

  // Add Appender which logs to STDOUT.
  ConsoleAppender *consoleAppender = new ConsoleAppender();
  fac.registerAppender(consoleAppender);

  fprintf(stdout, "lib1func\n");
  HL_DEBUG(HL, "lib1func logging");
}