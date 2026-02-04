/* crt_fseek_nolock @ 00461dbd */

/* fseek implementation (uses crt_lseek) */

int __cdecl crt_fseek_nolock(int *param_1,int param_2,DWORD param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  
  if (((param_1[3] & 0x83U) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    piVar4 = crt_errno_ptr();
    *piVar4 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = crt_ftell_nolock((char *)param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    crt_flushbuf(param_1);
    uVar1 = param_1[3];
    if ((uVar1 & 0x80) == 0) {
      if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) && ((uVar1 & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = uVar1 & 0xfffffffc;
    }
    lVar3 = crt_lseek(param_1[4],param_2,param_3);
    iVar2 = (lVar3 != -1) - 1;
  }
  return iVar2;
}



