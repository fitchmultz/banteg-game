/* FUN_10022ab9 @ 10022ab9 */

/* [binja] void* __stdcall sub_10022ab9(void* arg1, int32_t arg2, int32_t arg3) */

void * FUN_10022ab9(void *arg1,int arg2,int arg3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_48 [17];
  
  if ((arg1 == (void *)arg2) || (puVar5 = arg1, arg1 == (void *)arg3)) {
    puVar5 = local_48;
  }
  iVar8 = -4;
  do {
    iVar7 = -4;
    pfVar6 = (float *)(puVar5 + iVar8 + 4);
    fVar1 = *(float *)arg2;
    fVar2 = *(float *)(arg2 + 4);
    fVar3 = *(float *)(arg2 + 8);
    fVar4 = *(float *)(arg2 + 0xc);
    do {
      *pfVar6 = (float)((float10)fVar4 * (float10)*(float *)(arg3 + 0x40 + iVar7 * 4) +
                        (float10)fVar2 * (float10)*(float *)(arg3 + 0x20 + iVar7 * 4) +
                       (float10)fVar1 * (float10)*(float *)(arg3 + 0x10 + iVar7 * 4) +
                       (float10)fVar3 * (float10)*(float *)(arg3 + 0x30 + iVar7 * 4));
      pfVar6 = pfVar6 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0);
    ffree((float10)fVar1);
    ffree((float10)fVar2);
    ffree((float10)fVar3);
    ffree((float10)fVar4);
    arg2 = arg2 + 0x10;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0);
  if (puVar5 != arg1) {
    puVar9 = arg1;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  return arg1;
}



