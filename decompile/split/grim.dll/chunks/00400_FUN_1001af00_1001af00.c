/* FUN_1001af00 @ 1001af00 */

/* [binja] void* __fastcall sub_1001af00(void* arg1) */

void * __fastcall FUN_1001af00(void *arg1)

{
  undefined4 uVar1;
  
  if ((*(int *)((int)arg1 + 4) == 0x32545844) || (*(int *)((int)arg1 + 4) == 0x33545844)) {
    uVar1 = 0x41700000;
  }
  else {
    uVar1 = 0x437f0000;
  }
  *(undefined4 *)((int)arg1 + 0x106c) = uVar1;
  *(float *)((int)arg1 + 0x1070) = 1.0 / *(float *)((int)arg1 + 0x106c);
  *(float *)((int)arg1 + 0x1c) =
       (float)(int)ROUND(*(float *)((int)arg1 + 0x1c) * 31.0 + 0.5) * 0.032258064;
  *(float *)((int)arg1 + 0x20) =
       (float)(int)ROUND(*(float *)((int)arg1 + 0x20) * 63.0 + 0.5) * 0.015873017;
  *(float *)((int)arg1 + 0x24) =
       (float)(int)ROUND(*(float *)((int)arg1 + 0x24) * 31.0 + 0.5) * 0.032258064;
  *(float *)((int)arg1 + 0x28) =
       (float)(int)ROUND(*(float *)((int)arg1 + 0x106c) * *(float *)((int)arg1 + 0x28) + 0.5) *
       *(float *)((int)arg1 + 0x1070);
  return arg1;
}



