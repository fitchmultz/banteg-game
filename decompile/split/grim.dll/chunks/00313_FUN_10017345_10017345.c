/* FUN_10017345 @ 10017345 */

/* [binja] void*** __thiscall sub_10017345(void*** arg1, char arg2) */

void *** __thiscall FUN_10017345(void *this,void ***arg1,char arg2)

{
  grim_vertex_space_converter_destroy(this);
  if (((uint)arg1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



