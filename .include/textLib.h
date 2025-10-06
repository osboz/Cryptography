/**
 * @brief returns an int between 0 and max,
 * negative values goes down from max
 * @param input is the input int
 * @param max is the maximum int value
 * @return int between 0 and max
 */
int talCirkulærRunding(int Input, int max);

/**
 * @brief returns an int between min and max,
 * negative values goes down from max
 * @param input is the input int
 * @param min is the minimum int value
 * @param max is the maximum int value
 *
 * @return int between min and max, nu
 */
int talCirkulærRundingMinMax(int Input, int min, int max);

/**
 * @brief Shifts input text by x amount
 * @param plaintext char to shift
 * @param shift int of value to shift by
 * @param mode (e)ncrypt or (d)ecrypt
 * @return char
 */
char caesar(char plaintext, int shift, char mode);

/**
 * @brief
 * @param plaintext
 * @param shift the char that to shift the plaintext by
 * @param mode (e)ncrypt or (d)ecrypt
 * @return char
 */
char vigenere(char plaintextc, char shift, char mode);
