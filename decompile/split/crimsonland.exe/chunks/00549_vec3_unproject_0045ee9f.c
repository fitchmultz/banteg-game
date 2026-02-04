/* vec3_unproject @ 0045ee9f */

/* unprojects a screen-space vec3 using inverse matrices and viewport */

float * vec3_unproject(float *out,float *vec,float *viewport,float *world,float *view,float *proj)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 uVar7;
  undefined8 uVar6;
  undefined8 uVar8;
  unkbyte10 in_ST5;
  undefined8 uVar9;
  unkbyte10 in_ST6;
  float local_44 [16];
  
  uVar2 = (undefined8)in_ST5;
  uVar9 = (undefined8)in_ST6;
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
    FastExitMediaState();
    mat4_invert(local_44,(float *)0x0,world);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x02':
    FastExitMediaState();
    mat4_invert(local_44,(float *)0x0,view);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x03':
    FastExitMediaState();
    mat4_mul(local_44,view,world);
    mat4_invert(local_44,(float *)0x0,local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x04':
    FastExitMediaState();
    mat4_invert(local_44,(float *)0x0,proj);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x05':
    FastExitMediaState();
    mat4_mul(local_44,proj,world);
    mat4_invert(local_44,(float *)0x0,local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\x06':
    FastExitMediaState();
    mat4_mul(local_44,proj,view);
    mat4_invert(local_44,(float *)0x0,local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
    break;
  case '\a':
    FastExitMediaState();
    mat4_mul(local_44,proj,view);
    mat4_mul(local_44,local_44,world);
    mat4_invert(local_44,(float *)0x0,local_44);
    uVar2 = (undefined8)in_ST5;
    uVar9 = (undefined8)in_ST6;
    FastExitMediaState();
  }
  if (viewport != (float *)0x0) {
    FastExitMediaState();
    uVar4 = PackedIntToFloatingDwordConv(*(undefined8 *)viewport,*(undefined8 *)viewport);
    uVar1 = *(undefined8 *)(viewport + 4);
    uVar5 = PackedIntToFloatingDwordConv
                      (*(undefined8 *)(viewport + 2),*(undefined8 *)(viewport + 2));
    uVar7 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar6 = CONCAT44(uVar7,uVar7);
    uVar8 = FloatingReciprocalAprox(uVar2,uVar5);
    uVar6 = FloatingReciprocalAprox(uVar6,uVar6);
    uVar2 = PackedFloatingSUB(*(undefined8 *)vec,uVar4);
    uVar6 = CONCAT44((int)uVar6,(int)uVar8);
    uVar4 = PackedFloatingReciprocalIter1(uVar5,uVar6);
    uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar6);
    uVar4 = PackedFloatingMUL(uVar4,0x4000000040000000);
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
    uVar7 = (undefined4)((ulonglong)uVar1 >> 0x20);
    uVar3 = PackedFloatingSUB(uVar2,0x3f8000003f800000);
    uVar2 = PackedFloatingSUB(CONCAT44(uVar7,uVar7),uVar1);
    uVar9 = FloatingReciprocalAprox(uVar9,uVar2);
    uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar9);
    uVar9 = PackedFloatingReciprocalIter2(uVar2,uVar9);
    uVar2 = PackedFloatingSUB((ulonglong)(uint)vec[2],uVar1);
    uVar2 = PackedFloatingMUL(uVar2,uVar9);
    *(ulonglong *)out = uVar3 ^ 0x8000000000000000;
    out[2] = (float)uVar2;
    FastExitMediaState();
    vec = out;
  }
  vec3_transform_coord(out,vec,local_44);
  return out;
}



