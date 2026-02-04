/* grim_draw_text_small @ 10009730 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x144: small font draw (GRIM_Font2) */

void grim_draw_text_small(float x,float y,char *text)

{
  char cVar1;
  int *in_ECX;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 unaff_retaddr;
  undefined4 uVar6;
  int iVar7;
  undefined4 uStack_14;
  
  if ((grim_render_disabled == '\0') && (text != (char *)0x0)) {
    ftol();
    ftol();
    if ((grim_font2_texture_handle != -1) ||
       (grim_font2_texture_handle = (**(code **)(*in_ECX + 0xc0))(s_GRIM_Font2_10053c3c),
       grim_font2_texture_handle != -1)) {
      iVar7 = grim_font2_texture_handle;
      (**(code **)(*in_ECX + 0xc4))(grim_font2_texture_handle,0);
      if (DAT_1005ccd8 != 1) {
        (**(code **)(*in_ECX + 0x20))(0x15,1);
      }
      uVar6 = 0;
      (**(code **)(*in_ECX + 0xfc))(0);
      (**(code **)(*in_ECX + 0xe8))();
      uVar2 = 0xffffffff;
      pcVar4 = text;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      iVar5 = 0;
      if (0 < (int)(~uVar2 - 1)) {
        do {
          uVar3 = (uint)(byte)(&grim_font2_char_map)[(byte)text[iVar5]];
          if (text[iVar5] != 10) {
            (**(code **)(*in_ECX + 0x100))
                      ((float)(&grim_font2_uv_u)[uVar3 * 2] + 0.001953125,
                       (float)(&grim_font2_uv_v)[uVar3 * 2] + 0.001953125,
                       ((float)*(byte *)((int)&grim_font2_glyph_widths + uVar3) * 0.00390625 +
                       (float)(&grim_font2_uv_u)[uVar3 * 2] + 0.001953125) - 0.001953125,
                       ((float)(&grim_font2_uv_v)[uVar3 * 2] + 0.001953125 + 0.0625) - 0.001953125);
            (**(code **)(*in_ECX + 0x11c))(uVar6,iVar7,uStack_14,0x41800000);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)(~uVar2 - 1));
      }
      (**(code **)(*in_ECX + 0xf0))();
      (**(code **)(*in_ECX + 0x20))(0x15,unaff_retaddr);
    }
  }
  return;
}



