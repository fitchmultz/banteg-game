/* grim_create_texture @ 100075d0 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xac: create blank texture in a free slot */

int grim_create_texture(char *name,int width,int height)

{
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  void *unaff_EDI;
  LPDIRECT3DDEVICE8 name_00;
  undefined4 uVar4;
  void *pvVar5;
  IDirect3DTexture8 *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_1004b82b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = grim_find_free_texture_slot();
  if ((int)uVar1 < 0) {
    ExceptionList = local_c;
    return uVar1 & 0xffffff00;
  }
  pvVar5 = (void *)0x1;
  uVar4 = 1;
  name_00 = grim_d3d_device;
  uVar2 = (*grim_d3d_device->lpVtbl->CreateTexture)
                    (grim_d3d_device,width,height,1,1,grim_texture_format,D3DPOOL_DEFAULT,&local_10)
  ;
  if ((int)uVar2 < 0) {
    grim_error_text = s_D3D__Could_not_create_a_texture__10053c18;
    ExceptionList = pvVar5;
    return uVar2 & 0xffffff00;
  }
  pvVar3 = operator_new(0x18);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = grim_texture_init(pvVar3,unaff_EDI,(char *)name_00);
  }
  (&grim_texture_slots)[uVar1] = pvVar3;
  *(undefined4 *)((int)pvVar3 + 4) = uVar4;
  *(undefined1 *)((&grim_texture_slots)[uVar1] + 8) = 1;
  *(int *)((&grim_texture_slots)[uVar1] + 0xc) = width;
  *(int *)((&grim_texture_slots)[uVar1] + 0x10) = height;
  uVar2 = DAT_1005305c;
  if ((int)DAT_1005305c < (int)uVar1) {
    DAT_1005305c = uVar1;
  }
  ExceptionList = pvVar5;
  return CONCAT31((int3)(uVar2 >> 8),1);
}



