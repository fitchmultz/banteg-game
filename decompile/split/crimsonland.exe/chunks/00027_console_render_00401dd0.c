/* console_render @ 00401dd0 */

/* [binja] int32_t __fastcall sub_401dd0(void* arg1) */

int __fastcall console_render(void *arg1)

{
  IGrim2D_vtbl *pIVar1;
  float fVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float fVar9;
  char *text;
  float fStack_4c;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float local_1c;
  float local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar5 = *(int *)((int)arg1 + 0x18);
  local_18 = (float)-iVar5;
  fVar2 = (float)(int)local_18;
  fVar9 = *(float *)((int)arg1 + 0x1c);
  iVar3 = CONCAT22((short)((uint)local_18 >> 0x10),
                   (ushort)(fVar2 < fVar9) << 8 | (ushort)(NAN(fVar2) || NAN(fVar9)) << 10 |
                   (ushort)(fVar2 == fVar9) << 0xe);
  if (fVar2 < fVar9) {
    puVar7 = *(undefined4 **)((int)arg1 + 8);
    iVar3 = ((int)(iVar5 + (iVar5 >> 0x1f & 0xfU)) >> 4) + -2;
    if (*(int *)((int)arg1 + 0x20) <= iVar3) {
      iVar3 = *(int *)((int)arg1 + 0x20);
    }
    local_1c = ((float)iVar5 + *(float *)((int)arg1 + 0x1c)) / (float)iVar5;
    if (local_1c <= 1.0) {
      if (local_1c < 0.0) {
        local_1c = 0.0;
      }
    }
    else {
      local_1c = 1.0;
    }
    (*grim_interface_ptr->vtable->grim_set_color)(0.6,0.6,0.6,local_1c);
    (*grim_interface_ptr->vtable->grim_set_rotation)(0.0);
    uStack_14 = *(undefined4 *)((int)arg1 + 0x1c);
    fStack_4 = local_1c;
    puVar11 = &uStack_10;
    uStack_10 = 0x3e100000;
    uStack_c = 0x3e400000;
    fStack_8 = 0.2890625;
    local_18 = 0.0;
    (*grim_interface_ptr->vtable->grim_draw_rect_filled)
              (&local_18,screen_width_f,(float)*(int *)((int)arg1 + 0x18));
    (*grim_interface_ptr->vtable->grim_set_color)
              (0.1,0.6,1.0,
               ((float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c)) /
               (float)*(int *)((int)arg1 + 0x18));
    puVar10 = &uStack_14;
    local_18 = (float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c);
    uStack_14 = 0x3e600000;
    uStack_10 = 0x3e880000;
    uStack_c = 0x3ebc0000;
    local_1c = 0.0;
    fStack_8 = local_18 / (float)*(int *)((int)arg1 + 0x18);
    local_18 = local_18 - 4.0;
    (*grim_interface_ptr->vtable->grim_draw_rect_filled)(&local_1c,screen_width_f,4.0);
    (*grim_interface_ptr->vtable->grim_end_batch)(puVar10,puVar11);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
    (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
    (*grim_interface_ptr->vtable->grim_set_color)
              (1.0,1.0,1.0,
               (((float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c)) /
               (float)*(int *)((int)arg1 + 0x18)) * 0.3);
    (*grim_interface_ptr->vtable->grim_draw_text_small)
              (screen_width_f - 210.0,
               ((float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c)) - 18.0,
               s_Crimsonland_1_9_93_004712c4);
    (*grim_interface_ptr->vtable->grim_set_color)
              (1.0,1.0,1.0,
               (((float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c)) /
               (float)*(int *)((int)arg1 + 0x18)) * 0.5);
    (*grim_interface_ptr->vtable->grim_set_color)
              (1.0,1.0,1.0,
               ((float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c)) /
               (float)*(int *)((int)arg1 + 0x18));
    if (*(float *)(DAT_0047f4d0 + 0xc) == 0.0) {
      pIVar1 = grim_interface_ptr->vtable;
      pcVar4 = console_input_buffer();
      (*pIVar1->grim_draw_text_small_fmt)
                (grim_interface_ptr,10.0,(float)((iVar3 + 1) * 0x10) + *(float *)((int)arg1 + 0x1c),
                 &DAT_004712bc,pcVar4);
    }
    else {
      fVar9 = (float)((iVar3 + 1) * 0x10);
      (*grim_interface_ptr->vtable->grim_draw_text_mono)
                (10.0,fVar9 + *(float *)((int)arg1 + 0x1c),&console_prompt_string);
      pIVar1 = grim_interface_ptr->vtable;
      pcVar4 = console_input_buffer();
      (*pIVar1->grim_draw_text_mono)(26.0,fVar9 + *(float *)((int)arg1 + 0x1c),pcVar4);
    }
    (*grim_interface_ptr->vtable->grim_set_color)
              (0.6,0.6,0.7,
               ((float)*(int *)((int)arg1 + 0x18) + *(float *)((int)arg1 + 0x1c)) /
               (float)*(int *)((int)arg1 + 0x18));
    for (iVar5 = *(int *)((int)arg1 + 0x24); 0 < iVar5; iVar5 = iVar5 + -1) {
      if (puVar7 == (undefined4 *)0x0) goto LAB_004021ca;
      puVar7 = (undefined4 *)puVar7[1];
    }
    if (puVar7 != (undefined4 *)0x0) {
      iVar5 = iVar3 << 4;
      do {
        if (iVar3 < 0) break;
        fVar9 = (float)iVar5 + *(float *)((int)arg1 + 0x1c);
        if (*(float *)(DAT_0047f4d0 + 0xc) == 0.0) {
          (*grim_interface_ptr->vtable->grim_draw_text_small)(10.0,fVar9,(char *)*puVar7);
        }
        else {
          (*grim_interface_ptr->vtable->grim_draw_text_mono)(10.0,fVar9,(char *)*puVar7);
        }
        puVar7 = (undefined4 *)puVar7[1];
        iVar3 = iVar3 + -1;
        iVar5 = iVar5 + -0x10;
      } while (puVar7 != (undefined4 *)0x0);
    }
LAB_004021ca:
    iVar5 = *(int *)((int)arg1 + 0x18);
    iVar6 = ((int)(iVar5 + (iVar5 >> 0x1f & 0xfU)) >> 4) + -2;
    iVar3 = *(int *)((int)arg1 + 0x20);
    if (iVar6 < *(int *)((int)arg1 + 0x20)) {
      iVar3 = iVar6;
    }
    fsin((float10)game_time_s * (float10)3.0);
    crt_ci_pow();
    fVar8 = extraout_ST0;
    if (extraout_ST0 < (float10)0.2) {
      fVar8 = (float10)0.2;
    }
    fStack_4c = (float)((((float10)iVar5 + (float10)*(float *)((int)arg1 + 0x1c)) / (float10)iVar5)
                       * fVar8);
    if (fStack_4c <= 1.0) {
      if (fStack_4c < 0.0) {
        fStack_4c = 0.0;
      }
    }
    else {
      fStack_4c = 1.0;
    }
    (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,fStack_4c);
    if (*(float *)(DAT_0047f4d0 + 0xc) == 0.0) {
      pIVar1 = grim_interface_ptr->vtable;
      text = &DAT_004712b8;
      fVar9 = (float)((iVar3 + 1) * 0x10) + *(float *)((int)arg1 + 0x1c) + 2.0;
      pcVar4 = console_input_buffer();
      iVar5 = (*pIVar1->grim_measure_text_width)(pcVar4);
      (*pIVar1->grim_draw_text_small)((float)iVar5 + 16.0,fVar9,text);
    }
    else {
      (*grim_interface_ptr->vtable->grim_draw_text_mono)
                ((float)(console_input_cursor << 3) + 26.0,
                 (float)((iVar3 + 1) * 0x10) + *(float *)((int)arg1 + 0x1c) + 2.0,&DAT_004712b8);
    }
    iVar3 = (*grim_interface_ptr->vtable->grim_set_config_var)(0x15,2);
  }
  return iVar3;
}



