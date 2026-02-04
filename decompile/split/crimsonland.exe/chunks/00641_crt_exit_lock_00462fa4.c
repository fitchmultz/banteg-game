/* crt_exit_lock @ 00462fa4 */

/* exit lock */

void crt_exit_lock(void)

{
  crt_lock(0xd);
  return;
}



