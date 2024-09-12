/* Программа, иллюстрирующая использование системных вызовов open(), read() и close() для чтения информации из файла */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int fd;
  char string[60];

  /* Попытаемся открыть файл с именем в первом параметре выззова только
  для операций чтения */

  if((fd = open(argv[1], O_RDONLY)) < 0) {

    /* Если файл открыть не удалось, печатаем об этом сообщение и прекращаем работу */
    printf("Can\'t open file\n");
    exit(-1);
  }

  /* Читаем фаил пока не кончится и печатаем */
  ssize_t size = read(fd, string, 60);
  printf("%s\n", string); /* Печатаем прочитанное*/

  /*  Записываем файл под новым именем */
  /* Закрываем файл */
  if(close(fd) < 0) {
    printf("Can\'t close file\n");
  }
  /*  Открываем файл в редакторе */
  return 0;
}