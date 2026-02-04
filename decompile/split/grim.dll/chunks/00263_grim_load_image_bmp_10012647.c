/* grim_load_image_bmp @ 10012647 */

/* [binja] int32_t __stdcall sub_10012647(int16_t* arg1, void* arg2) */

int __thiscall grim_load_image_bmp(void *this,short *arg1,void *arg2)

{
  int iVar1;
  void *unaff_retaddr;
  
  if (((arg2 < (void *)0xe) || (*arg1 != 0x4d42)) || (arg2 < *(void **)(arg1 + 1))) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = FUN_100103d6(this,(int *)(arg1 + 7),(void *)((int)arg2 + -0xe),unaff_retaddr);
  }
  return iVar1;
}



