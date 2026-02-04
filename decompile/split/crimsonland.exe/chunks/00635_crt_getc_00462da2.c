/* crt_getc @ 00462da2 */

/* CRT: get character with stream lock */

uint __cdecl crt_getc(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  
  crt_lock_file((uint)param_1);
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    uVar2 = crt_filbuf(param_1);
  }
  else {
    uVar2 = (uint)*(byte *)*param_1;
    *param_1 = (byte *)*param_1 + 1;
  }
  crt_unlock_file((uint)param_1);
  return uVar2;
}



