/* grim_draw_rect_outline @ 10008f10 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xd4: UI panel outline/frame (4 edge quads) */

void grim_draw_rect_outline(float *xy,float w,float h)

{
  int *in_ECX;
  int iVar1;
  float *unaff_retaddr;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  
  (*grim_d3d_device->lpVtbl->SetTexture)(grim_d3d_device,0,(IDirect3DBaseTexture8 *)0x0);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,3);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,3);
  uVar4 = 0;
  (**(code **)(*in_ECX + 0xfc))(0);
  (**(code **)(*in_ECX + 0xe8))();
  if (w == 1.0) {
    iVar1 = *in_ECX;
    w = 1.0;
  }
  else {
    if ((float)xy != 1.0) {
      fVar3 = unaff_retaddr[1];
      (**(code **)(*in_ECX + 0x11c))(*unaff_retaddr,fVar3,xy,0x3f800000);
      fVar2 = unaff_retaddr[1];
      (**(code **)(*in_ECX + 0x11c))(*unaff_retaddr,fVar2,0x3f800000,uVar4);
      (**(code **)(*in_ECX + 0x11c))
                (*unaff_retaddr,(float)xy + unaff_retaddr[1],fVar3 + 1.0,0x3f800000);
      (**(code **)(*in_ECX + 0x11c))(fVar2 + *unaff_retaddr,unaff_retaddr[1],0x3f800000,uVar4);
      goto LAB_1000903e;
    }
    iVar1 = *in_ECX;
    xy = (float *)0x3f800000;
  }
  (**(code **)(iVar1 + 0x11c))(*unaff_retaddr,unaff_retaddr[1],xy,w);
LAB_1000903e:
  (**(code **)(*in_ECX + 0xf0))();
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,4);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,4);
  return;
}



