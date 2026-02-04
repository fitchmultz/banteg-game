/* FUN_1001aec8 @ 1001aec8 */

/* [binja] void*** __thiscall sub_1001aec8(void*** arg1, char arg2) */

void *** __thiscall FUN_1001aec8(void *this,void ***arg1,char arg2)

{
  void ***unaff_ESI;
  
  FUN_10016c3c(unaff_ESI);
  if (((uint)arg1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



