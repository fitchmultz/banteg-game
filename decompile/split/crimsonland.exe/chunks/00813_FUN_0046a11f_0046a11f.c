/* FUN_0046a11f @ 0046a11f */

/* [binja] int32_t* sub_46a11f(int32_t* arg1, int32_t arg2) */

int * __cdecl FUN_0046a11f(int *arg1,int arg2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int local_8;
  
  local_8 = 3;
  iVar2 = arg2 / 0x20;
  iVar6 = arg2 % 0x20;
  arg2 = 0;
  bVar4 = (byte)iVar6;
  puVar7 = (uint *)arg1;
  do {
    uVar1 = *puVar7;
    *puVar7 = uVar1 >> (bVar4 & 0x1f) | arg2;
    puVar7 = puVar7 + 1;
    arg2 = (uVar1 & ~(-1 << (bVar4 & 0x1f))) << (0x20 - bVar4 & 0x1f);
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  iVar6 = 2;
  iVar5 = 8;
  do {
    if (iVar6 < iVar2) {
      *(undefined4 *)(iVar5 + (int)arg1) = 0;
      piVar3 = arg1;
    }
    else {
      piVar3 = *(int **)(iVar5 + iVar2 * -4 + (int)arg1);
      *(int **)(iVar5 + (int)arg1) = piVar3;
    }
    iVar6 = iVar6 + -1;
    iVar5 = iVar5 + -4;
  } while (-1 < iVar5);
  return piVar3;
}



