/* music_entry_load_ogg @ 0043c3a0 */

/* loads an OGG stream into a music entry */

int __cdecl music_entry_load_ogg(void *entry,byte *path)

{
  ushort uVar1;
  FILE *pFVar2;
  int iVar3;
  void *stream;
  void *this;
  uint uVar4;
  undefined4 *puVar5;
  uint3 uVar6;
  uint uVar7;
  uint unaff_EDI;
  undefined4 local_24 [4];
  void *local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = resource_open_read(path,(int *)&path);
  pFVar2 = resource_fp;
  if ((char)iVar3 == '\0') {
    return iVar3;
  }
  stream = operator_new((uint)(path + 8));
  crt_fread((char *)((int)stream + 8),(uint)path,1,(int *)pFVar2);
  resource_close();
  this = operator_new(0x310);
  *(void **)((int)entry + 0x74) = this;
  iVar3 = vorbis_mem_open(this,stream,path,unaff_EDI);
  if ((char)iVar3 == '\0') {
    return iVar3;
  }
  *(undefined4 *)entry = 0;
  *(undefined4 *)((int)entry + 4) = 0;
  *(undefined4 *)((int)entry + 8) = 0;
  *(undefined4 *)((int)entry + 0xc) = 0;
  *(undefined2 *)((int)entry + 0x10) = 0;
  *(undefined2 *)entry = 1;
  uVar1 = *(ushort *)(*(int *)((int)entry + 0x74) + 0x2f4);
  *(ushort *)((int)entry + 2) = uVar1;
  *(undefined4 *)((int)entry + 4) = *(undefined4 *)(*(int *)((int)entry + 0x74) + 0x2f8);
  *(undefined2 *)((int)entry + 0xe) = 0x10;
  *(undefined2 *)((int)entry + 0x10) = 0;
  uVar4 = (int)((uint)uVar1 * 0x10) >> 3;
  *(short *)((int)entry + 0xc) = (short)uVar4;
  iVar3 = (uVar4 & 0xffff) * *(int *)((int)entry + 4);
  *(int *)((int)entry + 8) = iVar3;
  uVar4 = iVar3 * 2;
  *(uint *)((int)entry + 0x18) = uVar4;
  puVar5 = operator_new(uVar4);
  uVar4 = *(uint *)((int)entry + 0x18);
  *(undefined4 **)((int)entry + 0x14) = puVar5;
  for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  puVar5 = local_24;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  local_24[2] = *(undefined4 *)((int)entry + 0x18);
  local_10 = 0;
  local_4 = 0;
  local_8 = 0;
  local_24[0] = 0x24;
  local_24[1] = 0x180c0;
  local_c = 0;
  local_14 = entry;
  iVar3 = (**(code **)(*dsound_iface + 0xc))(dsound_iface,local_24,(int)entry + 0x24,0);
  uVar6 = (uint3)((uint)iVar3 >> 8);
  if (iVar3 < 0) {
    return (uint)uVar6 << 8;
  }
  *(undefined4 *)((int)entry + 0x80) = 0;
  return CONCAT31(uVar6,1);
}



