/*C
 * *
 * */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "table.h"

typedef unsigned char u8;

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

char *nato(char letter) {
  if ((letter == 'a') || (letter == 'A')) return "alpha";
  if ((letter == 'b') || (letter == 'B')) return "bravo";
  if ((letter == 'c') || (letter == 'C')) return "charlie";
  if ((letter == 'd') || (letter == 'D')) return "delta";
  if ((letter == 'e') || (letter == 'E')) return "echo";
  if ((letter == 'f') || (letter == 'F')) return "foxtrot";
  if ((letter == 'g') || (letter == 'G')) return "golf";
  if ((letter == 'h') || (letter == 'H')) return "hotel";
  if ((letter == 'i') || (letter == 'I')) return "india";
  if ((letter == 'j') || (letter == 'J')) return "juliett";
  if ((letter == 'k') || (letter == 'K')) return "kilo";
  if ((letter == 'l') || (letter == 'L')) return "lima";
  if ((letter == 'm') || (letter == 'M')) return "mike";
  if ((letter == 'n') || (letter == 'N')) return "november";
  if ((letter == 'o') || (letter == 'O')) return "oscar";
  if ((letter == 'p') || (letter == 'P')) return "papa";
  if ((letter == 'q') || (letter == 'Q')) return "quebec";
  if ((letter == 'r') || (letter == 'R')) return "romeo";
  if ((letter == 's') || (letter == 'S')) return "sierra";
  if ((letter == 't') || (letter == 'T')) return "tango";
  if ((letter == 'u') || (letter == 'U')) return "uniform";
  if ((letter == 'v') || (letter == 'V')) return "victor";
  if ((letter == 'w') || (letter == 'W')) return "whiskey";
  if ((letter == 'x') || (letter == 'X')) return "xray";
  if ((letter == 'y') || (letter == 'Y')) return "yankee";
  if ((letter == 'z') || (letter == 'Z')) return "zulu";
  return "";
}

void print_decimal_digits_in_natophone(u8 byte) {
  int ret = 0;
  char s[14];
  memset(s, 0, sizeof(s));
  if (byte < 10) {
    ret += snprintf(s, sizeof(s), "%s", digit_word(byte));
  } else {
    if (byte < 100) {
      ret += snprintf(s + ret, sizeof(s) - ret, "%s", digit_word(byte / 10));
      ret += snprintf(s + ret, sizeof(s) - ret, "%s", digit_word(byte % 10));
    } else {
      ret += snprintf(s + ret, sizeof(s) - ret, "%s", digit_word(byte / 100));
      ret += snprintf(s + ret, sizeof(s) - ret, "%s",
                      digit_word((byte % 100) / 10));
      ret += snprintf(s + ret, sizeof(s) - ret, "%s",
                      digit_word((byte % 100) % 10));
    }
  }
  for (int c = 0; c < ret; c++) {
    printf("%s", nato(s[c]));
    if (c < (ret - 1)) {
      printf(" ");
    }
  }
  //printf("\n");
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

void dev() {
  u8 byte;
  printf("static char *table[] = \\\n{");
  for (byte = 0; byte < 255; byte++) {
    printf("\"");
    print_decimal_digits_in_natophone(byte);
    printf("\",\n");
  }
  printf("\"");
  print_decimal_digits_in_natophone(255);
  printf("\"};\n");
}

void dev2() {
  int i = 0;
  for (i = 0; i < 256; i++) {
   printf("Line %d: %s\n", i, table[i]);
  }
  exit(0);
}

int main(int argc, char *argv[]) {
  dev2();
  dev();
  return 0;
}
