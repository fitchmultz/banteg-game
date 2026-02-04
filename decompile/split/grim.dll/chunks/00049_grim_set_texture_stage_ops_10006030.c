/* grim_set_texture_stage_ops @ 10006030 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* sets D3D texture stage states for a small set of blend modes (mode 0..3) */

uint __cdecl grim_set_texture_stage_ops(uint mode)

{
  HRESULT HVar1;
  
  switch(mode) {
  case 0:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,3);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,3);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  case 1:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  case 2:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLORARG2,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAARG2,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,2,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,2,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  case 3:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,7);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,7);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLORARG2,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,4);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAARG2,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,2,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,2,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  case 4:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,0x18);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,3);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  case 5:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,0x18);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,0);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  case 6:
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,0x18);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLORARG1,2);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLORARG2,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,1);
    (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,2,D3DTSS_COLOROP,1);
    HVar1 = (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,2,D3DTSS_ALPHAOP,1);
    return CONCAT31((int3)((uint)HVar1 >> 8),1);
  default:
    return mode & 0xffffff00;
  }
}



