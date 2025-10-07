#include "textLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// main 
int main(int argc, char *argv[])
{
  // checks if theres the correct amount of arguments
  if (argc != 5)
  {
    printf("\nUsage: <caesar or vigenere> <en- or decrypt> <text> <key>\n");
    return 1;
  }
// asigns arguments
  const char *algorithm = argv[1];
  const char *mode = argv[2];
  const char *text = argv[3];
  const char *key = argv[4];

  // exits if the mode is not encode or decode 
  if (mode[0] != 'e' && mode[0] != 'd')
  {
    printf("Invalid mode. Use 'e' or 'd'.\n");
    return 1;
  }
  
  // exits if the text or key is of lenth 0; burde ikke være nødventigt, men heller ektra sikker
  if (strlen(text) == 0 || strlen(key) == 0)
  {
    printf("Text and key cannot be empty.\n");
    return 1;
  }

  // går til enten ceasar or vinegére baseret på input
  if (algorithm[0] == 'c')
    goto Caesar;
  if (algorithm[0] == 'v')
    goto Vigenere;
  goto End;

Caesar:
// runs through each char in the input with the key (wraps around) in caesar
for (int i = 0; i < strlen(text); i++)
{
  printf_s("%c", caesar(text[i], (int)key[talCirkulærRunding(i, strlen(key) - 1)] + 4, mode[0]));
}
goto End;

Vigenere:
// runs through each char in the input with the key (wraps around) in vingenére
  for (int i = 0; i < strlen(text); i++)
  {
    printf_s("%c", vigenere(text[i], key[talCirkulærRunding(i, strlen(key) - 1)], mode[0]));
  }
  goto End;

End:
  return 0;
}