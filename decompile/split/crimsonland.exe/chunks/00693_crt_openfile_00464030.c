/* crt_openfile @ 00464030 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CRT: open file with mode string parsing */

undefined4 * __cdecl crt_openfile(LPCSTR param_1,char *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  uint oflag;
  uint uVar6;
  
  bVar4 = false;
  bVar3 = false;
  cVar1 = *param_2;
  if (cVar1 == 'a') {
    oflag = 0x109;
  }
  else {
    if (cVar1 == 'r') {
      oflag = 0;
      uVar6 = DAT_004d9b8c | 1;
      goto LAB_00464071;
    }
    if (cVar1 != 'w') {
      return (undefined4 *)0x0;
    }
    oflag = 0x301;
  }
  uVar6 = DAT_004d9b8c | 2;
LAB_00464071:
  bVar2 = true;
LAB_00464074:
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) {
    iVar5 = crt_sopen(param_1,oflag,param_3,0x1a4);
    if (iVar5 < 0) {
      return (undefined4 *)0x0;
    }
    _DAT_004d99d0 = _DAT_004d99d0 + 1;
    param_4[3] = uVar6;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[2] = 0;
    param_4[7] = 0;
    param_4[4] = iVar5;
    return param_4;
  }
  if (cVar1 < 'U') {
    if (cVar1 == 'T') {
      if ((oflag & 0x1000) == 0) {
        oflag = oflag | 0x1000;
        goto LAB_00464074;
      }
    }
    else if (cVar1 == '+') {
      if ((oflag & 2) == 0) {
        oflag = oflag & 0xfffffffe | 2;
        uVar6 = uVar6 & 0xfffffffc | 0x80;
        goto LAB_00464074;
      }
    }
    else if (cVar1 == 'D') {
      if ((oflag & 0x40) == 0) {
        oflag = oflag | 0x40;
        goto LAB_00464074;
      }
    }
    else if (cVar1 == 'R') {
      if (!bVar3) {
        bVar3 = true;
        oflag = oflag | 0x10;
        goto LAB_00464074;
      }
    }
    else if ((cVar1 == 'S') && (!bVar3)) {
      bVar3 = true;
      oflag = oflag | 0x20;
      goto LAB_00464074;
    }
  }
  else {
    if (cVar1 == 'b') {
      if ((oflag & 0xc000) != 0) goto LAB_00464154;
      oflag = oflag | 0x8000;
      goto LAB_00464074;
    }
    if (cVar1 == 'c') {
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 | 0x4000;
        goto LAB_00464074;
      }
    }
    else {
      if (cVar1 != 'n') {
        if ((cVar1 != 't') || ((oflag & 0xc000) != 0)) goto LAB_00464154;
        oflag = oflag | 0x4000;
        goto LAB_00464074;
      }
      if (!bVar4) {
        bVar4 = true;
        uVar6 = uVar6 & 0xffffbfff;
        goto LAB_00464074;
      }
    }
  }
LAB_00464154:
  bVar2 = false;
  goto LAB_00464074;
}



