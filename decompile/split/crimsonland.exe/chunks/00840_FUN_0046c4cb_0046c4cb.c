/* FUN_0046c4cb @ 0046c4cb */

/* [binja] int32_t* sub_46c4cb(int32_t arg1, int32_t* arg2, uint32_t arg3) */

int * __cdecl FUN_0046c4cb(int arg1,int *arg2,uint arg3)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  uint uVar4;
  uint local_5c [10];
  undefined8 local_34;
  uint local_24;
  
  arg3 = (uint)*(ushort *)arg3;
  iVar1 = *arg2;
  if (iVar1 == 1) {
LAB_0046c510:
    uVar4 = 8;
  }
  else if (iVar1 == 2) {
    uVar4 = 4;
  }
  else if (iVar1 == 3) {
    uVar4 = 0x11;
  }
  else if (iVar1 == 4) {
    uVar4 = 0x12;
  }
  else {
    if (iVar1 == 5) goto LAB_0046c510;
    if (iVar1 == 7) {
      *arg2 = 1;
      goto LAB_0046c566;
    }
    if (iVar1 != 8) goto LAB_0046c566;
    uVar4 = 0x10;
  }
  bVar2 = FUN_00469326(uVar4,(double *)(arg2 + 6),arg3);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    if (((arg1 == 0x10) || (arg1 == 0x16)) || (arg1 == 0x1d)) {
      local_34 = *(undefined8 *)(arg2 + 4);
      local_24 = local_24 & 0xffffffe3 | 3;
    }
    else {
      local_24 = local_24 & 0xfffffffe;
    }
    FUN_00469073(local_5c,&arg3,uVar4,arg1,(undefined8 *)(arg2 + 2),(undefined8 *)(arg2 + 6));
  }
LAB_0046c566:
  FUN_00469582();
  if (((*arg2 != 8) && (DAT_0047e088 == 0)) &&
     (piVar3 = (int *)FUN_0046d66c(), piVar3 != (int *)0x0)) {
    return piVar3;
  }
  piVar3 = FUN_0046953d((int *)*arg2);
  return piVar3;
}



