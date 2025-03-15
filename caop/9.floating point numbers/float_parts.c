#include <stdio.h>
#include <string.h>

// Print the number N in binary format with size bites
void print_bin(unsigned n, unsigned size) {
  unsigned i;
  for (i = 1 << (size - 1); i > 0; i >>= 1) {
    (n & i) ? printf("1") : printf("0");
  }
  printf("\n");
}

// Get exponential part of floating point number
unsigned get_exp(float num) {
  const int sign_bits = 1;
  const int mant_bits = 23;

  unsigned exp;
  memcpy(&exp, &num, sizeof(num));
  return exp << sign_bits >> (sign_bits + mant_bits);
}

unsigned get_mant(float num) {
  const int sign_bits = 1;
  const int exp_bits = 8;

  unsigned mant;
  memcpy(&mant, &num, sizeof(num));

  int to_remove = sign_bits + exp_bits;
  return mant << (to_remove) >> to_remove;
}

unsigned get_sign(float num) {
  const int sign_bits = 1;
  const int all_bits = 32;

  unsigned sign;
  memcpy(&sign, &num, sizeof(num));
  return sign >> (all_bits - sign_bits);
}

// implementation same as gcc ieee754
typedef union {
  float f;
  struct {
    unsigned int mantissa : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
  } parts;
} float_uni;

void print_float(float f) {
  float_uni fu = {.f = f};

  printf("%f\n", f);

  printf("sign\t\t = \t");
  print_bin(fu.parts.sign, 1);
  printf("exponent\t = \t");
  print_bin(fu.parts.exponent, 8);
  printf("mantissa\t = \t");
  print_bin(fu.parts.mantissa, 23);
}

int main() {
  float f = 0;

  // unsigned sign = get_sign(f);
  // unsigned exp = get_exp(f);
  // unsigned mant = get_mant(f);

  // printf("%f\n", f);
  // printf("sign\t\t = \t");
  // print_bin(sign, 1);
  // printf("exponent\t = \t");
  // print_bin(exp, 8);
  // printf("mantissa\t = \t");
  // print_bin(mant, 23);

  // same result
  print_float(f);
}
