/* ui_elements_max_timeline @ 00446190 */

/* returns max timeline value (element +0x10) among active UI elements */

int ui_elements_max_timeline(void)

{
  int iVar1;
  int iVar2;
  ui_element_t **ppuVar3;
  
  iVar2 = 0;
  ppuVar3 = &ui_element_table_end;
  do {
    if (((*ppuVar3)->active != '\0') && (iVar1 = *(int *)((*ppuVar3)->_pad0 + 0xe), iVar2 < iVar1))
    {
      iVar2 = iVar1;
    }
    ppuVar3 = ppuVar3 + 1;
  } while ((int)ppuVar3 < 0x48f20c);
  return iVar2;
}



