/* FUN_100030b0 @ 100030b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

undefined4 FUN_100030b0(void)

{
  int *piVar1;
  HRESULT HVar2;
  ULONG UVar3;
  int iVar4;
  int extraout_EAX;
  uint uVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  int *piVar6;
  int iVar7;
  undefined4 uStack_10;
  
  uVar5 = 0;
  if (grim_d3d_device == (LPDIRECT3DDEVICE8)0x0) {
LAB_100033a0:
    return uVar5 & 0xffffff00;
  }
  HVar2 = (*grim_d3d_device->lpVtbl->TestCooperativeLevel)(grim_d3d_device);
  DAT_1005c898 = HVar2 == 0;
  if ((!(bool)DAT_1005c898) && (HVar2 == -0x7789f797)) {
    Sleep(100);
    if ((grim_render_target_surface != (LPDIRECT3DSURFACE8)0x0) &&
       (UVar3 = (*grim_render_target_surface->lpVtbl->Release)(grim_render_target_surface),
       UVar3 == 0)) {
      grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
    }
    if ((grim_backbuffer_surface != (LPDIRECT3DSURFACE8)0x0) &&
       (UVar3 = (*grim_backbuffer_surface->lpVtbl->Release)(grim_backbuffer_surface), UVar3 == 0)) {
      grim_backbuffer_surface = (LPDIRECT3DSURFACE8)0x0;
    }
    iVar7 = 0;
    if (-1 < DAT_1005305c) {
      piVar6 = &grim_texture_slots;
      do {
        iVar4 = *piVar6;
        if ((((iVar4 != 0) && (*(char *)(iVar4 + 8) != '\0')) &&
            (piVar1 = *(int **)(iVar4 + 4), piVar1 != (int *)0x0)) &&
           (iVar4 = (**(code **)(*piVar1 + 8))(piVar1), iVar4 == 0)) {
          *(undefined4 *)(*piVar6 + 4) = 0;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar7 <= DAT_1005305c);
    }
    HVar2 = (*grim_d3d_device->lpVtbl->Reset)
                      (grim_d3d_device,(D3DPRESENT_PARAMETERS *)&grim_present_width);
    if (HVar2 == 0) {
      FUN_10004520();
      iVar7 = 0;
      if (-1 < DAT_1005305c) {
        piVar6 = &grim_texture_slots;
        do {
          iVar4 = *piVar6;
          if (((iVar4 != 0) && (*(char *)(iVar4 + 8) != '\0')) &&
             (HVar2 = (*grim_d3d_device->lpVtbl->CreateTexture)
                                (grim_d3d_device,*(UINT *)(iVar4 + 0xc),*(UINT *)(iVar4 + 0x10),1,1,
                                 grim_texture_format,D3DPOOL_DEFAULT,
                                 (IDirect3DTexture8 **)(iVar4 + 4)), HVar2 < 0)) {
            grim_error_text = s_D3D__Unable_to_recreate_a_textur_100537e0;
            *(undefined4 *)(*piVar6 + 4) = 0;
            grim_noop();
            grim_noop();
          }
          iVar7 = iVar7 + 1;
          piVar6 = piVar6 + 1;
        } while (iVar7 <= DAT_1005305c);
      }
      iVar7 = grim_restore_textures();
      DAT_1005d808 = 0;
      return CONCAT31((int3)((uint)iVar7 >> 8),1);
    }
    DAT_1005d808 = DAT_1005d808 + 1;
    Sleep(500);
    HVar2 = extraout_EAX;
    if (DAT_1005d808 == 5) {
      iVar7 = 0;
      HVar2 = DAT_1005305c;
      if (DAT_1005305c < 0) goto LAB_10003396;
      piVar6 = &grim_texture_slots;
      do {
        iVar4 = *piVar6;
        if ((iVar4 != 0) && (*(char *)(iVar4 + 8) != '\0')) {
          piVar1 = *(int **)(iVar4 + 0x14);
          if ((piVar1 != (int *)0x0) && (iVar4 = (**(code **)(*piVar1 + 8))(piVar1), iVar4 == 0)) {
            *(undefined4 *)(*piVar6 + 0x14) = 0;
          }
          piVar1 = *(int **)(*piVar6 + 4);
          if ((piVar1 != (int *)0x0) && (iVar4 = (**(code **)(*piVar1 + 8))(piVar1), iVar4 == 0)) {
            *(undefined4 *)(*piVar6 + 4) = 0;
          }
          _DAT_1005d0f8 = CONCAT31((int3)((uint)unaff_ESI >> 8),1);
          _DAT_1005d104 = uStack_10;
          _DAT_1005d0fc = unaff_EBP;
          _DAT_1005d100 = unaff_EBX;
          unaff_ESI = _DAT_1005d0f8;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
        HVar2 = DAT_1005305c;
      } while (iVar7 <= DAT_1005305c);
    }
    if (6 < DAT_1005d808) {
      grim_error_text = s_D3D__Unable_to_restore_device__10053804;
      uVar5 = MessageBoxA(DAT_1005d3f8,s_D3D__Unable_to_restore_device__10053804,&DAT_10053824,5);
      if (uVar5 == 2) goto LAB_100033a0;
      iVar7 = 0;
      HVar2 = DAT_1005305c;
      if (-1 < DAT_1005305c) {
        piVar6 = &grim_texture_slots;
        do {
          iVar4 = *piVar6;
          if ((iVar4 != 0) && (*(char *)(iVar4 + 8) != '\0')) {
            piVar1 = *(int **)(iVar4 + 0x14);
            if ((piVar1 != (int *)0x0) && (iVar4 = (**(code **)(*piVar1 + 8))(piVar1), iVar4 == 0))
            {
              *(undefined4 *)(*piVar6 + 0x14) = 0;
            }
            piVar1 = *(int **)(*piVar6 + 4);
            if ((piVar1 != (int *)0x0) && (iVar4 = (**(code **)(*piVar1 + 8))(piVar1), iVar4 == 0))
            {
              *(undefined4 *)(*piVar6 + 4) = 0;
            }
            _DAT_1005d0f8 = CONCAT31((int3)((uint)unaff_ESI >> 8),1);
            _DAT_1005d104 = uStack_10;
            _DAT_1005d0fc = unaff_EBP;
            _DAT_1005d100 = unaff_EBX;
            unaff_ESI = _DAT_1005d0f8;
          }
          iVar7 = iVar7 + 1;
          piVar6 = piVar6 + 1;
          HVar2 = DAT_1005305c;
        } while (iVar7 <= DAT_1005305c);
      }
    }
  }
LAB_10003396:
  return CONCAT31((int3)((uint)HVar2 >> 8),1);
}



