/* grim_apply_color_key @ 100174a8 */

/* zeroes RGBA pixels that match the current color key */

void __thiscall grim_apply_color_key(void *this,float *pixels)

{
  int iVar1;
  float *pfVar2;
  
  if (pixels < pixels + *(int *)((int)this + 0x1058) * 4) {
    iVar1 = ((uint)((int)(pixels + *(int *)((int)this + 0x1058) * 4) + (-1 - (int)pixels)) >> 4) + 1
    ;
    pfVar2 = pixels + 2;
    do {
      if ((((pfVar2[-2] == *(float *)((int)this + 0x1c)) &&
           (pfVar2[-1] == *(float *)((int)this + 0x20))) &&
          (*pfVar2 == *(float *)((int)this + 0x24))) && (pfVar2[1] == *(float *)((int)this + 0x28)))
      {
        pfVar2[1] = 0.0;
        *pfVar2 = 0.0;
        pfVar2[-1] = 0.0;
        pfVar2[-2] = 0.0;
      }
      pfVar2 = pfVar2 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}



