/* effect_uv_tables_init @ 0041fed0 */

/* precomputes UV grids for 2x2, 4x4, 8x8, 16x16 effect atlases */

void effect_uv_tables_init(void)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float *pfVar4;
  float *pfVar5;
  int local_8;
  int local_4;
  
  local_8 = 0;
  puVar2 = &DAT_00490f84;
  do {
    fVar1 = (float)local_8;
    puVar3 = puVar2 + 2;
    local_8 = local_8 + 1;
    puVar2[-1] = fVar1 * 0.0625;
    *puVar2 = 0;
    puVar2 = puVar3;
  } while ((int)puVar3 < 0x491004);
  local_4 = 0;
  pfVar5 = &effect_uv2.v;
  do {
    local_8 = 0;
    pfVar4 = pfVar5;
    do {
      fVar1 = (float)local_8;
      local_8 = local_8 + 1;
      ((uv2f_t *)(pfVar4 + -1))->u = fVar1 * 0.5;
      *pfVar4 = (float)local_4 * 0.5;
      pfVar4 = pfVar4 + 2;
    } while (local_8 < 2);
    local_4 = local_4 + 1;
    pfVar5 = pfVar5 + 4;
  } while (local_4 < 2);
  local_4 = 0;
  pfVar5 = &effect_uv4.v;
  do {
    local_8 = 0;
    pfVar4 = pfVar5;
    do {
      fVar1 = (float)local_8;
      local_8 = local_8 + 1;
      ((uv2f_t *)(pfVar4 + -1))->u = fVar1 * 0.25;
      *pfVar4 = (float)local_4 * 0.25;
      pfVar4 = pfVar4 + 2;
    } while (local_8 < 4);
    local_4 = local_4 + 1;
    pfVar5 = pfVar5 + 8;
  } while (local_4 < 4);
  local_4 = 0;
  pfVar5 = &effect_uv8.v;
  do {
    local_8 = 0;
    pfVar4 = pfVar5;
    do {
      fVar1 = (float)local_8;
      local_8 = local_8 + 1;
      ((uv2f_t *)(pfVar4 + -1))->u = fVar1 * 0.125;
      *pfVar4 = (float)local_4 * 0.125;
      pfVar4 = pfVar4 + 2;
    } while (local_8 < 8);
    local_4 = local_4 + 1;
    pfVar5 = pfVar5 + 0x10;
  } while (local_4 < 8);
  local_4 = 0;
  pfVar5 = &effect_uv16.v;
  do {
    local_8 = 0;
    pfVar4 = pfVar5;
    do {
      fVar1 = (float)local_8;
      local_8 = local_8 + 1;
      ((uv2f_t *)(pfVar4 + -1))->u = fVar1 * 0.0625;
      *pfVar4 = (float)local_4 * 0.0625;
      pfVar4 = pfVar4 + 2;
    } while (local_8 < 0x10);
    local_4 = local_4 + 1;
    pfVar5 = pfVar5 + 0x20;
  } while (local_4 < 0x10);
  return;
}



