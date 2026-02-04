/* effects_update @ 0042e710 */

/* ticks active effects and frees expired entries */

void effects_update(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = &effect_pool_pos_x.age;
  do {
    fVar1 = pfVar4[2];
    if (fVar1 != 0.0) {
      fVar2 = frame_dt + *pfVar4;
      *pfVar4 = fVar2;
      if (fVar2 < pfVar4[1]) {
        if (0.0 <= fVar2) {
          fVar3 = frame_dt * pfVar4[-5];
          ((effect_entry_t *)(pfVar4 + -9))->pos_x =
               frame_dt * pfVar4[-6] + ((effect_entry_t *)(pfVar4 + -9))->pos_x;
          pfVar4[-8] = fVar3 + pfVar4[-8];
          if (((uint)fVar1 & 4) != 0) {
            pfVar4[-4] = frame_dt * pfVar4[7] + pfVar4[-4];
          }
          if (((uint)fVar1 & 8) != 0) {
            pfVar4[-3] = frame_dt * pfVar4[8] + pfVar4[-3];
          }
          if (((uint)fVar1 & 0x10) != 0) {
            pfVar4[6] = 1.0 - fVar2 / pfVar4[1];
          }
        }
      }
      else {
        if (((uint)fVar1 & 0x80) != 0) {
          if (((uint)fVar1 & 0x100) == 0) {
            pfVar4[6] = 0.8;
          }
          else {
            pfVar4[6] = 0.35;
          }
          fx_queue_add((uint)*(byte *)(pfVar4 + -7),(float *)(pfVar4 + -9),pfVar4[-2] + pfVar4[-2],
                       pfVar4[-1] + pfVar4[-1],pfVar4[-4],pfVar4 + 3);
        }
        effect_free((effect_entry_t *)(pfVar4 + -9));
      }
    }
    pfVar4 = pfVar4 + 0x2f;
  } while ((int)pfVar4 < 0x4c2b54);
  return;
}



