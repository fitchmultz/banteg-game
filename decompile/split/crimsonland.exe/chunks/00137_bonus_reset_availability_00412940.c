/* bonus_reset_availability @ 00412940 */

/* [binja] char* sub_412940() */

char * bonus_reset_availability(void)

{
  uchar *puVar1;
  
  puVar1 = &bonus_meta_table.enabled;
  do {
    *puVar1 = '\x01';
    puVar1 = puVar1 + 0x14;
  } while ((int)puVar1 < 0x485508);
  bonus_meta_table.enabled = '\0';
  return (char *)puVar1;
}



