/* ui_focus_set @ 0043d7e0 */

/* sets the active focus candidate; optionally resets the focus timer */

void __cdecl ui_focus_set(int id,char reset_timer)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = ui_focus_index;
  if ((&ui_focus_candidates)[ui_focus_index] != id) {
    if (reset_timer != '\0') {
      ui_focus_timer_ms = 1000;
    }
    iVar2 = 0;
    if (0 < ui_focus_count) {
      piVar3 = &ui_focus_candidates;
      while (iVar1 = iVar2, *piVar3 != id) {
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
        if (ui_focus_count <= iVar2) {
          return;
        }
      }
    }
  }
  ui_focus_index = iVar1;
  return;
}



