/* FUN_00466a61 @ 00466a61 */

/* [binja] HMODULE sub_466a61(int32_t* arg1) */

void * __cdecl FUN_00466a61(int *arg1)

{
  HMODULE pHVar1;
  int iVar2;
  
  *arg1 = 0;
  pHVar1 = GetModuleHandleA((LPCSTR)0x0);
  if (((short)pHVar1->unused == 0x5a4d) && (pHVar1[0xf].unused != 0)) {
    iVar2 = (int)&pHVar1->unused + pHVar1[0xf].unused;
    *(undefined1 *)arg1 = *(undefined1 *)(iVar2 + 0x1a);
    pHVar1 = (HMODULE)CONCAT31((int3)((uint)iVar2 >> 8),*(undefined1 *)(iVar2 + 0x1b));
    *(undefined1 *)((int)arg1 + 1) = *(undefined1 *)(iVar2 + 0x1b);
  }
  return pHVar1;
}



