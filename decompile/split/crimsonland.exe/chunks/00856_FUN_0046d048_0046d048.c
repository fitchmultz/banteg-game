/* FUN_0046d048 @ 0046d048 */

uint __cdecl FUN_0046d048(LPWSTR param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
    bVar1 = *param_2;
    if (bVar1 != 0) {
      if (DAT_004d9a4c == 0) {
        if (param_1 != (LPWSTR)0x0) {
          *param_1 = (ushort)bVar1;
        }
        return 1;
      }
      if ((crt_ctype_table[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
        iVar2 = MultiByteToWideChar(DAT_004d9a5c,9,(LPCCH)param_2,1,param_1,
                                    (uint)(param_1 != (LPWSTR)0x0));
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        if (1 < (int)DAT_0047b3cc) {
          if ((int)param_3 < (int)DAT_0047b3cc) goto LAB_0046d0da;
          iVar2 = MultiByteToWideChar(DAT_004d9a5c,9,(LPCCH)param_2,DAT_0047b3cc,param_1,
                                      (uint)(param_1 != (LPWSTR)0x0));
          if (iVar2 != 0) {
            return DAT_0047b3cc;
          }
        }
        if ((DAT_0047b3cc <= param_3) && (param_2[1] != 0)) {
          return DAT_0047b3cc;
        }
      }
LAB_0046d0da:
      piVar3 = crt_errno_ptr();
      *piVar3 = 0x2a;
      return 0xffffffff;
    }
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
  }
  return 0;
}



