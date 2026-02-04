/* FUN_00467484 @ 00467484 */

/* [binja] int32_t sub_467484(int32_t* arg1, void** arg2, void* arg3) */

int __cdecl FUN_00467484(int *arg1,void **arg2,void *arg3)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  void *pvVar8;
  uint *puVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_c;
  
  iVar7 = arg1[4];
  uVar14 = (int)arg3 + 0x17U & 0xfffffff0;
  uVar12 = (uint)((int)arg2 - arg1[3]) >> 0xf;
  iVar5 = uVar12 * 0x204 + 0x144 + iVar7;
  pvVar8 = arg2[-1];
  iVar11 = (int)pvVar8 + -1;
  uVar15 = *(uint *)((int)pvVar8 + -5 + (int)arg2);
  if (iVar11 < (int)uVar14) {
    if (((uVar15 & 1) != 0) || ((int)(uVar15 + iVar11) < (int)uVar14)) {
      return 0;
    }
    local_c = ((int)uVar15 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (*(int *)((int)arg2 + (int)pvVar8 + -1) == *(int *)((int)arg2 + (int)pvVar8 + 3)) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + iVar7);
        uVar13 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar9 = (uint *)(iVar7 + 0x44 + uVar12 * 4);
        *puVar9 = *puVar9 & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *arg1 = *arg1 & uVar13;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + iVar7);
        uVar13 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar9 = (uint *)(iVar7 + 0xc4 + uVar12 * 4);
        *puVar9 = *puVar9 & uVar13;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          arg1[1] = arg1[1] & uVar13;
        }
      }
    }
    *(undefined4 *)(*(int *)((int)arg2 + (int)pvVar8 + 3) + 4) =
         *(undefined4 *)((int)arg2 + (int)pvVar8 + -1);
    *(undefined4 *)(*(int *)((int)arg2 + (int)pvVar8 + -1) + 8) =
         *(undefined4 *)((int)arg2 + (int)pvVar8 + 3);
    iVar11 = uVar15 + (iVar11 - uVar14);
    if (0 < iVar11) {
      uVar15 = (iVar11 >> 4) - 1;
      iVar2 = (int)arg2 + (uVar14 - 4);
      if (0x3f < uVar15) {
        uVar15 = 0x3f;
      }
      iVar5 = iVar5 + uVar15 * 8;
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar5 + 4);
      *(int *)(iVar2 + 8) = iVar5;
      *(int *)(iVar5 + 4) = iVar2;
      *(int *)(*(int *)(iVar2 + 4) + 8) = iVar2;
      if (*(int *)(iVar2 + 4) == *(int *)(iVar2 + 8)) {
        cVar6 = *(char *)(uVar15 + 4 + iVar7);
        *(char *)(uVar15 + 4 + iVar7) = cVar6 + '\x01';
        bVar10 = (byte)uVar15;
        if (uVar15 < 0x20) {
          if (cVar6 == '\0') {
            *arg1 = *arg1 | 0x80000000U >> (bVar10 & 0x1f);
          }
          puVar9 = (uint *)(iVar7 + 0x44 + uVar12 * 4);
        }
        else {
          if (cVar6 == '\0') {
            arg1[1] = arg1[1] | 0x80000000U >> (bVar10 - 0x20 & 0x1f);
          }
          puVar9 = (uint *)(iVar7 + 0xc4 + uVar12 * 4);
          bVar10 = bVar10 - 0x20;
        }
        *puVar9 = *puVar9 | 0x80000000U >> (bVar10 & 0x1f);
      }
      piVar3 = (int *)((int)arg2 + (uVar14 - 4));
      *piVar3 = iVar11;
      *(int *)(iVar11 + -4 + (int)piVar3) = iVar11;
    }
    arg2[-1] = (void *)(uVar14 + 1);
    *(void **)((int)arg2 + (uVar14 - 8)) = (void *)(uVar14 + 1);
  }
  else if ((int)uVar14 < iVar11) {
    arg3 = (void *)(iVar11 - uVar14);
    arg2[-1] = (void *)(uVar14 + 1);
    puVar4 = (undefined4 *)((int)arg2 + (uVar14 - 4));
    uVar13 = ((int)arg3 >> 4) - 1;
    puVar4[-1] = (void *)(uVar14 + 1);
    if (0x3f < uVar13) {
      uVar13 = 0x3f;
    }
    if ((uVar15 & 1) == 0) {
      uVar14 = ((int)uVar15 >> 4) - 1;
      if (0x3f < uVar14) {
        uVar14 = 0x3f;
      }
      if (*(int *)((int)arg2 + (int)pvVar8 + -1) == *(int *)((int)arg2 + (int)pvVar8 + 3)) {
        if (uVar14 < 0x20) {
          pcVar1 = (char *)(uVar14 + 4 + iVar7);
          uVar14 = ~(0x80000000U >> ((byte)uVar14 & 0x1f));
          puVar9 = (uint *)(iVar7 + 0x44 + uVar12 * 4);
          *puVar9 = *puVar9 & uVar14;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *arg1 = *arg1 & uVar14;
          }
        }
        else {
          pcVar1 = (char *)(uVar14 + 4 + iVar7);
          uVar14 = ~(0x80000000U >> ((byte)uVar14 - 0x20 & 0x1f));
          puVar9 = (uint *)(iVar7 + 0xc4 + uVar12 * 4);
          *puVar9 = *puVar9 & uVar14;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            arg1[1] = arg1[1] & uVar14;
          }
        }
      }
      *(undefined4 *)(*(int *)((int)arg2 + (int)pvVar8 + 3) + 4) =
           *(undefined4 *)((int)arg2 + (int)pvVar8 + -1);
      *(undefined4 *)(*(int *)((int)arg2 + (int)pvVar8 + -1) + 8) =
           *(undefined4 *)((int)arg2 + (int)pvVar8 + 3);
      arg3 = (void *)((int)arg3 + uVar15);
      uVar13 = ((int)arg3 >> 4) - 1;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
    }
    iVar11 = iVar5 + uVar13 * 8;
    puVar4[1] = *(undefined4 *)(iVar5 + 4 + uVar13 * 8);
    puVar4[2] = iVar11;
    *(undefined4 **)(iVar11 + 4) = puVar4;
    *(undefined4 **)(puVar4[1] + 8) = puVar4;
    if (puVar4[1] == puVar4[2]) {
      cVar6 = *(char *)(uVar13 + 4 + iVar7);
      *(char *)(uVar13 + 4 + iVar7) = cVar6 + '\x01';
      bVar10 = (byte)uVar13;
      if (uVar13 < 0x20) {
        if (cVar6 == '\0') {
          *arg1 = *arg1 | 0x80000000U >> (bVar10 & 0x1f);
        }
        puVar9 = (uint *)(iVar7 + 0x44 + uVar12 * 4);
      }
      else {
        if (cVar6 == '\0') {
          arg1[1] = arg1[1] | 0x80000000U >> (bVar10 - 0x20 & 0x1f);
        }
        puVar9 = (uint *)(iVar7 + 0xc4 + uVar12 * 4);
        bVar10 = bVar10 - 0x20;
      }
      *puVar9 = *puVar9 | 0x80000000U >> (bVar10 & 0x1f);
    }
    *puVar4 = arg3;
    *(void **)((int)arg3 + -4 + (int)puVar4) = arg3;
  }
  return 1;
}



