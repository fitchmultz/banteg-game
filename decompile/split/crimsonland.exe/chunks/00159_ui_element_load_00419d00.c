/* ui_element_load @ 00419d00 */

/* loads a UI element JAZ asset and logs failures */

void __cdecl ui_element_load(ui_element_t *element,char *jaz_path)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_100 [248];
  int iStack_8;
  
  uVar3 = 0xffffffff;
  pcVar5 = jaz_path;
  do {
    pcVar6 = pcVar5;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar6 + -uVar3;
  pcVar6 = local_100;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = jaz_path;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_100[~uVar3 - 5] = '\0';
  if (*(float *)((int)cv_silentloads + 0xc) == 0.0) {
    console_printf(&console_log_queue,s_Loading_uiElement__s_004737b4,local_100);
  }
  (*grim_interface_ptr->vtable->grim_load_texture)(local_100,jaz_path);
  iVar2 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(&stack0xfffffef8);
  *(int *)(iStack_8 + 0xe0) = iVar2;
  if (iVar2 == -1) {
    console_printf(&console_log_queue,s___FAILED_Loading_uiElement__s_00473794,&stack0xfffffef4);
  }
  return;
}



