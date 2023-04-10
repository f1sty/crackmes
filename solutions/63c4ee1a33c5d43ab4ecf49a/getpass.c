#include <stdio.h>
#include <stdlib.h>
/* #include <time.h> */

int main(void) {
  char *password = (char *)malloc(sizeof(char) * 15);
  int shift = 1;
  /* TODO: execute crackme only on seconds ending on 1, 4 or 7 */
  /* time_t now; */
  /* struct tm *time_tm; */

  /* time(&now); */
  /* time_tm = localtime(&now); */

  password[0] = '%';
  password[1] = 200 >> shift;
  password[2] = 0xd4 >> shift;
  password[3] = 'k';
  password[4] = 0x50 >> shift;
  password[5] = '9';
  password[6] = '^';
  password[7] = 0xf6 >> shift;
  password[8] = '.';
  password[9] = 'f';
  password[10] = 0x80 >> shift;
  password[0xb] = '1';
  password[0xc] = 'F';
  password[0xd] = 0x68 >> shift;
  /* password = "%d&k(9^{.f@1F4" */

  printf("%s\n", password);

  free(password);
  password = NULL;
}
