/* grim_load_texture_internal @ 100051e0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* allocates texture slot and loads file */

int grim_load_texture_internal(char *name,ushort *path)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  uint extraout_EAX;
  ushort *unaff_EDI;
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &DAT_1004b80b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = grim_find_free_texture_slot();
  if (iVar2 == -1) {
    grim_error_text = s_All_texture_slots_are_used__10053b60;
    ExceptionList = local_c;
    return -0x100;
  }
  uVar3 = grim_find_texture_by_name(name);
  if (uVar3 != 0xffffffff) {
    grim_error_text = s_D3D__Texture_slot_not_free__10053b44;
    ExceptionList = local_c;
    return uVar3 & 0xffffff00;
  }
  pvVar4 = operator_new(0x18);
  local_4 = 0;
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    pvVar4 = grim_texture_init(pvVar4,name,(char *)unaff_EDI);
  }
  local_4 = 0xffffffff;
  uVar3 = grim_texture_load_file(pvVar4,path,unaff_EDI);
  iVar1 = DAT_1005305c;
  if ((char)uVar3 == '\0') {
    grim_error_text = s_D3D__Could_not_load_a_texture__10053b24;
    if (pvVar4 != (void *)0x0) {
      grim_texture_release(pvVar4);
      operator_delete(pvVar4);
      uVar3 = extraout_EAX;
    }
    ExceptionList = local_c;
    return uVar3 & 0xffffff00;
  }
  (&grim_texture_slots)[iVar2] = pvVar4;
  if (iVar1 < iVar2) {
    DAT_1005305c = iVar2;
  }
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



