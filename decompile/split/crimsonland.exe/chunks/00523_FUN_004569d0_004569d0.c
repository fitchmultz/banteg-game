/* FUN_004569d0 @ 004569d0 */

/* WARNING: Removing unreachable block (ram,0x00456a4d) */
/* WARNING: Removing unreachable block (ram,0x00456a3b) */
/* WARNING: Removing unreachable block (ram,0x00456a20) */
/* WARNING: Removing unreachable block (ram,0x00456a04) */
/* WARNING: Removing unreachable block (ram,0x004569f9) */
/* [binja] int32_t sub_4569d0() */

int FUN_004569d0(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int *piVar7;
  bool bVar8;
  char local_2c [16];
  int local_1c;
  int local_18;
  int local_14;
  char cStack_10;
  undefined4 local_c;
  uint local_8;
  
  cStack_10 = '\0';
  builtin_strncpy(local_2c,"AuthenticAMD",0xd);
  cpuid_basic_info(0);
  local_8 = 1;
  piVar7 = (int *)cpuid_basic_info(0);
  local_1c = piVar7[1];
  local_18 = piVar7[2];
  local_14 = piVar7[3];
  if (*piVar7 != 0) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
    local_c = *puVar1;
    uVar3 = -(uint)((puVar1[2] & 0x800000) != 0) & 0x20;
    local_8 = uVar3 | 3;
    puVar2 = (uint *)cpuid(0x80000000);
    if (0x80000000 < *puVar2) {
      iVar4 = cpuid(0x80000001);
      uVar5 = *(uint *)(iVar4 + 8);
      local_8 = uVar3 | 7 | -(uint)((uVar5 & 0x80000000) != 0) & 0x80;
      bVar8 = local_8 == 0;
      iVar4 = 0xc;
      pcVar6 = local_2c;
      piVar7 = &local_1c;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar8 = *pcVar6 == (char)*piVar7;
        pcVar6 = pcVar6 + 1;
        piVar7 = (int *)((int)piVar7 + 1);
      } while (bVar8);
      if (bVar8) {
        local_8 = local_8 | -(uint)((uVar5 & 0x40000000) != 0) & 0x100 |
                  -(uint)((uVar5 & 0x400000) != 0) & 0x200;
      }
    }
  }
  return local_8;
}



