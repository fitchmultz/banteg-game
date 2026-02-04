/* crt_fopen @ 0046103f */

/* fopen wrapper (calls crt_fsopen with share=0x40) */

void __cdecl crt_fopen(LPCSTR param_1,char *param_2)

{
  crt_fsopen(param_1,param_2,0x40);
  return;
}



