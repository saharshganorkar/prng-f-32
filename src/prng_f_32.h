#ifndef PRNG_F_32_H
#define PRNG_F_32_H

#include <stdint.h>

struct prng_f_32_s {
  uint32_t blocks[32];
  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t d;
  uint32_t e;
  uint32_t f;
};

uint32_t prng_f_32(struct prng_f_32_s *s);

#endif
