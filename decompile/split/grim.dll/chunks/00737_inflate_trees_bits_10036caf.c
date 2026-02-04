/* inflate_trees_bits @ 10036caf */

/* zlib (internal): build bit length Huffman tree */

int __cdecl inflate_trees_bits(uInt *c,uInt *bb,void **tb,void *hp,z_streamp z)

{
  uInt *hn;
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  hn = (*z->zalloc)(z->opaque,0x13,4);
  if (hn == (uInt *)0x0) {
    iVar1 = -4;
  }
  else {
    iVar1 = huft_build(c,0x13,0x13,(uInt *)0x0,(uInt *)0x0,tb,hp,&local_8,hn);
    if (iVar1 == -3) {
      z->msg = "oversubscribed dynamic bit lengths tree";
    }
    else if ((iVar1 == -5) || (*bb == 0)) {
      z->msg = "incomplete dynamic bit lengths tree";
      iVar1 = -3;
    }
    (*z->zfree)(z->opaque,hn);
  }
  return iVar1;
}



