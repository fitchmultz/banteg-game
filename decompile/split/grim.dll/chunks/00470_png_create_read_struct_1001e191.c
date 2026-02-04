/* png_create_read_struct @ 1001e191 */

/* allocates png_struct, initializes zlib stream, checks version; error_fn/warn_fn are png_error_ptr
   callbacks */

png_structp __cdecl
png_create_read_struct(char *user_png_ver,png_voidp error_ptr,void *error_fn,void *warn_fn)

{
  png_structp png_ptr;
  int iVar1;
  png_bytep ppVar2;
  char *msg;
  
  png_ptr = (png_structp)FUN_100246f2(1);
  if (png_ptr == (png_structp)0x0) {
    return (png_structp)0x0;
  }
  iVar1 = setjmp3(png_ptr,0);
  if (iVar1 != 0) {
    png_free(png_ptr,png_ptr->zbuf);
    png_free_ptr(png_ptr);
    return (png_structp)0x0;
  }
  FUN_1001e0fa((int)png_ptr,error_ptr,error_fn,warn_fn);
  if ((user_png_ver == (char *)0x0) || (*user_png_ver != '1')) {
    png_error(png_ptr,"Incompatible libpng version in application and library");
  }
  png_ptr->zbuf_size = 0x2000;
  ppVar2 = png_malloc(png_ptr,0x2000);
  png_ptr->zbuf = ppVar2;
  (png_ptr->zstream).words[8] = (png_uint_32)FUN_1002052b;
  (png_ptr->zstream).words[9] = (png_uint_32)png_free_thunk;
  (png_ptr->zstream).words[10] = (png_uint_32)png_ptr;
  iVar1 = inflateInit_((z_streamp)&png_ptr->zstream,"1.1.3",0x38);
  if (iVar1 == -6) {
    msg = "zlib version error";
  }
  else if ((iVar1 == -4) || (iVar1 == -2)) {
    msg = "zlib memory error";
  }
  else {
    if (iVar1 == 0) goto LAB_1001e270;
    msg = "Unknown zlib error";
  }
  png_error(png_ptr,msg);
LAB_1001e270:
  (png_ptr->zstream).words[3] = (png_uint_32)png_ptr->zbuf;
  (png_ptr->zstream).words[4] = png_ptr->zbuf_size;
  FUN_100204a4(png_ptr,0,0);
  return png_ptr;
}



