/* grim_pixel_format_flush_yuv_cache @ 1001a595 */

/* flushes cached YUV<->RGB conversions back into packed 16-bit storage */

int __fastcall grim_pixel_format_flush_yuv_cache(void *this)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *local_10;
  uint local_c;
  
  if ((*(int *)((int)this + 0x108c) != 0) && (*(int *)((int)this + 0x1090) != 0)) {
    local_c = *(uint *)((int)this + 0x1070);
    local_10 = (ushort *)
               (*(int *)((int)this + 0x1080) * *(int *)((int)this + 0x1054) +
                *(int *)((int)this + 0x1074) * *(int *)((int)this + 0x1050) + local_c * 2 +
               *(int *)((int)this + 0x18));
    pfVar1 = *(float **)((int)this + 0x106c);
    if (local_c < *(uint *)((int)this + 0x1078)) {
      do {
        iVar2 = (int)ROUND(pfVar1[2] * 24.966 + pfVar1[1] * 128.553 + *pfVar1 * 65.481 + 0.5) + 0x10
        ;
        iVar4 = (int)ROUND(pfVar1[5] * 128.553 + pfVar1[6] * 24.966 + pfVar1[4] * 65.481 + 0.5) +
                0x10;
        iVar3 = (int)ROUND(((pfVar1[2] * 112.0 - pfVar1[1] * 74.203) - *pfVar1 * 37.797) + 0.5) +
                0x80;
        iVar5 = (int)ROUND((*pfVar1 * 112.0 - (pfVar1[2] * 18.214 + pfVar1[1] * 93.786)) + 0.5) +
                0x80;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else if (0xff < iVar2) {
          iVar2 = 0xff;
        }
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        else if (0xff < iVar4) {
          iVar4 = 0xff;
        }
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        else if (0xff < iVar3) {
          iVar3 = 0xff;
        }
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        else if (0xff < iVar5) {
          iVar5 = 0xff;
        }
        local_c = local_c + 2;
        pfVar1 = pfVar1 + 8;
        *local_10 = (ushort)(iVar2 << ((byte)*(undefined4 *)((int)this + 0x1094) & 0x1f)) |
                    (ushort)(iVar3 << ((byte)*(undefined4 *)((int)this + 0x1098) & 0x1f));
        local_10[1] = (ushort)(iVar4 << ((byte)*(undefined4 *)((int)this + 0x1094) & 0x1f)) |
                      (ushort)(iVar5 << ((byte)*(undefined4 *)((int)this + 0x1098) & 0x1f));
        local_10 = local_10 + 2;
      } while (local_c < *(uint *)((int)this + 0x1078));
    }
    *(undefined4 *)((int)this + 0x108c) = 0;
  }
  return 0;
}



