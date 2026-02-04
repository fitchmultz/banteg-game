/* FUN_100132bb @ 100132bb */

/* [binja] int32_t __fastcall sub_100132bb(int32_t* arg1) */

int __fastcall FUN_100132bb(int *arg1)

{
  int iVar1;
  
  iVar1 = *arg1;
  iVar1 = (*(code *)PTR_FUN_10054390)
                    (*(undefined4 *)(arg1[1] + 0x18),*(undefined4 *)(iVar1 + 0x18),
                     *(undefined4 *)(iVar1 + 0x1058),*(undefined4 *)(iVar1 + 0x105c),
                     *(undefined4 *)(iVar1 + 0x1050),*(undefined4 *)(arg1[1] + 0x1050));
  return iVar1;
}



