/* grim_pixel_format_load_yuv_cache @ 1001a7b9 */

/* loads packed YUV pixels into float cache and converts to RGB */

int __thiscall grim_pixel_format_load_yuv_cache(void *this,uint x,uint y,int load_from_surface)

{
  undefined2 uVar1;
  ushort uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  float *pfVar11;
  ushort *puVar12;
  
  if (*(int *)((int)this + 0x1090) == 0) {
    iVar10 = -0x7ff8fff2;
  }
  else {
    if ((((x < *(uint *)((int)this + 0x1074)) || (*(uint *)((int)this + 0x107c) <= x)) ||
        (y < *(uint *)((int)this + 0x1080))) || (*(uint *)((int)this + 0x1084) <= y)) {
      iVar10 = grim_pixel_format_flush_yuv_cache(this);
      if (iVar10 < 0) {
        return iVar10;
      }
      *(uint *)((int)this + 0x107c) = x + 1;
      *(uint *)((int)this + 0x1074) = x;
      *(uint *)((int)this + 0x1080) = y;
      *(uint *)((int)this + 0x1084) = y + 1;
      if (load_from_surface != 0) {
        load_from_surface = *(uint *)((int)this + 0x1070);
        pfVar11 = *(float **)((int)this + 0x106c);
        puVar12 = (ushort *)
                  (*(int *)((int)this + 0x1050) * x + *(int *)((int)this + 0x1054) * y +
                   load_from_surface * 2 + *(int *)((int)this + 0x18));
        if ((uint)load_from_surface < *(uint *)((int)this + 0x1078)) {
          do {
            uVar1 = *(undefined2 *)((int)this + 0x1094);
            uVar2 = puVar12[1];
            fVar7 = (float)(*puVar12 >> ((byte)*(undefined2 *)((int)this + 0x1098) & 0x1f) & 0xff) -
                    128.0;
            fVar6 = (float)(uVar2 >> ((byte)*(undefined2 *)((int)this + 0x1098) & 0x1f) & 0xff) -
                    128.0;
            fVar3 = fVar6 * 0.00625893;
            fVar5 = ((float)(*puVar12 >> ((byte)*(undefined2 *)((int)this + 0x1094) & 0x1f) & 0xff)
                    - 16.0) * 0.00456621;
            fVar4 = fVar5 + fVar3;
            *pfVar11 = fVar4;
            fVar8 = fVar7 * 0.00153632;
            fVar6 = fVar6 * 0.00318811;
            fVar9 = (fVar5 - fVar8) - fVar6;
            pfVar11[1] = fVar9;
            fVar7 = fVar7 * 0.00791071;
            fVar5 = fVar7 + fVar5;
            pfVar11[2] = fVar5;
            pfVar11[3] = 1.0;
            if (0.0 <= fVar4) {
              if (1.0 < fVar4) {
                fVar4 = 1.0;
              }
            }
            else {
              fVar4 = 0.0;
            }
            *pfVar11 = fVar4;
            if (0.0 <= fVar9) {
              if (1.0 < fVar9) {
                fVar9 = 1.0;
              }
            }
            else {
              fVar9 = 0.0;
            }
            pfVar11[1] = fVar9;
            if (0.0 <= fVar5) {
              if (1.0 < fVar5) {
                fVar5 = 1.0;
              }
            }
            else {
              fVar5 = 0.0;
            }
            pfVar11[2] = fVar5;
            fVar4 = ((float)(uVar2 >> ((byte)uVar1 & 0x1f) & 0xff) - 16.0) * 0.00456621;
            fVar3 = fVar4 + fVar3;
            pfVar11[4] = fVar3;
            fVar6 = (fVar4 - fVar8) - fVar6;
            pfVar11[5] = fVar6;
            fVar4 = fVar4 + fVar7;
            pfVar11[6] = fVar4;
            pfVar11[7] = 1.0;
            if (0.0 <= fVar3) {
              if (1.0 < fVar3) {
                fVar3 = 1.0;
              }
            }
            else {
              fVar3 = 0.0;
            }
            pfVar11[4] = fVar3;
            if (0.0 <= fVar6) {
              if (1.0 < fVar6) {
                fVar6 = 1.0;
              }
            }
            else {
              fVar6 = 0.0;
            }
            pfVar11[5] = fVar6;
            if (0.0 <= fVar4) {
              if (1.0 < fVar4) {
                fVar4 = 1.0;
              }
            }
            else {
              fVar4 = 0.0;
            }
            load_from_surface = load_from_surface + 2;
            pfVar11[6] = fVar4;
            puVar12 = puVar12 + 2;
            pfVar11 = pfVar11 + 8;
          } while ((uint)load_from_surface < *(uint *)((int)this + 0x1078));
        }
      }
    }
    iVar10 = 0;
  }
  return iVar10;
}



