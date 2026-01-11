#pragma once

typedef struct {
  int pid;
  char name[256];
  float cpu;
}process_info;

int get_processes(process_info *list, int max);

