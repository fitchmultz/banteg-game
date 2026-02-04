/* FUN_0046ac37 @ 0046ac37 */

/* [binja] int32_t sub_46ac37(int32_t arg1) */

int __cdecl FUN_0046ac37(int arg1)

{
  void **ppvVar1;
  int *piVar2;
  uint *puVar3;
  DWORD nStdHandle;
  
  if ((uint)arg1 < (uint)crt_nhandle) {
    ppvVar1 = (&crt_pioinfo_table)[arg1 >> 5] + (arg1 & 0x1fU) * 9;
    if ((((uint)ppvVar1[1] & 1) != 0) && (*ppvVar1 != (void *)0xffffffff)) {
      if (DAT_0047b184 == 1) {
        if (arg1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (arg1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (arg1 != 2) goto LAB_0046ac93;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_0046ac93:
      (&crt_pioinfo_table)[arg1 >> 5][(arg1 & 0x1fU) * 9] = (void *)0xffffffff;
      return 0;
    }
  }
  piVar2 = crt_errno_ptr();
  *piVar2 = 9;
  puVar3 = crt_doserrno_ptr();
  *puVar3 = 0;
  return -1;
}



