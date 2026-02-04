/* FUN_0045657a @ 0045657a */

/* WARNING: Removing unreachable block (ram,0x004565a4) */

void FUN_0045657a(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_EBP;
  
  FUN_004636c8();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffc4;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  builtin_strncpy((char *)(unaff_EBP + -0x24),"Genu",4);
  builtin_strncpy((char *)(unaff_EBP + -0x20),"ineI",4);
  builtin_strncpy((char *)(unaff_EBP + -0x1c),"ntel",4);
  *(char *)(unaff_EBP + -0x18) = '\0';
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = (undefined4 *)cpuid_basic_info(0);
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar2 = puVar1[3];
  *(undefined4 *)(unaff_EBP + -0x2c) = *puVar1;
  *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  FUN_004565c0();
  return;
}



