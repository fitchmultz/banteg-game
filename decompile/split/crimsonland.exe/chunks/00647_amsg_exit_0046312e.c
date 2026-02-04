/* __amsg_exit @ 0046312e */

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_004d99cc == 1) {
    crt_runtime_error_banner();
  }
  crt_report_runtime_error(param_1);
  (*(code *)PTR___exit_0047b180)(0xff);
  return;
}



