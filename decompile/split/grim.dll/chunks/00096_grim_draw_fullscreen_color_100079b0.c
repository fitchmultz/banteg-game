/* grim_draw_fullscreen_color @ 100079b0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xcc: fullscreen color/fade overlay */

void grim_draw_fullscreen_color(float r,float g,float b,float a)

{
  int *in_ECX;
  LPDIRECT3DDEVICE8 pIVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (0.0 < a) {
    (*grim_d3d_device->lpVtbl->SetTexture)(grim_d3d_device,0,(IDirect3DBaseTexture8 *)0x0);
    uVar4 = 3;
    uVar3 = 1;
    uVar2 = 0;
    pIVar1 = grim_d3d_device;
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,3);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,3);
    (**(code **)(*in_ECX + 0x114))(pIVar1,uVar2,uVar3,uVar4);
    (**(code **)(*in_ECX + 0xfc))(0);
    (**(code **)(*in_ECX + 0xe8))();
    (**(code **)(*in_ECX + 0x11c))(0,0,(float)grim_backbuffer_width,(float)grim_backbuffer_height);
    (**(code **)(*in_ECX + 0xf0))();
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,4);
  }
  return;
}



