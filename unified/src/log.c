#include "log.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

void read_logs(){
  printf("[LOG] Windows Event Log read(stub)\n");
}

#else 
void read_logs() {
  FILE *f = fopen("/var/log/auth.log", "r");
  if (!f) return;

  char line[2048];
  while (fgets(line, sizeof(line), f)){
    if (strstr(line, "failed")){
      printf("[ALERT] %s", line);
    }
  }
  fclose(f);
}
#endif 

