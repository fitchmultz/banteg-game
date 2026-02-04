/* FUN_0046abbb @ 0046abbb */

/* [binja] int32_t sub_46abbb(int32_t arg1, HANDLE arg2) */

int __cdecl FUN_0046abbb(int arg1,HANDLE arg2)

{
  int *piVar1;
  uint *puVar2;
  DWORD nStdHandle;
  
  if ((uint)arg1 < (uint)crt_nhandle) {
    if ((&crt_pioinfo_table)[arg1 >> 5][(arg1 & 0x1fU) * 9] == (void *)0xffffffff) {
      if (DAT_0047b184 == 1) {
        if (arg1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (arg1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (arg1 != 2) goto LAB_0046ac14;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,arg2);
      }
LAB_0046ac14:
      (&crt_pioinfo_table)[arg1 >> 5][(arg1 & 0x1fU) * 9] = arg2;
      return 0;
    }
  }
  piVar1 = crt_errno_ptr();
  *piVar1 = 9;
  puVar2 = crt_doserrno_ptr();
  *puVar2 = 0;
  return -1;
}



