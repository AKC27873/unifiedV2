#include "remediate.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>


void remediate_process(int pid){
  char cmd[64];
  snprintf(cmd, "taskkill /PID %d /F", pid);
  system(cmd);
}

#else
##include <signal.h>

void remediate_process(int pid){
  kill(pid, SIGKILL);
}
#endif
