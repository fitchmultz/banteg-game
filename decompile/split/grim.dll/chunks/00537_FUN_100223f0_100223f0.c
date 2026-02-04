/* FUN_100223f0 @ 100223f0 */

/* WARNING: Removing unreachable block (ram,0x1002246d) */
/* WARNING: Removing unreachable block (ram,0x1002245b) */
/* WARNING: Removing unreachable block (ram,0x10022440) */
/* WARNING: Removing unreachable block (ram,0x10022424) */
/* WARNING: Removing unreachable block (ram,0x10022419) */

undefined8 FUN_100223f0(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  bool bVar7;
  char local_2c [16];
  int local_1c;
  uint local_18;
  int local_14;
  char cStack_10;
  undefined4 local_c;
  uint local_8;
  
  cStack_10 = '\0';
  builtin_strncpy(local_2c,"AuthenticAMD",0xd);
  cpuid_basic_info(0);
  local_8 = 1;
  piVar6 = (int *)cpuid_basic_info(0);
  local_18 = piVar6[2];
  local_1c = piVar6[1];
  local_14 = piVar6[3];
  if (*piVar6 != 0) {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
    local_c = *puVar1;
    uVar3 = -(uint)((puVar1[2] & 0x800000) != 0) & 0x20;
    local_8 = uVar3 | 3;
    puVar2 = (uint *)cpuid(0x80000000);
    local_18 = puVar2[2];
    if (0x80000000 < *puVar2) {
      iVar4 = cpuid(0x80000001);
      local_18 = *(uint *)(iVar4 + 8);
      local_8 = uVar3 | 7 | -(uint)((local_18 & 0x80000000) != 0) & 0x80;
      bVar7 = local_8 == 0;
      iVar4 = 0xc;
      pcVar5 = local_2c;
      piVar6 = &local_1c;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar7 = *pcVar5 == (char)*piVar6;
        pcVar5 = pcVar5 + 1;
        piVar6 = (int *)((int)piVar6 + 1);
      } while (bVar7);
      if (bVar7) {
        local_8 = local_8 | -(uint)((local_18 & 0x40000000) != 0) & 0x100 |
                  -(uint)((local_18 & 0x400000) != 0) & 0x200;
      }
    }
  }
  return CONCAT44(local_18,local_8);
}



