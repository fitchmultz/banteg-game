/* FUN_0043b810 @ 0043b810 */

/* [binja] void* __fastcall sub_43b810(void* arg1) */

void * __fastcall FUN_0043b810(void *arg1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x10;
  *(undefined4 *)((int)arg1 + 0x80) = 0;
  *(undefined4 *)((int)arg1 + 0x7c) = 0;
  *(undefined4 *)((int)arg1 + 0x78) = 0;
  *(undefined4 *)((int)arg1 + 0x74) = 0;
  *(undefined4 *)((int)arg1 + 0x14) = 0;
  *(undefined4 *)((int)arg1 + 0x18) = 0;
  *(undefined4 *)((int)arg1 + 0x1c) = 0;
  *(undefined4 *)((int)arg1 + 0x20) = 0xbf800000;
  puVar1 = (undefined4 *)((int)arg1 + 0x60);
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + -1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return arg1;
}



