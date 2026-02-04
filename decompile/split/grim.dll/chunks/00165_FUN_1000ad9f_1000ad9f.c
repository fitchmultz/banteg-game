/* FUN_1000ad9f @ 1000ad9f */

/* [binja] int32_t sub_1000ad9f(int32_t arg1, int32_t arg2, int32_t* arg3, int32_t arg4, int32_t*
   arg5, int32_t* arg6) */

int FUN_1000ad9f(int arg1,int arg2,int *arg3,int arg4,int *arg5,int *arg6)

{
  int unaff_EBP;
  int *unaff_ESI;
  int iVar1;
  
  seh_prolog();
  FUN_10010285((int *)(unaff_EBP + -0x70));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_10016121((int *)(unaff_EBP + -0x1c));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if ((*(int *)(unaff_EBP + 8) == 0) || (*(int *)(unaff_EBP + 0x10) == 0)) {
    iVar1 = -0x7789f794;
  }
  else {
    iVar1 = FUN_100161bb((void *)(unaff_EBP + -0x1c),(char *)(unaff_EBP + -0xbc),
                         *(int **)(unaff_EBP + 0x10),*(int **)(unaff_EBP + 0x14),
                         *(int *)(unaff_EBP + 0x18),(int *)0x0,1,(int)unaff_ESI);
    if (((-1 < iVar1) &&
        (iVar1 = FUN_10010313((void *)(unaff_EBP + -0x70),(int *)(unaff_EBP + -0xbc),unaff_ESI),
        -1 < iVar1)) &&
       (iVar1 = FUN_1001237e(*(int **)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc),
                             *(int *)(unaff_EBP + 0x1c),unaff_ESI), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_100161b6((char *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_1001029e((void *)(unaff_EBP + -0x70));
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar1;
}



