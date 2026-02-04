/* ui_focus_update @ 0043d830 */

/* handles menu focus navigation and returns 1 when the given id is focused */

int __cdecl ui_focus_update(int id)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (&ui_focus_candidates)[ui_focus_index];
  if (ui_focus_frame_marker_ms == game_time_ms) {
    if (0x1f < ui_focus_count) {
      ui_focus_count = 0x1f;
    }
    (&ui_focus_candidates)[ui_focus_count] = id;
    ui_focus_count = ui_focus_count + 1;
    return CONCAT31((int3)((uint)ui_focus_count >> 8),id == iVar1);
  }
  ui_focus_timer_ms = ui_focus_timer_ms - frame_dt_ms;
  if (ui_focus_timer_ms < 0) {
    ui_focus_timer_ms = 0;
  }
  if ((DAT_004871ca == '\0') &&
     (iVar2 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xf), (char)iVar2 != '\0')) {
    iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x2a);
    if (((char)iVar2 == '\0') &&
       (iVar2 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x36), (char)iVar2 == '\0')) {
      ui_focus_index = ui_focus_index + 1;
    }
    else {
      ui_focus_index = ui_focus_index + -1;
    }
    ui_focus_timer_ms = 1000;
  }
  if (ui_focus_index < 0) {
    ui_focus_index = ui_focus_count + -1;
  }
  if (ui_focus_count + -1 < ui_focus_index) {
    ui_focus_index = 0;
  }
  ui_focus_frame_marker_ms = game_time_ms;
  ui_focus_candidates = id;
  ui_focus_count = 1;
  return (uint)(id == iVar1);
}



