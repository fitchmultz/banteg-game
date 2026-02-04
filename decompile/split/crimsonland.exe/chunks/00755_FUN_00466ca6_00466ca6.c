/* FUN_00466ca6 @ 00466ca6 */

/* [binja] int32_t* sub_466ca6(void* arg1, int32_t* arg2) */

int * __cdecl FUN_00466ca6(void *arg1,int *arg2)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  byte bVar7;
  uint uVar8;
  void *pvVar9;
  void *pvVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint local_8;
  
  piVar6 = *(int **)((int)arg1 + 0x10);
  puVar11 = (uint *)(arg2 + -1);
  uVar13 = (uint)((int)arg2 - *(int *)((int)arg1 + 0xc)) >> 0xf;
  piVar2 = piVar6 + uVar13 * 0x81 + 0x51;
  uVar12 = *puVar11;
  local_8 = uVar12 - 1;
  if ((local_8 & 1) == 0) {
    uVar4 = *(uint *)(local_8 + (int)puVar11);
    uVar5 = arg2[-2];
    if ((uVar4 & 1) == 0) {
      uVar8 = ((int)uVar4 >> 4) - 1;
      if (0x3f < uVar8) {
        uVar8 = 0x3f;
      }
      if (*(int *)((int)puVar11 + uVar12 + 3) == *(int *)((int)puVar11 + uVar12 + 7)) {
        if (uVar8 < 0x20) {
          pcVar1 = (char *)(uVar8 + 4 + (int)piVar6);
          uVar8 = ~(0x80000000U >> ((byte)uVar8 & 0x1f));
          piVar6[uVar13 + 0x11] = piVar6[uVar13 + 0x11] & uVar8;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *(uint *)arg1 = *(uint *)arg1 & uVar8;
          }
        }
        else {
          pcVar1 = (char *)(uVar8 + 4 + (int)piVar6);
          uVar8 = ~(0x80000000U >> ((byte)uVar8 - 0x20 & 0x1f));
          piVar6[uVar13 + 0x31] = piVar6[uVar13 + 0x31] & uVar8;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *(uint *)((int)arg1 + 4) = *(uint *)((int)arg1 + 4) & uVar8;
          }
        }
      }
      local_8 = local_8 + uVar4;
      *(undefined4 *)(*(int *)((int)puVar11 + uVar12 + 7) + 4) =
           *(undefined4 *)((int)puVar11 + uVar12 + 3);
      *(undefined4 *)(*(int *)((int)puVar11 + uVar12 + 3) + 8) =
           *(undefined4 *)((int)puVar11 + uVar12 + 7);
    }
    pvVar9 = (void *)(((int)local_8 >> 4) - 1);
    if ((void *)0x3f < pvVar9) {
      pvVar9 = (void *)0x3f;
    }
    pvVar10 = arg1;
    if ((uVar5 & 1) == 0) {
      puVar11 = (uint *)((int)puVar11 - uVar5);
      pvVar10 = (void *)(((int)uVar5 >> 4) - 1);
      if ((void *)0x3f < pvVar10) {
        pvVar10 = (void *)0x3f;
      }
      local_8 = local_8 + uVar5;
      pvVar9 = (void *)(((int)local_8 >> 4) - 1);
      if ((void *)0x3f < pvVar9) {
        pvVar9 = (void *)0x3f;
      }
      if (pvVar10 != pvVar9) {
        if (puVar11[1] == puVar11[2]) {
          if (pvVar10 < (void *)0x20) {
            uVar12 = ~(0x80000000U >> ((byte)pvVar10 & 0x1f));
            piVar6[uVar13 + 0x11] = piVar6[uVar13 + 0x11] & uVar12;
            pcVar1 = (char *)((int)pvVar10 + 4U + (int)piVar6);
            *pcVar1 = *pcVar1 + -1;
            if (*pcVar1 == '\0') {
              *(uint *)arg1 = *(uint *)arg1 & uVar12;
            }
          }
          else {
            uVar12 = ~(0x80000000U >> ((byte)pvVar10 - 0x20 & 0x1f));
            piVar6[uVar13 + 0x31] = piVar6[uVar13 + 0x31] & uVar12;
            pcVar1 = (char *)((int)pvVar10 + 4U + (int)piVar6);
            *pcVar1 = *pcVar1 + -1;
            if (*pcVar1 == '\0') {
              *(uint *)((int)arg1 + 4) = *(uint *)((int)arg1 + 4) & uVar12;
            }
          }
        }
        *(uint *)(puVar11[2] + 4) = puVar11[1];
        *(uint *)(puVar11[1] + 8) = puVar11[2];
      }
    }
    if (((uVar5 & 1) != 0) || (pvVar10 != pvVar9)) {
      puVar11[1] = piVar2[(int)pvVar9 * 2 + 1];
      puVar11[2] = (uint)(piVar2 + (int)pvVar9 * 2);
      (piVar2 + (int)pvVar9 * 2)[1] = (int)puVar11;
      *(uint **)(puVar11[1] + 8) = puVar11;
      if (puVar11[1] == puVar11[2]) {
        cVar3 = *(char *)((int)pvVar9 + 4U + (int)piVar6);
        *(char *)((int)pvVar9 + 4U + (int)piVar6) = cVar3 + '\x01';
        bVar7 = (byte)pvVar9;
        if (pvVar9 < (void *)0x20) {
          if (cVar3 == '\0') {
            *(uint *)arg1 = *(uint *)arg1 | 0x80000000U >> (bVar7 & 0x1f);
          }
          piVar6[uVar13 + 0x11] = piVar6[uVar13 + 0x11] | 0x80000000U >> (bVar7 & 0x1f);
        }
        else {
          if (cVar3 == '\0') {
            *(uint *)((int)arg1 + 4) =
                 *(uint *)((int)arg1 + 4) | 0x80000000U >> (bVar7 - 0x20 & 0x1f);
          }
          piVar6[uVar13 + 0x31] = piVar6[uVar13 + 0x31] | 0x80000000U >> (bVar7 - 0x20 & 0x1f);
        }
      }
    }
    *puVar11 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar11) = local_8;
    *piVar2 = *piVar2 + -1;
    piVar6 = piVar2;
    if (*piVar2 == 0) {
      if (DAT_004da394 != (void *)0x0) {
        VirtualFree((LPVOID)(DAT_004da38c * 0x8000 + *(int *)((int)DAT_004da394 + 0xc)),0x8000,
                    0x4000);
        *(uint *)((int)DAT_004da394 + 8) =
             *(uint *)((int)DAT_004da394 + 8) | 0x80000000U >> ((byte)DAT_004da38c & 0x1f);
        *(undefined4 *)(*(int *)((int)DAT_004da394 + 0x10) + 0xc4 + DAT_004da38c * 4) = 0;
        pcVar1 = (char *)(*(int *)((int)DAT_004da394 + 0x10) + 0x43);
        *pcVar1 = *pcVar1 + -1;
        if (*(char *)(*(int *)((int)DAT_004da394 + 0x10) + 0x43) == '\0') {
          *(uint *)((int)DAT_004da394 + 4) = *(uint *)((int)DAT_004da394 + 4) & 0xfffffffe;
        }
        if (*(int *)((int)DAT_004da394 + 8) == -1) {
          VirtualFree(*(LPVOID *)((int)DAT_004da394 + 0xc),0,0x8000);
          HeapFree(crt_heap_handle,0,*(LPVOID *)((int)DAT_004da394 + 0x10));
          crt_memmove(DAT_004da394,(void *)((int)DAT_004da394 + 0x14),
                      (DAT_004da398 * 0x14 - (int)DAT_004da394) + -0x14 + DAT_004da39c);
          DAT_004da398 = DAT_004da398 + -1;
          if (DAT_004da394 < arg1) {
            arg1 = (void *)((int)arg1 + -0x14);
          }
          DAT_004da390 = DAT_004da39c;
        }
      }
      DAT_004da394 = arg1;
      piVar6 = arg1;
      DAT_004da38c = uVar13;
    }
  }
  return piVar6;
}



