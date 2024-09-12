// получить строку из слов, нечетные вывести в обратном порядке, четные в прямом
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 0x1000
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
  const char* begin;
  const char* end;
} String;

static String oddWords[MAX_SIZE] = {};
static String evenWords[MAX_SIZE] = {};

void printString(const char* str, const char* end) {
  assert(str && end);

  for (const char* s = str; s != end; ++s) {
    if (!isspace(*s))
      fputc(*s, stdout);
  }
  fputc(' ', stdout);
}

void printReversedString(const char* str, const char* end) {
  assert(str && end);

  const char* s = end;
  do {
    --s;
    if (!isspace(*s))
      fputc(*s, stdout);
  } while (s != str);
  fputc(' ', stdout);
}

void printOddWords(unsigned count) {
  for (size_t i = 0; i < count; ++i) {
    printReversedString(oddWords[i].begin, oddWords[i].end);
    fputc(' ', stdout);
  }
  fputc('\n', stdout);
}

void printEvenWords(unsigned count) {
  for (size_t i = 0; i < count; ++i) {
    printString(evenWords[i].begin, evenWords[i].end);
    fputc(' ', stdout);
  }
  fputc('\n', stdout);
}

static void putWords(const char* str) {
  const char* prev = str;
  unsigned wordCount = 1;
  unsigned oddCount = 0;
  unsigned evenCount = 0;

  for (const char* s = str; *s != '\0'; ++s) {
    if (isspace(*s) && !isspace(*(s - 1))) {
      if (wordCount & 0x1) {
        oddWords[oddCount++] = (String){prev, s};
      } else {
        evenWords[evenCount++] = (String){prev, s};
      }
      ++wordCount;
      prev = s + 1;
    }
  }
  printOddWords(oddCount);
  printEvenWords(evenCount);
}

int main() {
  char str[MAX_SIZE] = {};
  fgets(str, sizeof(str), stdin);
  putWords(str);

  return 0;
}
