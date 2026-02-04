/* FUN_004652bc @ 004652bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t sub_4652bc(double arg1, int32_t arg2, int32_t arg3, double* arg4) */

int __cdecl FUN_004652bc(double arg1,int arg2,int arg3,double *arg4)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  dVar1 = arg1;
  if (arg1 < 0.0) {
    dVar1 = -arg1;
  }
  dVar2 = _DAT_0047dbb8;
  if (arg3 == 0x7ff00000) {
    if (arg2 != 0) {
LAB_00465347:
      if (arg1._4_4_ == 0x7ff00000) {
        if (arg1._0_4_ != 0) {
          return 0;
        }
        if (0.0 < _arg2) goto LAB_004653e2;
        if (_arg2 < 0.0) goto LAB_00465379;
      }
      else {
        if (arg1 != -INFINITY) {
          return 0;
        }
        iVar3 = FUN_004653ec(_arg2);
        if (0.0 < _arg2) {
          dVar2 = _DAT_0047dbb8;
          if (iVar3 == 1) {
            dVar2 = -_DAT_0047dbb8;
          }
          goto LAB_004653e2;
        }
        if (_arg2 < 0.0) {
          dVar2 = _DAT_0047dbd8;
          if (iVar3 != 1) {
            dVar2 = 0.0;
          }
          goto LAB_004653e2;
        }
      }
      dVar2 = 1.0;
      goto LAB_004653e2;
    }
    if (1.0 < dVar1) goto LAB_004653e2;
    if (1.0 <= dVar1) {
LAB_0046530c:
      *arg4 = _DAT_0047dbc0;
      return 1;
    }
  }
  else {
    if ((arg3 != -0x100000) || (arg2 != 0)) goto LAB_00465347;
    if (dVar1 <= 1.0) {
      if (1.0 <= dVar1) goto LAB_0046530c;
      goto LAB_004653e2;
    }
  }
LAB_00465379:
  dVar2 = 0.0;
LAB_004653e2:
  *arg4 = dVar2;
  return 0;
}



