/* FUN_00468887 @ 00468887 */

uint __thiscall FUN_00468887(void *this,uint param_1)

{
  uint uVar1;
  
  if (DAT_0047b3cc < 2) {
    uVar1 = (byte)crt_ctype_table[param_1 * 2] & 4;
  }
  else {
    uVar1 = crt_isctype(this,param_1,4);
  }
  if (uVar1 == 0) {
    param_1 = (param_1 & 0xffffffdf) - 7;
  }
  return param_1;
}



