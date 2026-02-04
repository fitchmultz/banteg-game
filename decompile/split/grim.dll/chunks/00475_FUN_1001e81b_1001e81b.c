/* FUN_1001e81b @ 1001e81b */

void __cdecl FUN_1001e81b(png_structp png_ptr,undefined4 *param_2,undefined4 *param_3)

{
  png_voidp pvVar1;
  png_error_ptr ppVar2;
  png_error_ptr ppVar3;
  int iVar4;
  png_structp ppVar5;
  png_uint_32 *ppVar6;
  int iVar7;
  png_uint_32 local_44 [16];
  
  iVar7 = 0;
  if (param_2 != (undefined4 *)0x0) {
    FUN_100205da((int)png_ptr);
  }
  if (param_3 != (undefined4 *)0x0) {
    FUN_100205da((int)png_ptr);
  }
  png_free(png_ptr,png_ptr->zbuf);
  png_free(png_ptr,png_ptr->sub_row);
  png_free(png_ptr,png_ptr->row_buf);
  png_free(png_ptr,png_ptr[1].io_ptr);
  png_free(png_ptr,(void *)png_ptr[1].mode);
  png_free(png_ptr,(void *)png_ptr[1].jmpbuf[6]);
  if ((png_ptr->flags & 0x1000) != 0) {
    png_free_thunk(png_ptr,*(void **)&png_ptr->num_palette);
  }
  if ((png_ptr->flags & 0x2000) != 0) {
    png_free(png_ptr,(void *)png_ptr[1].jmpbuf[0xf]);
  }
  if (png_ptr[1].jmpbuf[9] != 0) {
    iVar4 = 1 << (8U - (char)png_ptr[1].jmpbuf[3] & 0x1f);
    if (0 < iVar4) {
      do {
        png_free(png_ptr,*(void **)(png_ptr[1].jmpbuf[9] + iVar7 * 4));
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar4);
    }
    png_free(png_ptr,(void *)png_ptr[1].jmpbuf[9]);
  }
  inflateEnd((z_streamp)&png_ptr->zstream);
  pvVar1 = png_ptr->error_ptr;
  ppVar2 = png_ptr->error_fn;
  ppVar5 = png_ptr;
  ppVar6 = local_44;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *ppVar6 = ppVar5->jmpbuf[0];
    ppVar5 = (png_structp)(ppVar5->jmpbuf + 1);
    ppVar6 = ppVar6 + 1;
  }
  ppVar3 = png_ptr->warning_fn;
  ppVar5 = png_ptr;
  for (iVar7 = 0x67; iVar7 != 0; iVar7 = iVar7 + -1) {
    ppVar5->jmpbuf[0] = 0;
    ppVar5 = (png_structp)(ppVar5->jmpbuf + 1);
  }
  png_ptr->warning_fn = ppVar3;
  ppVar6 = local_44;
  ppVar5 = png_ptr;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    ppVar5->jmpbuf[0] = *ppVar6;
    ppVar6 = ppVar6 + 1;
    ppVar5 = (png_structp)(ppVar5->jmpbuf + 1);
  }
  png_ptr->error_fn = ppVar2;
  png_ptr->error_ptr = pvVar1;
  return;
}



