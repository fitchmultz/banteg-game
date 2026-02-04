/* FUN_1003d0d0 @ 1003d0d0 */

/* [binja] char* __fastcall sub_1003d0d0(int32_t arg1) */

char * __cdecl FUN_1003d0d0(int arg1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *_Src;
  char *pcVar4;
  int iVar5;
  int local_4;
  
  iVar1 = arg1;
  *(undefined4 *)(arg1 + 4) = 0;
  local_4 = FUN_1003e560();
  puVar2 = operator_new(0x50);
  if (puVar2 == (undefined4 *)0x0) {
    iVar5 = iVar1;
    grim_noop();
    *(undefined4 *)(*(int *)iVar1 + 0x14) = 0x35;
    *(undefined4 *)(*(int *)iVar1 + 0x18) = 0;
    (*(code *)**(undefined4 **)iVar1)(iVar1,iVar5);
  }
  *puVar2 = FUN_1003d210;
  puVar2[1] = FUN_1003d360;
  puVar2[2] = FUN_1003d420;
  puVar2[3] = FUN_1003d4d0;
  puVar2[4] = FUN_1003d580;
  puVar2[5] = FUN_1003d5f0;
  puVar2[6] = &LAB_1003d660;
  puVar2[7] = &LAB_1003d7e0;
  puVar2[8] = &LAB_1003d9d0;
  puVar2[9] = FUN_1003dbc0;
  puVar2[10] = &LAB_1003dcc0;
  puVar2[0xb] = local_4;
  puVar3 = puVar2 + 0xf;
  iVar5 = 2;
  do {
    puVar3[-2] = 0;
    *puVar3 = 0;
    puVar3 = puVar3 + -1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar2[0x10] = 0;
  puVar2[0x11] = 0;
  puVar2[0x12] = 0x50;
  *(undefined4 **)(iVar1 + 4) = puVar2;
  _Src = getenv(s_JPEGMEM_10058204);
  pcVar4 = (char *)0x0;
  if (_Src != (char *)0x0) {
    arg1 = CONCAT31(arg1._1_3_,0x78);
    pcVar4 = (char *)sscanf(_Src,s__ld_c_100581fc,&local_4,&arg1);
    if (0 < (int)pcVar4) {
      if (((char)arg1 == 'm') || ((char)arg1 == 'M')) {
        puVar2[0xb] = (char *)(local_4 * 1000000);
        return (char *)(local_4 * 1000000);
      }
      pcVar4 = (char *)(local_4 * 1000);
      puVar2[0xb] = pcVar4;
    }
  }
  return pcVar4;
}



