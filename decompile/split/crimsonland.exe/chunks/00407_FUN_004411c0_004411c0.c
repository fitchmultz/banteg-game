/* FUN_004411c0 @ 004411c0 */

void FUN_004411c0(void)

{
  float *unaff_retaddr;
  
  (*grim_interface_ptr->vtable->grim_set_color_ptr)((float *)&DAT_004ccca8);
  *unaff_retaddr = *unaff_retaddr - 16.0;
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(unaff_retaddr,192.0,1.0);
  *unaff_retaddr = *unaff_retaddr + 16.0;
  unaff_retaddr[1] = unaff_retaddr[1] + 4.0;
  return;
}



