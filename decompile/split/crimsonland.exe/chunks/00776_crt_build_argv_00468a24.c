/* crt_build_argv @ 00468a24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* parses command line into argv/argc */

void crt_build_argv(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_c;
  int local_8;
  
  if (DAT_004db4ec == 0) {
    crt_mbcs_init();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_004d9a7c,0x104);
  _DAT_004d99b0 = &DAT_004d9a7c;
  pbVar2 = &DAT_004d9a7c;
  if (*DAT_004db4e4 != 0) {
    pbVar2 = DAT_004db4e4;
  }
  crt_parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_c);
  puVar1 = _malloc(local_c + local_8 * 4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  crt_parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_c);
  _DAT_004d9998 = puVar1;
  _DAT_004d9994 = local_8 + -1;
  return;
}



