/* inflateInit_ @ 10024374 */

/* zlib: init inflate (wrapper for inflateInit2_) */

int __cdecl inflateInit_(z_streamp strm,char *version,int stream_size)

{
  int iVar1;
  
  iVar1 = inflateInit2_(strm,0xf,version,stream_size);
  return iVar1;
}



