/* inflateReset @ 10024212 */

/* zlib: reset inflate state */

int __cdecl inflateReset(z_streamp strm)

{
  internal_state *piVar1;
  
  if ((strm != (z_streamp)0x0) && (piVar1 = strm->state, piVar1 != (internal_state *)0x0)) {
    strm->total_out = 0;
    strm->total_in = 0;
    strm->msg = (char *)0x0;
    piVar1->dummy = -(uint)(piVar1[3].dummy != 0) & 7;
    inflate_blocks_reset((void *)strm->state[5].dummy,strm,(uLongf *)0x0);
    return 0;
  }
  return -2;
}



