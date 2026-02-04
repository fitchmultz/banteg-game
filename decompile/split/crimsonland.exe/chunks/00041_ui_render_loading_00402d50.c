/* ui_render_loading @ 00402d50 */

/* [binja] int32_t sub_402d50() */

int ui_render_loading(void)

{
  IGrim2D_vtbl *pIVar1;
  int iVar2;
  undefined4 uVar3;
  float y;
  char *text;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  uStack_24 = 0;
  fStack_2c = (float)(config_blob.screen_width / 2 + -0x6e);
  fStack_28 = (float)(config_blob.screen_height / 2 + -0x1e);
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&fStack_2c,220.0,60.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  fStack_2c = (float)(config_blob.screen_height / 2 + -0x1e);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)((float *)&stack0xffffffd0,220.0,60.0);
  pIVar1 = grim_interface_ptr->vtable;
  text = s_Please_wait____00471444;
  y = (float)(config_blob.screen_height / 2 + -8);
  iVar2 = (*pIVar1->grim_measure_text_width)(s_Please_wait____00471444);
  uVar3 = 0x402ead;
  (*pIVar1->grim_draw_text_small)((float)(config_blob.screen_width / 2 - iVar2 / 2),y,text);
  iVar2 = (*grim_interface_ptr->vtable->grim_set_config_var)
                    (0x36,CONCAT31((int3)((uint)uVar3 >> 8),1));
  return iVar2;
}



