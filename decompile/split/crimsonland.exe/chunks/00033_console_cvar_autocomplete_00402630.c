/* console_cvar_autocomplete @ 00402630 */

/* returns exact or prefix-matched cvar name */

char * __thiscall console_cvar_autocomplete(void *this,char *prefix)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  char *pcVar9;
  bool bVar10;
  
  uVar6 = 0xffffffff;
  pcVar9 = prefix;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  if (~uVar6 - 1 != 0) {
    puVar8 = *(undefined4 **)this;
    for (puVar3 = puVar8; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)puVar3[1]) {
      pbVar7 = (byte *)*puVar3;
      pbVar4 = (byte *)prefix;
      do {
        bVar2 = *pbVar4;
        bVar10 = bVar2 < *pbVar7;
        if (bVar2 != *pbVar7) {
LAB_0040267e:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_00402683;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar4[1];
        bVar10 = bVar2 < pbVar7[1];
        if (bVar2 != pbVar7[1]) goto LAB_0040267e;
        pbVar4 = pbVar4 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar2 != 0);
      iVar5 = 0;
LAB_00402683:
      if (iVar5 == 0) {
        return (char *)*puVar3;
      }
    }
    if (puVar8 != (undefined4 *)0x0) {
      do {
        iVar5 = _strncmp(prefix,(char *)*puVar8,~uVar6 - 1);
        if (iVar5 == 0) {
          return (char *)*puVar8;
        }
        puVar8 = (undefined4 *)puVar8[1];
      } while (puVar8 != (undefined4 *)0x0);
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



