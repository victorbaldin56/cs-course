/* Пример программы для изменения пользовательского контекста (запуска новой
 * программы) в порожденном процессе. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  pid_t pid, ppid, chpid;
  int a = 0, result = 0;

  chpid = fork();

  if (chpid == -1) {
    /* Ошибка */
    printf("Can\'t fork a child process\n");

  } else if (chpid > 0) {
    /* Родительский процесс */
    a = a + 1;

    pid = getpid();
    ppid = getppid();

    printf("pid = %d, ppid = %d, result = %d\n", (int)pid, (int)ppid, a);

  } else {

    /* Порожденный процесс */

    /* Мы будем запускать команду cat c аргументом командной строки без
    изменения параметров среды, т.е. фактически выполнять команду "cat имя
    файла", которая должна выдать содержимое данного файла на экран. Для
    функции execle в качестве имени программы мы указываем ее полное имя с
    путем от корневой директории. Первое слово в командной строке у нас должно
    совпадать с именем запускаемой программы. Второе слово в командной строке
    - это имя файла, содержимое которого мы хотим распечатать.
    */
    if (argc > 1) {
      result = execle("/bin/cat", "/bin/cat", argv[1], 0, envp);
    }

    if (result < 0) {
      /* Если возникла ошибка, то попадаем сюда*/
      printf("Error on program start\n");
      exit(-1);
    }
  }

  return 0;
}
