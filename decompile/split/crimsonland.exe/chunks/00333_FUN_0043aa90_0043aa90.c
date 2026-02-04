/* FUN_0043aa90 @ 0043aa90 */

/* [binja] void* sub_43aa90(void* arg1, void* arg2) */

void * __cdecl FUN_0043aa90(void *arg1,void *arg2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar4 = arg1;
  do {
    pcVar5 = pcVar4;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar5 + -uVar2;
  pcVar5 = arg2;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *(undefined4 *)((int)arg2 + 0x20) = *(undefined4 *)((int)arg1 + 0x20);
  *(undefined4 *)((int)arg2 + 0x24) = *(undefined4 *)((int)arg1 + 0x24);
  *(undefined1 *)((int)arg2 + 0x28) = *(undefined1 *)((int)arg1 + 0x28);
  *(undefined1 *)((int)arg2 + 0x29) = *(undefined1 *)((int)arg1 + 0x29);
  *(undefined1 *)((int)arg2 + 0x2a) = *(undefined1 *)((int)arg1 + 0x2a);
  *(undefined1 *)((int)arg2 + 0x2b) = *(undefined1 *)((int)arg1 + 0x2b);
  *(undefined4 *)((int)arg2 + 0x2c) = *(undefined4 *)((int)arg1 + 0x2c);
  *(undefined4 *)((int)arg2 + 0x34) = *(undefined4 *)((int)arg1 + 0x34);
  *(undefined4 *)((int)arg2 + 0x30) = *(undefined4 *)((int)arg1 + 0x30);
  *(undefined4 *)((int)arg2 + 0x38) = *(undefined4 *)((int)arg1 + 0x38);
  *(undefined4 *)((int)arg2 + 0x3c) = 0;
  return arg2;
}



