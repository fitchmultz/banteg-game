/* grim_dxt_pack_rgb565 @ 1002072b */

/* clamps rgb floats and packs into RGB565 */

uint __fastcall grim_dxt_pack_rgb565(float *rgb)

{
  float local_1c;
  float local_18;
  float local_14;
  
  if (0.0 <= *rgb) {
    if (1.0 < *rgb) {
      local_1c = 1.0;
    }
    else {
      local_1c = *rgb;
    }
  }
  else {
    local_1c = 0.0;
  }
  if (0.0 <= rgb[1]) {
    if (1.0 < rgb[1]) {
      local_18 = 1.0;
    }
    else {
      local_18 = rgb[1];
    }
  }
  else {
    local_18 = 0.0;
  }
  if (0.0 <= rgb[2]) {
    if (rgb[2] <= 1.0) {
      local_14 = rgb[2];
    }
    else {
      local_14 = 1.0;
    }
  }
  else {
    local_14 = 0.0;
  }
  fpu_save_control_word();
  return ((int)ROUND(local_1c * 31.0 + 0.5) << 6 | (int)ROUND(local_18 * 63.0 + 0.5)) << 5 |
         (int)ROUND(local_14 * 31.0 + 0.5);
}



