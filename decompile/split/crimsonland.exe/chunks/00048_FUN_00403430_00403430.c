/* FUN_00403430 @ 00403430 */

/* [binja] int32_t sub_403430(float* arg1, int32_t arg2, int32_t arg3) */

int __cdecl FUN_00403430(float *arg1,int arg2,int arg3)

{
  if ((((*arg1 - 10.0 < ui_mouse_x) && (arg1[1] - 2.0 < ui_mouse_y)) &&
      (ui_mouse_x < (float)arg3 + *arg1)) &&
     ((ui_mouse_y < (float)arg2 + arg1[1] && (ui_mouse_blocked == '\0')))) {
    return 1;
  }
  return 0;
}



