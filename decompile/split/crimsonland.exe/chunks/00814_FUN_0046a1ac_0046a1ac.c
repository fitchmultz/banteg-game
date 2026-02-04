/* FUN_0046a1ac @ 0046a1ac */

/* [binja] int32_t sub_46a1ac(int16_t* arg1, int32_t* arg2, int32_t* arg3) */

int __cdecl FUN_0046a1ac(short *arg1,int *arg2,int *arg3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_1c [3];
  uint local_10;
  int local_c;
  int local_8;
  
  uVar1 = arg1[5];
  local_10 = *(uint *)(arg1 + 3);
  local_c = *(int *)(arg1 + 1);
  uVar3 = uVar1 & 0x7fff;
  iVar4 = uVar3 - 0x3fff;
  local_8 = (uint)(ushort)*arg1 << 0x10;
  if (iVar4 == -0x3fff) {
    iVar4 = 0;
    iVar2 = FUN_0046a104((int *)&local_10);
    if (iVar2 != 0) {
LAB_0046a2d8:
      iVar2 = 0;
      goto LAB_0046a2da;
    }
    FUN_0046a0f8((int *)&local_10);
  }
  else {
    FUN_0046a0dd((int)local_1c,(int *)&local_10);
    iVar2 = FUN_0046a051((int)&local_10,(int *)arg3[2]);
    if (iVar2 != 0) {
      iVar4 = uVar3 - 0x3ffe;
    }
    iVar2 = arg3[1];
    if (iVar4 < iVar2 - arg3[2]) {
      FUN_0046a0f8((int *)&local_10);
    }
    else {
      if (iVar2 < iVar4) {
        if (*arg3 <= iVar4) {
          FUN_0046a0f8((int *)&local_10);
          local_10 = local_10 | 0x80000000;
          FUN_0046a11f((int *)&local_10,arg3[3]);
          iVar4 = arg3[5] + *arg3;
          iVar2 = 1;
          goto LAB_0046a2da;
        }
        local_10 = local_10 & 0x7fffffff;
        iVar4 = arg3[5] + iVar4;
        FUN_0046a11f((int *)&local_10,arg3[3]);
        goto LAB_0046a2d8;
      }
      FUN_0046a0dd((int)&local_10,local_1c);
      FUN_0046a11f((int *)&local_10,iVar2 - iVar4);
      FUN_0046a051((int)&local_10,(int *)arg3[2]);
      FUN_0046a11f((int *)&local_10,arg3[3] + 1);
    }
  }
  iVar4 = 0;
  iVar2 = 2;
LAB_0046a2da:
  local_10 = iVar4 << (0x1fU - (char)arg3[3] & 0x1f) | -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 |
             local_10;
  if (arg3[4] == 0x40) {
    arg2[1] = local_10;
    *arg2 = local_c;
  }
  else if (arg3[4] == 0x20) {
    *arg2 = local_10;
  }
  return iVar2;
}



