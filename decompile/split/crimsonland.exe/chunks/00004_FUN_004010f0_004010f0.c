/* FUN_004010f0 @ 004010f0 */

/* [binja] int32_t __stdcall sub_4010f0(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4) */

int FUN_004010f0(int arg1,int arg2,int arg3,int arg4)

{
  int iVar1;
  
  iVar1 = arg3 + -1;
  if (-1 < iVar1) {
    do {
      iVar1 = (*(code *)arg4)();
      arg3 = arg3 + -1;
    } while (arg3 != 0);
  }
  return iVar1;
}



