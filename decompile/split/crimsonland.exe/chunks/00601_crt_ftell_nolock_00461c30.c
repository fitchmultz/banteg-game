/* crt_ftell_nolock @ 00461c30 */

/* CRT: ftell without lock */

int __cdecl crt_ftell_nolock(char *param_1)

{
  uint fd;
  uint uVar1;
  byte bVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  int local_c;
  int local_8;
  
  pcVar7 = param_1;
  fd = *(uint *)(param_1 + 0x10);
  if (*(int *)(param_1 + 4) < 0) {
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  local_8 = crt_lseek(fd,0,1);
  if (local_8 < 0) {
LAB_00461cbe:
    local_c = -1;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xc);
    if ((uVar1 & 0x108) == 0) {
      return local_8 - *(int *)(param_1 + 4);
    }
    pcVar4 = *(char **)param_1;
    pcVar6 = *(char **)(param_1 + 8);
    local_c = (int)pcVar4 - (int)pcVar6;
    if ((uVar1 & 3) == 0) {
      if ((uVar1 & 0x80) == 0) {
        piVar3 = crt_errno_ptr();
        *piVar3 = 0x16;
        goto LAB_00461cbe;
      }
    }
    else {
      pcVar8 = pcVar6;
      if (((uint)(&crt_pioinfo_table)[(int)fd >> 5][(fd & 0x1f) * 9 + 1] & 0x80) != 0) {
        for (; pcVar8 < pcVar4; pcVar8 = pcVar8 + 1) {
          if (*pcVar8 == '\n') {
            local_c = local_c + 1;
          }
        }
      }
    }
    if (local_8 != 0) {
      if ((param_1[0xc] & 1U) != 0) {
        if (*(int *)(param_1 + 4) == 0) {
          local_c = 0;
        }
        else {
          pcVar4 = pcVar4 + (*(int *)(param_1 + 4) - (int)pcVar6);
          if (((uint)(&crt_pioinfo_table)[(int)fd >> 5][(fd & 0x1f) * 9 + 1] & 0x80) != 0) {
            lVar5 = crt_lseek(fd,0,2);
            if (lVar5 == local_8) {
              pcVar6 = *(char **)(param_1 + 8);
              pcVar8 = pcVar4 + (int)pcVar6;
              param_1 = pcVar4;
              for (; pcVar6 < pcVar8; pcVar6 = pcVar6 + 1) {
                if (*pcVar6 == '\n') {
                  param_1 = param_1 + 1;
                }
              }
              bVar2 = pcVar7[0xd] & 0x20;
            }
            else {
              crt_lseek(fd,local_8,0);
              pcVar7 = (char *)0x200;
              if ((((char *)0x200 < pcVar4) || ((*(uint *)(param_1 + 0xc) & 8) == 0)) ||
                 ((*(uint *)(param_1 + 0xc) & 0x400) != 0)) {
                pcVar7 = *(char **)(param_1 + 0x18);
              }
              bVar2 = *(byte *)((&crt_pioinfo_table)[(int)fd >> 5] + (fd & 0x1f) * 9 + 1) & 4;
              param_1 = pcVar7;
            }
            pcVar4 = param_1;
            if (bVar2 != 0) {
              pcVar4 = param_1 + 1;
            }
          }
          param_1 = pcVar4;
          local_8 = local_8 - (int)param_1;
        }
      }
      local_c = local_c + local_8;
    }
  }
  return local_c;
}



