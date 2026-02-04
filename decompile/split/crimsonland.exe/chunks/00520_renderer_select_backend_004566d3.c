/* renderer_select_backend @ 004566d3 */

/* selects renderer table based on config */

int renderer_select_backend(int reset)

{
  uint uVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  if (reset == 0) {
    DAT_00479770 = 0xffff;
    ppuVar3 = &PTR_FUN_00479688;
    ppuVar4 = &PTR_LAB_004795a0;
    for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
  }
  else if (DAT_00479770 == 0xffff) {
    DAT_00479770 = 0;
    ppuVar3 = &PTR_FUN_00479688;
    ppuVar4 = &PTR_LAB_004795a0;
    for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    FUN_00457127(&PTR_LAB_004795a0);
    iVar2 = FUN_004564e6(4,"DisableD3DXPSGP",(LPBYTE)&reset);
    if (iVar2 == 0) {
      reset = 0;
    }
    if (reset != 1) {
      uVar1 = FUN_0045661f(7);
      if (uVar1 == 0) {
        uVar1 = FUN_0045661f(10);
        if (uVar1 == 0) {
          uVar1 = FUN_0045661f(6);
          if (uVar1 != 0) {
            FUN_004567b0(&PTR_LAB_004795a0);
            DAT_00479770 = 3;
          }
        }
        else {
          FUN_004568c0(&PTR_LAB_004795a0);
          DAT_00479770 = 2;
        }
      }
      else {
        FUN_00456aa5(&PTR_LAB_004795a0);
        DAT_00479770 = 1;
      }
    }
  }
  return DAT_00479770;
}



