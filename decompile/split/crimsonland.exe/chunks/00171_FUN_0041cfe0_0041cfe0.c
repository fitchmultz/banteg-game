/* FUN_0041cfe0 @ 0041cfe0 */

/* [binja] int32_t sub_41cfe0(int32_t* arg1, int32_t* arg2, char* arg3) */

int __cdecl FUN_0041cfe0(int *arg1,int *arg2,char *arg3)

{
  char cVar1;
  bool bVar2;
  UINT UVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined8 uVar10;
  uint local_408;
  uint local_404;
  char local_400 [512];
  CHAR local_200 [259];
  undefined1 local_fd;
  
  bVar2 = false;
  UVar3 = GetSystemDirectoryA(local_200,0x104);
  if (UVar3 == 0) goto LAB_0041db13;
  uVar4 = 0xffffffff;
  local_fd = 0;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s__ddraw_dll_004739ac;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(4,2,0,0x5f);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 1;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    uVar10 = FUN_0041dc10(4,3,0,0x448);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 2;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    uVar10 = FUN_0041dc10(4,4,0,0x44);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 3;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &DAT_0047399c;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(4,4,0,0x46);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 3;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = 'a';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s__ddraw_dll_004739ac;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(4,5,0,0x9b);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 5;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    uVar10 = FUN_0041dc10(4,6,0,0x13e);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 6;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    uVar10 = FUN_0041dc10(4,6,0,0x1b4);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 6;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 1;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &DAT_00473990;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(4,6,3,0x206);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 6;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 1;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = 'a';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s__ddraw_dll_004739ac;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(4,7,0,700);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 7;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s__dinput_dll_00473984;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(4,7,0,0x2cc);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 7;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = 'a';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s__ddraw_dll_004739ac;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    if (local_404 >> 0x10 == 4) {
      uVar10 = FUN_0041dc10(4,8,0,400);
      iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
      if (iVar6 < 0) goto LAB_0041d692;
LAB_0041d6c4:
      if (arg1 != (int *)0x0) {
        *arg1 = 8;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 0;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    else {
LAB_0041d692:
      if (local_404 >> 0x10 == 5) {
        uVar10 = FUN_0041dc10(5,1,0x8d2,400);
        iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
        if (-1 < iVar6) goto LAB_0041d6c4;
      }
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &DAT_00473978;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    if (local_404 >> 0x10 == 4) {
      uVar10 = FUN_0041dc10(4,8,1,0x371);
      iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
      if (iVar6 < 0) goto LAB_0041d79c;
LAB_0041d7d0:
      if (arg1 != (int *)0x0) {
        *arg1 = 8;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 1;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    else {
LAB_0041d79c:
      if (local_404 >> 0x10 == 5) {
        uVar10 = FUN_0041dc10(5,1,0xa28,0x371);
        iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
        if (-1 < iVar6) goto LAB_0041d7d0;
      }
    }
    if (local_404 >> 0x10 == 4) {
      uVar10 = FUN_0041dc10(4,8,1,0x385);
      iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
      if (iVar6 < 0) goto LAB_0041d84c;
LAB_0041d87e:
      if (arg1 != (int *)0x0) {
        *arg1 = 8;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 1;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = 'a';
      }
      bVar2 = true;
    }
    else {
LAB_0041d84c:
      if (local_404 >> 0x10 == 5) {
        uVar10 = FUN_0041dc10(5,1,0xa28,0x385);
        iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
        if (-1 < iVar6) goto LAB_0041d87e;
      }
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &DAT_00473968;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    uVar10 = FUN_0041dc10(6,3,1,0x375);
    iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
    if (-1 < iVar6) {
      if (arg1 != (int *)0x0) {
        *arg1 = 8;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 1;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = 'b';
      }
      bVar2 = true;
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = s__dpnet_dll_0047395c;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    if (local_404 >> 0x10 == 4) {
      uVar10 = FUN_0041dc10(4,9,0,0x86);
      iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
      if (iVar6 < 0) goto LAB_0041da0b;
LAB_0041da3d:
      if (arg1 != (int *)0x0) {
        *arg1 = 8;
      }
      if (arg2 != (int *)0x0) {
        *arg2 = 2;
      }
      if (arg3 != (char *)0x0) {
        *arg3 = ' ';
      }
      bVar2 = true;
    }
    else {
LAB_0041da0b:
      if (local_404 >> 0x10 == 5) {
        uVar10 = FUN_0041dc10(5,2,0xe5d,0x86);
        iVar6 = FUN_0041dc50(local_408,local_404,(uint)uVar10,(uint)((ulonglong)uVar10 >> 0x20));
        if (-1 < iVar6) goto LAB_0041da3d;
      }
    }
  }
  uVar4 = 0xffffffff;
  pcVar7 = local_200;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = local_400;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar4 = 0xffffffff;
  pcVar7 = &DAT_00473950;
  do {
    pcVar9 = pcVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar7 = local_400;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar4;
  pcVar9 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar6 = FUN_0041db50((uint)local_400,(int *)&local_408);
  if (-1 < iVar6) {
    if (arg1 != (int *)0x0) {
      *arg1 = 9;
    }
    if (arg2 != (int *)0x0) {
      *arg2 = 0;
    }
    if (arg3 == (char *)0x0) {
      return 0;
    }
    *arg3 = ' ';
    return 0;
  }
  if (bVar2) {
    return 0;
  }
LAB_0041db13:
  if (arg1 != (int *)0x0) {
    *arg1 = 0;
  }
  if (arg2 != (int *)0x0) {
    *arg2 = 0;
  }
  if (arg3 != (char *)0x0) {
    *arg3 = ' ';
  }
  return 0;
}



