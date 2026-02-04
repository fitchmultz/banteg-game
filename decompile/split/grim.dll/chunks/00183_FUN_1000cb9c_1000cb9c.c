/* FUN_1000cb9c @ 1000cb9c */

/* [binja] int32_t __stdcall sub_1000cb9c(int32_t** arg1, int32_t* arg2, int32_t arg3, int32_t arg4,
   int32_t arg5, int32_t arg6, void* arg7, int32_t arg8, int32_t arg9, int32_t** arg10, int32_t
   arg11, int32_t arg12, int32_t arg13, int32_t arg14) */

int FUN_1000cb9c(int **arg1,int *arg2,int arg3,int arg4,int arg5,int arg6,void *arg7,int arg8,
                int arg9,int **arg10,int arg11,int arg12,int arg13,int arg14)

{
  int iVar1;
  int *unaff_ESI;
  int local_14 [2];
  void *local_c;
  int *local_8;
  
  FUN_1001bca5(local_14);
  iVar1 = FUN_1001bcb7(local_14,arg2,(int *)0x0,unaff_ESI);
  if (-1 < iVar1) {
    iVar1 = FUN_1000cb5c(arg1,local_c,local_8,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,
                         arg13,arg14);
  }
  FUN_1001bed2(local_14);
  return iVar1;
}



