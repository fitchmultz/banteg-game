/* FUN_1002f7ce @ 1002f7ce */

void __cdecl FUN_1002f7ce(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x184);
  if (*(int *)(iVar1 + 0x10) != 0) {
    if (*(char *)(param_1 + 0x49) != '\0') {
      uVar2 = FUN_1002f1ce();
      if ((char)uVar2 != '\0') {
        *(undefined1 **)(iVar1 + 0xc) = &LAB_1002f2b1;
        goto LAB_1002f7ff;
      }
    }
    *(code **)(iVar1 + 0xc) = FUN_1002f068;
  }
LAB_1002f7ff:
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}



