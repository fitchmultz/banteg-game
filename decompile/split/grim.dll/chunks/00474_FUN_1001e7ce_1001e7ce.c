/* FUN_1001e7ce @ 1001e7ce */

void __cdecl FUN_1001e7ce(png_structp png_ptr,undefined4 *param_2)

{
  png_uint_32 pVar1;
  png_uint_32 pVar2;
  undefined4 *puVar3;
  png_structp extraout_ECX;
  png_structp this;
  undefined4 local_8;
  
  this = png_ptr;
  local_8 = FUN_1001ebf8((int)png_ptr);
  pVar1 = png_ptr->height;
  png_ptr->num_rows = pVar1;
  pVar2 = pVar1;
  puVar3 = param_2;
  if (0 < local_8) {
    do {
      for (; pVar2 != 0; pVar2 = pVar2 - 1) {
        FUN_1001e427(this,png_ptr,(byte *)*puVar3,(byte *)0x0);
        puVar3 = puVar3 + 1;
        this = extraout_ECX;
      }
      local_8 = local_8 + -1;
      pVar2 = pVar1;
      puVar3 = param_2;
    } while (local_8 != 0);
  }
  return;
}



