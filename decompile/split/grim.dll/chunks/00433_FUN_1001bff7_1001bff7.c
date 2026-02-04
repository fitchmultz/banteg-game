/* FUN_1001bff7 @ 1001bff7 */

/* WARNING: Removing unreachable block (ram,0x1001c016) */
/* WARNING: Removing unreachable block (ram,0x1001c008) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* [binja] int32_t __fastcall sub_1001bff7(int32_t arg1) */

int __fastcall FUN_1001bff7(int arg1)

{
  uint *puVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  puVar1 = (uint *)cpuid(0x80000000);
  if (0x80000000 < *puVar1) {
    iVar2 = cpuid(0x80000001);
    local_8 = (uint)((*(uint *)(iVar2 + 8) & 0x80000000) != 0);
  }
  return local_8;
}



