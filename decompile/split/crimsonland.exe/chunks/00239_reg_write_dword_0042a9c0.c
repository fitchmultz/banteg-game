/* reg_write_dword @ 0042a9c0 */

/* writes a registry DWORD */

int __cdecl reg_write_dword(HKEY key,char *name,uint value)

{
  LONG LVar1;
  
  LVar1 = RegSetValueExA((HKEY)key,name,0,4,(BYTE *)&value,4);
  return -(uint)(LVar1 != 0) & 0x80004005;
}



