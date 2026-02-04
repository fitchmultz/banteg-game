/* FUN_00447420 @ 00447420 */

/* [binja] int32_t sub_447420() */

int FUN_00447420(void)

{
  undefined4 in_EAX;
  
  ui_transition_direction = 0;
  if (DAT_004824d1 != '\0') {
    game_state_pending = 5;
    return CONCAT31((int3)((uint)in_EAX >> 8),DAT_004824d1);
  }
  game_state_pending = -(uint)(render_pass_mode != '\0') & 5;
  return game_state_pending;
}



