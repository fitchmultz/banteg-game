/* FUN_00413540 @ 00413540 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00413540(float param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  iVar2 = render_overlay_player_index;
  fVar1 = (&player_state_table)[render_overlay_player_index].heading;
  while (fVar1 < 0.0) {
    fVar1 = (&player_state_table)[iVar2].heading + 6.2831855;
    (&player_state_table)[iVar2].heading = fVar1;
  }
  fVar1 = (&player_state_table)[iVar2].heading;
  while (6.2831855 < fVar1) {
    fVar1 = (&player_state_table)[iVar2].heading - 6.2831855;
    (&player_state_table)[iVar2].heading = fVar1;
  }
  fVar3 = ABS(param_1 - (&player_state_table)[iVar2].heading);
  fVar1 = (&player_state_table)[iVar2].heading;
  if ((&player_state_table)[iVar2].heading < param_1) {
    fVar1 = param_1;
  }
  fVar4 = (&player_state_table)[iVar2].heading;
  if (param_1 < (&player_state_table)[iVar2].heading) {
    fVar4 = param_1;
  }
  fVar4 = ABS((6.2831855 - fVar1) + fVar4);
  fVar1 = fVar4;
  if (fVar3 < fVar4) {
    fVar1 = fVar3;
  }
  if (fVar3 <= fVar4) {
    if ((&player_state_table)[iVar2].heading < param_1) {
      _DAT_00487198 = frame_dt * fVar1 * 5.0;
      goto LAB_00413686;
    }
  }
  else if (param_1 < (&player_state_table)[iVar2].heading) {
    _DAT_00487198 = frame_dt * fVar1 * 5.0;
    goto LAB_00413686;
  }
  _DAT_00487198 = frame_dt * fVar1 * -5.0;
LAB_00413686:
  (&player_state_table)[iVar2].heading = _DAT_00487198 + (&player_state_table)[iVar2].heading;
  return;
}



