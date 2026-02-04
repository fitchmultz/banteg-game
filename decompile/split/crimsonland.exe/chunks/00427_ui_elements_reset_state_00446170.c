/* ui_elements_reset_state @ 00446170 */

/* clears active flags and hover timers on all UI elements */

void ui_elements_reset_state(void)

{
  ui_element_t **ppuVar1;
  ui_element_t **ppuVar2;
  
  ppuVar1 = &ui_element_table_end;
  do {
    ppuVar2 = ppuVar1 + 1;
    (*ppuVar1)->active = '\0';
    (*ppuVar1)->counter_value = 0;
    ppuVar1 = ppuVar2;
  } while ((int)ppuVar2 < 0x48f20c);
  return;
}



