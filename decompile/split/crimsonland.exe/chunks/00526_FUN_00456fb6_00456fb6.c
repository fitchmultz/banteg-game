/* FUN_00456fb6 @ 00456fb6 */

/* [binja] int32_t __stdcall sub_456fb6(int32_t arg1, int32_t arg2, void* arg3) */

int FUN_00456fb6(int arg1,int arg2,void *arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  undefined4 local_44 [16];
  
  iVar5 = arg1;
  if (arg3 == (void *)arg1) {
    if (arg2 != arg1) {
      iVar7 = -4;
      do {
        iVar6 = -0x10;
        fVar9 = (float10)*(float *)((int)arg3 + iVar7 * 4 + 0x10);
        fVar10 = (float10)*(float *)((int)arg3 + iVar7 * 4 + 0x20);
        fVar11 = (float10)*(float *)((int)arg3 + iVar7 * 4 + 0x30);
        fVar12 = (float10)*(float *)((int)arg3 + iVar7 * 4 + 0x40);
        do {
          *(float *)(arg1 + 0x40 + iVar6 * 4) =
               (float)(fVar12 * (float10)*(float *)(arg2 + 0x4c + iVar6 * 4) +
                       fVar10 * (float10)*(float *)(arg2 + 0x44 + iVar6 * 4) +
                      fVar9 * (float10)*(float *)(arg2 + 0x40 + iVar6 * 4) +
                      fVar11 * (float10)*(float *)(arg2 + 0x48 + iVar6 * 4));
          iVar6 = iVar6 + 4;
        } while (iVar6 != 0);
        ffree(fVar9);
        ffree(fVar10);
        ffree(fVar11);
        ffree(fVar12);
        arg1 = arg1 + 4;
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0);
      return iVar5;
    }
    puVar8 = local_44;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *(undefined4 *)arg3;
      arg3 = (undefined4 *)((int)arg3 + 4);
      puVar8 = puVar8 + 1;
    }
    arg3 = local_44;
  }
  iVar7 = -4;
  do {
    iVar6 = -4;
    fVar1 = *(float *)arg2;
    fVar2 = *(float *)(arg2 + 4);
    fVar3 = *(float *)(arg2 + 8);
    fVar4 = *(float *)(arg2 + 0xc);
    do {
      *(float *)(arg1 + 0x10 + iVar6 * 4) =
           (float)((float10)fVar4 * (float10)*(float *)((int)arg3 + iVar6 * 4 + 0x40) +
                   (float10)fVar2 * (float10)*(float *)((int)arg3 + iVar6 * 4 + 0x20) +
                  (float10)fVar1 * (float10)*(float *)((int)arg3 + iVar6 * 4 + 0x10) +
                  (float10)fVar3 * (float10)*(float *)((int)arg3 + iVar6 * 4 + 0x30));
      iVar6 = iVar6 + 1;
    } while (iVar6 != 0);
    ffree((float10)fVar1);
    ffree((float10)fVar2);
    ffree((float10)fVar3);
    ffree((float10)fVar4);
    arg2 = arg2 + 0x10;
    arg1 = arg1 + 0x10;
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0);
  return iVar5;
}



