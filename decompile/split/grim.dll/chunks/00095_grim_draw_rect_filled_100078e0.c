/* grim_draw_rect_filled @ 100078e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xd0: UI panel fill/quad */

void grim_draw_rect_filled(float *xy,float w,float h)

{
  int *in_ECX;
  int in_stack_00000010;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (0.0 < *(float *)(in_stack_00000010 + 0xc)) {
    (*grim_d3d_device->lpVtbl->SetTexture)(grim_d3d_device,0,(IDirect3DBaseTexture8 *)0x0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,3);
    uVar3 = 3;
    uVar2 = 4;
    puVar1 = (undefined4 *)0x0;
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,3);
    (**(code **)(*in_ECX + 0x110))();
    (**(code **)(*in_ECX + 0xfc))(0);
    (**(code **)(*in_ECX + 0xe8))();
    (**(code **)(*in_ECX + 0x11c))(*puVar1,puVar1[1],uVar2,uVar3);
    (**(code **)(*in_ECX + 0xf0))();
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,4);
  }
  return;
}



