/* reg_read_dword_default @ 0042a980 */

/* reads a registry DWORD or writes fallback to output */

int __cdecl reg_read_dword_default(HKEY key,char *name,uint *out,uint fallback)

{
  uint *puVar1;
  LONG LVar2;
  DWORD local_4;
  
  puVar1 = out;
  local_4 = 4;
  LVar2 = RegQueryValueExA((HKEY)key,name,(LPDWORD)0x0,(LPDWORD)&out,(LPBYTE)out,&local_4);
  if (LVar2 != 0) {
    *puVar1 = fallback;
  }
  return 0;
}



