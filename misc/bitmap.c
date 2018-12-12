#include <stdio.h>
#include <limits.h>    /* for CHAR_BIT */
#include <stdint.h>   /* for uint32_t */

typedef uint32_t word_t;

enum { BITS_PER_WORD = sizeof(word_t) * CHAR_BIT };
#define WORD_OFFSET(b) ((b) / BITS_PER_WORD)
#define BIT_OFFSET(b)  ((b) % BITS_PER_WORD)

void set_bit(word_t *words, int n) { 
    words[WORD_OFFSET(n)] |= (1 << BIT_OFFSET(n));
}

void clear_bit(word_t *words, int n) {
    words[WORD_OFFSET(n)] &= ~(1 << BIT_OFFSET(n)); 
}

int get_bit(word_t *words, int n) {
    word_t bit = words[WORD_OFFSET(n)] & (1 << BIT_OFFSET(n));
    return bit != 0;
}

int main()
{
  int a = 25;
  printf("BITS_PER_WORD = %d\n", BITS_PER_WORD);
  printf("WORD_OFFSET = %d\n", WORD_OFFSET(a));
  printf("BIT_OFFSET = %d\n", BIT_OFFSET(a));
  return 0;
} 

