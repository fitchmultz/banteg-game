/* FUN_10002fc0 @ 10002fc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t __fastcall sub_10002fc0(char* arg1) */

int __fastcall FUN_10002fc0(char *arg1)

{
  int iVar1;
  undefined4 *puVar2;
  tagRECT local_10;
  
  grim_noop();
  *arg1 = '\0';
  arg1[4] = -1;
  arg1[5] = -1;
  arg1[6] = -1;
  arg1[7] = -1;
  arg1[8] = '\0';
  arg1[9] = '\0';
  arg1[10] = '\0';
  arg1[0xb] = '\0';
  arg1[0x1c] = '\0';
  arg1[0x1d] = '\0';
  arg1[0x1e] = '\0';
  arg1[0x1f] = '\0';
  arg1[0x24] = '\0';
  arg1[0x25] = '\0';
  arg1[0x26] = '\0';
  arg1[0x27] = '\0';
  arg1[0x29] = '\0';
  arg1[0x28] = '\0';
  arg1[0x14] = '\0';
  arg1[0x15] = '\0';
  arg1[0x16] = '\0';
  arg1[0x17] = '\0';
  GetClientRect(DAT_1005d3f8,&local_10);
  *(LONG *)(arg1 + 0x10) = local_10.right;
  *(LONG *)(arg1 + 0xc) = local_10.bottom;
  *(undefined4 *)(arg1 + 0x10) = grim_backbuffer_width;
  *(undefined4 *)(arg1 + 0xc) = grim_backbuffer_height;
  puVar2 = &DAT_10059e3c;
  for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  _getcwd((char *)&DAT_10059e3c,0x104);
  local_10.left = local_10.left & 0xffffff00;
  _DAT_1005d1c8 = local_10.left;
  _DAT_1005d1cc = local_10.top;
  _DAT_1005d1d4 = local_10.bottom;
  _DAT_1005d1d0 = local_10.right;
  return CONCAT31((int3)((uint)local_10.bottom >> 8),1);
}



