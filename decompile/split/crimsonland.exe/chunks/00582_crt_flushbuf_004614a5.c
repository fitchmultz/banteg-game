/* crt_flushbuf @ 004614a5 */

/* CRT: flush write buffer */

undefined4 __cdecl crt_flushbuf(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint count;
  
  uVar2 = 0;
  if ((((byte)param_1[3] & 3) == 2) && ((param_1[3] & 0x108U) != 0)) {
    count = *param_1 - param_1[2];
    if (0 < (int)count) {
      uVar1 = crt_write(param_1[4],(char *)param_1[2],count);
      if (uVar1 == count) {
        if ((param_1[3] & 0x80U) != 0) {
          param_1[3] = param_1[3] & 0xfffffffd;
        }
      }
      else {
        param_1[3] = param_1[3] | 0x20;
        uVar2 = 0xffffffff;
      }
    }
  }
  param_1[1] = 0;
  *param_1 = param_1[2];
  return uVar2;
}



