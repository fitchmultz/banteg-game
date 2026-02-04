/* crt_dosmaperr @ 00465d20 */

/* map Win32 error to errno/doserrno */

void __cdecl crt_dosmaperr(uint os_error)

{
  uint *puVar1;
  undefined **ppuVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = crt_doserrno_ptr();
  iVar4 = 0;
  *puVar1 = os_error;
  ppuVar2 = (undefined **)&crt_dosmaperr_table;
  do {
    if ((undefined *)os_error == *ppuVar2) {
      piVar3 = crt_errno_ptr();
      *piVar3 = *(int *)(iVar4 * 8 + 0x47b7c4);
      return;
    }
    ppuVar2 = ppuVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (ppuVar2 < &PTR_crt_terminate_0047b928);
  if ((0x12 < os_error) && (os_error < 0x25)) {
    piVar3 = crt_errno_ptr();
    *piVar3 = 0xd;
    return;
  }
  if ((0xbb < os_error) && (os_error < 0xcb)) {
    piVar3 = crt_errno_ptr();
    *piVar3 = 8;
    return;
  }
  piVar3 = crt_errno_ptr();
  *piVar3 = 0x16;
  return;
}



