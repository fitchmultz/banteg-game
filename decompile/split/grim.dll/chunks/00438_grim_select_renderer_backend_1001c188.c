/* grim_select_renderer_backend @ 1001c188 */

/* copies the render backend vtable and selects D3DX/alt paths based on config */

int grim_select_renderer_backend(int force)

{
  uint uVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  if (force == 0) {
    DAT_1005449c = 0xffff;
    ppuVar3 = &PTR_FUN_10053d40;
    ppuVar4 = &PTR_LAB_10053c58;
    for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
  }
  else if (DAT_1005449c == 0xffff) {
    DAT_1005449c = 0;
    ppuVar3 = &PTR_FUN_10053d40;
    ppuVar4 = &PTR_LAB_10053c58;
    for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = *ppuVar3;
      ppuVar3 = ppuVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    FUN_10022b47(&PTR_LAB_10053c58);
    iVar2 = FUN_1001bedd(4,"DisableD3DXPSGP",(LPBYTE)&force);
    if (iVar2 == 0) {
      force = 0;
    }
    if (force != 1) {
      uVar1 = FUN_1001c0d4(7);
      if (uVar1 == 0) {
        uVar1 = FUN_1001c0d4(10);
        if (uVar1 == 0) {
          uVar1 = FUN_1001c0d4(6);
          if (uVar1 != 0) {
            FUN_100221d0(&PTR_LAB_10053c58);
            DAT_1005449c = 3;
          }
        }
        else {
          FUN_100222e0(&PTR_LAB_10053c58);
          DAT_1005449c = 2;
        }
      }
      else {
        grim_init_mmx_sse_functions(&PTR_LAB_10053c58);
        DAT_1005449c = 1;
      }
    }
  }
  return DAT_1005449c;
}



