/* console_flush_log @ 00402860 */

/* flushes console lines to the log file */

int __fastcall console_flush_log(void *console_state,char *filename)

{
  char cVar1;
  char *pcVar2;
  FILE *fp;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *in_stack_00000004;
  char *pcVar7;
  
  pcVar7 = &DAT_004712dc;
  pcVar2 = game_build_path(in_stack_00000004);
  fp = (FILE *)crt_fopen(pcVar2,pcVar7);
  if (fp == (FILE *)0x0) {
    return 0;
  }
  iVar4 = *(int *)((int)console_state + 0x20);
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      crt_fflush((int *)fp);
      iVar4 = crt_fclose(fp);
      return CONCAT31((int3)((uint)iVar4 >> 8),1);
    }
    puVar3 = *(undefined4 **)((int)console_state + 8);
    iVar5 = iVar4;
    if (0 < iVar4) {
      do {
        puVar3 = (undefined4 *)puVar3[1];
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    uVar6 = 0xffffffff;
    pcVar2 = (char *)*puVar3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    crt_fwrite((char *)*puVar3,~uVar6 - 1,1,(int *)fp);
  } while( true );
}



