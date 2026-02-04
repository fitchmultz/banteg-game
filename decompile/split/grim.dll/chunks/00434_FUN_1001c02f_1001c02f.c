/* FUN_1001c02f @ 1001c02f */

/* WARNING: Removing unreachable block (ram,0x1001c059) */
/* [binja] int32_t __fastcall sub_1001c02f(int32_t arg1) */

int FUN_1001c02f(int arg1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int unaff_EBP;
  
  seh_prolog();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  builtin_strncpy((char *)(unaff_EBP + -0x24),"Genu",4);
  builtin_strncpy((char *)(unaff_EBP + -0x20),"ineI",4);
  builtin_strncpy((char *)(unaff_EBP + -0x1c),"ntel",4);
  *(char *)(unaff_EBP + -0x18) = '\0';
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = (undefined4 *)cpuid_basic_info(0);
  uVar5 = puVar1[1];
  uVar4 = puVar1[2];
  uVar3 = puVar1[3];
  *(undefined4 *)(unaff_EBP + -0x2c) = *puVar1;
  *(undefined4 *)(unaff_EBP + -0x38) = uVar5;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar3;
  iVar2 = FUN_1001c075();
  return iVar2;
}



