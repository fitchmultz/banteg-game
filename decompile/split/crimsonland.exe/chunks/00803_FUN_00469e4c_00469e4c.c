/* FUN_00469e4c @ 00469e4c */

uint __thiscall FUN_00469e4c(void *this,uint param_1,uint param_2)

{
  uint uVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_8;
  
  local_8 = CONCAT22((short)((uint)this >> 0x10),in_FPUControlWord);
  uVar1 = FUN_00469e97(local_8);
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_00469f29(uVar1);
  return uVar1;
}



