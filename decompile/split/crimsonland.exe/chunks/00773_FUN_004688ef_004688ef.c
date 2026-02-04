/* FUN_004688ef @ 004688ef */

/* [binja] uint32_t sub_4688ef(int32_t* arg1, int32_t* arg2) */

uint __cdecl FUN_004688ef(int *arg1,int *arg2)

{
  uint c;
  uint uVar1;
  void *this;
  
  do {
    *arg1 = *arg1 + 1;
    c = FUN_004688be(arg2);
    uVar1 = crt_isspace(this,c);
  } while (uVar1 != 0);
  return c;
}



