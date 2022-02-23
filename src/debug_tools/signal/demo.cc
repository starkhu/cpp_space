#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
#include "case.h"

using namespace std;

void signalHandler(int signum ) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    exit(signum);
}

int main () {
  abort_signal(signalHandler);

  calculate_irregular_signal(signalHandler);

  send_interrupt_singal();

  return 0;
}
