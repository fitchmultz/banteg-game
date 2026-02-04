/* FUN_10035f08 @ 10035f08 */

void __cdecl FUN_10035f08(int param_1,int param_2,short *param_3,int param_4,int param_5)

{
  int iVar1;
  int aiStack_90 [35];
  
  iVar1 = *(int *)(param_1 + 0x11c) + 0x80;
  if (DAT_100554e8 == '\0') {
    FUN_10036f75(param_3,*(short **)(param_2 + 0x50),aiStack_90,param_4,param_5,iVar1);
  }
  else {
    FUN_100373d7((undefined8 *)param_3,(undefined8 *)*(short **)(param_2 + 0x50),
                 (undefined8 *)aiStack_90,param_4,param_5,iVar1);
  }
  return;
}



