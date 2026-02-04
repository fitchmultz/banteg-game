/* FUN_0046a104 @ 0046a104 */

/* [binja] int32_t sub_46a104(int32_t* arg1) */

int __cdecl FUN_0046a104(int *arg1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*arg1 != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    arg1 = arg1 + 1;
  } while (iVar1 < 3);
  return 1;
}



