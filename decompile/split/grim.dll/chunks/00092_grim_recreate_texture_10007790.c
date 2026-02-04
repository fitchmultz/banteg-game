/* grim_recreate_texture @ 10007790 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xb0: recreate D3D texture surface */

int grim_recreate_texture(int handle)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  
  iVar2 = (&grim_texture_slots)[handle];
  if (iVar2 == 0) {
    return 0;
  }
  uVar1 = FUN_1000b297(*(void **)(iVar2 + 0x10),(int **)grim_d3d_device,*(int *)(iVar2 + 0xc),
                       (int)*(void **)(iVar2 + 0x10),1);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffff00;
  }
  iVar2 = FUN_1000b3fe((int *)handle,*(int **)((&grim_texture_slots)[handle] + 4),0,0,2.24208e-44);
  if (iVar2 < 0) {
    uVar1 = (**(code **)(*(int *)handle + 8))(handle);
    return uVar1 & 0xffffff00;
  }
  (**(code **)(**(int **)((&grim_texture_slots)[handle] + 4) + 8))
            (*(int **)((&grim_texture_slots)[handle] + 4));
  *(undefined4 *)((&grim_texture_slots)[handle] + 4) = unaff_retaddr;
  return CONCAT31((int3)((uint)unaff_retaddr >> 8),1);
}



