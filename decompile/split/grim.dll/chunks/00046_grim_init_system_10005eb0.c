/* grim_init_system @ 10005eb0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Grim2D vtable 0x14: Grim2D init; returns success */

int __fastcall grim_init_system(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = &DAT_10059e3c;
  for (iVar3 = 0x41; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  _getcwd((char *)&DAT_10059e3c,0x104);
  iVar3 = grim_d3d_init();
  if ((char)iVar3 == '\0') {
    return iVar3;
  }
  if ((DAT_1005cc48 == '\x01') && (grim_input_cached == '\0')) {
    iVar3 = grim_mouse_init();
    if ((char)iVar3 == '\0') {
      grim_error_text = s_DI8__Could_not_initialize_mouse__10053bf4;
      grim_mouse_shutdown();
      FUN_10004280();
      uVar1 = grim_window_destroy();
      return uVar1 & 0xffffff00;
    }
  }
  if (DAT_1005cc38 == '\x01') {
    iVar3 = grim_keyboard_init(DAT_1005d3f8);
    if ((char)iVar3 == '\0') {
      grim_error_text = s_DI8__Could_not_initialize_keyboa_10053bd0;
      grim_mouse_shutdown();
      grim_keyboard_shutdown();
      FUN_10004280();
      uVar1 = grim_window_destroy();
      return uVar1 & 0xffffff00;
    }
  }
  if (DAT_1005cc68 == '\x01') {
    iVar3 = grim_joystick_init(DAT_1005d3f8);
    if ((char)iVar3 == '\0') {
      grim_error_text = s_DI8__Could_not_initialize_joysti_10053bac;
      DAT_1005cc68 = '\0';
    }
  }
  FUN_10004920();
  FUN_10004970();
  (**(code **)(*in_ECX + 0x20))(0x15,2);
  _DAT_1005d0b4 = &DAT_1005d3f8;
  (**(code **)(*in_ECX + 0x20))(0x10);
  puVar2 = (undefined4 *)FUN_10005ae0((byte *)s_load_smallFnt_dat_10053b8c);
  if (puVar2 != (undefined4 *)0x0) {
    puVar4 = puVar2;
    puVar5 = &grim_font2_glyph_widths;
    for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return CONCAT31((int3)((uint)puVar2 >> 8),1);
}



