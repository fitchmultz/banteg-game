/* FUN_0041dc50 @ 0041dc50 */

int __cdecl FUN_0041dc50(uint param_1,uint param_2,uint param_3,uint param_4)

{
  if (param_4 < param_2) {
    return 1;
  }
  if (param_2 < param_4) {
    return -1;
  }
  if (param_3 < param_1) {
    return 1;
  }
  return -(uint)(param_1 < param_3);
}



