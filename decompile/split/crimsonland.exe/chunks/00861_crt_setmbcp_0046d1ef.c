/* crt_setmbcp @ 0046d1ef */

/* CRT: set multibyte code page and rebuild ctype tables */

int __cdecl crt_setmbcp(int codepage)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  WINBOOL WVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  undefined4 *puVar14;
  _cpinfo local_1c;
  uint local_8;
  
  crt_lock(0x19);
  CodePage = FUN_0046d39c(codepage);
  if (CodePage != DAT_004da164) {
    if (CodePage != 0) {
      iVar13 = 0;
      pUVar5 = &DAT_0047df98;
LAB_0046d22c:
      if (*pUVar5 != CodePage) goto code_r0x0046d230;
      local_8 = 0;
      puVar14 = &DAT_004da280;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar14 = 0;
        puVar14 = puVar14 + 1;
      }
      iVar13 = iVar13 * 0x30;
      *(undefined1 *)puVar14 = 0;
      pbVar12 = (byte *)(iVar13 + 0x47dfa8);
      do {
        bVar3 = *pbVar12;
        pbVar11 = pbVar12;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_0047df90)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_004da280 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar12 = pbVar12 + 8;
      } while (local_8 < 4);
      DAT_004da17c = 1;
      DAT_004da164 = CodePage;
      DAT_004da384 = FUN_0046d3e6(CodePage);
      DAT_004da170 = *(undefined4 *)(iVar13 + 0x47df9c);
      DAT_004da174 = *(undefined4 *)(iVar13 + 0x47dfa0);
      DAT_004da178 = *(undefined4 *)(iVar13 + 0x47dfa4);
      goto LAB_0046d380;
    }
    goto LAB_0046d37b;
  }
  goto LAB_0046d216;
code_r0x0046d230:
  pUVar5 = pUVar5 + 0xc;
  iVar13 = iVar13 + 1;
  if ((UINT *)0x47e087 < pUVar5) goto code_r0x0046d23b;
  goto LAB_0046d22c;
code_r0x0046d23b:
  WVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (WVar6 == 1) {
    DAT_004da384 = 0;
    puVar14 = &DAT_004da280;
    for (iVar13 = 0x40; iVar13 != 0; iVar13 = iVar13 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
    *(undefined1 *)puVar14 = 0;
    if (local_1c.MaxCharSize < 2) {
      DAT_004da17c = 0;
      DAT_004da164 = CodePage;
    }
    else {
      DAT_004da164 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar12 = (byte *)((int)&DAT_004da280 + uVar7 + 1);
            *pbVar12 = *pbVar12 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar12 = (byte *)((int)&DAT_004da280 + uVar8 + 1);
        *pbVar12 = *pbVar12 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_004da384 = FUN_0046d3e6(CodePage);
      DAT_004da17c = 1;
    }
    DAT_004da170 = 0;
    DAT_004da174 = 0;
    DAT_004da178 = 0;
  }
  else {
    if (DAT_004d9cb0 == 0) {
      iVar13 = -1;
      goto LAB_0046d38d;
    }
LAB_0046d37b:
    FUN_0046d419();
  }
LAB_0046d380:
  FUN_0046d442();
LAB_0046d216:
  iVar13 = 0;
LAB_0046d38d:
  crt_unlock(0x19);
  return iVar13;
}



