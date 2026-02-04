/* crt_fp_parse @ 0046b265 */

/* parses a floating-point string into an 80-bit buffer (CRT scanf helper) */

int __thiscall
crt_fp_parse(void *this,void *ctx,ushort *out,int *cursor,byte *str,int flags,int width,int prec,
            int mode)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  char local_60 [23];
  char local_49;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  int *local_3e;
  ushort local_3a;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  byte *local_20;
  int local_1c;
  int local_18;
  int local_14;
  char *local_10;
  int local_c;
  uint local_8;
  
  local_10 = local_60;
  local_2c = 0;
  local_1c = 1;
  local_8 = 0;
  local_14 = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0;
  local_34 = 0;
  local_20 = (byte *)0x0;
  local_c = 0;
  local_18 = 0;
  pbVar8 = (byte *)cursor;
  while( true ) {
    bVar6 = *pbVar8;
    this = (void *)CONCAT31((int3)((uint)this >> 8),bVar6);
    if ((((bVar6 != 0x20) && (bVar6 != 9)) && (bVar6 != 10)) && (bVar6 != 0xd)) break;
    pbVar8 = pbVar8 + 1;
  }
  iVar1 = 4;
  iVar9 = 0;
  iVar5 = local_14;
LAB_0046b2bc:
  local_14 = iVar5;
  pbVar7 = pbVar8;
  iVar5 = 1;
  bVar6 = *pbVar7;
  pbVar8 = pbVar7 + 1;
  iVar2 = local_14;
  switch(iVar9) {
  case 0:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) {
LAB_0046b2d9:
      local_14 = iVar2;
      iVar9 = 3;
      goto LAB_0046b4fe;
    }
    if (bVar6 == DAT_0047b3d0) goto LAB_0046b2e8;
    if (bVar6 == 0x2b) {
      local_2c = 0;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else if (bVar6 == 0x2d) {
      local_2c = 0x8000;
      iVar9 = 2;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_0046b5d8;
    }
    goto LAB_0046b2bc;
  case 1:
    local_14 = 1;
    if (('0' < (char)bVar6) && (iVar2 = iVar5, (char)bVar6 < ':')) goto LAB_0046b2d9;
    iVar9 = iVar1;
    if (bVar6 != DAT_0047b3d0) {
      iVar9 = iVar5;
      if ((bVar6 == 0x2b) || (iVar9 = local_14, bVar6 == 0x2d)) goto LAB_0046b36d;
      iVar9 = iVar5;
      local_14 = iVar5;
      if (bVar6 != 0x30) goto LAB_0046b346;
    }
    goto LAB_0046b2bc;
  case 2:
    if (('0' < (char)bVar6) && ((char)bVar6 < ':')) goto LAB_0046b2d9;
    if (bVar6 == DAT_0047b3d0) {
LAB_0046b2e8:
      iVar9 = 5;
      iVar5 = local_14;
    }
    else {
      iVar9 = iVar5;
      pbVar7 = (byte *)cursor;
      iVar5 = local_14;
      if (bVar6 != 0x30) goto LAB_0046b5dd;
    }
    goto LAB_0046b2bc;
  case 3:
    local_14 = iVar5;
    while( true ) {
      if (DAT_0047b3cc < 2) {
        uVar3 = (byte)crt_ctype_table[(uint)bVar6 * 2] & 4;
        this = crt_ctype_table;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = crt_isctype(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      else {
        local_c = local_c + 1;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    iVar9 = iVar1;
    iVar5 = local_14;
    if (bVar6 != DAT_0047b3d0) goto LAB_0046b45a;
    goto LAB_0046b2bc;
  case 4:
    local_14 = 1;
    local_28 = 1;
    iVar9 = iVar5;
    if (local_8 == 0) {
      while (iVar5 = local_28, iVar9 = local_14, bVar6 == 0x30) {
        local_c = local_c + -1;
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      }
    }
    while( true ) {
      local_14 = iVar9;
      local_28 = iVar5;
      if (DAT_0047b3cc < 2) {
        uVar3 = (byte)crt_ctype_table[(uint)bVar6 * 2] & 4;
        this = crt_ctype_table;
      }
      else {
        pbVar7 = (byte *)0x4;
        uVar3 = crt_isctype(this,(uint)bVar6,4);
        this = pbVar7;
      }
      if (uVar3 == 0) break;
      if (local_8 < 0x19) {
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        pcVar4 = local_10 + 1;
        *local_10 = bVar6 - 0x30;
        local_10 = pcVar4;
      }
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      iVar5 = local_28;
      iVar9 = local_14;
    }
LAB_0046b45a:
    iVar9 = local_14;
    if ((bVar6 == 0x2b) || (bVar6 == 0x2d)) {
LAB_0046b36d:
      local_14 = iVar9;
      iVar9 = 0xb;
      pbVar8 = pbVar8 + -1;
      iVar5 = local_14;
    }
    else {
LAB_0046b346:
      if (((char)bVar6 < 'D') ||
         (('E' < (char)bVar6 && (((char)bVar6 < 'd' || ('e' < (char)bVar6)))))) goto LAB_0046b5d8;
      iVar9 = 6;
      iVar5 = local_14;
    }
    goto LAB_0046b2bc;
  case 5:
    local_28 = iVar5;
    if (DAT_0047b3cc < 2) {
      uVar3 = (byte)crt_ctype_table[(uint)bVar6 * 2] & 4;
      this = crt_ctype_table;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = crt_isctype(this,(uint)bVar6,4);
      this = pbVar7;
    }
    iVar9 = iVar1;
    pbVar7 = (byte *)cursor;
    if (uVar3 != 0) goto LAB_0046b4fe;
    goto LAB_0046b5dd;
  case 6:
    pbVar7 = pbVar7 + -1;
    this = pbVar7;
    cursor = (int *)pbVar7;
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      if (bVar6 == 0x2b) goto LAB_0046b533;
      if (bVar6 == 0x2d) goto LAB_0046b527;
      if (bVar6 != 0x30) goto LAB_0046b5dd;
LAB_0046b4cc:
      iVar9 = 8;
      iVar5 = local_14;
      goto LAB_0046b2bc;
    }
    break;
  case 7:
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) {
      pbVar7 = (byte *)cursor;
      if (bVar6 == 0x30) goto LAB_0046b4cc;
      goto LAB_0046b5dd;
    }
    break;
  case 8:
    local_24 = 1;
    while (bVar6 == 0x30) {
      bVar6 = *pbVar8;
      pbVar8 = pbVar8 + 1;
    }
    if (((char)bVar6 < '1') || ('9' < (char)bVar6)) goto LAB_0046b5d8;
    break;
  case 9:
    local_24 = 1;
    pbVar7 = (byte *)0x0;
    goto LAB_0046b55e;
  default:
    goto switchD_0046b2c8_caseD_a;
  case 0xb:
    if (prec != 0) {
      if (bVar6 == 0x2b) {
LAB_0046b533:
        iVar9 = 7;
        this = pbVar7;
        cursor = (int *)pbVar7;
        iVar5 = local_14;
      }
      else {
        cursor = (int *)pbVar7;
        if (bVar6 != 0x2d) goto LAB_0046b5dd;
LAB_0046b527:
        local_1c = -1;
        iVar9 = 7;
        this = pbVar7;
        cursor = (int *)pbVar7;
        iVar5 = local_14;
      }
      goto LAB_0046b2bc;
    }
    iVar9 = 10;
    pbVar8 = pbVar7;
switchD_0046b2c8_caseD_a:
    pbVar7 = pbVar8;
    iVar5 = local_14;
    if (iVar9 != 10) goto LAB_0046b2bc;
    goto LAB_0046b5dd;
  }
  iVar9 = 9;
LAB_0046b4fe:
  pbVar8 = pbVar8 + -1;
  iVar5 = local_14;
  goto LAB_0046b2bc;
LAB_0046b55e:
  if (DAT_0047b3cc < 2) {
    uVar3 = (byte)crt_ctype_table[(uint)bVar6 * 2] & 4;
    this = crt_ctype_table;
  }
  else {
    pbVar10 = (byte *)0x4;
    uVar3 = crt_isctype(this,(uint)bVar6,4);
    this = pbVar10;
  }
  if (uVar3 == 0) goto LAB_0046b5a8;
  this = (void *)(int)(char)bVar6;
  pbVar7 = (byte *)((int)this + (int)pbVar7 * 10 + -0x30);
  if (0x1450 < (int)pbVar7) goto LAB_0046b5a0;
  bVar6 = *pbVar8;
  pbVar8 = pbVar8 + 1;
  goto LAB_0046b55e;
LAB_0046b5a0:
  pbVar7 = (byte *)0x1451;
LAB_0046b5a8:
  while( true ) {
    local_20 = pbVar7;
    if (DAT_0047b3cc < 2) {
      uVar3 = (byte)crt_ctype_table[(uint)bVar6 * 2] & 4;
      this = crt_ctype_table;
    }
    else {
      pbVar7 = (byte *)0x4;
      uVar3 = crt_isctype(this,(uint)bVar6,4);
      this = pbVar7;
    }
    if (uVar3 == 0) break;
    bVar6 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    pbVar7 = local_20;
  }
LAB_0046b5d8:
  pbVar7 = pbVar8 + -1;
LAB_0046b5dd:
  *(byte **)out = pbVar7;
  if (local_14 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (int *)0x0;
    cursor = (int *)0x0;
    local_18 = 4;
    goto LAB_0046b6eb;
  }
  pcVar4 = local_10;
  if (0x18 < local_8) {
    if ('\x04' < local_49) {
      local_49 = local_49 + '\x01';
    }
    local_8 = 0x18;
    local_c = local_c + 1;
    pcVar4 = local_10 + -1;
  }
  if (local_8 == 0) {
    local_44 = 0;
    local_3a = 0;
    local_3e = (int *)0x0;
    cursor = (int *)0x0;
  }
  else {
    while (pcVar4 = pcVar4 + -1, *pcVar4 == '\0') {
      local_8 = local_8 - 1;
      local_c = local_c + 1;
    }
    FUN_0046d9bc(local_60,local_8,(int)&local_44);
    pbVar8 = local_20;
    if (local_1c < 0) {
      pbVar8 = (byte *)-(int)local_20;
    }
    pbVar8 = pbVar8 + local_c;
    if (local_24 == 0) {
      pbVar8 = pbVar8 + flags;
    }
    if (local_28 == 0) {
      pbVar8 = pbVar8 + -width;
    }
    if ((int)pbVar8 < 0x1451) {
      if (-0x1451 < (int)pbVar8) {
        FUN_0046e05b((int *)&local_44,(uint)pbVar8,(int)str);
        cursor = (int *)CONCAT22(uStack_40,uStack_42);
        goto LAB_0046b670;
      }
      local_34 = 1;
    }
    else {
      local_30 = 1;
    }
    local_3a = (ushort)cursor;
    local_3e = cursor;
    local_44 = local_3a;
  }
LAB_0046b670:
  if (local_30 == 0) {
    if (local_34 != 0) {
      local_44 = 0;
      local_3a = 0;
      local_3e = (int *)0x0;
      cursor = (int *)0x0;
      local_18 = 1;
    }
  }
  else {
    cursor = (int *)0x0;
    local_3a = 0x7fff;
    local_3e = (int *)0x80000000;
    local_44 = 0;
    local_18 = 2;
  }
LAB_0046b6eb:
  *(int **)((int)ctx + 6) = local_3e;
  *(int **)((int)ctx + 2) = cursor;
  *(ushort *)((int)ctx + 10) = local_3a | (ushort)local_2c;
  *(ushort *)ctx = local_44;
  return local_18;
}



