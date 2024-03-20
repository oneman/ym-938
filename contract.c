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
  /* printf("contract\n"); */
  for (i = 0; i < 256; i++) {
    len = strlen(table[i]);
    if (len == sz) {
      if (memcmp(buf, table[i], len) == 0) {
        /*printf("%d\n", i);*/
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
  char linebuf[1024];
  for (;;) {
    ret = read(STDIN_FILENO, linebuf + pos, sizeof(linebuf) - pos);
    if (ret == 0) break;
    pos += ret;
    /*printf("read %d\n", ret);*/
    ret = 0;
    for (int i = 0; i < pos; i++) {
      if (linebuf[i] == '\n') {
        contract(linebuf, i);
        memmove(linebuf, linebuf + i + 1, pos - (i + 1));
        i = -1;
      }
    }
  }
  return 0;
}
