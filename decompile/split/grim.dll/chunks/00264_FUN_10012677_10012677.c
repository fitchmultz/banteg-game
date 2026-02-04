/* FUN_10012677 @ 10012677 */

/* [binja] int32_t __thiscall sub_10012677(int32_t* arg1, void* arg2, int32_t* arg3, int32_t* arg4,
   int32_t arg5) */

int __thiscall FUN_10012677(void *this,int *arg1,void *arg2,int *arg3,int *arg4,int arg5)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int *unaff_EDI;
  int *piVar4;
  int local_24 [8];
  
  local_24[0] = 0;
  local_24[1] = 5;
  local_24[2] = 4;
  local_24[3] = 1;
  local_24[4] = 3;
  local_24[5] = 2;
  local_24[6] = 6;
  local_24[7] = 0;
  pvVar2 = arg2;
  do {
    *(int **)((int)this + 0x40) = arg4;
    iVar3 = local_24[local_24[7]];
    *(int *)((int)this + 0x48) = iVar3;
    *(undefined4 *)((int)this + 0x44) = 3;
    if (iVar3 == 0) {
      pvVar2 = (void *)grim_load_image_bmp(this,(short *)arg1,arg2);
    }
    else if (iVar3 == 1) {
      pvVar2 = (void *)grim_load_image_jpg(arg1,(int)arg2,(int)unaff_EDI);
    }
    else if (iVar3 == 2) {
      pvVar2 = (void *)FUN_10011083(this,arg1,arg2,(int)unaff_EDI);
    }
    else if (iVar3 == 3) {
      pvVar2 = (void *)grim_load_image_png(arg1,arg2,unaff_EDI);
    }
    else if (iVar3 == 4) {
      pvVar2 = (void *)grim_load_image_dds(this,arg1,(uint)arg2,unaff_EDI);
    }
    else if (iVar3 == 5) {
      pvVar2 = (void *)grim_load_image_pnm(this,arg1,arg2,(int)unaff_EDI);
    }
    else if (iVar3 == 6) {
      pvVar2 = (void *)FUN_100103d6(this,arg1,arg2,unaff_EDI);
    }
    if (-1 < (int)pvVar2) break;
    if ((*(void **)((int)this + 4) != (void *)0x0) && (*(int *)((int)this + 0x38) != 0)) {
      operator_delete(*(void **)((int)this + 4));
    }
    if ((*(void **)((int)this + 8) != (void *)0x0) && (*(int *)((int)this + 0x3c) != 0)) {
      operator_delete(*(void **)((int)this + 8));
    }
    if (*(void **)((int)this + 0x4c) != (void *)0x0) {
      FUN_100102f7(*(void **)((int)this + 0x4c),(void *)0x1,(char)unaff_EDI);
    }
    if (*(void **)((int)this + 0x50) != (void *)0x0) {
      FUN_100102f7(*(void **)((int)this + 0x50),(void *)0x1,(char)unaff_EDI);
    }
    local_24[7] = local_24[7] + 1;
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x3c) = 0;
    *(undefined4 *)((int)this + 0x4c) = 0;
    *(undefined4 *)((int)this + 0x50) = 0;
  } while ((uint)local_24[7] < 7);
  iVar3 = 7;
  if (local_24[7] == 7) {
    iVar3 = -0x7789f4a7;
  }
  else {
    piVar4 = arg3;
    pvVar2 = this;
    if (arg3 != (int *)0x0) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      *arg3 = *(int *)((int)this + 0xc);
      arg3[1] = *(int *)((int)this + 0x10);
      arg3[2] = *(int *)((int)this + 0x14);
      arg3[3] = 1;
      iVar3 = FUN_1000ac8f(*(int *)this);
      arg3[4] = iVar3;
      arg3[5] = *(int *)((int)this + 0x44);
      arg3[6] = *(int *)((int)this + 0x48);
      for (pvVar1 = this; *(int *)((int)pvVar1 + 0x4c) != 0; pvVar1 = *(void **)((int)pvVar1 + 0x4c)
          ) {
        arg3[3] = arg3[3] + 1;
      }
    }
    do {
      for (; this != (void *)0x0; this = *(void **)((int)this + 0x4c)) {
        *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0xc);
        *(undefined4 *)((int)this + 0x24) = *(undefined4 *)((int)this + 0x10);
        *(undefined4 *)((int)this + 0x18) = 0;
        *(undefined4 *)((int)this + 0x1c) = 0;
        *(undefined4 *)((int)this + 0x28) = 0;
        *(undefined4 *)((int)this + 0x2c) = *(undefined4 *)((int)this + 0x14);
      }
      this = *(void **)((int)pvVar2 + 0x50);
      pvVar2 = this;
    } while (this != (void *)0x0);
    iVar3 = 0;
  }
  return iVar3;
}



