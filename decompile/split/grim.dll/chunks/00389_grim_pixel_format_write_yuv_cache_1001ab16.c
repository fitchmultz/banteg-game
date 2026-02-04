/* grim_pixel_format_write_yuv_cache @ 1001ab16 */

/* loads YUV cache for coords, copies RGBA floats into cache, marks dirty for flush */

void __thiscall grim_pixel_format_write_yuv_cache(void *this,int x,int y,float *pixels)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    pixels = grim_convert_vertex_space(this,pixels);
  }
  iVar1 = grim_pixel_format_load_yuv_cache
                    (this,x + *(int *)((int)this + 0x1034),y + *(int *)((int)this + 0x1040),
                     (uint)(*(int *)((int)this + 0x1088) != *(int *)((int)this + 0x1058)));
  if (-1 < iVar1) {
    pfVar3 = (float *)((*(int *)((int)this + 0x1030) - *(int *)((int)this + 0x1070)) * 0x10 +
                      *(int *)((int)this + 0x106c));
    for (uVar2 = (uint)(*(int *)((int)this + 0x1058) << 4) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pfVar3 = *pixels;
      pixels = pixels + 1;
      pfVar3 = pfVar3 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)pfVar3 = *(undefined1 *)pixels;
      pixels = (float *)((int)pixels + 1);
      pfVar3 = (float *)((int)pfVar3 + 1);
    }
    *(undefined4 *)((int)this + 0x108c) = 1;
  }
  return;
}



