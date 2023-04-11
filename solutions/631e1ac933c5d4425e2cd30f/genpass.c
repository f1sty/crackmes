#include <stdio.h>

/* correct_password = "Ala ma kota." */
/* it's "what a cat" on arabic:)     */
int main(int argc, char *argv[]) {

  char decode_vector[] = {0xEB, 0xC6, 0xCB, 0x8A, 0xC7, 0xCB,
                          0x8A, 0xC1, 0xC5, 0xDE, 0xCB, 0x84};

  for (int i = 0; i <= 11; i++) putc(decode_vector[i] ^ 0xffffffaa, stdout);

  return 0;
}
