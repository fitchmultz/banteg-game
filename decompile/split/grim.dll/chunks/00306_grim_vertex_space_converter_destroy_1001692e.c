/* grim_vertex_space_converter_destroy @ 1001692e */

/* frees the converted vertex buffer at this+0x104c */

void __fastcall grim_vertex_space_converter_destroy(void *this)

{
  *(undefined ***)this = &PTR_FUN_1004cae4;
  operator_delete(*(void **)((int)this + 0x104c));
  return;
}



