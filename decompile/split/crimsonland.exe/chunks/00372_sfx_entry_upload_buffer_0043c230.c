/* sfx_entry_upload_buffer @ 0043c230 */

/* uploads PCM data into a DirectSound buffer */

int __cdecl sfx_entry_upload_buffer(int entry)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined1 local_4 [4];
  
  iVar1 = entry;
  piVar8 = &entry;
  uVar7 = 0;
  iVar2 = (**(code **)(**(int **)(entry + 0x24) + 0x2c))
                    (*(int **)(entry + 0x24),0,*(undefined4 *)(entry + 0x18),piVar8,local_4,0,0,0);
  if ((iVar2 < 0) && (iVar2 == -0x7787ff6a)) {
    iVar2 = dsound_restore_buffer(*(void **)(iVar1 + 0x24));
    if ((char)iVar2 == '\0') {
      return iVar2;
    }
  }
  uVar4 = *(uint *)(iVar1 + 0x18);
  piVar5 = *(int **)(iVar1 + 0x14);
  piVar6 = piVar8;
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *piVar6 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)piVar6 = (char)*piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
    piVar6 = (int *)((int)piVar6 + 1);
  }
  uVar7 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x4c))(*(int **)(iVar1 + 0x24),piVar8,uVar7,0,0);
  return CONCAT31((int3)((uint)uVar7 >> 8),1);
}



