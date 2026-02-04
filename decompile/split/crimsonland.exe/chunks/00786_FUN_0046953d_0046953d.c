/* FUN_0046953d @ 0046953d */

/* [binja] int32_t* sub_46953d(int32_t* arg1) */

int * __cdecl FUN_0046953d(int *arg1)

{
  int *piVar1;
  
  if (arg1 == (int *)0x1) {
    arg1 = crt_errno_ptr();
    *arg1 = 0x21;
  }
  else if ((1 < (int)arg1) && ((int)arg1 < 4)) {
    piVar1 = crt_errno_ptr();
    *piVar1 = 0x22;
    return piVar1;
  }
  return arg1;
}



