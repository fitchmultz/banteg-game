/* inflate_trees_dynamic @ 10036d2e */

/* zlib (internal): build dynamic Huffman trees */

int __cdecl
inflate_trees_dynamic
          (uInt nl,uInt nd,uInt *c,uInt *bl,uInt *bd,void **tl,void **td,void *hp,z_streamp z)

{
  uInt *hn;
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  hn = (*z->zalloc)(z->opaque,0x120,4);
  if (hn == (uInt *)0x0) {
    return -4;
  }
  iVar1 = huft_build(c,nl,0x101,(uInt *)&DAT_1004f868,(uInt *)&DAT_1004f8e8,tl,hp,&local_8,hn);
  if (iVar1 == 0) {
    if (*bl == 0) goto LAB_10036e13;
    iVar1 = huft_build(c + nl,nd,0,(uInt *)&DAT_1004f968,(uInt *)&DAT_1004f9e0,td,hp,&local_8,hn);
    if (iVar1 == 0) {
      if ((*bd != 0) || (nl < 0x102)) {
        iVar1 = 0;
        goto LAB_10036e1f;
      }
LAB_10036df7:
      z->msg = "empty distance tree with lengths";
    }
    else {
      if (iVar1 == -3) {
        z->msg = "oversubscribed distance tree";
        goto LAB_10036e1f;
      }
      if (iVar1 != -5) {
        if (iVar1 == -4) goto LAB_10036e1f;
        goto LAB_10036df7;
      }
      z->msg = "incomplete distance tree";
    }
  }
  else {
    if (iVar1 == -3) {
      z->msg = "oversubscribed literal/length tree";
      goto LAB_10036e1f;
    }
    if (iVar1 == -4) goto LAB_10036e1f;
LAB_10036e13:
    z->msg = "incomplete literal/length tree";
  }
  iVar1 = -3;
LAB_10036e1f:
  (*z->zfree)(z->opaque,hn);
  return iVar1;
}



