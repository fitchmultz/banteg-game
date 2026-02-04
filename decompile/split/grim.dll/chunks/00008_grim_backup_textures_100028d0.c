/* grim_backup_textures @ 100028d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* backup texture surfaces before device reset */

int grim_backup_textures(void)

{
  undefined4 extraout_EAX;
  HRESULT HVar1;
  int iVar2;
  ULONG UVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  int *piVar4;
  int iVar5;
  IDirect3DSurface8 *local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  grim_noop();
  if (DAT_1005d810 != '\0') {
    grim_noop();
    if (DAT_1005d810 != '\0') {
      return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
    }
  }
  iVar5 = 0;
  local_14 = (IDirect3DSurface8 *)0x0;
  if (-1 < DAT_1005305c) {
    piVar4 = &grim_texture_slots;
    do {
      if ((*piVar4 != 0) && (*(char *)(*piVar4 + 8) != '\0')) {
        grim_noop();
        iVar2 = *piVar4;
        HVar1 = (*grim_d3d_device->lpVtbl->CreateImageSurface)
                          (grim_d3d_device,*(UINT *)(iVar2 + 0xc),*(UINT *)(iVar2 + 0x10),
                           grim_texture_format,(IDirect3DSurface8 **)(iVar2 + 0x14));
        if (HVar1 < 0) {
          grim_error_text = s_D3D__Unable_to_backup_texture____10053678;
          grim_noop();
          grim_noop();
          return extraout_EAX_00 & 0xffffff00;
        }
        iVar2 = (**(code **)(**(int **)(*piVar4 + 4) + 0x3c))(*(int **)(*piVar4 + 4),0,&local_14);
        if (iVar2 < 0) {
          piVar4 = *(int **)((&grim_texture_slots)[iVar5] + 0x14);
          if (piVar4 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar4 + 8))(piVar4);
            if (iVar2 == 0) {
              *(undefined4 *)((&grim_texture_slots)[iVar5] + 0x14) = 0;
            }
          }
          grim_error_text = s_D3D__Unable_to_backup_texture____10053644;
          grim_noop();
          grim_noop();
          return extraout_EAX_01 & 0xffffff00;
        }
        HVar1 = (*grim_d3d_device->lpVtbl->CopyRects)
                          (grim_d3d_device,local_14,(RECT *)0x0,0,
                           *(IDirect3DSurface8 **)(*piVar4 + 0x14),(POINT *)0x0);
        if (HVar1 < 0) {
          piVar4 = *(int **)((&grim_texture_slots)[iVar5] + 0x14);
          if (piVar4 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar4 + 8))(piVar4);
            if (iVar2 == 0) {
              *(undefined4 *)((&grim_texture_slots)[iVar5] + 0x14) = 0;
            }
          }
          if (local_14 != (IDirect3DSurface8 *)0x0) {
            UVar3 = (*local_14->lpVtbl->Release)(local_14);
            if (UVar3 == 0) {
              local_14 = (IDirect3DSurface8 *)0x0;
            }
          }
          grim_error_text = s_D3D__Unable_to_backup_texture____10053618;
          grim_noop();
          uStack_10 = CONCAT31(uStack_10._1_3_,1);
          _DAT_1005d0f8 = uStack_10;
          _DAT_1005d0fc = uStack_c;
          _DAT_1005d100 = uStack_8;
          _DAT_1005d104 = uStack_4;
          if (HVar1 == -0x7789f798) {
            grim_noop();
            return extraout_EAX_02 & 0xffffff00;
          }
          if (HVar1 == -0x7789f794) {
            grim_noop();
            return extraout_EAX_03 & 0xffffff00;
          }
          grim_noop();
          return extraout_EAX_04 & 0xffffff00;
        }
        if (local_14 != (IDirect3DSurface8 *)0x0) {
          UVar3 = (*local_14->lpVtbl->Release)(local_14);
          if (UVar3 == 0) {
            local_14 = (IDirect3DSurface8 *)0x0;
          }
        }
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 <= DAT_1005305c);
  }
  DAT_1005d810 = '\x01';
  return CONCAT31((int3)((uint)DAT_1005305c >> 8),1);
}



