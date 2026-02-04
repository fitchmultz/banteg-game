/* crt_fread_nolock @ 00461b26 */

/* fread implementation (no locking) */

uint __cdecl crt_fread_nolock(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *size;
  
  piVar1 = param_4;
  pcVar6 = (char *)(param_2 * param_3);
  if (pcVar6 == (char *)0x0) {
    param_3 = 0;
  }
  else {
    pcVar5 = param_1;
    param_1 = pcVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((*(ushort *)(piVar1 + 3) & 0x10c) == 0) ||
         (pcVar2 = (char *)piVar1[1], pcVar2 == (char *)0x0)) {
        if (param_1 < param_4) {
          uVar4 = crt_filbuf(piVar1);
          if (uVar4 == 0xffffffff) goto LAB_00461c02;
          *pcVar5 = (char)uVar4;
          param_4 = (int *)piVar1[6];
          pcVar5 = pcVar5 + 1;
          param_1 = param_1 + -1;
        }
        else {
          pcVar2 = param_1;
          if (param_4 != (int *)0x0) {
            pcVar2 = param_1 + -((uint)param_1 % (uint)param_4);
          }
          iVar3 = crt_read(piVar1[4],pcVar5,(uint)pcVar2);
          if (iVar3 == 0) {
            piVar1[3] = piVar1[3] | 0x10;
LAB_00461c02:
            return (uint)((int)pcVar6 - (int)param_1) / param_2;
          }
          if (iVar3 == -1) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_00461c02;
          }
          param_1 = param_1 + -iVar3;
          pcVar5 = pcVar5 + iVar3;
        }
      }
      else {
        size = param_1;
        if (pcVar2 <= param_1) {
          size = pcVar2;
        }
        crt_bufcpy(pcVar5,(void *)*piVar1,(size_t)size);
        param_1 = param_1 + -(int)size;
        piVar1[1] = piVar1[1] - (int)size;
        *piVar1 = (int)(size + *piVar1);
        pcVar5 = pcVar5 + (int)size;
      }
    } while (param_1 != (char *)0x0);
  }
  return param_3;
}



