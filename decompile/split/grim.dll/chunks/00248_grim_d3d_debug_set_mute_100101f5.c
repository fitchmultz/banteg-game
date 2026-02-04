/* grim_d3d_debug_set_mute @ 100101f5 */

/* loads DebugSetMute from d3d8/d3d8d and toggles D3D debug output */

void __cdecl grim_d3d_debug_set_mute(int mute)

{
  HMODULE pHVar1;
  
  if (DAT_1005db64 == (FARPROC)0x0) {
    if (DAT_1005db60 != (FARPROC)0x0) goto LAB_1001027e;
    pHVar1 = GetModuleHandleA("d3d8.dll");
    if (pHVar1 != (HMODULE)0x0) {
      pHVar1 = LoadLibraryA("d3d8.dll");
      if (pHVar1 != (HMODULE)0x0) {
        DAT_1005db64 = GetProcAddress(pHVar1,"DebugSetMute");
      }
    }
    pHVar1 = GetModuleHandleA("d3d8d.dll");
    if (pHVar1 != (HMODULE)0x0) {
      pHVar1 = LoadLibraryA("d3d8d.dll");
      if (pHVar1 != (HMODULE)0x0) {
        DAT_1005db60 = GetProcAddress(pHVar1,"DebugSetMute");
      }
    }
    if (DAT_1005db64 != (FARPROC)0x0) goto LAB_1001026a;
  }
  else {
LAB_1001026a:
    (*DAT_1005db64)(mute);
  }
  if (DAT_1005db60 == (FARPROC)0x0) {
    return;
  }
LAB_1001027e:
                    /* WARNING: Could not recover jumptable at 0x1001027e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_1005db60)();
  return;
}



