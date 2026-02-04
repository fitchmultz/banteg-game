/* crt_sbh_find_block @ 004679d6 */

/* CRT: map a pointer to its small-block heap block header */

void * __cdecl crt_sbh_find_block(void *ptr,void **region_out,uint *page_base)

{
  undefined **ppuVar1;
  uint uVar2;
  
  ppuVar1 = &PTR_LOOP_0047baf0;
  while ((ptr <= ppuVar1[4] || (ppuVar1[5] <= ptr))) {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &PTR_LOOP_0047baf0) {
      return (void *)0x0;
    }
  }
  if (((uint)ptr & 0xf) != 0) {
    return (void *)0x0;
  }
  if (((uint)ptr & 0xfff) < 0x100) {
    return (void *)0x0;
  }
  *region_out = ppuVar1;
  uVar2 = (uint)ptr & 0xfffff000;
  *page_base = uVar2;
  return (void *)(((int)((int)ptr + (-0x100 - uVar2)) >> 4) + 8 + uVar2);
}



