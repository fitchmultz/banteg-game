/* FUN_00464be7 @ 00464be7 */

void __thiscall FUN_00464be7(void *this,uint *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  uint uVar3;
  short local_1c [6];
  int local_10;
  undefined4 uStack_c;
  int local_8;
  
  uVar3 = 0;
  uVar1 = crt_fp_parse(this,local_1c,(ushort *)&local_8,(int *)param_2,(byte *)0x0,0,0,0,unaff_EDI);
  if ((uVar1 & 4) == 0) {
    iVar2 = FUN_0046a318(local_1c,&local_10);
    if (((uVar1 & 2) != 0) || (iVar2 == 1)) {
      uVar3 = 0x80;
    }
    if (((uVar1 & 1) != 0) || (iVar2 == 2)) {
      uVar3 = uVar3 | 0x100;
    }
  }
  else {
    uVar3 = 0x200;
    local_10 = 0;
    uStack_c = 0;
  }
  *param_1 = uVar3;
  *(ulonglong *)(param_1 + 4) = CONCAT44(uStack_c,local_10);
  param_1[1] = local_8 - (int)param_2;
  return;
}



