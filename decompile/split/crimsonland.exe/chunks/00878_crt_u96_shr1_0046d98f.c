/* crt_u96_shr1 @ 0046d98f */

/* CRT: shift 96-bit value right by 1 (in-place) */

void __cdecl crt_u96_shr1(uint *value)

{
  uint uVar1;
  
  uVar1 = value[1];
  value[1] = uVar1 >> 1 | value[2] << 0x1f;
  value[2] = value[2] >> 1;
  *value = *value >> 1 | uVar1 << 0x1f;
  return;
}



