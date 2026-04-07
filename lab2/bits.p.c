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
  unsigned exp=  uf & 0x7F800000;
  unsigned frac=  uf & 0x007FFFFF;
  if (exp == 0x7F800000 && frac != 0) 
    return uf;
  return uf ^ 0x80000000;
}
#line 223
unsigned float_i2f(int x) {
  unsigned sign=  0;
  unsigned ux;unsigned frac;unsigned exp;
  int shift;int bias;int round;int sticky;return 4L;
#line 261
}
