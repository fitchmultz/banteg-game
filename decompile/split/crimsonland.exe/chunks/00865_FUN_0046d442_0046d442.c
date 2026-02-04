/* FUN_0046d442 @ 0046d442 */

/* [binja] void* sub_46d442() */

void * FUN_0046d442(void)

{
  WINBOOL WVar1;
  uint uVar2;
  void *pvVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined1 uVar8;
  BYTE *pBVar9;
  CHAR *pCVar10;
  WORD local_518 [256];
  ushort local_318 [128];
  ushort local_218 [128];
  CHAR local_118 [256];
  _cpinfo local_18;
  
  WVar1 = GetCPInfo(DAT_004da164,&local_18);
  if (WVar1 == 1) {
    uVar2 = 0;
    do {
      local_118[uVar2] = (CHAR)uVar2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < 0x100);
    local_118[0] = ' ';
    if (local_18.LeadByte[0] != 0) {
      pBVar9 = local_18.LeadByte + 1;
      do {
        uVar2 = (uint)local_18.LeadByte[0];
        if (uVar2 <= *pBVar9) {
          uVar5 = (*pBVar9 - uVar2) + 1;
          uVar6 = uVar5 >> 2;
          pCVar10 = local_118 + uVar2;
          while (uVar6 != 0) {
            uVar6 = uVar6 - 1;
            builtin_memcpy(pCVar10,"    ",4);
            pCVar10 = pCVar10 + 4;
          }
          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
            *pCVar10 = ' ';
            pCVar10 = pCVar10 + 1;
          }
        }
        local_18.LeadByte[0] = pBVar9[1];
        pBVar9 = pBVar9 + 2;
      } while (local_18.LeadByte[0] != 0);
    }
    FUN_0046a8ce(1,local_118,0x100,local_518,DAT_004da164,DAT_004da384,0);
    crt_lcmap_string(DAT_004da384,0x100,local_118,0x100,local_218,0x100,DAT_004da164,0);
    crt_lcmap_string(DAT_004da384,0x200,local_118,0x100,local_318,0x100,DAT_004da164,0);
    pvVar3 = (void *)0x0;
    puVar7 = local_518;
    do {
      if ((*puVar7 & 1) == 0) {
        if ((*puVar7 & 2) != 0) {
          *(byte *)((int)pvVar3 + 0x4da281U) = *(byte *)((int)pvVar3 + 0x4da281U) | 0x20;
          uVar8 = *(undefined1 *)((int)local_318 + (int)pvVar3);
          goto LAB_0046d54e;
        }
        *(undefined1 *)((int)pvVar3 + 0x4da180) = 0;
      }
      else {
        *(byte *)((int)pvVar3 + 0x4da281U) = *(byte *)((int)pvVar3 + 0x4da281U) | 0x10;
        uVar8 = *(undefined1 *)((int)local_218 + (int)pvVar3);
LAB_0046d54e:
        *(undefined1 *)((int)pvVar3 + 0x4da180) = uVar8;
      }
      pvVar3 = (void *)((int)pvVar3 + 1);
      puVar7 = puVar7 + 1;
    } while (pvVar3 < (void *)0x100);
  }
  else {
    pvVar3 = (void *)0x0;
    do {
      if ((pvVar3 < (void *)0x41) || ((void *)0x5a < pvVar3)) {
        if (((void *)0x60 < pvVar3) && (pvVar3 < (void *)0x7b)) {
          *(byte *)((int)pvVar3 + 0x4da281U) = *(byte *)((int)pvVar3 + 0x4da281U) | 0x20;
          cVar4 = (char)pvVar3 + -0x20;
          goto LAB_0046d598;
        }
        *(undefined1 *)((int)pvVar3 + 0x4da180) = 0;
      }
      else {
        *(byte *)((int)pvVar3 + 0x4da281U) = *(byte *)((int)pvVar3 + 0x4da281U) | 0x10;
        cVar4 = (char)pvVar3 + ' ';
LAB_0046d598:
        *(char *)((int)pvVar3 + 0x4da180) = cVar4;
      }
      pvVar3 = (void *)((int)pvVar3 + 1);
    } while (pvVar3 < (void *)0x100);
  }
  return pvVar3;
}



