/* FUN_0046e617 @ 0046e617 */

/* [binja] int32_t sub_46e617(char* arg1, int32_t arg2) */

int __cdecl FUN_0046e617(char *arg1,int arg2)

{
  byte *pbVar1;
  int iVar2;
  char **ppcVar3;
  size_t sVar4;
  char *dst;
  char **ppcVar5;
  bool bVar6;
  
  if (arg1 == (char *)0x0) {
    return -1;
  }
  pbVar1 = FUN_0046e85d((byte *)arg1,0x3d);
  if (pbVar1 == (byte *)0x0) {
    return -1;
  }
  if ((byte *)arg1 == pbVar1) {
    return -1;
  }
  bVar6 = pbVar1[1] == 0;
  if (crt_environ == DAT_004d99a4) {
    crt_environ = FUN_0046e7f6((int *)crt_environ);
  }
  if (crt_environ == (char **)0x0) {
    if ((arg2 == 0) || (DAT_004d99a8 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      crt_environ = _malloc(4);
      if (crt_environ == (char **)0x0) {
        return -1;
      }
      *crt_environ = (char *)0x0;
      if (DAT_004d99a8 == (undefined4 *)0x0) {
        DAT_004d99a8 = _malloc(4);
        if (DAT_004d99a8 == (undefined4 *)0x0) {
          return -1;
        }
        *DAT_004d99a8 = 0;
      }
    }
    else {
      iVar2 = FUN_0046e301();
      if (iVar2 != 0) {
        return -1;
      }
    }
  }
  ppcVar3 = crt_environ;
  iVar2 = FUN_0046e79e((uchar *)arg1,(int)pbVar1 - (int)arg1);
  if ((iVar2 < 0) || (*ppcVar3 == (char *)0x0)) {
    if (bVar6) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    ppcVar3 = crt_realloc(ppcVar3,iVar2 * 4 + 8);
    if (ppcVar3 == (char **)0x0) {
      return -1;
    }
    ppcVar3[iVar2] = arg1;
    ppcVar3[iVar2 + 1] = (char *)0x0;
  }
  else {
    if (!bVar6) {
      ppcVar3[iVar2] = arg1;
      goto LAB_0046e74b;
    }
    ppcVar5 = ppcVar3 + iVar2;
    crt_free_base(ppcVar3[iVar2]);
    for (; *ppcVar5 != (char *)0x0; ppcVar5 = ppcVar5 + 1) {
      iVar2 = iVar2 + 1;
      *ppcVar5 = ppcVar5[1];
    }
    ppcVar3 = crt_realloc(ppcVar3,iVar2 << 2);
    if (ppcVar3 == (char **)0x0) goto LAB_0046e74b;
  }
  crt_environ = ppcVar3;
LAB_0046e74b:
  if (arg2 != 0) {
    sVar4 = _strlen(arg1);
    dst = _malloc(sVar4 + 2);
    if (dst != (char *)0x0) {
      crt_strcpy(dst,arg1);
      pbVar1[(int)dst - (int)arg1] = 0;
      SetEnvironmentVariableA
                (dst,(LPCSTR)(~-(uint)bVar6 & (uint)(pbVar1 + ((int)dst - (int)arg1) + 1)));
      crt_free_base(dst);
    }
  }
  return 0;
}



