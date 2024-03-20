/*C
 * *
 * */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "table.h"

typedef unsigned char u8;

int contract(char *buf, size_t sz) {
  int i;
  int len;
  u8 out[1];
  if (sz == 0) exit(1);
  for (i = 0; i < 256; i++) {
    len = strlen(table[i]);
    if (len == sz) {
      if (memcmp(buf, table[i], len) == 0) {
        out[0] = i;
        write(STDOUT_FILENO, out, 1);
        return sz;
      }
    }
  }
  exit(1);
  return -1;
}

int main(int argc, char *argv[]) {
  int ret = 0;
  int pos = 0;
  char line[96];
  u8 byte = 0;
  for (;;) {
    ret = read(STDIN_FILENO, line + pos, 1);
    if (ret != 1) exit(1);
    byte = line[pos];
    pos += ret;
    if (byte == '\n') {
      contract(line, pos - 1);
      pos = 0;
    }
  }
  return 0;
}
