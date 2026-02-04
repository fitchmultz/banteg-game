/* console_destroy @ 004016e0 */

/* [binja] void __fastcall sub_4016e0(int32_t* arg1) */

void __fastcall console_destroy(int *arg1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)arg1[2];
  if (puVar1 != (undefined4 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      crt_free((void *)*puVar1);
    }
    *puVar1 = 0;
    if ((void *)puVar1[1] != (void *)0x0) {
      console_log_node_free((void *)puVar1[1],'\x01');
    }
    puVar1[1] = 0;
    crt_free(puVar1);
  }
  puVar1 = (undefined4 *)*arg1;
  arg1[2] = 0;
  if (puVar1 != (undefined4 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      crt_free((void *)*puVar1);
    }
    *puVar1 = 0;
    crt_free(puVar1);
  }
  puVar1 = (undefined4 *)arg1[1];
  *arg1 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      crt_free((void *)*puVar1);
    }
    *puVar1 = 0;
    crt_free(puVar1);
  }
  puVar1 = (undefined4 *)arg1[4];
  arg1[1] = 0;
  if (puVar1 != (undefined4 *)0x0) {
    if ((void *)*puVar1 != (void *)0x0) {
      crt_free((void *)*puVar1);
    }
    *puVar1 = 0;
    if ((void *)puVar1[1] != (void *)0x0) {
      console_log_node_free((void *)puVar1[1],'\x01');
    }
    puVar1[1] = 0;
    crt_free(puVar1);
  }
  arg1[4] = 0;
  return;
}



