/* mod_load_mod @ 0040e860 */

/* loads mods\%s, calls CMOD_GetMod, wires the mod context (offset +4), and returns the mod
   interface pointer */

void * mod_load_mod(void)

{
  FARPROC pFVar1;
  void *pvVar2;
  char local_200 [512];
  
  crt_sprintf(local_200,s_mods__s_00472f58);
  console_printf(&console_log_queue,s_CMOD____s__00472fec,local_200);
  plugin_module_handle = (HMODULE)LoadLibraryA(local_200);
  if (plugin_module_handle == (HMODULE)0x0) {
    console_printf(&console_log_queue,s_CMOD__Load_library_failed__00472fd0);
    return (void *)0x0;
  }
  pFVar1 = GetProcAddress((HMODULE)plugin_module_handle,s_CMOD_GetMod_00473044);
  if (pFVar1 == (FARPROC)0x0) {
    console_printf(&console_log_queue,s_CMOD__CMOD_GetMod_failed__00473028);
    FreeLibrary((HMODULE)plugin_module_handle);
    return (void *)0x0;
  }
  pvVar2 = (void *)(*pFVar1)();
  if (pvVar2 == (void *)0x0) {
    console_printf(&console_log_queue,s_CMOD__bad_CMOD_GetMod_function_00473008);
  }
  else {
    *(mod_api_t **)((int)pvVar2 + 4) = &mod_api_context;
  }
  console_printf(&console_log_queue,s_CMOD_GetMod_ok_00472ff8);
  return pvVar2;
}



