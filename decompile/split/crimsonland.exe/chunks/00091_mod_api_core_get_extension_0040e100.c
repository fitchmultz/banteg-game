/* mod_api_core_get_extension @ 0040e100 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* mod API vtable 0x18: clAPI_t::CORE_GetExtension (handles "grimgfx", "grimsfx", "IDirect3D8") */

void * mod_api_core_get_extension(char *ext)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  bool bVar6;
  uint auStack_10 [4];
  
  pbVar4 = &DAT_00472f48;
  pbVar2 = (byte *)ext;
  do {
    bVar1 = *pbVar2;
    bVar6 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040e139:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_0040e13e;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar6 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040e139;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040e13e:
  if (iVar3 == 0) {
    return grim_interface_ptr;
  }
  pbVar4 = &DAT_00472f40;
  pbVar2 = (byte *)ext;
  do {
    bVar1 = *pbVar2;
    bVar6 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_0040e17f:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_0040e184;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar6 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_0040e17f;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0040e184:
  if (iVar3 != 0) {
    pcVar5 = s_IDirect3D8_00472f34;
    do {
      bVar1 = *ext;
      bVar6 = bVar1 < (byte)*pcVar5;
      if (bVar1 != *pcVar5) {
LAB_0040e1b7:
        iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0040e1bc;
      }
      if (bVar1 == 0) break;
      bVar1 = ((byte *)ext)[1];
      bVar6 = bVar1 < ((byte *)pcVar5)[1];
      if (bVar1 != ((byte *)pcVar5)[1]) goto LAB_0040e1b7;
      ext = (char *)((byte *)ext + 2);
      pcVar5 = (char *)((byte *)pcVar5 + 2);
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0040e1bc:
    if (iVar3 == 0) {
      iVar3 = (*grim_interface_ptr->vtable->grim_get_config_var)(auStack_10,0x51);
      return *(void **)(iVar3 + 0xc);
    }
  }
  return (void *)0x0;
}



