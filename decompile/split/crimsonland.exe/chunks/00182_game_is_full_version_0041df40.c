/* game_is_full_version @ 0041df40 */

/* returns non-zero when full version/unlimited mode is enabled */

int game_is_full_version(void)

{
  undefined4 in_EAX;
  
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



