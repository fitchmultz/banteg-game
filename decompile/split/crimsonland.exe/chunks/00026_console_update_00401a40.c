/* console_update @ 00401a40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* console update loop: input polling, history, autocomplete, and key handling */

void __fastcall console_update(int console_state)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  float10 fVar13;
  
  if (*(char *)(console_state + 0x28) == '\0') {
    _DAT_0047115c = _DAT_0047ea48 * 3.5 + _DAT_0047115c;
    if (1.0 < _DAT_0047115c) {
      _DAT_0047115c = 1.0;
    }
    fVar13 = (float10)fsin(((float10)1.0 - (float10)_DAT_0047115c) * (float10)1.5707964);
    *(float *)(console_state + 0x1c) =
         (float)(fVar13 * (float10)*(int *)(console_state + 0x18) -
                (float10)*(int *)(console_state + 0x18));
    return;
  }
  _DAT_0047115c = _DAT_0047115c - _DAT_0047ea48 * 3.5;
  if (_DAT_0047115c < 0.0) {
    _DAT_0047115c = 0.0;
  }
  fVar13 = (float10)fsin(((float10)1.0 - (float10)_DAT_0047115c) * (float10)1.5707964);
  *(float *)(console_state + 0x1c) =
       (float)(fVar13 * (float10)*(int *)(console_state + 0x18) -
              (float10)*(int *)(console_state + 0x18));
  console_input_poll();
  iVar3 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x1d);
  if ((char)iVar3 == '\0') {
    iVar3 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x9d);
    if ((char)iVar3 != '\0') goto LAB_00401ac4;
LAB_00401add:
    iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(200);
    if ((char)iVar3 != '\0') {
      *(int *)(console_state + 0x14) = *(int *)(console_state + 0x14) + 1;
      console_history_apply(console_state);
    }
  }
  else {
LAB_00401ac4:
    iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(200);
    if ((char)iVar3 == '\0') goto LAB_00401add;
    *(int *)(console_state + 0x24) = *(int *)(console_state + 0x24) + 1;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x1d);
  if ((char)iVar3 == '\0') {
    iVar3 = (*grim_interface_ptr->vtable->grim_is_key_down)(0x9d);
    if ((char)iVar3 != '\0') goto LAB_00401b24;
LAB_00401b3d:
    iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xd0);
    if ((char)iVar3 != '\0') {
      iVar3 = *(int *)(console_state + 0x14) + -1;
      *(int *)(console_state + 0x14) = iVar3;
      if (iVar3 < 0) {
        *(undefined4 *)(console_state + 0x14) = 0;
      }
      console_history_apply(console_state);
    }
  }
  else {
LAB_00401b24:
    iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xd0);
    if ((char)iVar3 == '\0') goto LAB_00401b3d;
    *(int *)(console_state + 0x24) = *(int *)(console_state + 0x24) + -1;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xcb);
  if (((char)iVar3 != '\0') &&
     (console_input_cursor = console_input_cursor + -1, console_input_cursor < 0)) {
    console_input_cursor = 0;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xcd);
  if ((char)iVar3 != '\0') {
    uVar7 = 0xffffffff;
    console_input_cursor = console_input_cursor + 1;
    pcVar4 = (char *)&console_input_buf;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((int)(~uVar7 - 1) < console_input_cursor) {
      uVar7 = 0xffffffff;
      pcVar4 = (char *)&console_input_buf;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      console_input_cursor = ~uVar7 - 1;
    }
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xc9);
  if ((char)iVar3 != '\0') {
    *(int *)(console_state + 0x24) = *(int *)(console_state + 0x24) + 2;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xd1);
  if (((char)iVar3 != '\0') &&
     (iVar3 = *(int *)(console_state + 0x24) + -2, *(int *)(console_state + 0x24) = iVar3, iVar3 < 0
     )) {
    *(undefined4 *)(console_state + 0x24) = 0;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(199);
  if ((char)iVar3 != '\0') {
    *(int *)(console_state + 0x24) = *(int *)(console_state + 0x24) + 0x14;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xcf);
  if ((char)iVar3 != '\0') {
    *(undefined4 *)(console_state + 0x24) = 0;
  }
  iVar3 = (*grim_interface_ptr->vtable->grim_was_key_pressed)(0xf);
  if ((char)iVar3 != '\0') {
    pcVar4 = console_input_buffer();
    console_tokenize_line(pcVar4);
    pcVar4 = console_input_buffer();
    pcVar4 = console_cvar_autocomplete((void *)console_state,pcVar4);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = console_input_buffer();
      pcVar4 = console_command_autocomplete((void *)console_state,pcVar4);
      if (pcVar4 == (char *)0x0) goto LAB_00401cb5;
    }
    uVar7 = 0xffffffff;
    pcVar10 = pcVar4;
    do {
      pcVar11 = pcVar10;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    uVar7 = ~uVar7;
    pcVar10 = pcVar11 + -uVar7;
    pcVar11 = (char *)&console_input_buf;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    uVar7 = 0xffffffff;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    console_input_cursor = ~uVar7 - 1;
  }
LAB_00401cb5:
  if (console_input_ready == '\0') {
    console_input_buffer();
    (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
    return;
  }
  pbVar5 = (byte *)console_input_buffer();
  pbVar9 = (byte *)**(undefined4 **)(console_state + 0x10);
  do {
    bVar2 = *pbVar9;
    bVar12 = bVar2 < *pbVar5;
    if (bVar2 != *pbVar5) {
LAB_00401cf1:
      iVar3 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
      goto LAB_00401cf6;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar9[1];
    bVar12 = bVar2 < pbVar5[1];
    if (bVar2 != pbVar5[1]) goto LAB_00401cf1;
    pbVar9 = pbVar9 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar2 != 0);
  iVar3 = 0;
LAB_00401cf6:
  if (iVar3 != 0) {
    puVar6 = operator_new(8);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6[1] = 0;
      *puVar6 = 0;
    }
    pcVar4 = console_input_buffer();
    pcVar4 = strdup_malloc(pcVar4);
    *puVar6 = pcVar4;
    puVar6[1] = *(undefined4 *)(console_state + 0x10);
    *(undefined4 **)(console_state + 0x10) = puVar6;
  }
  *(undefined4 *)(console_state + 0x14) = 0;
  pcVar4 = console_input_buffer();
  console_printf(&console_log_queue,s_>__s_004712b0,pcVar4);
  pcVar4 = console_input_buffer();
  console_exec_line((void *)console_state,pcVar4);
  console_input_clear();
  (*grim_interface_ptr->vtable->grim_was_key_pressed)(0x1c);
  return;
}



