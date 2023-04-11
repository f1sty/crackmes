#include <stdio.h>
#define KEY_LEN 19

/* correct_key = "{r0bot1+key-f0und_}" */
int main(int argc, char *argv[]) {
  char alphanum;
  char cracked_key[KEY_LEN];
  char input_key1[KEY_LEN];
  char input_key2[KEY_LEN] = {0x1a, 0x43, 0x53, 0x51, 0xa,  0x41, 0x56,
                              0x1c, 0x2,  0x5c, 0x18, 0x1c, 5,    3,
                              0x10, 0x5b, 3,    0x68, 0x14};

  for (int i = 0, toggle = 1; i < KEY_LEN; i++, toggle = !toggle)
    input_key1[i] = (toggle == 0 ? '0' : 'a') + i - (i / 10) * 10;

  for (int i = 0; i < KEY_LEN; i++) putc(input_key2[i] ^ input_key1[i], stdout);

  return 0;
}
