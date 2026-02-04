/* crt_fp_to_string @ 0046a415 */

/* formats a floating-point value for printf-style conversion */

int * __cdecl crt_fp_to_string(double value,int *out,uint *digits)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  undefined4 in_stack_ffffffbc;
  undefined2 uVar4;
  short local_2c;
  char local_2a;
  char local_28 [24];
  uint local_10;
  uint uStack_c;
  undefined2 uStack_8;
  
  uVar4 = (undefined2)((uint)in_stack_ffffffbc >> 0x10);
  FUN_0046a471((int *)&local_10,(int *)&value);
  iVar3 = FUN_0046da83(local_10,uStack_c,CONCAT22(uVar4,uStack_8),0x11,0,&local_2c);
  puVar2 = digits;
  piVar1 = out;
  out[2] = iVar3;
  *out = (int)local_2a;
  out[1] = (int)local_2c;
  crt_strcpy((char *)digits,local_28);
  piVar1[3] = (int)puVar2;
  return piVar1;
}



