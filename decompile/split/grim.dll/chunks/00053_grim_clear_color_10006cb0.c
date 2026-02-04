/* grim_clear_color @ 10006cb0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0x2c: packs RGBA into device clear color */

void grim_clear_color(float r,float g,float b,float a)

{
  IDirect3DDevice8Vtbl *pIVar1;
  LPDIRECT3DDEVICE8 This;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  float z;
  DWORD stencil;
  
  This = grim_d3d_device;
  if ((grim_render_disabled == '\0') && (DAT_1005c898 != '\0')) {
    stencil = 0;
    z = 0.0;
    pIVar1 = grim_d3d_device->lpVtbl;
    uVar2 = ftol();
    iVar3 = ftol();
    uVar4 = ftol();
    uVar5 = ftol();
    (*pIVar1->Clear)(This,0,(D3DRECT *)0x0,1,
                     ((uVar2 & 0xff | iVar3 << 8) << 8 | uVar4 & 0xff) << 8 | uVar5 & 0xff,z,stencil
                    );
  }
  return;
}



