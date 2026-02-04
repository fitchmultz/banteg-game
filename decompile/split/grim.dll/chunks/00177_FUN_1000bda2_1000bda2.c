/* FUN_1000bda2 @ 1000bda2 */

/* [binja] int32_t __stdcall sub_1000bda2(int32_t* arg1, int32_t arg2, int32_t arg3, int32_t* arg4,
   int32_t arg5, int32_t arg6, int32_t arg7, int32_t arg8) */

int FUN_1000bda2(int *arg1,int arg2,int arg3,int *arg4,int arg5,int arg6,int arg7,int arg8)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined1 local_2c [36];
  int local_8;
  
  FUN_1001619a(&local_8);
  if ((arg1 == (int *)0x0) || (arg4 == (int *)0x0)) {
    iVar2 = -0x7789f794;
  }
  else {
    iVar1 = 1;
    if (arg1 == arg4) {
      iVar1 = 0x10001;
    }
    iVar1 = FUN_100165d3(&local_8,&local_54,arg4,(int *)arg5,arg6,0,iVar1,unaff_ESI);
    if (-1 < iVar1) {
      iVar1 = FUN_1000ae72(arg1,arg2,arg3,local_54,local_50,local_4c,local_48,arg5,(int)local_2c,
                           arg7,arg8);
      iVar2 = 0;
      if (-1 < iVar1) goto LAB_1000be19;
    }
    iVar2 = iVar1;
  }
LAB_1000be19:
  thunk_FUN_100161a0(&local_8);
  return iVar2;
}



