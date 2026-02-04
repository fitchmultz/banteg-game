/* grim_set_config_var @ 10006580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0x20: config/state dispatcher; updates config tables, some IDs map to D3D
   render/texture state; extra args for some IDs */

void grim_set_config_var(uint id,uint value)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  WORD WVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint uVar10;
  uint *puVar11;
  WORD *pWVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  bool bVar16;
  uint in_stack_0000000c;
  uint in_stack_00000010;
  byte *in_stack_00000014;
  D3DGAMMARAMP DStack_600;
  
  switch(id) {
  case 5:
    DAT_1005d3a8 = in_stack_00000014;
    return;
  case 6:
    DAT_10059770 = in_stack_00000014;
    return;
  case 7:
    if (DAT_1005bac8 != (byte *)0x0) {
      operator_delete(DAT_1005bac8);
    }
    uVar6 = 0xffffffff;
    pbVar13 = in_stack_00000014;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar1 = *pbVar13;
      pbVar13 = pbVar13 + 1;
    } while (bVar1 != 0);
    DAT_1005bac8 = operator_new(~uVar6);
    uVar6 = 0xffffffff;
    do {
      pbVar13 = in_stack_00000014;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pbVar13 = in_stack_00000014 + 1;
      bVar1 = *in_stack_00000014;
      in_stack_00000014 = pbVar13;
    } while (bVar1 != 0);
    uVar6 = ~uVar6;
    pbVar13 = pbVar13 + -uVar6;
    pbVar15 = DAT_1005bac8;
    for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pbVar15 = *(undefined4 *)pbVar13;
      pbVar13 = pbVar13 + 4;
      pbVar15 = pbVar15 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pbVar15 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      pbVar15 = pbVar15 + 1;
    }
    *(byte **)(&grim_config_var3_table + id * 0x10) = DAT_1005bac8;
    return;
  default:
    puVar11 = &grim_config_var0_table + id * 4;
    *puVar11 = value;
    goto LAB_10006b54;
  case 0xb:
  case 0xc:
  case 0xe:
  case 0x42:
    *(char *)(&grim_config_var0_table + id * 4) = (char)value;
    return;
  case 0xd:
    *(char *)(&grim_config_var0_table + id * 4) = (char)value;
    if (grim_input_cached != '\0') {
      DAT_1005cc48 = 1;
      return;
    }
    break;
  case 0x10:
    pbVar15 = &DAT_1005d828;
    pbVar13 = in_stack_00000014;
    do {
      bVar1 = *pbVar13;
      bVar16 = bVar1 < *pbVar15;
      if (bVar1 != *pbVar15) {
LAB_10006882:
        iVar14 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
        goto LAB_10006887;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar13[1];
      bVar16 = bVar1 < pbVar15[1];
      if (bVar1 != pbVar15[1]) goto LAB_10006882;
      pbVar13 = pbVar13 + 2;
      pbVar15 = pbVar15 + 2;
    } while (bVar1 != 0);
    iVar14 = 0;
LAB_10006887:
    if (iVar14 == 0) {
      if (*(void **)(&grim_config_var3_table + id * 0x10) != (void *)0x0) {
        operator_delete(*(void **)(&grim_config_var3_table + id * 0x10));
      }
      _DAT_1005cc94 = _strdup(&DAT_1005d828);
      DAT_1005bc14 = 0;
    }
    uVar8 = FUN_10005a40((char *)in_stack_00000014);
    DAT_1005bc14 = (undefined1)uVar8;
    if (*(void **)(&grim_config_var3_table + id * 0x10) != (void *)0x0) {
      operator_delete(*(void **)(&grim_config_var3_table + id * 0x10));
    }
    pcVar9 = _strdup((char *)in_stack_00000014);
    *(char **)(&grim_config_var3_table + id * 0x10) = pcVar9;
    *(undefined1 *)(&grim_config_var0_table + id * 4) = DAT_1005bc14;
    return;
  case 0x12:
    if (*(char *)(&grim_config_var0_table + id * 4) != (char)value) {
      (*grim_d3d_device->lpVtbl->SetRenderState)
                (grim_d3d_device,D3DRS_ALPHABLENDENABLE,value & 0xff);
      *(char *)(&grim_config_var0_table + id * 4) = (char)value;
      return;
    }
    break;
  case 0x13:
    if ((&grim_config_var0_table)[id * 4] != value) {
      (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_SRCBLEND,value);
      (&grim_config_var0_table)[id * 4] = value;
      return;
    }
    break;
  case 0x14:
    if ((&grim_config_var0_table)[id * 4] != value) {
      (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_DESTBLEND,value);
      (&grim_config_var0_table)[id * 4] = value;
      return;
    }
    break;
  case 0x15:
    if (0 < (int)value) {
      if (2 < (int)value) {
        if (value != 3) {
          return;
        }
        if ((&grim_config_var0_table)[id * 4] != 3) {
          (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MAXANISOTROPY,3)
          ;
        }
      }
      if ((&grim_config_var0_table)[id * 4] == 3) {
        (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MAXANISOTROPY,1);
      }
      (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MINFILTER,value);
      (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MAGFILTER,value);
      (&grim_config_var0_table)[id * 4] = value;
      return;
    }
    break;
  case 0x1a:
    uVar6 = grim_set_texture_stage_ops(value);
    if ((char)uVar6 == '\0') {
      return;
    }
    puVar11 = &grim_config_var0_table + id * 4;
    *puVar11 = value;
LAB_10006b54:
    puVar11[1] = in_stack_0000000c;
    puVar11[2] = in_stack_00000010;
    puVar11[3] = (uint)in_stack_00000014;
    break;
  case 0x1b:
    (&grim_config_var0_table)[id * 4] = value;
    (&grim_config_var1_table)[id * 4] = in_stack_0000000c;
    *(uint *)(&grim_config_var2_table + id * 0x10) = in_stack_00000010;
    *(byte **)(&grim_config_var3_table + id * 0x10) = in_stack_00000014;
    uVar2 = ftol();
    uVar3 = ftol();
    uVar4 = ftol();
    (*grim_d3d_device->lpVtbl->SetRenderState)
              (grim_d3d_device,D3DRS_TEXTUREFACTOR,(uint)CONCAT21(CONCAT11(uVar2,uVar3),uVar4));
    return;
  case 0x1c:
    iVar14 = 0;
    pWVar12 = DStack_600.green;
    do {
      iVar7 = ftol();
      if (iVar7 < 0x10000) {
        if (iVar7 < 0) {
          iVar7 = 0;
        }
      }
      else {
        iVar7 = 0xffff;
      }
      WVar5 = (WORD)iVar7;
      ((D3DGAMMARAMP *)(pWVar12 + -0x100))->red[0] = WVar5;
      *pWVar12 = WVar5;
      pWVar12[0x100] = WVar5;
      iVar14 = iVar14 + 1;
      pWVar12 = pWVar12 + 1;
    } while (iVar14 < 0x100);
    (*grim_d3d_device->lpVtbl->SetGammaRamp)(grim_d3d_device,1,&DStack_600);
    (&grim_config_var0_table)[id * 4] = value;
    (&grim_config_var1_table)[id * 4] = in_stack_0000000c;
    *(uint *)(&grim_config_var2_table + id * 0x10) = in_stack_00000010;
    *(byte **)(&grim_config_var3_table + id * 0x10) = in_stack_00000014;
    return;
  case 0x29:
    grim_backbuffer_width = value;
    (&grim_config_var0_table)[id * 4] = value;
    return;
  case 0x2a:
    grim_backbuffer_height = value;
    (&grim_config_var0_table)[id * 4] = value;
    return;
  case 0x2b:
    (&grim_config_var0_table)[id * 4] = value;
    grim_texture_format = (value != 0x20) + 0x16;
    return;
  case 0x2d:
    DAT_1005977c = in_stack_00000014;
    return;
  case 0x34:
    *(char *)(&grim_config_var0_table + id * 4) = (char)value;
    return;
  case 0x36:
    (*grim_d3d_device->lpVtbl->Present)
              (grim_d3d_device,(RECT *)0x0,(RECT *)0x0,(HWND)0x0,(RGNDATA *)0x0);
    return;
  case 0x52:
    (&grim_config_var0_table)[id * 4] = value;
    (&grim_config_var1_table)[id * 4] = in_stack_0000000c;
    *(uint *)(&grim_config_var2_table + id * 0x10) = in_stack_00000010;
    *(byte **)(&grim_config_var3_table + id * 0x10) = in_stack_00000014;
    DAT_1005d3fc = *(undefined4 *)in_stack_00000014;
    return;
  case 0x55:
    grim_render_disabled = (char)value;
    return;
  }
  return;
}



