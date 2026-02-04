/* FUN_10002cf0 @ 10002cf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

undefined4 FUN_10002cf0(void)

{
  int *piVar1;
  ULONG UVar2;
  int iVar3;
  HRESULT HVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  int *piVar5;
  int iVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  grim_noop();
  if ((grim_render_target_surface != (LPDIRECT3DSURFACE8)0x0) &&
     (UVar2 = (*grim_render_target_surface->lpVtbl->Release)(grim_render_target_surface), UVar2 == 0
     )) {
    grim_render_target_surface = (LPDIRECT3DSURFACE8)0x0;
  }
  if ((grim_backbuffer_surface != (LPDIRECT3DSURFACE8)0x0) &&
     (UVar2 = (*grim_backbuffer_surface->lpVtbl->Release)(grim_backbuffer_surface), UVar2 == 0)) {
    grim_backbuffer_surface = (LPDIRECT3DSURFACE8)0x0;
  }
  iVar6 = 0;
  if (-1 < DAT_1005305c) {
    piVar5 = &grim_texture_slots;
    do {
      iVar3 = *piVar5;
      if ((((iVar3 != 0) && (*(char *)(iVar3 + 8) != '\0')) &&
          (piVar1 = *(int **)(iVar3 + 4), piVar1 != (int *)0x0)) &&
         (iVar3 = (**(code **)(*piVar1 + 8))(piVar1), iVar3 == 0)) {
        *(undefined4 *)(*piVar5 + 4) = 0;
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar6 <= DAT_1005305c);
  }
  iVar6 = (*grim_d3d_device->lpVtbl->Reset)
                    (grim_d3d_device,(D3DPRESENT_PARAMETERS *)&grim_present_width);
  do {
    if (iVar6 == 0) {
      FUN_10004520();
      iVar6 = 0;
      if (-1 < DAT_1005305c) {
        piVar5 = &grim_texture_slots;
        do {
          iVar3 = *piVar5;
          if (((iVar3 != 0) && (*(char *)(iVar3 + 8) != '\0')) &&
             (HVar4 = (*grim_d3d_device->lpVtbl->CreateTexture)
                                (grim_d3d_device,*(UINT *)(iVar3 + 0xc),*(UINT *)(iVar3 + 0x10),1,1,
                                 grim_texture_format,D3DPOOL_DEFAULT,
                                 (IDirect3DTexture8 **)(iVar3 + 4)), HVar4 < 0)) {
            grim_error_text = s_D3D__Unable_to_recreate_a_textur_100537e0;
            grim_noop();
            *(undefined4 *)(*piVar5 + 4) = 0;
            Sleep(200);
          }
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar6 <= DAT_1005305c);
      }
      iVar6 = grim_restore_textures();
      if ((char)iVar6 == '\0') {
        grim_noop();
      }
      grim_noop();
      DAT_1005d808 = 0;
      return 0;
    }
    DAT_1005d808 = DAT_1005d808 + 1;
    Sleep(500);
    if (3 < DAT_1005d808) {
      grim_error_text = s_D3D__Unable_to_restore_device__10053804;
      iVar6 = MessageBoxA(DAT_1005d3f8,s_D3D__Unable_to_restore_device__10053804,&DAT_10053824,5);
      if (iVar6 == 2) {
        grim_noop();
        return 0x88760869;
      }
      iVar6 = 0;
      if (-1 < DAT_1005305c) {
        piVar5 = &grim_texture_slots;
        do {
          iVar3 = *piVar5;
          if ((iVar3 != 0) && (*(char *)(iVar3 + 8) != '\0')) {
            piVar1 = *(int **)(iVar3 + 0x14);
            if ((piVar1 != (int *)0x0) && (iVar3 = (**(code **)(*piVar1 + 8))(piVar1), iVar3 == 0))
            {
              *(undefined4 *)(*piVar5 + 0x14) = 0;
            }
            piVar1 = *(int **)(*piVar5 + 4);
            if ((piVar1 != (int *)0x0) && (iVar3 = (**(code **)(*piVar1 + 8))(piVar1), iVar3 == 0))
            {
              *(undefined4 *)(*piVar5 + 4) = 0;
            }
            _DAT_1005d0f8 = CONCAT31((int3)((uint)unaff_EBP >> 8),1);
            _DAT_1005d100 = uStack_10;
            _DAT_1005d104 = uStack_c;
            _DAT_1005d0fc = unaff_EBX;
            unaff_EBP = _DAT_1005d0f8;
          }
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar6 <= DAT_1005305c);
      }
    }
    iVar6 = (*grim_d3d_device->lpVtbl->Reset)
                      (grim_d3d_device,(D3DPRESENT_PARAMETERS *)&grim_present_width);
  } while( true );
}



