/* ui_update_notice_update @ 00442150 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders the update-available notice and its button */

void __cdecl ui_update_notice_update(float *xy,float alpha)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_4 = alpha * 0.8;
  puVar1 = &local_10;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(xy,266.0,76.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)xy);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(xy,266.0,76.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,0.2,0.2,1.0);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 12.0,xy[1] + 14.0,s_NOTE__004789c0,puVar1);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,0.8);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 60.0,xy[1] + 4.0,s_There_is_a_newer_version_of_the_004789f8);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 60.0,xy[1] + 18.0,s_game_available_for_download__004789d8);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 60.0,xy[1] + 32.0,&s_empty_string);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,*xy + 60.0,xy[1] + 46.0,&s_empty_string);
  if ((DAT_004cc930 & 1) == 0) {
    DAT_004cc930 = DAT_004cc930 | 1;
    DAT_004d0ed6 = 1;
    DAT_004d0ee5 = 0;
    DAT_004d0ee4 = 0;
    _DAT_004d0ee0 = 0x3f800000;
    _DAT_004d0edc = 0;
    _DAT_004d0ed0 = (char *)0x0;
    DAT_004d0ed4 = 0;
    DAT_004d0ed5 = '\0';
    _DAT_004d0ed8 = 0;
    crt_atexit(&DAT_004423c0);
  }
  _DAT_004d0ed0 = s_Get_the_update_004789c8;
  ui_button_update((float *)&stack0xffffffe4,(ui_button_t *)&DAT_004d0ed0);
  if (DAT_004d0ed5 != '\0') {
    DAT_00480838 = 1;
  }
  return;
}



