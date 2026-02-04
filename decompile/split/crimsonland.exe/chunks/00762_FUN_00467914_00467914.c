/* FUN_00467914 @ 00467914 */

void __cdecl FUN_00467914(int param_1)

{
  WINBOOL WVar1;
  int *piVar2;
  int iVar3;
  int *arg1;
  int *piVar4;
  int local_8;
  
  arg1 = (int *)PTR_LOOP_0047baf4;
  do {
    piVar4 = arg1;
    if (arg1[4] != -1) {
      local_8 = 0;
      piVar4 = arg1 + 0x804;
      iVar3 = 0x3ff000;
      do {
        if (*piVar4 == 0xf0) {
          WVar1 = VirtualFree((LPVOID)(iVar3 + arg1[4]),0x1000,0x4000);
          if (WVar1 != 0) {
            *piVar4 = -1;
            DAT_004d9a70 = DAT_004d9a70 + -1;
            if (((int *)arg1[3] == (int *)0x0) || (piVar4 < (int *)arg1[3])) {
              arg1[3] = (int)piVar4;
            }
            local_8 = local_8 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar3 = iVar3 + -0x1000;
        piVar4 = piVar4 + -2;
      } while (-1 < iVar3);
      piVar4 = (int *)arg1[1];
      if ((local_8 != 0) && (arg1[6] == -1)) {
        piVar2 = arg1 + 8;
        iVar3 = 1;
        do {
          if (*piVar2 != -1) break;
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 2;
        } while (iVar3 < 0x400);
        if (iVar3 == 0x400) {
          FUN_004678be(arg1);
        }
      }
    }
    if ((piVar4 == (int *)PTR_LOOP_0047baf4) || (arg1 = piVar4, param_1 < 1)) {
      return;
    }
  } while( true );
}



