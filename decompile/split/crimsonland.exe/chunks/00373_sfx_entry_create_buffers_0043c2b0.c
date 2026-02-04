/* sfx_entry_create_buffers @ 0043c2b0 */

/* creates DirectSound buffers for an sfx entry */

int __cdecl sfx_entry_create_buffers(int entry)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint extraout_EAX;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_24 [4];
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar7 = (undefined4 *)(entry + 0x24);
  puVar5 = local_24;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_24[2] = *(undefined4 *)(entry + 0x18);
  local_10 = 0;
  local_8 = 0;
  local_4 = 0;
  local_24[0] = 0x24;
  local_24[1] = 0x80e0;
  local_c = 0;
  local_14 = entry;
  uVar1 = (**(code **)(*dsound_iface + 0xc))(dsound_iface,local_24,puVar7,0);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  iVar6 = 1;
  iVar4 = entry + 0x28;
  do {
    iVar2 = (**(code **)(*dsound_iface + 0x14))(dsound_iface,*puVar7,iVar4);
    if (iVar2 < 0) {
      OutputDebugStringA(s_____SND__Failed_to_duplicate_the_00477ca0);
      return extraout_EAX & 0xffffff00;
    }
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar6 < 0x10);
  sfx_entry_upload_buffer(entry);
  iVar4 = 0;
  do {
    *(undefined1 *)(iVar4 + 100 + entry) = 0;
    (**(code **)(*(int *)*puVar7 + 0x48))((int *)*puVar7);
    uVar3 = (**(code **)(*(int *)*puVar7 + 0x34))((int *)*puVar7,0);
    iVar4 = iVar4 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar4 < 0x10);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}



