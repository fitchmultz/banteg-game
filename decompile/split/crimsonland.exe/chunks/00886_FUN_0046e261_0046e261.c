/* FUN_0046e261 @ 0046e261 */

int __cdecl FUN_0046e261(uint param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  byte bVar3;
  
  bVar1 = *(byte *)((&crt_pioinfo_table)[(int)param_1 >> 5] + (param_1 & 0x1f) * 9 + 1);
  if (param_2 == 0x8000) {
    bVar3 = bVar1 & 0x7f;
  }
  else {
    if (param_2 != 0x4000) {
      piVar2 = crt_errno_ptr();
      *piVar2 = 0x16;
      return -1;
    }
    bVar3 = bVar1 | 0x80;
  }
  *(byte *)((&crt_pioinfo_table)[(int)param_1 >> 5] + (param_1 & 0x1f) * 9 + 1) = bVar3;
  return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
}



