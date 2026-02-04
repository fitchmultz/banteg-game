/* grim_texture_load_file @ 10004ec0 */

/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* loads texture data from file path */

int __thiscall grim_texture_load_file(void *this,void *texture,ushort *path)

{
  undefined4 *arg14;
  bool bVar1;
  uint in_EAX;
  void **arg2;
  FILE *_File;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint3 uVar5;
  char *pcVar6;
  bool bVar7;
  int iStack_2c;
  void *local_28;
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (texture == (void *)0x0) {
    return in_EAX & 0xffffff00;
  }
  piVar3 = *(int **)((int)this + 4);
  arg14 = (undefined4 *)((int)this + 4);
  local_28 = this;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  *arg14 = 0;
  pcVar6 = (char *)0x0;
  bVar7 = false;
  if (DAT_1005bc14 != '\0') {
    pcVar6 = (char *)FUN_10005ae0(texture);
    bVar7 = pcVar6 != (char *)0x0;
  }
  bVar1 = FUN_10004b00(texture,&DAT_10053b20);
  if (!bVar1) {
    if ((DAT_1005bc14 != '\0') && (bVar7)) {
      piVar3 = (int *)FUN_10005b80(texture);
      iVar4 = FUN_1000cb5c((int **)grim_d3d_device,pcVar6,piVar3,-1,-1,1,0,
                           grim_preferred_texture_format,1,-1,(int **)0xffffffff,0,(int)&uStack_1c,0
                           ,(int)arg14);
      uVar5 = (uint3)((uint)iVar4 >> 8);
      if (-1 < iVar4) {
        *(undefined4 *)((int)this + 0xc) = uStack_1c;
        *(undefined4 *)((int)this + 0x10) = uStack_18;
        return CONCAT31(uVar5,1);
      }
      *arg14 = 0;
      return (uint)uVar5 << 8;
    }
    uVar2 = FUN_1000cb9c((int **)grim_d3d_device,texture,-1,-1,1,0,grim_preferred_texture_format,1,
                         -1,(int **)0xffffffff,0,(int)&uStack_1c,0,(int)arg14);
    if (-1 < (int)uVar2) {
      *(undefined4 *)((int)this + 0xc) = uStack_1c;
      *(undefined4 *)((int)this + 0x10) = uStack_18;
      return CONCAT31((int3)((uint)uStack_1c >> 8),1);
    }
    *arg14 = 0;
    return uVar2 & 0xffffff00;
  }
  if ((DAT_1005bc14 == '\0') || (!bVar7)) {
    _File = fopen(texture,&DAT_10053244);
    if (_File == (FILE *)0x0) {
      return 0;
    }
    fseek(_File,0,2);
    arg2 = (void **)ftell(_File);
    fseek(_File,0,0);
    pcVar6 = operator_new((uint)arg2);
    fread(pcVar6,(size_t)arg2,1,_File);
    fclose(_File);
  }
  else {
    arg2 = (void **)FUN_10005b80(texture);
  }
  pcVar6 = FUN_10004b70(pcVar6,arg2,(int *)&piStack_20,&iStack_2c);
  uVar2 = 0;
  if (pcVar6 != (char *)0x0) {
    *(int *)((int)local_28 + 0xc) = iStack_2c;
    *(undefined4 *)((int)local_28 + 0x10) = uStack_24;
    uVar2 = FUN_1000cb5c((int **)grim_d3d_device,pcVar6,piStack_20,-1,-1,1,0,
                         grim_preferred_texture_format,1,-1,(int **)0xffffffff,0,(int)&uStack_1c,0,
                         (int)arg14);
    if ((int)uVar2 < 0) {
      *arg14 = 0;
      return uVar2 & 0xffffff00;
    }
  }
  return CONCAT31((int3)(uVar2 >> 8),1);
}



