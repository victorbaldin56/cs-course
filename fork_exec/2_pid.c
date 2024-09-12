/* Пример программы печатающей значения PPID и PID для текущего процесса */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid, ppid;

  pid = getpid();
  ppid = getppid();

  printf("My pid = %d, my ppid = %d\n", pid, ppid);
}
