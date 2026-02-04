/* sfx_mute_all @ 0043d550 */

/* mutes all unmuted sfx ids (recursive) */

void __cdecl sfx_mute_all(int sfx_id)

{
  int iVar1;
  int sfx_id_00;
  
  if (((sfx_unmuted_flag != '\0') && (config_blob.reserved0[1] == '\0')) &&
     (config_blob.reserved0[0] == '\0')) {
    DAT_004cc8d4 = 0;
    sfx_id_00 = 0;
    do {
      if (sfx_id_00 != sfx_id) {
        iVar1 = sfx_is_unmuted(sfx_id_00);
        if ((char)iVar1 != '\0') {
          sfx_mute_all(sfx_id_00);
        }
      }
      sfx_id_00 = sfx_id_00 + 1;
    } while (sfx_id_00 < 0x80);
    sfx_mute_flags[sfx_id] = '\x01';
  }
  return;
}



