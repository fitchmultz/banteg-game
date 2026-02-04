/* highscore_find_name_entry @ 0043af30 */

/* finds a matching name entry in the loaded high score table */

byte * __cdecl highscore_find_name_entry(byte *record,int count)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  highscore_record_t *phVar5;
  highscore_record_t *phVar6;
  bool bVar7;
  
  iVar4 = 0;
  if (0 < count) {
    phVar5 = &highscore_table;
    pbVar2 = record;
    phVar6 = phVar5;
LAB_0043af49:
    do {
      bVar1 = *pbVar2;
      bVar7 = bVar1 < (byte)phVar5->player_name[0];
      if (bVar1 == phVar5->player_name[0]) {
        if (bVar1 != 0) {
          bVar1 = pbVar2[1];
          bVar7 = bVar1 < (byte)phVar5->player_name[1];
          if (bVar1 != phVar5->player_name[1]) goto LAB_0043af6d;
          phVar5 = (highscore_record_t *)(phVar5->player_name + 2);
          pbVar2 = pbVar2 + 2;
          if (bVar1 != 0) goto LAB_0043af49;
        }
        iVar3 = 0;
      }
      else {
LAB_0043af6d:
        iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      }
      if (iVar3 == 0) {
        return (byte *)(&highscore_table + iVar4);
      }
      iVar4 = iVar4 + 1;
      phVar5 = phVar6 + 1;
      pbVar2 = record;
      phVar6 = phVar5;
    } while (iVar4 < count);
  }
  return (byte *)0x0;
}



