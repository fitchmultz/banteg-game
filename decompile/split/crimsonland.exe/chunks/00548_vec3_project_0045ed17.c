/* vec3_project @ 0045ed17 */

/* projects a vec3 through optional matrices and viewport scale/bias */

float * vec3_project(float *out,float *vec,float *viewport,float *world,float *view,float *proj)

{
  float *mat;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar6;
  undefined8 uVar5;
  float local_44 [16];
  
  mat = local_44;
  switch(((proj != (float *)0x0) << 1 | view != (float *)0x0) << 1 | world != (float *)0x0) {
  case '\0':
    local_44[0xe] = 0.0;
    local_44[0xd] = 0.0;
    local_44[0xc] = 0.0;
    local_44[0xb] = 0.0;
    local_44[9] = 0.0;
    local_44[8] = 0.0;
    local_44[7] = 0.0;
    local_44[6] = 0.0;
    local_44[4] = 0.0;
    local_44[3] = 0.0;
    local_44[2] = 0.0;
    local_44[1] = 0.0;
    local_44[0xf] = 1.0;
    local_44[10] = 1.0;
    local_44[5] = 1.0;
    local_44[0] = 1.0;
    break;
  case '\x01':
    mat = world;
    break;
  case '\x02':
    mat = view;
    break;
  case '\x03':
    FastExitMediaState();
    mat4_mul(local_44,view,world);
    FastExitMediaState();
    break;
  case '\x04':
    mat = proj;
    break;
  case '\x05':
    FastExitMediaState();
    mat4_mul(local_44,proj,world);
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    mat4_mul(local_44,proj,view);
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    mat4_mul(local_44,proj,view);
    mat4_mul(local_44,local_44,world);
    FastExitMediaState();
  }
  vec3_transform_coord(out,vec,mat);
  if (viewport != (float *)0x0) {
    FastExitMediaState();
    uVar2 = *(undefined8 *)(viewport + 4);
    uVar3 = PackedIntToFloatingDwordConv(*(undefined8 *)viewport,*(undefined8 *)viewport);
    uVar4 = PackedIntToFloatingDwordConv
                      (*(undefined8 *)(viewport + 2),*(undefined8 *)(viewport + 2));
    uVar1 = PackedFloatingADD(*(ulonglong *)out ^ 0x8000000000000000,0x3f8000003f800000);
    uVar4 = PackedFloatingMUL(uVar4,0x3f0000003f000000);
    uVar6 = (undefined4)((ulonglong)uVar2 >> 0x20);
    uVar5 = PackedFloatingSUB(CONCAT44(uVar6,uVar6),uVar2);
    uVar1 = PackedFloatingMUL(uVar1,uVar4);
    uVar4 = PackedFloatingMUL((ulonglong)(uint)out[2],uVar5);
    uVar4 = PackedFloatingADD(uVar4,uVar2);
    uVar2 = PackedFloatingADD(uVar1,uVar3);
    *(undefined8 *)out = uVar2;
    out[2] = (float)uVar4;
    FastExitMediaState();
  }
  return out;
}



