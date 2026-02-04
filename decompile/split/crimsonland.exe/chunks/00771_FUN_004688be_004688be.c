/* FUN_004688be @ 004688be */

/* [binja] uint32_t sub_4688be(int32_t* arg1) */

uint __cdecl FUN_004688be(int *arg1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  
  piVar1 = arg1 + 1;
  *piVar1 = *piVar1 + -1;
  if (-1 < *piVar1) {
    bVar2 = *(byte *)*arg1;
    *arg1 = (int)((byte *)*arg1 + 1);
    return (uint)bVar2;
  }
  uVar3 = crt_filbuf(arg1);
  return uVar3;
}



