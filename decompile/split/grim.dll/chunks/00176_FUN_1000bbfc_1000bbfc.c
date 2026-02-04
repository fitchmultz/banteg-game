/* FUN_1000bbfc @ 1000bbfc */

/* [binja] int32_t __stdcall sub_1000bbfc(int32_t* arg1, int32_t* arg2, int32_t* arg3, int32_t*
   arg4, int32_t* arg5, int32_t arg6, int32_t arg7) */

int FUN_1000bbfc(int *arg1,int *arg2,int *arg3,int *arg4,int *arg5,int arg6,int arg7)

{
  int *arg2_00;
  int iVar1;
  int *piVar2;
  int unaff_EDI;
  int *piVar3;
  bool bVar4;
  int in_stack_00000020;
  int local_a0;
  int local_9c;
  int local_98;
  int local_78 [9];
  undefined1 local_54 [24];
  int local_3c;
  int local_38;
  int local_34 [4];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_10016121(local_34);
  arg2_00 = arg4;
  if (arg1 == (int *)0x0) {
    iVar1 = -0x7789f794;
    goto LAB_1000bd90;
  }
  if (arg4 == (int *)0x0) {
    iVar1 = -0x7789f794;
    goto LAB_1000bd90;
  }
  if (((arg7 & 0xffffU) == 5) || (in_stack_00000020 != 0)) {
LAB_1000bd39:
    iVar1 = 1;
    if (arg1 == arg2_00) {
      iVar1 = 0x10001;
    }
    iVar1 = FUN_100161bb(local_34,(char *)&local_a0,arg2_00,arg5,arg6,(int *)0x0,iVar1,unaff_EDI);
    if ((iVar1 < 0) ||
       (iVar1 = FUN_1000acc0(arg1,(int)arg2,arg3,local_a0,local_9c,local_98,(int)arg5,local_78,arg7,
                             in_stack_00000020), iVar1 < 0)) goto LAB_1000bd90;
  }
  else {
    if (arg2 != arg5) {
      if ((arg2 != (int *)0x0) && (arg5 != (int *)0x0)) {
        iVar1 = 0x100;
        bVar4 = true;
        piVar2 = arg2;
        piVar3 = arg5;
        do {
          if (iVar1 == 0) break;
          iVar1 = iVar1 + -1;
          bVar4 = *piVar2 == *piVar3;
          piVar2 = piVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (bVar4);
        if (bVar4) goto LAB_1000bc77;
      }
      goto LAB_1000bd39;
    }
LAB_1000bc77:
    if (arg3 == (int *)0x0) {
      (**(code **)(*arg1 + 0x20))(arg1,local_54);
      local_14 = 0;
      local_10 = 0;
      local_c = local_3c;
      local_8 = local_38;
    }
    else {
      local_14 = *arg3;
      local_10 = arg3[1];
      local_c = arg3[2];
      local_8 = arg3[3];
    }
    if (arg6 == 0) {
      (**(code **)(*arg2_00 + 0x20))(arg2_00,local_54);
      local_24 = 0;
      local_20 = 0;
      local_1c = local_3c;
      local_18 = local_38;
    }
    else {
      local_24 = *(int *)arg6;
      local_20 = *(int *)(arg6 + 4);
      local_1c = *(int *)(arg6 + 8);
      local_18 = *(int *)(arg6 + 0xc);
    }
    if ((local_c - local_14 != local_1c - local_24) || (local_8 - local_10 != local_18 - local_20))
    goto LAB_1000bd39;
    (**(code **)(*arg2_00 + 0xc))(arg2_00,&arg4);
    grim_d3d_debug_set_mute(1);
    iVar1 = (**(code **)(*arg4 + 0x70))(arg4,arg2_00,&local_24,1,arg1,&local_14);
    grim_d3d_debug_set_mute(0);
    (**(code **)(*arg4 + 8))(arg4);
    if (iVar1 < 0) goto LAB_1000bd39;
  }
  iVar1 = 0;
LAB_1000bd90:
  FUN_100161b6((char *)local_34);
  return iVar1;
}



