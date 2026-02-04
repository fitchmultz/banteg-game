/* FUN_0046aa98 @ 0046aa98 */

uint FUN_0046aa98(void)

{
  void **ppvVar1;
  void **ppvVar2;
  void ***pppvVar3;
  uint fd;
  int local_8;
  int local_4;
  
  fd = 0xffffffff;
  crt_lock(0x12);
  local_8 = 0;
  local_4 = 0;
  pppvVar3 = &crt_pioinfo_table;
  while (ppvVar2 = *pppvVar3, ppvVar1 = ppvVar2, ppvVar2 != (void **)0x0) {
    for (; ppvVar2 < ppvVar1 + 0x120; ppvVar2 = ppvVar2 + 9) {
      if (((uint)ppvVar2[1] & 1) == 0) {
        if (ppvVar2[2] == (void *)0x0) {
          crt_lock(0x11);
          if (ppvVar2[2] == (void *)0x0) {
            InitializeCriticalSection((LPCRITICAL_SECTION)(ppvVar2 + 3));
            ppvVar2[2] = (void *)((int)ppvVar2[2] + 1);
          }
          crt_unlock(0x11);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(ppvVar2 + 3));
        if (((uint)ppvVar2[1] & 1) == 0) {
          *ppvVar2 = (void *)0xffffffff;
          fd = ((int)ppvVar2 - (int)*pppvVar3) / 0x24 + local_4;
          if (fd != 0xffffffff) goto LAB_0046abaa;
          break;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(ppvVar2 + 3));
      }
      ppvVar1 = *pppvVar3;
    }
    local_4 = local_4 + 0x20;
    pppvVar3 = pppvVar3 + 1;
    local_8 = local_8 + 1;
    if (0x4da4bf < (int)pppvVar3) goto LAB_0046abaa;
  }
  ppvVar2 = _malloc(0x480);
  if (ppvVar2 != (void **)0x0) {
    crt_nhandle = crt_nhandle + 0x20;
    (&crt_pioinfo_table)[local_8] = ppvVar2;
    ppvVar1 = ppvVar2;
    for (; ppvVar2 < ppvVar1 + 0x120; ppvVar2 = ppvVar2 + 9) {
      *(undefined1 *)(ppvVar2 + 1) = 0;
      *ppvVar2 = (void *)0xffffffff;
      ppvVar2[2] = (void *)0x0;
      *(undefined1 *)((int)ppvVar2 + 5) = 10;
      ppvVar1 = (&crt_pioinfo_table)[local_8];
    }
    fd = local_8 << 5;
    crt_lock_fh(fd);
  }
LAB_0046abaa:
  crt_unlock(0x12);
  return fd;
}



