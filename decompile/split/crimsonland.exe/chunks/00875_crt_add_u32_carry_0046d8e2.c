/* crt_add_u32_carry @ 0046d8e2 */

/* CRT: add two u32 values and return carry */

int __cdecl crt_add_u32_carry(uint a,uint b,uint *out)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = a + b;
  if ((uVar1 < a) || (uVar1 < b)) {
    iVar2 = 1;
  }
  *out = uVar1;
  return iVar2;
}



