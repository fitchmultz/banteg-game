/* crt_run_initializers @ 00462eb0 */

/* invokes CRT initializer function ranges */

void crt_run_initializers(void)

{
  if (PTR_FUN_0047b160 != (undefined *)0x0) {
    (*(code *)PTR_FUN_0047b160)();
  }
  crt_call_fn_range((undefined4 *)&DAT_004710e4,(undefined4 *)&DAT_004710f8);
  crt_call_fn_range((undefined4 *)&DAT_00471000,(undefined4 *)&DAT_004710e0);
  return;
}



