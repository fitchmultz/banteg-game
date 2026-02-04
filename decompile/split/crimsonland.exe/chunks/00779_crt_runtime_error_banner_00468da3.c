/* crt_runtime_error_banner @ 00468da3 */

/* runtime error prolog/epilog around report */

void crt_runtime_error_banner(void)

{
  if ((DAT_004d99cc == 1) || ((DAT_004d99cc == 0 && (DAT_0047b184 == 1)))) {
    crt_report_runtime_error(0xfc);
    if (DAT_004d9b84 != (code *)0x0) {
      (*DAT_004d9b84)();
    }
    crt_report_runtime_error(0xff);
  }
  return;
}



