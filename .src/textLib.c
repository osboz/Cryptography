#include <ctype.h>
#include <stdio.h>
#include "textLib.h"

int talCirkulærRundingMinMax(int input, int min, int max)
{
  // intervallet
  int interval = max - min;
  // fløt input så det starter fra 0
  int shiftedInput = input - min;
  // Læg intervallet til i tilfælde af negative tal
  int wrappedInput = (shiftedInput + interval) % interval;
  // Shift the result back to the original range
  int output = wrappedInput + min;

  return output;
}
/** version jeg ikke ville kunne bruge om 1 måned fordi jeg ville have glemt hvordan den virker
 * int talCirkulærRundingMinMax(int input, int min, int max)
 * {
 *   int interval = max - min + 1;
 *   return ((input - min) % interval + interval) % interval + min;
 * }
 */


int talCirkulærRunding(int input, int max)
{
  return ((input % (max + 1)) + (max + 1)) % (max + 1);
}

char caesar(char plaintext, int shift, char mode)
{
  if (mode == 'd')
    shift *= -1;
  return talCirkulærRunding(plaintext + (shift + 'A'), 25) + 'A';
}

char vigenere(char plaintext, char shift, char mode)
{
  // inverts the shift in we're in decode mode
  if (mode == 'd')
    shift *= -1;
  return talCirkulærRunding(plaintext + shift, 25) + 'A';
}

// ill get to you when i know memory allocation
// /**
//  * @brief
//  *
//  * @param plaintext
//  * @param key
//  * @return char*
//  */
// char *vigenereCipherEncrypt(char *plaintext, char *key)
// {
//   int length = strlen(plaintext);
//   char *output = malloc((length + 1) * sizeof(char)); // dynamically allocate memory
//   if (output == NULL)
//   {
//     // handle memory allocation error
//     return NULL;
//   }

//   for (int i = 0; i < 5; i++)
//   {
//     output[i] = caesarEncryptChar(plaintext[i], key[i], 0);
//     printf_s("%c + %c -- > %c \n", plaintext[i], key[i], output[i]);
//   }

//   printf_s("output in function : %s \n", output);
//   return output;
// }
