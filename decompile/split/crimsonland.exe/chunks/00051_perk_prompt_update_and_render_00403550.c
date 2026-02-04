/* perk_prompt_update_and_render @ 00403550 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates perk prompt timer, animates transforms, and renders the prompt text */

void perk_prompt_update_and_render(void)

{
  IGrim2D_vtbl *pIVar1;
  char *pcVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float y;
  char acStack_80 [128];
  
  if ((demo_mode_active == '\0') && (config_blob.reserved0._24_4_ != 2)) {
    if ((perk_pending_count < 1) || (game_state_id != 9)) {
      perk_prompt_timer = perk_prompt_timer - frame_dt_ms;
      if (perk_prompt_timer < 0) {
        perk_prompt_timer = 0;
      }
    }
    else {
      perk_prompt_timer = perk_prompt_timer + frame_dt_ms;
      if (200 < perk_prompt_timer) {
        perk_prompt_timer = 200;
      }
    }
    if ((config_blob.full_version != '\0') && (0 < perk_prompt_timer)) {
      (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)perk_prompt_timer * 0.005);
      pcVar2 = input_key_name(config_blob.key_pick_perk);
      crt_sprintf(acStack_80,s_Press__s_to_pick_a_perk_00471488,pcVar2);
      y = _perk_prompt_origin_y + 8.0;
      pIVar1 = grim_interface_ptr->vtable;
      pcVar2 = acStack_80;
      iVar3 = (*pIVar1->grim_measure_text_width)(acStack_80);
      (*pIVar1->grim_draw_text_small)((float)((config_blob.screen_width - iVar3) + -0x10),y,pcVar2);
    }
    DAT_0048f20c = 1;
    fVar4 = ((float10)1.0 - (float10)perk_prompt_timer * (float10)0.005) * (float10)-1.5707964;
    fVar5 = (float10)fcos(fVar4);
    _perk_prompt_transform_cos = (float)fVar5;
    fVar4 = (float10)fsin((float10)(float)fVar4);
    _perk_prompt_transform_sin_neg = (float)-fVar4;
    _perk_prompt_transform_sin = (float)fVar4;
    _perk_prompt_transform_cos_2 = (float)fVar5;
    ui_element_render((ui_element_t *)&DAT_0048f20c);
  }
  return;
}



