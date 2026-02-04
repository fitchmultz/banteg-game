/* FUN_0046d9bc @ 0046d9bc */

/* [binja] int32_t sub_46d9bc(char* arg1, int32_t arg2, int32_t arg3) */

int __cdecl FUN_0046d9bc(char *arg1,int arg2,int arg3)

{
  int value;
  int iVar1;
  int extraout_EAX;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  value = arg3;
  local_8 = 0x404e;
  *(undefined4 *)arg3 = 0;
  *(undefined4 *)(arg3 + 4) = 0;
  *(undefined4 *)(arg3 + 8) = 0;
  iVar1 = 0;
  if (arg2 != 0) {
    arg3 = arg2;
    do {
      local_14 = *(uint *)value;
      local_10 = *(undefined4 *)(value + 4);
      local_c = *(undefined4 *)(value + 8);
      crt_u96_shl1((uint *)value);
      crt_u96_shl1((uint *)value);
      ___add_12((uint *)value,&local_14);
      crt_u96_shl1((uint *)value);
      local_10 = 0;
      local_c = 0;
      local_14 = (uint)*arg1;
      iVar1 = ___add_12((uint *)value,&local_14);
      arg1 = arg1 + 1;
      arg3 = arg3 + -1;
    } while (arg3 != 0);
  }
  while (*(int *)(value + 8) == 0) {
    *(uint *)(value + 8) = *(uint *)(value + 4) >> 0x10;
    iVar1 = *(uint *)value << 0x10;
    local_8 = local_8 + 0xfff0;
    *(uint *)(value + 4) = *(uint *)value >> 0x10 | *(uint *)(value + 4) << 0x10;
    *(int *)value = iVar1;
  }
  while ((*(uint *)(value + 8) & 0x8000) == 0) {
    crt_u96_shl1((uint *)value);
    local_8 = local_8 + 0xffff;
    iVar1 = extraout_EAX;
  }
  *(undefined2 *)(value + 10) = (undefined2)local_8;
  return CONCAT22((short)((uint)iVar1 >> 0x10),(undefined2)local_8);
}



