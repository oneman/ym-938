/*C
 * *
 * */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned char u8;

int byte_to_words(u8 byte, char *text, size_t sz) {
/*  int ret = 0;
  if (sz < 14) exit(1);
  if (n < 10) {
    return snprintf(text, sz, "%s", digit_word(n));
  }
  if (n < 100) {
      printf("%s ", digit_word(n / 10));
      printf("%s", digit_word(n % 10));
      continue;
    }
    printf("%s ", digit_word(n / 100));
    printf("%s ", digit_word((n % 100) / 10));
    printf("%s\n", digit_word((n % 100) % 10));
*/
  return -1;
}

char *digit_word(u8 d) {
  if (d > 9) exit(1);
  if (d == 0) { return("zero"); }
  if (d == 1) { return("one"); }
  if (d == 2) { return("two"); }
  if (d == 3) { return("three"); }
  if (d == 4) { return("four"); }
  if (d == 5) { return("five"); }
  if (d == 6) { return("six"); }
  if (d == 7) { return("seven"); }
  if (d == 8) { return("eight"); }
  if (d == 9) { return("nine"); }
  exit(1);
}

void print_decimal_digits_in_natophone(u8 byte) {
  char s[14];
  memset(s, 0, sizeof(s));
  if (byte < 10) {
    snprintf(s, sizeof(s), "%s\n", digit_word(byte));
    return;
  }
  if (byte < 100) {
    printf("%s ", digit_word(byte / 10));
    printf("%s\n", digit_word(byte % 10));
    return;
  }
  printf("%s ", digit_word(byte / 100));
  printf("%s ", digit_word((byte % 100) / 10));
  printf("%s\n", digit_word((byte % 100) % 10));
}

int expand(u8 *buf, size_t sz) {
  int ret = 0;
  if (!buf) exit(1);
  if (sz < 1) exit(1);
  for (int b = 0; b < sz; b++) {
    print_decimal_digits_in_natophone(buf[b]);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int ret = 0;
  u8 page[4096];
  for (;;) {
    ret = read(1, page, sizeof(page));
    expand(page, ret);
  }
  printf("good and doneish\n");
  return 0;
}
