/* FUN_10004350 @ 10004350 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

uint FUN_10004350(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  HRESULT HVar4;
  
  grim_vertex_capacity = 0x100;
  uVar3 = (*grim_d3d_device->lpVtbl->CreateVertexBuffer)
                    (grim_d3d_device,0x1c00,0x218,0,D3DPOOL_SYSTEMMEM,&grim_vertex_buffer);
  if ((int)uVar3 < 0) {
    grim_error_text = s_D3D__Internal__Could_not_create_v_10053ac4;
    return uVar3 & 0xffffff00;
  }
  HVar4 = (*grim_d3d_device->lpVtbl->CreateIndexBuffer)
                    (grim_d3d_device,grim_vertex_capacity * 0xc,0x218,D3DFMT_INDEX16,
                     D3DPOOL_SYSTEMMEM,&DAT_10059bb8);
  if (-1 < HVar4) {
    uVar3 = (*DAT_10059bb8->lpVtbl->Lock)(DAT_10059bb8,0,0,(BYTE **)&DAT_1005b2c0,0x2000);
    if (-1 < (int)uVar3) {
      if (grim_vertex_capacity != 0) {
        sVar2 = 2;
        do {
          *DAT_1005b2c0 = sVar2 + -2;
          DAT_1005b2c0 = DAT_1005b2c0 + 1;
          *DAT_1005b2c0 = sVar2 + -1;
          DAT_1005b2c0 = DAT_1005b2c0 + 1;
          *DAT_1005b2c0 = sVar2;
          DAT_1005b2c0 = DAT_1005b2c0 + 1;
          *DAT_1005b2c0 = sVar2;
          DAT_1005b2c0 = DAT_1005b2c0 + 1;
          *DAT_1005b2c0 = sVar2 + 1;
          DAT_1005b2c0 = DAT_1005b2c0 + 1;
          *DAT_1005b2c0 = sVar2 + -2;
          DAT_1005b2c0 = DAT_1005b2c0 + 1;
          uVar1 = sVar2 + 2;
          sVar2 = sVar2 + 4;
        } while (uVar1 < grim_vertex_capacity);
      }
      (*DAT_10059bb8->lpVtbl->Unlock)(DAT_10059bb8);
      (*grim_d3d_device->lpVtbl->SetStreamSource)(grim_d3d_device,0,grim_vertex_buffer,0x1c);
      HVar4 = (*grim_d3d_device->lpVtbl->SetIndices)(grim_d3d_device,DAT_10059bb8,0);
      return CONCAT31((int3)((uint)HVar4 >> 8),1);
    }
    DAT_1005c898 = 0;
    return uVar3 & 0xffffff00;
  }
  grim_error_text = s_D3D__Internal__Could_not_create_i_10053a94;
  uVar3 = FUN_100044e0();
  return uVar3 & 0xffffff00;
}



