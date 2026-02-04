/* grim_release @ 10005c80 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x0: delete interface */

void grim_release(void)

{
  void *in_ECX;
  
  operator_delete(in_ECX);
  return;
}



