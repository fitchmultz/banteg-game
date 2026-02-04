/* FUN_10035f54 @ 10035f54 */

void __cdecl FUN_10035f54(int param_1,int param_2,short *param_3,int *param_4,int param_5)

{
  int iVar1;
  short asStack_90 [70];
  
  iVar1 = *(int *)(param_1 + 0x11c) + 0x80;
  if (DAT_100554e8 == '\0') {
    FUN_10037a8f(param_3,asStack_90,*(short **)(param_2 + 0x50),(int)param_4,param_5,iVar1);
  }
  else {
    FUN_10037dea((undefined8 *)param_3,(undefined8 *)asStack_90,
                 (undefined8 *)*(short **)(param_2 + 0x50),param_4,param_5,iVar1);
  }
  return;
}



