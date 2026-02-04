/* FUN_00461fd5 @ 00461fd5 */

int __cdecl FUN_00461fd5(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  crt_lock_file2(1,0x47b3f8);
  iVar1 = FUN_004666f5((int *)&DAT_0047b3f8);
  iVar2 = crt_output((int *)&DAT_0047b3f8,param_1,(undefined4 *)&stack0x00000008);
  FUN_00466782(iVar1,(int *)&DAT_0047b3f8);
  crt_unlock_file2(1,0x47b3f8);
  return iVar2;
}



