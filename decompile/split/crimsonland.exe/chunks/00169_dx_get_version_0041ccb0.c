/* dx_get_version @ 0041ccb0 */

/* query DirectX version */

int __cdecl dx_get_version(int *version,char *out,int out_len)

{
  char *dst;
  int size;
  char cVar1;
  int iVar2;
  int local_4;
  
  size = out_len;
  dst = out;
  if (version != (int *)0x0) {
    *version = 0;
  }
  if ((out != (char *)0x0) && (0 < out_len)) {
    *out = '\0';
  }
  out_len = 0;
  local_4 = 0;
  out = (char *)CONCAT31(out._1_3_,0x20);
  iVar2 = FUN_0041cdb0();
  if (iVar2 < 0) {
    iVar2 = FUN_0041cfe0(&out_len,&local_4,(char *)&out);
    if (iVar2 < 0) {
      return -0x7fffbffb;
    }
  }
  iVar2 = crt_tolower((int)(char)out);
  cVar1 = (char)iVar2;
  out = (char *)CONCAT31(out._1_3_,cVar1);
  if (version != (int *)0x0) {
    iVar2 = (out_len * 0x100 + local_4) * 0x100;
    if (('`' < cVar1) && (cVar1 < '{')) {
      iVar2 = iVar2 + -0x60 + (int)cVar1;
    }
    *version = iVar2;
  }
  if ((dst != (char *)0x0) && (0 < size)) {
    if (cVar1 == ' ') {
      crt_snprintf(dst,size,s__d__d_0047381c,out_len,local_4);
      dst[size + -1] = '\0';
      return 0;
    }
    crt_snprintf(dst,size,s__d__d_c_0047389c,out_len,local_4,(int)cVar1);
    dst[size + -1] = '\0';
  }
  return 0;
}



