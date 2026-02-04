/* FUN_1001b472 @ 1001b472 */

/* [binja] void*** __thiscall sub_1001b472(void*** arg1, char arg2) */

void *** __thiscall FUN_1001b472(void *this,void ***arg1,char arg2)

{
  void ***unaff_ESI;
  
  thunk_FUN_10016c3c(unaff_ESI);
  if (((uint)arg1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



