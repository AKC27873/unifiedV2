#include "monitor.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#include <tlhelp32.h>

int get_processes(process_info *list, int max){
  HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  PROCESSENTRY32 pe = { .dwsize = sizeof(pe)};
  int count = 0;

  if (process32First(snap, &pe)){
    do {
      list[count].pid = pe.th32ProcessID;
      snprintf(list[count].name, 256, "%ws", pw.szExeFile);
      list[count].cpu = 0.0f;
      count++;
    } while(Process32Next(snap, &pe) && count < max);
  }
  CloseHandle(snap);
  return count;
}

#else 
#include <dirent.h>
#include <string.h>

int get_processes(process_info *list, int max){
  DIR *d = opendir("/proc");
  struct dirent *ent;
  int count = 0;

  while ((ent = readdir(d)) && count < max){
    if (ent->d_type == DT_DIR) {
      int pid = atoi(ent->d_name);
      if (pid > 0){
        list[count].pid = pid;
        snprintf(list[count].name, 256, "%d", pid);
        list[count].cpu = 0.0f;
        count++;
      }
    }
  }
  closedir(d);
  return count++;
}
#endif
