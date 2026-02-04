/* console_set_open @ 004018b0 */

/* sets console_open_flag (console_state+0x28) and console_input_enabled (0x0047f4d4); flushes input
   via Grim2D vtable +0x4c */

void __thiscall console_set_open(void *this,char open)

{
  *(char *)((int)this + 0x28) = open;
  console_input_enabled = open;
  (*grim_interface_ptr->vtable->grim_flush_input)();
  return;
}



