/* FUN_1001e93e @ 1001e93e */

void __cdecl FUN_1001e93e(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *ptr;
  undefined4 local_c;
  undefined4 local_8;
  
  ptr = (undefined4 *)0x0;
  local_8 = (png_structp)0x0;
  local_c = (undefined4 *)0x0;
  if (param_1 != (undefined4 *)0x0) {
    local_8 = (png_structp)*param_1;
  }
  if (param_2 != (undefined4 *)0x0) {
    ptr = (undefined4 *)*param_2;
  }
  if (param_3 != (undefined4 *)0x0) {
    local_c = (undefined4 *)*param_3;
  }
  if (local_8 != (png_structp)0x0) {
    FUN_1001e81b(local_8,ptr,local_c);
  }
  if (ptr != (undefined4 *)0x0) {
    png_free_ptr(ptr);
    *param_2 = 0;
  }
  if (local_c != (undefined4 *)0x0) {
    png_free_ptr(local_c);
    *param_3 = 0;
  }
  if (local_8 != (png_structp)0x0) {
    png_free_ptr(local_8);
    *param_1 = 0;
  }
  return;
}



