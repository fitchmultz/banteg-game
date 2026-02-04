/* crt_fwrite_nolock @ 004615dd */

/* fwrite implementation (no locking) */

uint __cdecl crt_fwrite_nolock(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *size;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar1 = param_4;
  piVar5 = (int *)(param_2 * param_3);
  if (piVar5 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar4 = piVar5;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar6 = (int *)piVar1[1], piVar6 == (int *)0x0)) {
        if (param_4 <= piVar4) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = crt_flushbuf(piVar1), iVar2 != 0)) {
LAB_004616de:
            return (uint)((int)piVar5 - (int)piVar4) / param_2;
          }
          piVar6 = piVar4;
          if (param_4 != (int *)0x0) {
            piVar6 = (int *)((int)piVar4 - (uint)piVar4 % (uint)param_4);
          }
          size = (int *)crt_write(piVar1[4],param_1,(uint)piVar6);
          if ((size == (int *)0xffffffff) ||
             (piVar4 = (int *)((int)piVar4 - (int)size), size < piVar6)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_004616de;
          }
          goto LAB_00461695;
        }
        uVar3 = crt_flsbuf((int)*param_1,piVar1);
        if (uVar3 == 0xffffffff) goto LAB_004616de;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar4 = (int *)((int)piVar4 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        size = piVar4;
        if (piVar6 <= piVar4) {
          size = piVar6;
        }
        crt_bufcpy((void *)*piVar1,param_1,(size_t)size);
        piVar1[1] = piVar1[1] - (int)size;
        *piVar1 = *piVar1 + (int)size;
        piVar4 = (int *)((int)piVar4 - (int)size);
LAB_00461695:
        param_1 = param_1 + (int)size;
      }
    } while (piVar4 != (int *)0x0);
  }
  return param_3;
}



