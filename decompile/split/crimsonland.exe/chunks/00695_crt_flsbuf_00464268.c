/* crt_flsbuf @ 00464268 */

/* flush buffer or write single char (fputc core) */

uint __cdecl crt_flsbuf(uint param_1,int *param_2)

{
  uint uVar1;
  uint fd;
  char *buf;
  int *piVar2;
  byte bVar3;
  undefined3 extraout_var;
  void **ppvVar4;
  int *count;
  
  piVar2 = param_2;
  uVar1 = param_2[3];
  fd = param_2[4];
  if (((uVar1 & 0x82) == 0) || ((uVar1 & 0x40) != 0)) {
LAB_00464374:
    param_2[3] = uVar1 | 0x20;
  }
  else {
    if ((uVar1 & 1) != 0) {
      param_2[1] = 0;
      if ((uVar1 & 0x10) == 0) goto LAB_00464374;
      *param_2 = param_2[2];
      param_2[3] = uVar1 & 0xfffffffe;
    }
    uVar1 = param_2[3];
    param_2[1] = 0;
    param_2 = (int *)0x0;
    piVar2[3] = uVar1 & 0xffffffef | 2;
    if (((uVar1 & 0x10c) == 0) &&
       (((piVar2 != (int *)&DAT_0047b3f8 && (piVar2 != (int *)&DAT_0047b418)) ||
        (bVar3 = FUN_0046b08c(fd), CONCAT31(extraout_var,bVar3) == 0)))) {
      crt_file_buffer_init(piVar2);
    }
    if ((*(ushort *)(piVar2 + 3) & 0x108) == 0) {
      count = (int *)0x1;
      param_2 = (int *)crt_write(fd,(char *)&param_1,1);
    }
    else {
      buf = (char *)piVar2[2];
      count = (int *)(*piVar2 - (int)buf);
      *piVar2 = (int)(buf + 1);
      piVar2[1] = piVar2[6] + -1;
      if ((int)count < 1) {
        if (fd == 0xffffffff) {
          ppvVar4 = (void **)&DAT_0047b930;
        }
        else {
          ppvVar4 = (&crt_pioinfo_table)[(int)fd >> 5] + (fd & 0x1f) * 9;
        }
        if (((uint)ppvVar4[1] & 0x20) != 0) {
          crt_lseek(fd,0,2);
        }
      }
      else {
        param_2 = (int *)crt_write(fd,buf,(uint)count);
      }
      *(undefined1 *)piVar2[2] = (undefined1)param_1;
    }
    if (param_2 == count) {
      return param_1 & 0xff;
    }
    piVar2[3] = piVar2[3] | 0x20;
  }
  return 0xffffffff;
}



