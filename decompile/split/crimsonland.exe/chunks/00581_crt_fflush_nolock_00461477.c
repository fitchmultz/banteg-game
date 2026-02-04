/* crt_fflush_nolock @ 00461477 */

/* CRT: fflush without lock */

int __cdecl crt_fflush_nolock(int *param_1)

{
  int iVar1;
  
  iVar1 = crt_flushbuf(param_1);
  if (iVar1 != 0) {
    return -1;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 0x40) != 0) {
    iVar1 = crt_commit(param_1[4]);
    return -(uint)(iVar1 != 0);
  }
  return 0;
}



