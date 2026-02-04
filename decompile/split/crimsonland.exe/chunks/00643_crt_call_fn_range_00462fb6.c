/* crt_call_fn_range @ 00462fb6 */

/* call function pointers in a range */

void __cdecl crt_call_fn_range(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



