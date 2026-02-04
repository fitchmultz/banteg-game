/* FUN_0041a810 @ 0041a810 */

void __cdecl FUN_0041a810(char *param_1,int param_2,float *param_3,float *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  bonus_hud_slot_t *pbVar4;
  int iVar5;
  float **ppfVar6;
  
  iVar2 = 0;
  pbVar4 = bonus_hud_slot_table;
  do {
    if (pbVar4->active == '\0') {
      bonus_hud_slot_table[iVar2].slide.timer_ptr = param_3;
      bonus_hud_slot_table[iVar2].slide.icon_id = param_2;
      uVar1 = config_blob.reserved0._20_4_;
      bonus_hud_slot_table[iVar2].slide.alt_timer_ptr = param_4;
      bonus_hud_slot_table[iVar2].active = '\x01';
      bonus_hud_slot_table[iVar2].slide.slide_x = -184.0;
      bonus_hud_slot_table[iVar2].slide.label = param_1;
      if ((int)uVar1 < 2) {
        bonus_hud_slot_table[iVar2].slide.alt_timer_ptr = (float *)0x0;
      }
      iVar2 = 0;
      ppfVar6 = &bonus_hud_slot_table[0].slide.timer_ptr;
      do {
        if ((char)ppfVar6[-3] != '\0') {
          iVar5 = 0x10;
          puVar3 = &DAT_0048f788;
          do {
            if ((*ppfVar6 == *(float **)(puVar3 + 0xc)) && (iVar2 != iVar5)) {
              *puVar3 = 0;
            }
            puVar3 = puVar3 + -0x20;
            iVar5 = iVar5 + -1;
          } while (0x48f587 < (int)puVar3);
        }
        ppfVar6 = ppfVar6 + 8;
        iVar2 = iVar2 + 1;
      } while ((int)ppfVar6 < 0x48f794);
      return;
    }
    pbVar4 = pbVar4 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)pbVar4 < 0x48f788);
  return;
}



