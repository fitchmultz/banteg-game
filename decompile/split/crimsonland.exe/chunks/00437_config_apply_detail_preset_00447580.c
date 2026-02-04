/* config_apply_detail_preset @ 00447580 */

/* Applies config_detail_preset ("Graphics detail" 1..5) to the config_fx_detail_flag0/1/2 bytes. */

void config_apply_detail_preset(void)

{
  switch(config_blob.detail_preset) {
  case 1:
    config_blob.reserved0[0x11] = '\0';
  case 2:
    config_blob.reserved0[0xe] = '\0';
    config_blob.reserved0[0x10] = '\0';
    return;
  case 3:
  case 4:
  case 5:
    config_blob.reserved0[0x10] = '\x01';
    config_blob.reserved0[0x11] = '\x01';
    config_blob.reserved0[0xe] = '\x01';
  default:
    return;
  }
}



