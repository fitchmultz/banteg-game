/* FUN_0046e05b @ 0046e05b */

void __cdecl FUN_0046e05b(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **arg2;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 uStack_a;
  undefined *puStack_8;
  
  ppuVar3 = &PTR_s_November_0047e120;
  if (param_2 != 0) {
    if ((int)param_2 < 0) {
      param_2 = -param_2;
      ppuVar3 = (undefined **)0x47e280;
    }
    if (param_3 == 0) {
      *(undefined2 *)param_1 = 0;
    }
    while (param_2 != 0) {
      ppuVar3 = ppuVar3 + 0x15;
      uVar1 = (int)param_2 >> 3;
      uVar2 = param_2 & 7;
      param_2 = uVar1;
      if (uVar2 != 0) {
        arg2 = ppuVar3 + uVar2 * 3;
        if (0x7fff < *(ushort *)(ppuVar3 + uVar2 * 3)) {
          local_10 = SUB42(*arg2,0);
          local_e._0_2_ = (undefined2)((uint)*arg2 >> 0x10);
          local_e._2_2_ = SUB42(arg2[1],0);
          uStack_a = (undefined2)((uint)arg2[1] >> 0x10);
          puStack_8 = arg2[2];
          local_e = CONCAT22(local_e._2_2_,(undefined2)local_e) + -1;
          arg2 = (undefined **)&local_10;
        }
        FUN_0046de3b((short *)param_1,(int *)arg2);
      }
    }
  }
  return;
}



