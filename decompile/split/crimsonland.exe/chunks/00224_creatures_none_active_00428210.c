/* creatures_none_active @ 00428210 */

/* returns low byte 1 when no active creature entries exist (0 otherwise); sets DAT_0048700c */

uint creatures_none_active(void)

{
  creature_t *pcVar1;
  
  pcVar1 = &creature_pool;
  do {
    if (pcVar1->active != '\0') {
      creatures_any_active_flag = 0;
      return (uint)pcVar1 & 0xffffff00;
    }
    pcVar1 = pcVar1 + 1;
  } while ((int)pcVar1 < 0x4aa338);
  creatures_any_active_flag = 1;
  return CONCAT31((int3)((uint)pcVar1 >> 8),1);
}



