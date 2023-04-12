#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>

/*
   flag = "flag{w3ll_d0ne_y0ung_pad4wan}"
   option = "--d0n7l00k@m3"

   Used ghidra adn IDA Free (static analysis), to compile do:
   `gcc -lssl -lcrypto decrypt_data.c -o decrypt_data`.

   Also, you can run next command to get the flag:
   `./secr3tfl4g --d0n7l00k@m3`
*/

unsigned char *decrypt_data(unsigned char *data) {
  const EVP_CIPHER *cipher = EVP_aes_128_ecb();
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  unsigned char *out = (unsigned char *)malloc(0x400);
  int in_len = strlen((char *)data);
  int out_len = 0;
  unsigned char *key =
      "\x92\x10\x57\x80\xb6\x5e\x8b\xa3\x6d\x3a\x88\x0e\xc6\x0f\x3d\xa5\x0";
  unsigned char *iv =
      "\x6c\xe5\xbf\x2f\x4c\xe9\x7e\xe2\xdb\x8e\x98\xda\xa8\xcb\x8f\xbc";

  EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv);
  EVP_DecryptUpdate(ctx, out, &out_len, data, in_len);
  EVP_DecryptFinal_ex(ctx, out + out_len, &out_len);
  EVP_CIPHER_CTX_free(ctx);

  return out;
}

int main(int argc, char **argv) {

  unsigned char *encrypted_flag =
      "\x14\x0f\xe1\xa0\xe8\xd5\x6c\x38\x4f\x84\xb2\xb9\x81\xbd\x75\x04\x09\xd2"
      "\xd4\x93\x2a\xbd\xa7\x28\x41\x26\xbf\x23\x28\x38\x7c\xed\x00\x00\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
  unsigned char *encrypted_option =
      "\xab\x88\x06\xa0\x8a\x17\xf6\x25\x1d\x4c\x44\x92\x88\x2b\x33\xc0\x00\x00"
      "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
  unsigned char *decrypted_flag = decrypt_data(encrypted_flag);
  unsigned char *decrypted_option = decrypt_data(encrypted_option);

  printf("flag: %s\noption: %s\n", decrypted_flag, decrypted_option);
}
