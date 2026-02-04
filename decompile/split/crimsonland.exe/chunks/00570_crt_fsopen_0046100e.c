/* crt_fsopen @ 0046100e */

/* opens file with explicit share mode (fopen uses share=0x40) */

undefined4 * __cdecl crt_fsopen(LPCSTR param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = crt_getstream();
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar2 = crt_openfile(param_1,param_2,param_3,puVar1);
  crt_unlock_file((uint)puVar1);
  return puVar2;
}



