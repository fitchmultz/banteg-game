/* entry @ 1000a9e9 */

/* [binja] int32_t __stdcall _start(HINSTANCE arg1, int32_t arg2, int32_t arg3) */

int entry(HINSTANCE arg1,int arg2,int arg3)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  
  iVar1 = arg2;
  iVar3 = DAT_1005db5c;
  if (arg2 != 0) {
    if ((arg2 != 1) && (arg2 != 2)) goto LAB_1000aa31;
    if ((DAT_1005dbc4 != (code *)0x0) && (iVar3 = (*DAT_1005dbc4)(arg1,arg2,arg3), iVar3 == 0)) {
      return 0;
    }
    iVar3 = FUN_1000a93e((int)arg1);
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_1000aa31:
  BVar2 = DllMain(arg1,arg2,(LPVOID)arg3);
  if (arg2 == 1) {
    if (BVar2 != 0) {
      return BVar2;
    }
    FUN_1000a93e((int)arg1);
  }
  if ((arg2 != 0) && (arg2 != 3)) {
    return BVar2;
  }
  iVar3 = FUN_1000a93e((int)arg1);
  arg2 = BVar2;
  if (iVar3 == 0) {
    arg2 = 0;
  }
  if (arg2 != 0) {
    if (DAT_1005dbc4 != (code *)0x0) {
      iVar3 = (*DAT_1005dbc4)(arg1,iVar1,arg3);
      return iVar3;
    }
    return arg2;
  }
  return 0;
}



