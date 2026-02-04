/* FUN_10004520 @ 10004520 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

void FUN_10004520(void)

{
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_LIGHTING,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_SPECULARENABLE,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_ZENABLE,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_ZWRITEENABLE,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_FOGENABLE,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_NORMALIZENORMALS,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_CULLMODE,1);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_SHADEMODE,2);
  (*grim_d3d_device->lpVtbl->SetRenderState)
            (grim_d3d_device,D3DRS_DITHERENABLE,_DAT_1005d108 & 0xff);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_ALPHATESTENABLE,1);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_ALPHAFUNC,7);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_ALPHAREF,4);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MINFILTER,2);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MAGFILTER,2);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_MIPFILTER,0);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLOROP,4);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG1,2);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_COLORARG2,0);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAOP,4);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG1,2);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_ALPHAARG2,0);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_COLOROP,1);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_ALPHAOP,1);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,0,D3DTSS_TEXCOORDINDEX,0);
  (*grim_d3d_device->lpVtbl->SetTextureStageState)(grim_d3d_device,1,D3DTSS_TEXCOORDINDEX,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_WRAP0,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_WRAP1,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_WRAP2,0);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_WRAP3,0);
  (*grim_d3d_device->lpVtbl->SetStreamSource)(grim_d3d_device,0,grim_vertex_buffer,0x1c);
  (*grim_d3d_device->lpVtbl->SetIndices)(grim_d3d_device,DAT_10059bb8,0);
  (*grim_d3d_device->lpVtbl->SetVertexShader)(grim_d3d_device,0x144);
  (*grim_d3d_device->lpVtbl->SetRenderState)
            (grim_d3d_device,D3DRS_ALPHABLENDENABLE,DAT_1005cca8 & 0xff);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_SRCBLEND,DAT_1005ccb8);
  (*grim_d3d_device->lpVtbl->SetRenderState)(grim_d3d_device,D3DRS_DESTBLEND,DAT_1005ccc8);
  return;
}



