/* DllMain @ 10009a20 */

/* DLL entrypoint (process attach): caches module handle and loads dialog icon */

BOOL DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)

{
  if (fdwReason == 1) {
    grim_module_handle = hinstDLL;
    DAT_10059778 = LoadIconA((HINSTANCE)hinstDLL,(LPCSTR)0x72);
  }
  return 1;
}



