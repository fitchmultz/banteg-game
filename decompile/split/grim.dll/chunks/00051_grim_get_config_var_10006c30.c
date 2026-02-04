/* grim_get_config_var @ 10006c30 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x24 (provisional): fills 4 dwords for config entry (id 0..0x7f) */

void grim_get_config_var(uint *out,int id)

{
  if ((-1 < id) && (id < 0x80)) {
    *out = (&grim_config_var0_table)[id * 4];
    out[1] = (&grim_config_var1_table)[id * 4];
    out[2] = *(uint *)(&grim_config_var2_table + id * 0x10);
    out[3] = *(uint *)(&grim_config_var3_table + id * 0x10);
    return;
  }
  *out = DAT_1005a478;
  out[1] = DAT_1005a47c;
  out[2] = DAT_1005a480;
  out[3] = DAT_1005a484;
  return;
}



