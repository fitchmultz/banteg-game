/* FUN_100247b3 @ 100247b3 */

/* [binja] int32_t sub_100247b3(int32_t arg1, char arg2, int32_t arg3) */

int __cdecl FUN_100247b3(int arg1,char arg2,int arg3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined3 in_stack_00000009;
  uint in_stack_00000010;
  
  puVar2 = _arg2;
  for (uVar1 = in_stack_00000010 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = CONCAT22(CONCAT11((undefined1)arg3,(undefined1)arg3),
                       CONCAT11((undefined1)arg3,(undefined1)arg3));
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = in_stack_00000010 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined1 *)puVar2 = (undefined1)arg3;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  return (int)_arg2;
}



