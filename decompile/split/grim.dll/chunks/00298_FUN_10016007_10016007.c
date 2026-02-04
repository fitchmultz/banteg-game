/* FUN_10016007 @ 10016007 */

/* [binja] int32_t __thiscall sub_10016007(int32_t* arg1, void*** arg2, void*** arg3, int32_t arg4)
    */

int __thiscall FUN_10016007(void *this,int *arg1,void ***arg2,void ***arg3,int arg4)

{
  void *pvVar1;
  int iVar2;
  int *unaff_EBX;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(void ****)((int)this + 8) = arg3;
  if (((((uint)arg3 & 0xffff) == 0) || (5 < ((uint)arg3 & 0xffff))) ||
     (((uint)arg3 & 0xfff00000) != 0)) {
    return -0x7789f794;
  }
  arg1[0x10] = (uint)arg3 & 0x80000;
  pvVar1 = grim_pixel_format_create((uint *)arg1);
  *(void **)((int)this + 4) = pvVar1;
  if (pvVar1 != (void *)0x0) {
    pvVar1 = grim_pixel_format_create((uint *)arg2);
    *(void **)this = pvVar1;
    if (pvVar1 != (void *)0x0) {
      iVar2 = FUN_10017361(pvVar1,unaff_EBX);
      if (iVar2 < 0) goto LAB_100160f3;
      iVar2 = FUN_1001416a(this);
      if ((((-1 < iVar2) || (iVar2 = FUN_100142a2(unaff_EBX), -1 < iVar2)) ||
          ((iVar2 = FUN_10014393(unaff_EBX), -1 < iVar2 ||
           ((iVar2 = FUN_10014595(unaff_EBX), -1 < iVar2 ||
            (iVar2 = FUN_10014799(unaff_EBX), -1 < iVar2)))))) ||
         ((iVar2 = FUN_10014bbc(unaff_EBX), -1 < iVar2 ||
          ((((iVar2 = FUN_1001514e(unaff_EBX), -1 < iVar2 ||
             (iVar2 = FUN_10015534(unaff_EBX), -1 < iVar2)) ||
            (iVar2 = FUN_10015c65(unaff_EBX), -1 < iVar2)) ||
           (iVar2 = FUN_10012b93(unaff_EBX), -1 < iVar2)))))) {
        iVar2 = 0;
        goto LAB_100160f3;
      }
    }
  }
  iVar2 = -0x7fffbffb;
LAB_100160f3:
  if (*(undefined4 **)((int)this + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)this + 4))(1);
    *(undefined4 *)((int)this + 4) = 0;
  }
  if (*(undefined4 **)this != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)this)(1);
    *(undefined4 *)this = 0;
  }
  return iVar2;
}



