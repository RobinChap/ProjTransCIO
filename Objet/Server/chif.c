/* chif.c : librairie qui chiffre les donnees avec une cle de 4 octets */

#include <stdint.h>

void chif4(char *b, int max, uint32_t cle)
{
uint32_t *bl, *bf;
    bl = (uint32_t*)b;
    bf = (uint32_t*)(b+max);
    while (bl < bf) *bl++ ^= cle;
}
