/* crt_mbcs_init @ 0046d5c7 */

/* CRT: one-time init of multibyte/ctype tables (GetACP) */

void crt_mbcs_init(void)

{
  if (DAT_004db4ec == 0) {
    crt_setmbcp(-3);
    DAT_004db4ec = 1;
  }
  return;
}



