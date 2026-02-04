/* grim_restore_textures @ 10002b40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* restore texture surfaces after device reset */

int grim_restore_textures(void)

{
  int *piVar1;
  uint in_EAX;
  uint extraout_EAX;
  int iVar2;
  HRESULT HVar3;
  ULONG UVar4;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  int *piVar5;
  int iVar6;
  IDirect3DSurface8 *local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (DAT_1005d804 != '\0') {
    return in_EAX & 0xffffff00;
  }
  grim_noop();
  if (DAT_1005d810 == '\0') {
    grim_noop();
    if (DAT_1005d810 == '\0') {
      return extraout_EAX & 0xffffff00;
    }
  }
  iVar6 = 0;
  local_14 = (IDirect3DSurface8 *)0x0;
  if (-1 < DAT_1005305c) {
    piVar5 = &grim_texture_slots;
    do {
      iVar2 = *piVar5;
      if (((iVar2 != 0) && (*(char *)(iVar2 + 8) != '\0')) && (*(int *)(iVar2 + 0x14) != 0)) {
        grim_noop();
        piVar1 = *(int **)(*piVar5 + 4);
        if (piVar1 != (int *)0x0) {
          iVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,0,&local_14);
          if (iVar2 < 0) {
            grim_error_text = s_D3D__Unable_to_recreate_texture__10053704;
            grim_noop();
            return extraout_EAX_00 & 0xffffff00;
          }
        }
        HVar3 = (*grim_d3d_device->lpVtbl->CopyRects)
                          (grim_d3d_device,*(IDirect3DSurface8 **)(*piVar5 + 0x14),(RECT *)0x0,0,
                           local_14,(POINT *)0x0);
        if (HVar3 < 0) {
          if (local_14 != (IDirect3DSurface8 *)0x0) {
            UVar4 = (*local_14->lpVtbl->Release)(local_14);
            if (UVar4 == 0) {
              local_14 = (IDirect3DSurface8 *)0x0;
            }
          }
          piVar5 = *(int **)((&grim_texture_slots)[iVar6] + 0x14);
          if (piVar5 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar5 + 8))(piVar5);
            if (iVar2 == 0) {
              *(undefined4 *)((&grim_texture_slots)[iVar6] + 0x14) = 0;
            }
          }
          uStack_10 = CONCAT31(uStack_10._1_3_,1);
          _DAT_1005d0f8 = uStack_10;
          DAT_1005d810 = 0;
          grim_error_text = s_D3D__Unable_to_restore_texture____100536d8;
          _DAT_1005d0fc = uStack_c;
          _DAT_1005d100 = uStack_8;
          _DAT_1005d104 = uStack_4;
          grim_noop();
          return extraout_EAX_01 & 0xffffff00;
        }
        if (local_14 != (IDirect3DSurface8 *)0x0) {
          UVar4 = (*local_14->lpVtbl->Release)(local_14);
          if (UVar4 == 0) {
            local_14 = (IDirect3DSurface8 *)0x0;
          }
        }
        piVar1 = *(int **)(*piVar5 + 0x14);
        if (piVar1 != (int *)0x0) {
          iVar2 = (**(code **)(*piVar1 + 8))(piVar1);
          if (iVar2 == 0) {
            *(undefined4 *)(*piVar5 + 0x14) = 0;
          }
        }
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar6 <= DAT_1005305c);
  }
  DAT_1005d810 = 0;
  return CONCAT31((int3)((uint)DAT_1005305c >> 8),1);
}



