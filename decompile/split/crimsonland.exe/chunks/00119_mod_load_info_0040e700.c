/* mod_load_info @ 0040e700 */

/* loads mods\%s, calls CMOD_GetInfo, copies the info struct to DAT_00481c88, and returns it */

void * mod_load_info(void)

{
  FARPROC pFVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  mod_info_t *pmVar5;
  char local_200 [512];
  
  crt_sprintf(local_200,s_mods__s_00472f58);
  console_printf(&console_log_queue,s_CMOD____s__00472fec,local_200);
  plugin_module_handle = (HMODULE)LoadLibraryA(local_200);
  if (plugin_module_handle == (HMODULE)0x0) {
    console_printf(&console_log_queue,s_CMOD__Load_library_failed__00472fd0);
    return (void *)0x0;
  }
  pFVar1 = GetProcAddress((HMODULE)plugin_module_handle,s_CMOD_GetInfo_00472fc0);
  if (pFVar1 != (FARPROC)0x0) {
    if ((DAT_004819c8 & 1) == 0) {
      DAT_004819c8 = DAT_004819c8 | 1;
      mod_info_block.version = 1.0;
      mod_info_block.usesApiVersion = 3;
      pmVar5 = &mod_info_block;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        pmVar5->name[0] = '\0';
        pmVar5->name[1] = '\0';
        pmVar5->name[2] = '\0';
        pmVar5->name[3] = '\0';
        pmVar5 = (mod_info_t *)(pmVar5->name + 4);
      }
      pcVar4 = mod_info_block.author;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        pcVar4[0] = '\0';
        pcVar4[1] = '\0';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        pcVar4 = pcVar4 + 4;
      }
      crt_atexit(&DAT_0040e850);
    }
    puVar2 = (undefined4 *)(*pFVar1)();
    if (puVar2 == (undefined4 *)0x0) {
      console_printf(&console_log_queue,s_CMOD__bad_CMOD_GetInfo_function_00472f84);
    }
    else {
      pmVar5 = &mod_info_block;
      for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined4 *)pmVar5->name = *puVar2;
        puVar2 = puVar2 + 1;
        pmVar5 = (mod_info_t *)(pmVar5->name + 4);
      }
    }
    FreeLibrary((HMODULE)plugin_module_handle);
    console_printf(&console_log_queue,s_CMOD__mod_enum___s__00472f6c,&mod_info_block);
    return &mod_info_block;
  }
  console_printf(&console_log_queue,s_CMOD_GetInfo_failed__00472fa8);
  FreeLibrary((HMODULE)plugin_module_handle);
  return (void *)0x0;
}



