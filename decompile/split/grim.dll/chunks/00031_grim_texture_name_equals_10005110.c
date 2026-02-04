/* grim_texture_name_equals @ 10005110 */

/* compares stored texture name */

int __thiscall grim_texture_name_equals(void *this,void *texture,char *name)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  pbVar2 = *(byte **)this;
  if ((pbVar2 == (byte *)0x0) || (texture == (void *)0x0)) {
    return (uint)pbVar2 & 0xffffff00;
  }
  while( true ) {
    bVar1 = *pbVar2;
    bVar4 = bVar1 < *(byte *)texture;
    if (bVar1 != *(byte *)texture) break;
    if (bVar1 == 0) {
      return 1;
    }
    bVar1 = pbVar2[1];
    bVar4 = bVar1 < *(byte *)((int)texture + 1);
    if (bVar1 != *(byte *)((int)texture + 1)) break;
    pbVar2 = pbVar2 + 2;
    texture = (void *)((int)texture + 2);
    if (bVar1 == 0) {
      return 1;
    }
  }
  iVar3 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
  return CONCAT31((int3)((uint)iVar3 >> 8),iVar3 == 0);
}



