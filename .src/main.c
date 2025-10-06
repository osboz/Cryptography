#include "textLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  // printf("\n 0 %s \n 1 %s \n 2 %s \n 3 %s \n 4 %s\n", argv[0], argv[1], argv[2], argv[3], argv[4]);

  // printf_s("%c", caesar('A', 1 + 3, 'e'));
  // printf_s("%c\n", caesar('A', 1 + 3, 'd'));

  if (argc != 5)
  {
    printf("\nUsage: <caesar or vigenere> <en- or decrypt> <text> <key>\n");
    return 1;
  }

  const char *algorithm = argv[1];
  const char *mode = argv[2];
  const char *text = argv[3];
  const char *key = argv[4];

  if (mode[0] != 'e' && mode[0] != 'd')
  {
    printf("Invalid mode. Use 'e' or 'd'.\n");
    return 1;
  }

  if (strlen(text) == 0 || strlen(key) == 0)
  {
    printf("Text and key cannot be empty.\n");
    return 1;
  }

  if (algorithm[0] == 'c')
    goto Caesar;
  if (algorithm[0] == 'v')
    goto Vigenere;
  goto End;

Caesar:
  for (int i = 0; i < strlen(text); i++)
  {
    printf_s("%c", caesar(text[i], (int)key[talCirkulærRunding(i, strlen(key) - 1)] + 4, mode[0]));
  }
  goto End;

Vigenere:
  for (int i = 0; i < strlen(text); i++)
  {
    printf_s("%c", vigenere(text[i], key[talCirkulærRunding(i, strlen(key) - 1)], mode[0]));
  }
  goto End;

End:
  return 0;
}