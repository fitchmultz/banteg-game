/* creature_find_by_name @ 00445590 */

/* returns the first creature index whose name matches DAT_004d152c, or -1 */

int __cdecl creature_find_by_name(char *name)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  creature_t *pcVar7;
  bool bVar8;
  
  iVar2 = 0;
  pbVar5 = &DAT_004d152c;
  pcVar7 = &creature_pool;
  do {
    pbVar3 = pbVar5;
    pbVar6 = (byte *)name;
    if (pcVar7->active != '\0') {
      do {
        bVar1 = *pbVar3;
        bVar8 = bVar1 < *pbVar6;
        if (bVar1 != *pbVar6) {
LAB_004455cf:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_004455d4;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar8 = bVar1 < pbVar6[1];
        if (bVar1 != pbVar6[1]) goto LAB_004455cf;
        pbVar3 = pbVar3 + 2;
        pbVar6 = pbVar6 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_004455d4:
      if (iVar4 == 0) {
        return iVar2;
      }
    }
    pcVar7 = pcVar7 + 1;
    iVar2 = iVar2 + 1;
    pbVar5 = pbVar5 + 0x40;
    if (0x4aa337 < (int)pcVar7) {
      return -1;
    }
  } while( true );
}



