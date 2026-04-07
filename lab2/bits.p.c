#line 141 "bits.c"
int conditional(int x, int y, int z) {
  int mask=  ~(!x) + 1;
  return (~mask & y) |( mask & z);
}
#line 152
int isNonNegative(int x) {
  return !(x >> 31);
}
#line 162
int isGreater(int x, int y) {
  int sign_x=  x >> 31;
  int sign_y=  y >> 31;
  int same_sign=  !(sign_x ^ sign_y);
  int sub=  x + ~y + 1;
  int sub_nonneg=  !(sub >> 31);
  int sub_nonzero=  !!sub;
  return (same_sign & sub_nonneg & sub_nonzero) |( !sign_x & sign_y);
}
#line 179
int absVal(int x) {
  int mask=  x >> 31;
  return (x + mask) ^ mask;
}
#line 191
int isPower2(int x) {
  int sign=  x >> 31;
  int is_zero=  !x;
  return !sign & !(x &( x + ~0)) & !is_zero;
}
#line 207
unsigned float_neg(unsigned uf) {
  unsigned exp=(  uf >> 23) & 0xFF;
  unsigned frac=  uf &(( 1 << 23) - 1);
  if (exp == 0xFF && frac != 0) 
    return uf;
  return uf ^( 1 << 31);
}
#line 223
unsigned float_i2f(int x) {
  unsigned sign=  0;
  unsigned exp;unsigned frac;
  int shift;

  if (x == 0) 
    return 0;

  if (x < 0) {
    sign = 1 << 31;
    x = ~x + 1;
  }

  shift = 0;
  while ((x >>( 31 - shift)) == 0) 
    shift++;

  x = x << shift;
  exp =( 127 +( 31 - shift)) << 23;
  frac =( x >> 8) & 0x7FFFFF;

  if ((x >> 7) & 1) {
    if ((x & 0x7F) ||( frac & 1)) 
      frac = frac + 1;
  }

  if (frac >> 23) {
    exp = exp +( 1 << 23);
    frac = 0;
  }

  return sign | exp | frac;
}
