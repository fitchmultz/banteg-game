/* crt_u96_shl1 @ 0046d961 */

/* CRT: shift 96-bit value left by 1 (in-place) */

void __cdecl crt_u96_shl1(uint *value)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *value;
  uVar2 = value[1];
  *value = uVar1 * 2;
  value[1] = uVar2 * 2 | uVar1 >> 0x1f;
  value[2] = value[2] << 1 | uVar2 >> 0x1f;
  return;
}



