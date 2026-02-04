/* FUN_100161a0 @ 100161a0 */

/* [binja] int32_t __fastcall sub_100161a0(int32_t* arg1) */

int __fastcall FUN_100161a0(int *arg1)

{
  int *piVar1;
  
  piVar1 = (int *)*arg1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1);
  }
  *arg1 = 0;
  return 0;
}



