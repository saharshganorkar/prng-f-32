#include "prng_f_32.h"

void prng_f_32(struct prng_f_32_s *s) {
  uint32_t blocks_capture[4] = {
    s->blocks[s->a & 31],
    s->blocks[s->b & 31],
    s->blocks[s->c & 31],
    s->blocks[s->d & 31]
  };
  uint8_t i = 0;
  uint8_t j;
  uint8_t k = 0;

  s->a += 111111;
  s->b += s->a;
  s->c -= 111111;
  s->d -= s->c;

  while (i < 4) {
    s->e += s->b;
    s->f ^= s->d;
    blocks_capture[i] += (s->e << 9) | (s->e >> 23);
    j = 0;

    while (j < 8) {
      s->blocks[k] += (blocks_capture[i] << 25) | (blocks_capture[i] >> 7);
      s->blocks[k] ^= s->f;
      blocks_capture[i] += s->blocks[k];
      j++;
      k++;
    }

    i++;
  }
}
