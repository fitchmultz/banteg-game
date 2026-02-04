/* FUN_00441220 @ 00441220 */

void FUN_00441220(void)

{
  float *unaff_retaddr;
  
  (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004ccca8);
  *unaff_retaddr = *unaff_retaddr - 16.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(unaff_retaddr,1.0,48.0);
  *unaff_retaddr = *unaff_retaddr + 16.0;
  return;
}



