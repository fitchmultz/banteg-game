/* FUN_1001bf39 @ 1001bf39 */

/* WARNING: Removing unreachable block (ram,0x1001bf45) */
/* [binja] int32_t __fastcall sub_1001bf39(int32_t arg1) */

int __fastcall FUN_1001bf39(int arg1)

{
  int iVar1;
  
  iVar1 = cpuid_Version_info(1);
  return (uint)((*(uint *)(iVar1 + 8) & 0x800000) != 0);
}



