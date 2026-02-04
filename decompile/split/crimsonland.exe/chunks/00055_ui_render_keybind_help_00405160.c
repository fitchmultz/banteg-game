/* ui_render_keybind_help @ 00405160 */

/* renders the in-game key bindings help overlay */

void __cdecl ui_render_keybind_help(float *xy,float alpha)

{
  IGrim2D_vtbl *pIVar1;
  char *pcVar2;
  float fVar3;
  float x;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  
  (*grim_interface_ptr->vtable->grim_draw_rect_filled)(xy,512.0,256.0);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)xy);
  (*grim_interface_ptr->vtable->grim_draw_rect_outline)(xy,512.0,256.0);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f4ccccd);
  (*grim_interface_ptr->vtable->grim_draw_text_mono_fmt)
            (grim_interface_ptr,*xy + 16.0,xy[1] + 16.0,s_key_info_00471ffc);
  (*grim_interface_ptr->vtable->grim_set_color)(1.0,1.0,1.0,(float)xy);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x18,0x3f000000);
  x = *xy + 32.0;
  fVar3 = xy[1] + 50.0;
  fVar5 = x;
  fVar6 = fVar3;
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,x,fVar3,s_Level_Up__00471ff0);
  fVar7 = fVar5 + 128.0;
  pIVar1 = grim_interface_ptr->vtable;
  pcVar2 = input_key_name(config_blob.key_pick_perk);
  (*pIVar1->grim_draw_text_small_fmt)
            (grim_interface_ptr,fVar7,fVar3,s__s_or_SPACE_BAR_or_KeyPadAdd_00471fd0,pcVar2);
  fVar6 = fVar6 + 18.0;
  fVar3 = fVar6;
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,x,fVar6,s_Reload__00471fc8);
  pIVar1 = grim_interface_ptr->vtable;
  pcVar2 = input_key_name(config_blob.key_reload);
  (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar7,fVar6,&s_fmt_percent_s,pcVar2);
  fVar3 = fVar3 + 18.0 + 20.0;
  fVar7 = fVar3;
  iVar8 = 0;
  do {
    if (iVar8 == 1) {
      x = fVar5 + 256.0;
      fVar5 = x;
    }
    iVar4 = iVar8 + 1;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,x,fVar3,s_Player__d_00471fb8,iVar4);
    fVar7 = fVar7 + 22.0;
    fVar3 = fVar7;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,x,fVar7,&DAT_00471fb4);
    fVar6 = fVar5 + 64.0;
    pIVar1 = grim_interface_ptr->vtable;
    pcVar2 = input_key_name(config_blob.keybinds_p1[iVar8 * 5]);
    (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar6,fVar7,&s_fmt_percent_s,pcVar2);
    fVar3 = fVar3 + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,x,fVar3,s_Down__00471fac);
    pIVar1 = grim_interface_ptr->vtable;
    pcVar2 = input_key_name(config_blob.keybinds_p1[iVar8 * 5 + 1]);
    (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar6,fVar3,&s_fmt_percent_s,pcVar2);
    fVar3 = fVar3 + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,x,fVar3,s_Left__00471fa4);
    pIVar1 = grim_interface_ptr->vtable;
    pcVar2 = input_key_name(config_blob.keybinds_p1[iVar8 * 5 + 2]);
    (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar6,fVar3,&s_fmt_percent_s,pcVar2);
    fVar3 = fVar3 + 16.0;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,x,fVar3,s_Right__00471f9c);
    pIVar1 = grim_interface_ptr->vtable;
    pcVar2 = input_key_name(config_blob.keybinds_p1[iVar8 * 5 + 3]);
    (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar6,fVar3,&s_fmt_percent_s,pcVar2);
    fVar3 = fVar3 + 16.0;
    fVar7 = fVar3;
    (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
              (grim_interface_ptr,x,fVar3,s_Fire__00471f94);
    pIVar1 = grim_interface_ptr->vtable;
    pcVar2 = input_key_name(config_blob.keybinds_p1[iVar8 * 5 + 4]);
    (*pIVar1->grim_draw_text_small_fmt)(grim_interface_ptr,fVar6,fVar3,&s_fmt_percent_s,pcVar2);
    if (iVar8 == 0) {
      fVar3 = fVar7 - 94.0;
      fVar7 = fVar3;
    }
    iVar8 = iVar4;
  } while (iVar4 < 2);
  (*grim_interface_ptr->vtable->grim_draw_text_small_fmt)
            (grim_interface_ptr,fVar5 - 20.0,fVar7 + 32.0,s_Press_F1_to_return_to_game_00471f78);
  return;
}



