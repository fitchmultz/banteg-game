/* sfx_entry_load_ogg @ 0043bcf0 */

/* loads an OGG sample into an sfx entry */

int __cdecl sfx_entry_load_ogg(void *entry,byte *path)

{
  FILE *pFVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint unaff_EDI;
  char *dst;
  void *local_314;
  undefined1 local_310 [740];
  uint local_2c;
  uint local_1c;
  int local_18;
  
  iVar2 = resource_open_read(path,(int *)&local_314);
  pFVar1 = resource_fp;
  if ((char)iVar2 == '\0') {
    return iVar2;
  }
  pvVar3 = operator_new((int)local_314 + 8);
  crt_fread((char *)((int)pvVar3 + 8),(uint)local_314,1,(int *)pFVar1);
  resource_close();
  iVar2 = vorbis_mem_open(local_310,pvVar3,local_314,unaff_EDI);
  if ((char)iVar2 != '\0') {
    *(undefined4 *)entry = 0;
    *(undefined4 *)((int)entry + 4) = 0;
    *(undefined4 *)((int)entry + 8) = 0;
    *(undefined4 *)((int)entry + 0xc) = 0;
    *(undefined2 *)((int)entry + 0x10) = 0;
    *(short *)((int)entry + 2) = (short)local_1c;
    *(undefined2 *)entry = 1;
    uVar4 = (int)((local_1c & 0xffff) * 0x10) >> 3;
    *(short *)((int)entry + 0xc) = (short)uVar4;
    *(uint *)((int)entry + 8) = (uVar4 & 0xffff) * local_18;
    *(int *)((int)entry + 4) = local_18;
    *(undefined2 *)((int)entry + 0xe) = 0x10;
    *(undefined2 *)((int)entry + 0x10) = 0;
    *(uint *)((int)entry + 0x18) = local_2c;
    pvVar3 = operator_new(local_2c);
    dst = *(char **)((int)entry + 0x18);
    *(void **)((int)entry + 0x14) = pvVar3;
    iVar2 = 1;
    while ((dst != (char *)0x0 && (iVar2 != 0))) {
      iVar2 = vorbis_read_pcm16(local_310,
                                (void *)((*(int *)((int)entry + 0x18) - (int)dst) +
                                        *(int *)((int)entry + 0x14)),dst,unaff_EDI);
      dst = dst + -iVar2;
    }
    vorbis_mem_close(local_310);
    iVar2 = sfx_entry_create_buffers((int)entry);
    return CONCAT31((int3)((uint)iVar2 >> 8),(char)iVar2 != '\0');
  }
  return iVar2;
}



