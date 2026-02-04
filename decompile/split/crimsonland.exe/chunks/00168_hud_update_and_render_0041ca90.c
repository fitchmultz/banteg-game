/* hud_update_and_render @ 0041ca90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* updates HUD flags/targets and renders the HUD */

void hud_update_and_render(void)

{
  float fVar1;
  float local_28;
  float local_20;
  float local_1c;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar1 = (float)ui_elements_timeline / (float)(DAT_0048eb48 - DAT_0048eb4c);
  if ((1.0 < fVar1) || (fVar1 == 1.0)) {
    DAT_00487241 = 0;
  }
  if (DAT_00487268 != -1) {
    local_14 = _camera_offset_y + (&creature_pool)[DAT_00487268].pos_y;
    local_28 = (&creature_pool)[DAT_00487268].health / (&creature_pool)[DAT_00487268].max_health;
    if (local_28 <= 1.0) {
      if (local_28 < 0.0) {
        local_28 = 0.0;
      }
    }
    else {
      local_28 = 1.0;
    }
    local_8 = 0x3e4ccccd;
    local_10 = (1.0 - local_28) * 0.9 + 0.1;
    local_4 = 0x3f333333;
    local_c = local_28 * 0.9 + 0.1;
    local_20 = (_camera_offset_x + (&creature_pool)[DAT_00487268].pos_x) - 32.0;
    local_1c = local_14 + 32.0;
    ui_draw_progress_bar(&local_20,64.0,local_28,&local_10);
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,1.0);
  }
  if (config_blob.reserved0._24_4_ == 3) {
    DAT_004871b0 = 1;
    DAT_004871b1 = 1;
    DAT_004871b2 = 1;
    DAT_004871b3 = 1;
  }
  else {
    if (config_blob.reserved0._24_4_ == 1) {
      DAT_004871b0 = 1;
      DAT_004871b1 = 1;
      DAT_004871b2 = 1;
    }
    else {
      if (config_blob.reserved0._24_4_ == 2) {
        DAT_004871b0 = 1;
        DAT_004871b1 = 0;
        DAT_004871b2 = 0;
        DAT_004871b3 = 0;
        DAT_004871b4 = 1;
        goto LAB_0041cc88;
      }
      if (config_blob.reserved0._24_4_ == 4) {
        DAT_004871b0 = 1;
        DAT_004871b1 = 0;
        DAT_004871b2 = 1;
        DAT_004871b3 = 0;
        DAT_004871b4 = 1;
        goto LAB_0041cc88;
      }
      DAT_004871b0 = 0;
      DAT_004871b1 = 0;
      DAT_004871b2 = 0;
    }
    DAT_004871b3 = 0;
  }
  DAT_004871b4 = 0;
LAB_0041cc88:
  if (demo_mode_active == '\0') {
    ui_render_hud();
  }
  return;
}



