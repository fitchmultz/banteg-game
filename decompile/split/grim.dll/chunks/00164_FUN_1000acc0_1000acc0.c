/* FUN_1000acc0 @ 1000acc0 */

/* [binja] int32_t __stdcall sub_1000acc0(int32_t* arg1, int32_t arg2, int32_t* arg3, int32_t arg4,
   int32_t arg5, int32_t arg6, int32_t arg7, int32_t* arg8, int32_t arg9, int32_t arg10) */

int FUN_1000acc0(int *arg1,int arg2,int *arg3,int arg4,int arg5,int arg6,int arg7,int *arg8,int arg9
                ,int arg10)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int *piVar3;
  int unaff_EDI;
  int *piVar4;
  int local_b8 [19];
  void **local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  int local_5c [4];
  undefined4 local_4c;
  undefined4 local_48;
  int local_44 [7];
  int local_28;
  int local_24;
  int local_20 [4];
  int local_10 [3];
  
  FUN_1001284c(local_10);
  FUN_10016121(local_20);
  if (arg1 == (int *)0x0) {
    iVar2 = -0x7789f794;
  }
  else if ((arg4 == 0) || (arg8 == (int *)0x0)) {
    iVar2 = -0x7789f794;
  }
  else {
    if (arg9 == -1) {
      arg9 = 0x80004;
    }
    iVar1 = FUN_100161bb(local_20,(char *)local_b8,arg1,(int *)arg2,(int)arg3,(int *)0x0,0,unaff_ESI
                        );
    if (-1 < iVar1) {
      local_68 = arg5;
      local_6c = (void **)arg4;
      local_64 = arg6;
      local_60 = 0;
      local_5c[0] = *arg8;
      local_5c[1] = arg8[1];
      local_5c[2] = arg8[2];
      local_5c[3] = arg8[3];
      local_4c = 0;
      local_48 = 1;
      piVar3 = local_5c;
      piVar4 = local_44;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      local_28 = arg10;
      local_24 = arg7;
      iVar1 = FUN_10016007(local_10,local_b8,&local_6c,(void ***)arg9,unaff_EDI);
      iVar2 = 0;
      if (-1 < iVar1) goto LAB_1000ad85;
    }
    iVar2 = iVar1;
  }
LAB_1000ad85:
  FUN_100161b6((char *)local_20);
  FUN_10012856(local_10);
  return iVar2;
}



