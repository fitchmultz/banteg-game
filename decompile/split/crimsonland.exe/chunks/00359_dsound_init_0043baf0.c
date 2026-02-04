/* dsound_init @ 0043baf0 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* initializes DirectSound and the primary buffer */

int __cdecl dsound_init(void *hwnd,uint coop_level)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uStack_54;
  undefined4 auStack_30 [4];
  undefined4 uStack_20;
  short sStack_10;
  ushort uStack_8;
  
  if (dsound_iface != (int *)0x0) {
    (**(code **)(*dsound_iface + 8))();
  }
  dsound_iface = (int *)0x0;
  uVar1 = DirectSoundCreate8((LPCGUID)0x0,(LPDIRECTSOUND8 *)&dsound_iface,(LPUNKNOWN)0x0);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  uVar1 = (**(code **)(*dsound_iface + 0x18))();
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  puVar4 = auStack_30;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  uStack_54 = 0;
  auStack_30[0] = 0x24;
  auStack_30[1] = 1;
  auStack_30[2] = 0;
  uStack_20 = 0;
  uVar1 = (**(code **)(*dsound_iface + 0xc))(dsound_iface,auStack_30);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  uStack_54 = CONCAT22(sStack_10,1);
  piVar5 = &uStack_54;
  uVar1 = (**(code **)(CONCAT22(uStack_8,(uStack_8 >> 3) * sStack_10) + 0x38))(&stack0xffffffb8);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  uVar2 = 0;
  if (piVar5 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar5 + 8))(piVar5);
  }
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}



