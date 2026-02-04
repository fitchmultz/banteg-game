/* FUN_10024790 @ 10024790 */

/* [binja] int32_t sub_10024790(int32_t arg1, int32_t arg2, int32_t arg3) */

int __cdecl FUN_10024790(int arg1,int arg2,int arg3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint in_stack_00000010;
  
  puVar2 = (undefined4 *)arg2;
  for (uVar1 = in_stack_00000010 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *(undefined4 *)arg3;
    arg3 = (int)(arg3 + 4);
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = in_stack_00000010 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)arg3;
    arg3 = (int)(arg3 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return arg2;
}



