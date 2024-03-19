/*C
 * *
 * */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "table.h"

typedef unsigned char u8;

void contract(char *buf, size_t sz) {
}

int main(int argc, char *argv[]) {
  int ret = 0;
  char line[1024];
  for (;;) {
    ret = read(STDIN_FILENO, line, sizeof(line));
    if (ret == 0) break;
    contract(line, ret);
  }
  return 0;
}
