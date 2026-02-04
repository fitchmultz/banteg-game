/* grim_dxt_unpremultiply_rgba_block @ 1002065a */

/* divides rgb by alpha for a 4x4 RGBA block */

int __fastcall grim_dxt_unpremultiply_rgba_block(float *rgba)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = 0x10;
  do {
    if (rgba[3] == 0.0) {
      *rgba = 0.0;
      rgba[1] = 0.0;
      fVar1 = 0.0;
LAB_100206cc:
      rgba[2] = fVar1;
    }
    else if (rgba[3] < 1.0) {
      fVar1 = 1.0 / rgba[3];
      if (rgba[3] <= *rgba) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = fVar1 * *rgba;
      }
      *rgba = fVar2;
      if (rgba[3] <= rgba[1]) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = fVar1 * rgba[1];
      }
      rgba[1] = fVar2;
      if (rgba[3] <= rgba[2]) {
        fVar1 = 1.0;
      }
      else {
        fVar1 = fVar1 * rgba[2];
      }
      goto LAB_100206cc;
    }
    rgba = rgba + 4;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  } while( true );
}



