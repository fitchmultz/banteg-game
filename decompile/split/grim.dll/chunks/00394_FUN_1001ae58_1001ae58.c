/* FUN_1001ae58 @ 1001ae58 */

/* [binja] void*** __thiscall sub_1001ae58(void*** arg1, char arg2) */

void *** __thiscall FUN_1001ae58(void *this,void ***arg1,char arg2)

{
  grim_vertex_space_converter_destroy(this);
  if (((uint)arg1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



