/* effects_render @ 0042e820 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* renders active effects (rotated quads) */

void effects_render(void)

{
  undefined1 uVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  longlong lVar5;
  undefined2 uVar7;
  undefined3 uVar6;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  
  fStack_40 = 6.144453e-39;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  (*grim_interface_ptr->vtable->grim_bind_texture)((int)particles_texture,0);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  iVar2 = 0x4ab364;
  do {
    if (((*(uint *)(iVar2 + -8) != 0) && (0.0 <= *(float *)(iVar2 + -0x10))) &&
       ((*(uint *)(iVar2 + -8) & 0x40) != 0)) {
      fStack_44 = *(float *)(iVar2 + -0x20);
      fcos((float10)fStack_44);
      fsin((float10)fStack_44);
      lVar5 = __ftol();
      uVar1 = (undefined1)lVar5;
      lVar5 = __ftol();
      uVar7 = CONCAT11(uVar1,(char)lVar5);
      lVar5 = __ftol();
      uVar6 = CONCAT21(uVar7,(char)lVar5);
      lVar5 = __ftol();
      fStack_40 = _camera_offset_x + *(float *)(iVar2 + -0x34);
      fStack_48 = (float)CONCAT31(uVar6,(char)lVar5);
      (*grim_interface_ptr->vtable->grim_submit_vertices_transform_color)
                ((float *)(iVar2 + 0x14),4,&fStack_40,(float *)&stack0xffffffc8,&fStack_48);
    }
    iVar2 = iVar2 + 0xbc;
  } while (iVar2 < 0x4c2b64);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,2);
  (*grim_interface_ptr->vtable->grim_begin_batch)();
  iVar2 = 0x4ab364;
  do {
    if (((*(uint *)(iVar2 + -8) != 0) && (0.0 <= *(float *)(iVar2 + -0x10))) &&
       ((*(uint *)(iVar2 + -8) & 0x40) == 0)) {
      fVar3 = (float10)fcos((float10)*(float *)(iVar2 + -0x20));
      fVar4 = (float10)fsin((float10)*(float *)(iVar2 + -0x20));
      fStack_48 = (float)-fVar4 * *(float *)(iVar2 + -0x1c);
      fStack_44 = (float)fVar4 * *(float *)(iVar2 + -0x1c);
      fStack_40 = (float)(fVar3 * (float10)*(float *)(iVar2 + -0x1c));
      __ftol();
      __ftol();
      __ftol();
      __ftol();
      (*grim_interface_ptr->vtable->grim_submit_vertices_transform_color)
                ((float *)(iVar2 + 0x14),4,(float *)&stack0xffffffac,(float *)&stack0xffffffb4,
                 (float *)&stack0xffffffa4);
    }
    iVar2 = iVar2 + 0xbc;
  } while (iVar2 < 0x4c2b64);
  (*grim_interface_ptr->vtable->grim_end_batch)();
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  return;
}



