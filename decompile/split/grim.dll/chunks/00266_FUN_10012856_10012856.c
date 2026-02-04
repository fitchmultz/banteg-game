/* FUN_10012856 @ 10012856 */

/* [binja] void __fastcall sub_10012856(int32_t* arg1) */

void __fastcall FUN_10012856(int *arg1)

{
  if ((undefined4 *)arg1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)arg1[1])(1);
  }
  if ((undefined4 *)*arg1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*arg1)(1);
  }
  return;
}



