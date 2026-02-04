/* FUN_1000ae72 @ 1000ae72 */

/* [binja] int32_t __stdcall sub_1000ae72(int32_t* arg1, int32_t arg2, int32_t arg3, int32_t arg4,
   int32_t arg5, int32_t arg6, int32_t arg7, int32_t arg8, int32_t arg9, int32_t arg10, int32_t
   arg11) */

int FUN_1000ae72(int *arg1,int arg2,int arg3,int arg4,int arg5,int arg6,int arg7,int arg8,int arg9,
                int arg10,int arg11)

{
  int unaff_ESI;
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  undefined4 *puVar3;
  int local_ac [19];
  void **local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined4 local_50 [6];
  undefined4 local_38 [7];
  int local_1c;
  int local_18;
  int local_14 [3];
  int local_8;
  
  FUN_1001284c(local_14);
  FUN_1001619a(&local_8);
  if (((arg1 == (int *)0x0) || (arg4 == 0)) || (arg9 == 0)) {
    iVar1 = -0x7789f794;
  }
  else {
    if (arg10 == -1) {
      arg10 = 0x80004;
    }
    iVar1 = FUN_100165d3(&local_8,local_ac,arg1,(int *)arg2,arg3,0,0,unaff_ESI);
    if (-1 < iVar1) {
      local_5c = arg5;
      local_58 = arg6;
      local_60 = (void **)arg4;
      local_54 = arg7;
      puVar2 = (undefined4 *)arg9;
      puVar3 = local_50;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = local_38;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *(undefined4 *)arg9;
        arg9 = (int)(arg9 + 4);
        puVar2 = puVar2 + 1;
      }
      local_1c = arg11;
      local_18 = arg8;
      iVar1 = FUN_10016007(local_14,local_ac,&local_60,(void ***)arg10,unaff_EDI);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  thunk_FUN_100161a0(&local_8);
  FUN_10012856(local_14);
  return iVar1;
}



