/* crt_toupper @ 00462104 */

/* CRT: toupper (current locale) */

int __cdecl crt_toupper(int c)

{
  void *extraout_ECX;
  int unaff_EDI;
  bool bVar1;
  void *this;
  
  if (DAT_004d9a4c == 0) {
    if ((0x60 < c) && (c < 0x7b)) {
      return c + -0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&DAT_004da3b0);
    bVar1 = DAT_004da3ac != 0;
    this = extraout_ECX;
    if (bVar1) {
      InterlockedDecrement((LONG *)&DAT_004da3b0);
      this = (void *)0x13;
      crt_lock(0x13);
    }
    c = crt_toupper_l(this,(void *)c,unaff_EDI);
    if (bVar1) {
      crt_unlock(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&DAT_004da3b0);
    }
  }
  return c;
}



