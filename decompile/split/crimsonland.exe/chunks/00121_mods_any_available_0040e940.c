/* mods_any_available @ 0040e940 */

/* returns true if any mods\*.dll exist */

bool mods_any_available(void)

{
  HANDLE handle;
  int iVar1;
  int iVar2;
  uint local_118 [70];
  
  iVar2 = 0;
  handle = crt_findfirst(s_mods___dll_00473050,local_118);
  if ((handle != (HANDLE)0xffffffff) && (&stack0x00000000 != (undefined1 *)0x104)) {
    do {
      iVar2 = iVar2 + 1;
      iVar1 = crt_findnext(handle,local_118);
    } while (iVar1 == 0);
  }
  crt_findclose(handle);
  return iVar2 != 0;
}



