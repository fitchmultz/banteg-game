/* inflate_flush @ 10036e60 */

/* zlib (internal): flush pending output */

int __cdecl inflate_flush(void *s,z_streamp z,int r)

{
  Bytef *pBVar1;
  void *pvVar2;
  uLong uVar3;
  uint uVar4;
  Bytef *pBVar5;
  Bytef *pBVar6;
  uint uVar7;
  Bytef *pBVar8;
  Bytef *local_c;
  
  pvVar2 = s;
  pBVar1 = *(Bytef **)((int)s + 0x30);
  local_c = z->next_out;
  pBVar5 = *(Bytef **)((int)s + 0x34);
  if (pBVar5 < pBVar1) {
    pBVar5 = *(Bytef **)((int)s + 0x2c);
  }
  uVar4 = z->avail_out;
  uVar7 = (int)pBVar5 - (int)pBVar1;
  if (uVar4 < (uint)((int)pBVar5 - (int)pBVar1)) {
    uVar7 = uVar4;
  }
  if ((uVar7 != 0) && (r == -5)) {
    r = 0;
  }
  z->total_out = z->total_out + uVar7;
  z->avail_out = uVar4 - uVar7;
  if (*(code **)((int)s + 0x38) != (code *)0x0) {
    uVar3 = (**(code **)((int)s + 0x38))(*(undefined4 *)((int)s + 0x3c),pBVar1,uVar7);
    *(uLong *)((int)s + 0x3c) = uVar3;
    z->adler = uVar3;
  }
  pBVar5 = pBVar1;
  pBVar6 = local_c;
  for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pBVar6 = *(undefined4 *)pBVar5;
    pBVar5 = pBVar5 + 4;
    pBVar6 = pBVar6 + 4;
  }
  local_c = local_c + uVar7;
  for (uVar4 = uVar7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pBVar6 = *pBVar5;
    pBVar5 = pBVar5 + 1;
    pBVar6 = pBVar6 + 1;
  }
  pBVar5 = pBVar1 + uVar7;
  if (pBVar1 + uVar7 == *(Bytef **)((int)s + 0x2c)) {
    pBVar1 = *(Bytef **)((int)s + 0x28);
    if (*(Bytef **)((int)s + 0x34) == *(Bytef **)((int)s + 0x2c)) {
      *(Bytef **)((int)s + 0x34) = pBVar1;
    }
    uVar4 = z->avail_out;
    uVar7 = *(int *)((int)s + 0x34) - (int)pBVar1;
    if (uVar4 < uVar7) {
      uVar7 = uVar4;
    }
    if ((uVar7 != 0) && (r == -5)) {
      r = 0;
    }
    z->total_out = z->total_out + uVar7;
    z->avail_out = uVar4 - uVar7;
    if (*(code **)((int)s + 0x38) != (code *)0x0) {
      uVar3 = (**(code **)((int)s + 0x38))(*(undefined4 *)((int)s + 0x3c),pBVar1,uVar7);
      *(uLong *)((int)s + 0x3c) = uVar3;
      z->adler = uVar3;
    }
    pBVar6 = pBVar1;
    pBVar8 = local_c;
    for (uVar4 = uVar7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pBVar8 = *(undefined4 *)pBVar6;
      pBVar6 = pBVar6 + 4;
      pBVar8 = pBVar8 + 4;
    }
    local_c = local_c + uVar7;
    for (uVar4 = uVar7 & 3; pBVar5 = pBVar1 + uVar7, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pBVar8 = *pBVar6;
      pBVar6 = pBVar6 + 1;
      pBVar8 = pBVar8 + 1;
    }
  }
  s = pBVar5;
  z->next_out = local_c;
  *(void **)((int)pvVar2 + 0x30) = s;
  return r;
}



