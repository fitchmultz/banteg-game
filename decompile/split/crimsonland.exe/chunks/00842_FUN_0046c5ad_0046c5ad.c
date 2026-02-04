/* FUN_0046c5ad @ 0046c5ad */

void FUN_0046c5ad(void)

{
  if (DAT_004d9c48 == 0) {
    crt_lock(0xb);
    if (DAT_004d9c48 == 0) {
      FUN_0046c5db();
      DAT_004d9c48 = DAT_004d9c48 + 1;
    }
    crt_unlock(0xb);
  }
  return;
}



