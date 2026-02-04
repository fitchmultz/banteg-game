/* FUN_10010aec @ 10010aec */

/* [binja] int32_t __thiscall sub_10010aec(int32_t* arg1, HANDLE arg2) */

int __thiscall FUN_10010aec(void *this,int *arg1,HANDLE arg2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  DWORD nNumberOfBytesToWrite;
  int *piVar7;
  uint uVar8;
  LPCVOID lpBuffer;
  undefined1 local_498 [1024];
  int local_98 [3];
  undefined2 local_8c;
  ushort local_8a;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined2 local_2c;
  int local_2a;
  undefined2 uStack_26;
  undefined2 uStack_24;
  int local_22;
  LPCVOID local_1c;
  undefined1 local_18 [4];
  uint local_14;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  DWORD local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_f = 0;
  local_e = 0;
  local_d = 0;
  local_8 = 0xff000000;
  local_18[0] = 0;
  local_14 = 0xff000000;
  piVar7 = local_98;
  for (iVar4 = 0x1b; uVar1 = local_8, iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  iVar4 = *(int *)this;
  local_8._3_1_ = SUB41(uVar1,3);
  local_8._0_3_ = CONCAT12(0xaa,CONCAT11(0x55,(undefined1)local_8));
  local_18[1] = 0x24;
  local_18[2] = 0x49;
  local_18[3] = 0x6d;
  local_14 = CONCAT13(local_14._3_1_,0xdbb692);
  local_c = 0;
  if (iVar4 == 0x14) {
    local_98[0] = 0x28;
    local_8a = 0x18;
  }
  else if (iVar4 == 0x1b) {
    local_98[0] = 0x28;
    local_8a = 8;
    local_c = 0x400;
    uVar5 = 0;
    do {
      uVar3 = local_18[uVar5 >> 5];
      iVar4 = uVar5 * 4;
      *(undefined1 *)((int)local_98 + iVar4 + -0x3fd) = 0;
      *(undefined1 *)((int)local_98 + iVar4 + -0x3fe) = uVar3;
      *(undefined1 *)((int)local_98 + iVar4 + -0x3ff) = local_18[uVar5 >> 2 & 7];
      uVar8 = uVar5 + 1;
      *(undefined1 *)(local_98 + (uVar5 - 0x100)) = *(undefined1 *)((int)&local_8 + (uVar5 & 3));
      uVar5 = uVar8;
    } while (uVar8 < 0x100);
  }
  else if (iVar4 == 0x29) {
    iVar4 = *(int *)((int)this + 8);
    puVar6 = (undefined1 *)(iVar4 + 2);
    local_98[0] = 0x28;
    local_8a = 8;
    local_c = 0x400;
    uVar5 = 0;
    do {
      iVar2 = uVar5 * 4;
      *(undefined1 *)((int)local_98 + iVar2 + -0x3fe) = *(undefined1 *)(iVar4 + iVar2);
      *(undefined1 *)((int)local_98 + iVar2 + -0x3ff) = puVar6[-1];
      uVar3 = *puVar6;
      *(undefined1 *)((int)local_98 + iVar2 + -0x3fd) = 0;
      uVar8 = uVar5 + 1;
      puVar6 = puVar6 + 4;
      *(undefined1 *)(local_98 + (uVar5 - 0x100)) = uVar3;
      uVar5 = uVar8;
    } while (uVar8 < 0x100);
  }
  else {
    if (iVar4 != 0x32) {
      return -0x7fffbffb;
    }
    local_98[0] = 0x28;
    local_8a = 8;
    local_c = 0x400;
    uVar5 = 0;
    do {
      iVar4 = uVar5 * 4;
      *(undefined1 *)((int)local_98 + iVar4 + -0x3fd) = 0;
      uVar3 = (undefined1)uVar5;
      *(undefined1 *)((int)local_98 + iVar4 + -0x3fe) = uVar3;
      *(undefined1 *)((int)local_98 + iVar4 + -0x3ff) = uVar3;
      *(undefined1 *)(local_98 + (uVar5 - 0x100)) = uVar3;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x100);
  }
  local_88 = 0;
  local_98[1] = *(int *)((int)this + 0xc);
  local_98[2] = *(int *)((int)this + 0x10);
  local_80 = 0xb12;
  local_7c = 0xb12;
  local_1c = (LPCVOID)(uint)(local_8a >> 3);
  local_8 = local_98[1] * (int)local_1c;
  local_14 = local_8 + 3 & 0xfffffffc;
  local_2a = local_98[2] * local_14 + 0x36 + local_c;
  uStack_26 = 0;
  uStack_24 = 0;
  nNumberOfBytesToWrite = (local_2a + 3U & 0xfffffffc) - local_2a;
  local_2a = nNumberOfBytesToWrite + local_2a;
  local_22 = local_c + 0x36;
  local_8c = 1;
  local_2c = 0x4d42;
  if (arg2 != (HANDLE)0x0) {
    WriteFile(arg1,&local_2c,0xe,(LPDWORD)&arg2,(LPOVERLAPPED)0x0);
  }
  WriteFile(arg1,local_98,0x28,(LPDWORD)&arg2,(LPOVERLAPPED)0x0);
  if (local_c != 0) {
    WriteFile(arg1,local_498,local_c,(LPDWORD)&arg2,(LPOVERLAPPED)0x0);
  }
  local_1c = (LPCVOID)(*(int *)((int)this + 0x1c) * *(int *)((int)this + 0x30) +
                       *(int *)((int)this + 0x18) * (int)local_1c + *(int *)((int)this + 4));
  lpBuffer = (LPCVOID)((*(int *)((int)this + 0x10) + -1) * *(int *)((int)this + 0x30) +
                      (int)local_1c);
  if (local_1c <= lpBuffer) {
    do {
      WriteFile(arg1,lpBuffer,local_8,(LPDWORD)&arg2,(LPOVERLAPPED)0x0);
      if (local_8 < local_14) {
        WriteFile(arg1,&local_10,local_14 - local_8,(LPDWORD)&arg2,(LPOVERLAPPED)0x0);
      }
      lpBuffer = (LPCVOID)((int)lpBuffer - *(int *)((int)this + 0x30));
    } while (local_1c <= lpBuffer);
  }
  if (nNumberOfBytesToWrite != 0) {
    WriteFile(arg1,&local_10,nNumberOfBytesToWrite,(LPDWORD)&arg2,(LPOVERLAPPED)0x0);
  }
  return 0;
}



