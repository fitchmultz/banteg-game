/* grim_pixel_format_init_dxt @ 1001ac4a */

/* initializes DXT block-compressed pixel format (DXT1..DXT5) */

void * __thiscall grim_pixel_format_init_dxt(void *this,uint *desc)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 1;
  grim_pixel_format_init(this,desc,0,1);
  *(undefined ***)this = &PTR_FUN_1004caf8;
  if (desc[6] == 1) {
    *(undefined4 *)((int)this + 0x1078) = 0;
  }
  else if (desc[6] == 2) {
    *(undefined4 *)((int)this + 0x1078) = 1;
  }
  else {
    *(undefined4 *)((int)this + 0x1078) = 3;
  }
  if (desc[7] == 1) {
    *(undefined4 *)((int)this + 0x107c) = 0;
  }
  else if (desc[7] == 2) {
    *(undefined4 *)((int)this + 0x107c) = 1;
  }
  else {
    *(undefined4 *)((int)this + 0x107c) = 3;
  }
  if ((*(int *)((int)this + 0x1078) == 3) && (*(int *)((int)this + 0x107c) == 3)) {
    uVar4 = 0;
  }
  *(undefined4 *)((int)this + 0x1074) = uVar4;
  iVar1 = *(int *)((int)this + 4);
  if (iVar1 == 0x31545844) {
    *(undefined4 *)((int)this + 0x1080) = 8;
    *(undefined1 **)((int)this + 0x1088) = &LAB_10021b96;
    *(code **)((int)this + 0x1084) = grim_dxt1_decode_color_block;
  }
  else if (iVar1 == 0x32545844) {
    *(undefined4 *)((int)this + 0x1080) = 0x10;
    *(code **)((int)this + 0x1088) = grim_dxt2_encode_block;
    *(undefined1 **)((int)this + 0x1084) = &grim_dxt2_decode_block;
  }
  else if (iVar1 == 0x33545844) {
    *(undefined4 *)((int)this + 0x1080) = 0x10;
    *(code **)((int)this + 0x1088) = grim_dxt3_encode_block;
    *(code **)((int)this + 0x1084) = grim_dxt3_decode_block;
  }
  else if (iVar1 == 0x34545844) {
    *(undefined4 *)((int)this + 0x1080) = 0x10;
    *(code **)((int)this + 0x1088) = grim_dxt4_encode_block;
    *(undefined1 **)((int)this + 0x1084) = &grim_dxt4_decode_block;
  }
  else if (iVar1 == 0x35545844) {
    *(undefined4 *)((int)this + 0x1080) = 0x10;
    *(code **)((int)this + 0x1088) = grim_dxt5_encode_block;
    *(code **)((int)this + 0x1084) = grim_dxt5_decode_block;
  }
  *(undefined4 *)((int)this + 0x10b0) = 0xffffffff;
  *(undefined4 *)((int)this + 0x10b4) = 0xffffffff;
  *(undefined4 *)((int)this + 0x109c) = *(undefined4 *)((int)this + 0x1040);
  uVar2 = *(int *)((int)this + 0x1038) + 3U & 0xfffffffc;
  uVar6 = *(uint *)((int)this + 0x1030) & 0xfffffffc;
  *(uint *)((int)this + 0x1094) = uVar2;
  uVar5 = *(uint *)((int)this + 0x1034) & 0xfffffffc;
  uVar3 = *(int *)((int)this + 0x103c) + 3U & 0xfffffffc;
  *(uint *)((int)this + 0x1098) = uVar3;
  *(uint *)((int)this + 0x10a4) = uVar2 - uVar6 >> 2;
  *(int *)((int)this + 0x10a0) = *(int *)((int)this + 0x1044);
  *(uint *)((int)this + 0x108c) = uVar6;
  *(undefined4 *)((int)this + 0x10b8) = 0;
  *(undefined4 *)((int)this + 0x10bc) = 0;
  *(undefined4 *)((int)this + 0x10c0) = 0;
  *(uint *)((int)this + 0x1090) = uVar5;
  *(uint *)((int)this + 0x10a8) = uVar3 - uVar5 >> 2;
  *(int *)((int)this + 0x10ac) = *(int *)((int)this + 0x1044) - *(int *)((int)this + 0x1040);
  return this;
}



