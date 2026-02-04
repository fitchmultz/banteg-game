/* vorbis_mem_read @ 0041dce0 */

/* ov_open_callbacks read hook for memory-backed OGG data */

uint __cdecl vorbis_mem_read(void *dst,uint size,uint count,void *datasource)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (*(uint *)((int)datasource + -8) <= *(uint *)((int)datasource + -4)) {
    *(undefined4 *)((int)datasource + -4) = 0;
  }
  iVar1 = *(int *)((int)datasource + -4);
  uVar4 = size * count;
  uVar2 = uVar4;
  if (*(uint *)((int)datasource + -8) < uVar4 + iVar1) {
    uVar2 = *(uint *)((int)datasource + -8) - iVar1;
  }
  puVar5 = (undefined4 *)(iVar1 + (int)datasource);
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)dst = *puVar5;
    puVar5 = puVar5 + 1;
    dst = (undefined4 *)((int)dst + 4);
  }
  for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)dst = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    dst = (undefined4 *)((int)dst + 1);
  }
  *(uint *)((int)datasource + -4) = *(int *)((int)datasource + -4) + uVar4;
  return uVar2;
}



