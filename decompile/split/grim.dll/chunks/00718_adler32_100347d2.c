/* adler32 @ 100347d2 */

/* zlib: adler32 checksum */

uLong __cdecl adler32(uLong adler,Bytef *buf,uInt len)

{
  uLong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  
  uVar4 = adler & 0xffff;
  uVar20 = adler >> 0x10;
  if (buf == (Bytef *)0x0) {
    uVar1 = 1;
  }
  else {
    while (len != 0) {
      uVar3 = 0x15b0;
      if (len < 0x15b0) {
        uVar3 = len;
      }
      len = len - uVar3;
      if (0xf < (int)uVar3) {
        uVar2 = uVar3 >> 4;
        uVar3 = uVar3 + uVar2 * -0x10;
        do {
          iVar5 = uVar4 + *buf;
          iVar6 = iVar5 + (uint)buf[1];
          iVar7 = iVar6 + (uint)buf[2];
          iVar8 = iVar7 + (uint)buf[3];
          iVar9 = iVar8 + (uint)buf[4];
          iVar10 = iVar9 + (uint)buf[5];
          iVar11 = iVar10 + (uint)buf[6];
          iVar12 = iVar11 + (uint)buf[7];
          iVar13 = iVar12 + (uint)buf[8];
          iVar14 = iVar13 + (uint)buf[9];
          iVar15 = iVar14 + (uint)buf[10];
          iVar16 = iVar15 + (uint)buf[0xb];
          iVar17 = iVar16 + (uint)buf[0xc];
          iVar18 = iVar17 + (uint)buf[0xd];
          iVar19 = iVar18 + (uint)buf[0xe];
          uVar4 = iVar19 + (uint)buf[0xf];
          uVar20 = uVar20 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 +
                   iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + iVar19 + uVar4;
          buf = buf + 0x10;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        uVar4 = uVar4 + *buf;
        buf = buf + 1;
        uVar20 = uVar20 + uVar4;
      }
      uVar4 = uVar4 % 0xfff1;
      uVar20 = uVar20 % 0xfff1;
    }
    uVar1 = uVar20 << 0x10 | uVar4;
  }
  return uVar1;
}



