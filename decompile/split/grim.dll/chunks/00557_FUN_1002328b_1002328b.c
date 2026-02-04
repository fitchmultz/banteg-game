/* FUN_1002328b @ 1002328b */

/* [binja] void* sub_1002328b(uint32_t arg1, int32_t arg2, int32_t arg3) */

void * __thiscall FUN_1002328b(void *this,uint arg1,int arg2,int arg3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar3 = *(int *)(arg1 + 4);
  if (0x3b9ac9f0 < (uint)arg3) {
    FUN_1002317a(this,3);
  }
  if ((arg3 & 7U) != 0) {
    arg3 = arg3 + (8 - (arg3 & 7U));
  }
  if ((arg2 < 0) || (1 < arg2)) {
    *(undefined4 *)(*(int *)arg1 + 0x14) = 0xc;
    *(int *)(*(int *)arg1 + 0x18) = arg2;
    (*(code *)**(undefined4 **)arg1)(arg1);
  }
  iVar6 = arg3 + 0x10;
  puVar5 = (undefined4 *)FUN_1002e65a(arg1);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_1002317a(iVar6,4);
  }
  piVar1 = (int *)(iVar3 + 0x48);
  *piVar1 = *piVar1 + arg3 + 0x10;
  puVar2 = (undefined4 *)(iVar3 + 0x38 + arg2 * 4);
  uVar4 = *puVar2;
  puVar5[2] = 0;
  puVar5[1] = arg3;
  *puVar5 = uVar4;
  *puVar2 = puVar5;
  return puVar5 + 4;
}



