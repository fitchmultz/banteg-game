/* mod_api_core_printf @ 0040e000 */

/* mod API vtable 0x00: clAPI_t::CORE_Printf (writes to OutputDebugStringA) */

void __cdecl mod_api_core_printf(char *fmt,...)

{
  char local_ffc [4092];
  
  crt_vsprintf(local_ffc,fmt,&stack0x00000008);
  OutputDebugStringA(local_ffc);
  return;
}



