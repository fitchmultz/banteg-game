/* effect_init_entry @ 0042de80 */

/* initializes an effect entry to default values */

void __cdecl effect_init_entry(void *entry)

{
  undefined4 *puVar1;
  int iVar2;
  
  *(undefined4 *)((int)entry + 0x2c) = 0;
  *(undefined4 *)((int)entry + 0x24) = 0;
  *(undefined4 *)((int)entry + 0x14) = 0;
  *(undefined4 *)((int)entry + 0x30) = 0x3f800000;
  *(undefined4 *)((int)entry + 0x34) = 0x3f800000;
  *(undefined4 *)((int)entry + 0x18) = 0x3f800000;
  *(undefined4 *)((int)entry + 0x38) = 0x3f800000;
  *(undefined4 *)((int)entry + 0x3c) = 0x3f800000;
  puVar1 = (undefined4 *)((int)entry + 0x50);
  iVar2 = 4;
  do {
    puVar1[2] = 0xffffffff;
    *puVar1 = 0x3f000000;
    puVar1[1] = 0x3f800000;
    puVar1 = puVar1 + 7;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



