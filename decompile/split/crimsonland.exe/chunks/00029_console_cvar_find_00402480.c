/* console_cvar_find @ 00402480 */

/* finds a cvar entry by name */

void * __thiscall console_cvar_find(void *this,char *name)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  
  puVar2 = *(undefined4 **)this;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return (void *)0x0;
    }
    pbVar5 = (byte *)*puVar2;
    pbVar3 = (byte *)name;
    do {
      bVar1 = *pbVar3;
      bVar6 = bVar1 < *pbVar5;
      if (bVar1 != *pbVar5) {
LAB_004024ba:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_004024bf;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar6 = bVar1 < pbVar5[1];
      if (bVar1 != pbVar5[1]) goto LAB_004024ba;
      pbVar3 = pbVar3 + 2;
      pbVar5 = pbVar5 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_004024bf:
    if (iVar4 == 0) {
      return puVar2;
    }
    puVar2 = (undefined4 *)puVar2[1];
  } while( true );
}



