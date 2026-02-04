/* grim_was_key_pressed @ 10007390 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Grim2D vtable 0x48 (provisional) */

int grim_was_key_pressed(uint key)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = grim_keyboard_key_down(key);
  if ((char)iVar2 == '\0') {
    uVar3 = key & 0xff;
    (&DAT_1005a058)[uVar3] = 0;
    (&DAT_10059f44)[uVar3] = 1;
  }
  else {
    uVar4 = key & 0xff;
    fVar1 = (float)(&DAT_1005a058)[uVar4];
    uVar3 = CONCAT22((short)((uint)iVar2 >> 0x10),
                     (ushort)(fVar1 < 0.0) << 8 | (ushort)NAN(fVar1) << 10 |
                     (ushort)(fVar1 == 0.0) << 0xe);
    if ((fVar1 == 0.0) != 0) {
      fVar1 = _DAT_10053044;
      if ((&DAT_10059f44)[uVar4] == '\0') {
        fVar1 = _DAT_10053044 * 0.2;
      }
      (&DAT_1005a058)[uVar4] = fVar1;
      (&DAT_10059f44)[uVar4] = 0;
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}



