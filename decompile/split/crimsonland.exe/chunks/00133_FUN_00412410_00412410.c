/* FUN_00412410 @ 00412410 */

/* [binja] void* __fastcall sub_412410(int32_t* arg1) */

void * __fastcall FUN_00412410(int *arg1)

{
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  if ((void *)*arg1 != (void *)0x0) {
    crt_free((void *)*arg1);
    pvVar1 = extraout_EAX;
  }
  if ((void *)arg1[1] != (void *)0x0) {
    crt_free((void *)arg1[1]);
    pvVar1 = extraout_EAX_00;
  }
  return pvVar1;
}



