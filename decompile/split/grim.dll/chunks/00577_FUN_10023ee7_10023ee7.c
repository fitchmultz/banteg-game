/* FUN_10023ee7 @ 10023ee7 */

void FUN_10023ee7(void)

{
  int iVar1;
  int iVar2;
  int arg1;
  int *unaff_ESI;
  char local_8;
  
  iVar1 = unaff_ESI[0x5f];
  FUN_10023c89(unaff_ESI);
  FUN_10023e78();
  *(undefined4 *)(iVar1 + 0xc) = 0;
  iVar2 = FUN_10023c18(arg1,unaff_ESI);
  *(char *)(iVar1 + 0x10) = (char)iVar2;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  if ((*(char *)((int)unaff_ESI + 0x4a) == '\0') || ((char)unaff_ESI[0x10] == '\0')) {
    *(undefined1 *)(unaff_ESI + 0x16) = 0;
    *(undefined1 *)((int)unaff_ESI + 0x59) = 0;
    *(undefined1 *)((int)unaff_ESI + 0x5a) = 0;
  }
  if (*(char *)((int)unaff_ESI + 0x4a) == '\0') goto LAB_10023f85;
  if (*(char *)((int)unaff_ESI + 0x41) != '\0') {
    *(undefined4 *)(*unaff_ESI + 0x14) = 0x2e;
    (**(code **)*unaff_ESI)();
  }
  if (unaff_ESI[0x19] == 3) {
    if (unaff_ESI[0x1d] == 0) {
      if ((char)unaff_ESI[0x14] == '\0') goto LAB_10023f52;
      *(undefined1 *)((int)unaff_ESI + 0x5a) = 1;
    }
    else {
      *(undefined1 *)((int)unaff_ESI + 0x59) = 1;
    }
  }
  else {
    *(undefined1 *)((int)unaff_ESI + 0x59) = 0;
    *(undefined1 *)((int)unaff_ESI + 0x5a) = 0;
    unaff_ESI[0x1d] = 0;
LAB_10023f52:
    *(undefined1 *)(unaff_ESI + 0x16) = 1;
  }
  if ((char)unaff_ESI[0x16] != '\0') {
    FUN_10033e84(unaff_ESI);
    *(int *)(iVar1 + 0x14) = unaff_ESI[0x69];
  }
  if ((*(char *)((int)unaff_ESI + 0x5a) != '\0') || (*(char *)((int)unaff_ESI + 0x59) != '\0')) {
    FUN_100333f2(unaff_ESI);
    *(int *)(iVar1 + 0x18) = unaff_ESI[0x69];
  }
LAB_10023f85:
  if (*(char *)((int)unaff_ESI + 0x41) == '\0') {
    if (*(char *)(iVar1 + 0x10) == '\0') {
      FUN_10031e84(unaff_ESI);
      FUN_100316f9(unaff_ESI);
    }
    else {
      FUN_1003247d((int)unaff_ESI);
    }
    FUN_1003123a((int)unaff_ESI,*(char *)((int)unaff_ESI + 0x5a));
  }
  FUN_10030f9f(unaff_ESI);
  if (*(char *)((int)unaff_ESI + 0xc9) == '\0') {
    if ((char)unaff_ESI[0x32] == '\0') {
      FUN_100301d9((int)unaff_ESI);
    }
    else {
      FUN_10030d87((int)unaff_ESI);
    }
  }
  else {
    *(undefined4 *)(*unaff_ESI + 0x14) = 1;
    (**(code **)*unaff_ESI)();
  }
  if ((*(char *)(unaff_ESI[99] + 0x10) != '\0') || (local_8 = '\0', (char)unaff_ESI[0x10] != '\0'))
  {
    local_8 = '\x01';
  }
  FUN_1002f809((int)unaff_ESI,local_8);
  if (*(char *)((int)unaff_ESI + 0x41) == '\0') {
    FUN_1002ebca(unaff_ESI,'\0');
  }
  (**(code **)(unaff_ESI[1] + 0x18))();
  (**(code **)(unaff_ESI[99] + 8))();
  if (((unaff_ESI[2] != 0) && ((char)unaff_ESI[0x10] == '\0')) &&
     (*(char *)(unaff_ESI[99] + 0x10) != '\0')) {
    iVar2 = unaff_ESI[8];
    if ((char)unaff_ESI[0x32] != '\0') {
      iVar2 = iVar2 * 3 + 2;
    }
    *(undefined4 *)(unaff_ESI[2] + 4) = 0;
    *(int *)(unaff_ESI[2] + 8) = unaff_ESI[0x46] * iVar2;
    *(undefined4 *)(unaff_ESI[2] + 0xc) = 0;
    *(uint *)(unaff_ESI[2] + 0x10) = (*(char *)((int)unaff_ESI + 0x5a) != '\0') + 2;
    *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  }
  return;
}



