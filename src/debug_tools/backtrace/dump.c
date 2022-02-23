#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<execinfo.h>

#define BACKTRACE_SIZE 16

void dump() {
  int j, nptrs;
  void *buffer[BACKTRACE_SIZE];
  char **str;

  nptrs = backtrace(buffer, BACKTRACE_SIZE);

  printf("backtrace() returned %d addresses\n", nptrs);

  str = backtrace_symbols(buffer, nptrs);

  if (str == NULL) {
    perror("backtrace symbols");
    exit(EXIT_FAILURE);
  }

  for (j=0; j<nptrs; j++) {
    printf("  [%02d] %s\n", j, str[j]);
  }

  free(str);
}

void signal_handler(int sig) {
  printf("\n=====================>>> catch signal %d <<<=====================\n", sig);

  printf("Dump stack start ... \n");
  dump();
  printf("Dump stack end ... \n");

  signal(sig, SIG_DFL); // recovery default signal
  raise(sig);
}
