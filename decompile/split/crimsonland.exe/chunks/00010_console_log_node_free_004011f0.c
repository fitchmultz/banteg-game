/* console_log_node_free @ 004011f0 */

/* frees a console log node (text + next chain) and optionally frees the node */

void __thiscall console_log_node_free(void *this,char free_self)

{
  if (*(void **)this != (void *)0x0) {
    crt_free(*(void **)this);
  }
  *(undefined4 *)this = 0;
  if (*(void **)((int)this + 4) != (void *)0x0) {
    console_log_node_free(*(void **)((int)this + 4),'\x01');
  }
  *(undefined4 *)((int)this + 4) = 0;
  if ((free_self & 1U) != 0) {
    crt_free(this);
  }
  return;
}



