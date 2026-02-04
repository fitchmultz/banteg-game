/* perk_can_offer @ 0042fb10 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* returns nonzero when perk is eligible for selection */

int __cdecl perk_can_offer(int perk_index)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = config_blob.reserved0._24_4_;
  if (((((config_blob.reserved0._24_4_ != 3) || (config_blob.hardcore == '\0')) ||
       (_quest_stage_minor != 10)) ||
      ((_quest_stage_major != 2 ||
       (((perk_index != perk_id_poison_bullets && (perk_index != perk_id_veins_of_poison)) &&
        (perk_index != perk_id_plaguebearer)))))) &&
     (((config_blob.reserved0._20_4_ != 2 || (((&perk_meta_table)[perk_index].flags & 2) != 0)) &&
      ((config_blob.reserved0._24_4_ != 3 ||
       (uVar2 = perk_index * 5, ((&perk_meta_table)[perk_index].flags & 1) != 0)))))) {
    iVar1 = (&perk_meta_table)[perk_index].prerequisite;
    if (iVar1 == -1) {
      return -0xff;
    }
    if (0 < player_state_table.perk_counts[iVar1]) {
      return CONCAT31((int3)((uint)iVar1 >> 8),1);
    }
    uVar2 = game_is_full_version();
    if (((((char)uVar2 == '\0') && (perk_index != perk_id_living_fortress)) &&
        (perk_index != perk_id_man_bomb)) && (perk_index != perk_id_fire_caugh)) {
      uVar2 = perk_id_tough_reloader;
    }
  }
  return uVar2 & 0xffffff00;
}



