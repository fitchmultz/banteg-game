/* crt_sbh_alloc_units @ 00467a72 */

/* WARNING: Type propagation algorithm not settling */
/* allocates small-block heap blocks in 16-byte units */

void * __cdecl crt_sbh_alloc_units(uint blocks)

{
  uint *puVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  int *piVar4;
  void *pvVar5;
  undefined **ppuVar6;
  int *piVar7;
  uint *puVar8;
  undefined **ppuVar9;
  int local_8;
  
  piVar7 = (int *)PTR_LOOP_0047db10;
  do {
    if (piVar7[4] != -1) {
      puVar8 = (uint *)piVar7[2];
      piVar4 = (int *)(((int)puVar8 + (-0x18 - (int)piVar7) >> 3) * 0x1000 + piVar7[4]);
      if (puVar8 < piVar7 + 0x806) {
        do {
          if (((int)blocks <= (int)*puVar8) && (blocks < puVar8[1])) {
            pvVar5 = (void *)FUN_00467c7a(piVar4,*puVar8,blocks);
            if (pvVar5 != (void *)0x0) goto LAB_00467b3d;
            puVar8[1] = blocks;
          }
          puVar8 = puVar8 + 2;
          piVar4 = piVar4 + 0x400;
        } while (puVar8 < piVar7 + 0x806);
      }
      puVar1 = (uint *)piVar7[2];
      piVar4 = (int *)piVar7[4];
      for (puVar8 = (uint *)(piVar7 + 6); puVar8 < puVar1; puVar8 = puVar8 + 2) {
        if (((int)blocks <= (int)*puVar8) && (blocks < puVar8[1])) {
          pvVar5 = (void *)FUN_00467c7a(piVar4,*puVar8,blocks);
          if (pvVar5 != (void *)0x0) {
LAB_00467b3d:
            PTR_LOOP_0047db10 = (undefined *)piVar7;
            *puVar8 = *puVar8 - blocks;
            piVar7[2] = (int)puVar8;
            return pvVar5;
          }
          puVar8[1] = blocks;
        }
        piVar4 = piVar4 + 0x400;
      }
    }
    piVar7 = (int *)*piVar7;
    if (piVar7 == (int *)PTR_LOOP_0047db10) {
      ppuVar9 = &PTR_LOOP_0047baf0;
      while ((ppuVar9[4] == (undefined *)0xffffffff || (ppuVar9[3] == (undefined *)0x0))) {
        ppuVar9 = (undefined **)*ppuVar9;
        if (ppuVar9 == &PTR_LOOP_0047baf0) {
          ppuVar9 = crt_sbh_create_region();
          if (ppuVar9 == (undefined **)0x0) {
            return (void *)0x0;
          }
          piVar7 = (int *)ppuVar9[4];
          *(char *)(piVar7 + 2) = (char)blocks;
          PTR_LOOP_0047db10 = (undefined *)ppuVar9;
          *piVar7 = (int)piVar7 + blocks + 8;
          piVar7[1] = 0xf0 - blocks;
          ppuVar9[6] = ppuVar9[6] + -(blocks & 0xff);
          return piVar7 + 0x40;
        }
      }
      ppuVar2 = (undefined **)ppuVar9[3];
      local_8 = 0;
      piVar7 = (int *)(ppuVar9[4] + ((int)ppuVar2 + (-0x18 - (int)ppuVar9) >> 3) * 0x1000);
      puVar3 = *ppuVar2;
      ppuVar6 = ppuVar2;
      for (; (puVar3 == (undefined *)0xffffffff && (local_8 < 0x10)); local_8 = local_8 + 1) {
        ppuVar6 = ppuVar6 + 2;
        puVar3 = *ppuVar6;
      }
      piVar4 = VirtualAlloc(piVar7,local_8 << 0xc,0x1000,4);
      if (piVar4 != piVar7) {
        return (void *)0x0;
      }
      _memset(piVar7,local_8 << 0xc,0);
      ppuVar6 = ppuVar2;
      if (0 < local_8) {
        piVar4 = piVar7 + 1;
        do {
          *(undefined1 *)(piVar4 + 0x3d) = 0xff;
          piVar4[-1] = (int)(piVar4 + 1);
          *piVar4 = 0xf0;
          *ppuVar6 = (undefined *)0xf0;
          ppuVar6[1] = (undefined *)0xf1;
          piVar4 = piVar4 + 0x400;
          ppuVar6 = ppuVar6 + 2;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      for (; (ppuVar6 < ppuVar9 + 0x806 && (*ppuVar6 != (undefined *)0xffffffff));
          ppuVar6 = ppuVar6 + 2) {
      }
      PTR_LOOP_0047db10 = (undefined *)ppuVar9;
      ppuVar9[3] = (undefined *)(-(uint)(ppuVar6 < ppuVar9 + 0x806) & (uint)ppuVar6);
      *(char *)(piVar7 + 2) = (char)blocks;
      ppuVar9[2] = (undefined *)ppuVar2;
      *ppuVar2 = *ppuVar2 + -blocks;
      piVar7[1] = piVar7[1] - blocks;
      *piVar7 = (int)piVar7 + blocks + 8;
      return piVar7 + 0x40;
    }
  } while( true );
}



