/* FUN_10002f80 @ 10002f80 */

/* [binja] uint32_t __fastcall sub_10002f80(void* arg1) */

uint __fastcall FUN_10002f80(void *arg1)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  
  DVar2 = timeGetTime();
  iVar1 = *(int *)((int)arg1 + 4);
  if (iVar1 < 0) {
    *(DWORD *)((int)arg1 + 4) = DVar2;
    return DVar2 & 0xffffff00;
  }
  *(DWORD *)((int)arg1 + 4) = DVar2;
  uVar3 = *(int *)((int)arg1 + 8) + (DVar2 - iVar1);
  *(uint *)((int)arg1 + 8) = uVar3;
  if ((int)uVar3 < 0x1e) {
    return uVar3 & 0xffffff00;
  }
  *(int *)((int)arg1 + 8) = (int)uVar3 % 0x1e;
  return CONCAT31((int3)((uint)((int)uVar3 / 0x1e) >> 8),1);
}



