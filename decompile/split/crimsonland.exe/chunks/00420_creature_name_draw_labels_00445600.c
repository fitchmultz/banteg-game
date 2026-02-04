/* creature_name_draw_labels @ 00445600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* debug overlay: draws creature name labels over world positions */

void creature_name_draw_labels(void)

{
  float fVar1;
  int iVar2;
  float x;
  float *pfVar3;
  char *text;
  float a;
  
  a = 1.0;
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  text = &DAT_004d152c;
  pfVar3 = &creature_pool.hitbox_size;
  do {
    if (((creature_t *)(pfVar3 + -4))->active != '\0') {
      iVar2 = (*grim_interface_ptr->vtable->grim_measure_text_width)(text);
      fVar1 = _camera_offset_x + pfVar3[1];
      x = (float)(iVar2 + 8);
      (*grim_interface_ptr->vtable->grim_draw_rect_filled)
                ((float *)&stack0xffffffd4,(float)(int)x,15.0);
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,a);
      (*grim_interface_ptr->vtable->grim_draw_text_small)(x,fVar1 - (float)iVar2 * 0.5,text);
    }
    pfVar3 = pfVar3 + 0x26;
    text = text + 0x40;
  } while ((int)pfVar3 < 0x4aa348);
  return;
}



