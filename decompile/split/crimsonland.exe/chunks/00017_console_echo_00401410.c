/* console_echo @ 00401410 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* toggles echo on/off or prints args back into the console (echo command handler) */

void console_echo(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  byte *pbVar5;
  int index;
  bool bVar6;
  
  iVar2 = console_cmd_argc_get();
  if (iVar2 == 2) {
    pbVar3 = (byte *)console_cmd_arg_get(1);
    pbVar5 = &DAT_004711cc;
    do {
      bVar1 = *pbVar5;
      bVar6 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_00401455:
        iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0040145a;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar6 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_00401455;
      pbVar5 = pbVar5 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_0040145a:
    if (iVar2 == 0) {
      console_echo_enabled = 0;
      return;
    }
  }
  iVar2 = console_cmd_argc_get();
  if (iVar2 == 2) {
    pbVar3 = (byte *)console_cmd_arg_get(1);
    pbVar5 = &DAT_004711c8;
    do {
      bVar1 = *pbVar5;
      bVar6 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_004014a9:
        iVar2 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_004014ae;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar6 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_004014a9;
      pbVar5 = pbVar5 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar2 = 0;
LAB_004014ae:
    if (iVar2 == 0) {
      console_echo_enabled = 1;
      return;
    }
  }
  index = 1;
  iVar2 = console_cmd_argc_get();
  if (1 < iVar2) {
    do {
      pcVar4 = console_cmd_arg_get(index);
      console_printf(&console_log_queue,&DAT_004711c4,pcVar4);
      index = index + 1;
      iVar2 = console_cmd_argc_get();
    } while (index < iVar2);
  }
  console_printf(&console_log_queue,&DAT_004711c0);
  return;
}



