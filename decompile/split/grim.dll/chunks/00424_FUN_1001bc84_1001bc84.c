/* FUN_1001bc84 @ 1001bc84 */

/* [binja] void*** __thiscall sub_1001bc84(void*** arg1, char arg2) */

void *** __thiscall FUN_1001bc84(void *this,void ***arg1,char arg2)

{
  void ***unaff_ESI;
  
  thunk_FUN_1001b493(unaff_ESI);
  if (((uint)arg1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



