/* ui_get_element_index @ 00446150 */

/* returns index of element in ui_element_table_end list, or -1 */

int __cdecl ui_get_element_index(ui_element_t *element)

{
  int iVar1;
  ui_element_t **ppuVar2;
  
  iVar1 = 0;
  ppuVar2 = &ui_element_table_end;
  do {
    if (element == *ppuVar2) {
      return iVar1;
    }
    ppuVar2 = ppuVar2 + 1;
    iVar1 = iVar1 + 1;
  } while ((int)ppuVar2 < 0x48f20c);
  return -1;
}



