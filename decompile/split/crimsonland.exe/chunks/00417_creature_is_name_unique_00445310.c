/* creature_is_name_unique @ 00445310 */

/* [binja] int32_t sub_445310(char* arg1, int32_t arg2) */

int __cdecl creature_is_name_unique(char *arg1,int arg2)

{
  byte bVar1;
  int in_EAX;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  creature_t *pcVar6;
  bool bVar7;
  
  iVar3 = 0;
  pbVar4 = &DAT_004d152c;
  pcVar6 = &creature_pool;
  do {
    if ((pcVar6->active != '\0') && (pbVar2 = pbVar4, pbVar5 = (byte *)arg1, iVar3 != arg2)) {
      do {
        bVar1 = *pbVar2;
        bVar7 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_00445355:
          in_EAX = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
          goto LAB_0044535a;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_00445355;
        pbVar2 = pbVar2 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      in_EAX = 0;
LAB_0044535a:
      if (in_EAX == 0) {
        return 0;
      }
    }
    pcVar6 = pcVar6 + 1;
    iVar3 = iVar3 + 1;
    pbVar4 = pbVar4 + 0x40;
    if (0x4aa337 < (int)pcVar6) {
      return CONCAT31((int3)((uint)in_EAX >> 8),1);
    }
  } while( true );
}



