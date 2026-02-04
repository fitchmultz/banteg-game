/* FUN_0046a0dd @ 0046a0dd */

/* [binja] int32_t* sub_46a0dd(int32_t arg1, int32_t* arg2) */

int * __cdecl FUN_0046a0dd(int arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = arg1 - (int)arg2;
  iVar2 = 3;
  do {
    *(int *)(iVar1 + (int)arg2) = *arg2;
    arg2 = arg2 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return arg2;
}



