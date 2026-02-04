/* vec3_transform_coord @ 0045eac0 */

/* transforms a vec3 by a matrix and divides by W (perspective) */

float * vec3_transform_coord(float *out,float *vec,float *mat)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  FastExitMediaState();
  uVar1 = (undefined4)*(undefined8 *)vec;
  uVar4 = CONCAT44(uVar1,uVar1);
  uVar1 = (undefined4)((ulonglong)*(undefined8 *)vec >> 0x20);
  uVar7 = CONCAT44(uVar1,uVar1);
  uVar8 = CONCAT44(vec[2],vec[2]);
  uVar2 = PackedFloatingMUL(uVar4,*(undefined8 *)mat);
  uVar3 = PackedFloatingMUL(uVar7,*(undefined8 *)(mat + 4));
  uVar5 = PackedFloatingMUL(uVar8,*(undefined8 *)(mat + 8));
  uVar2 = PackedFloatingADD(uVar2,*(undefined8 *)(mat + 0xc));
  uVar6 = PackedFloatingMUL(uVar4,*(undefined8 *)(mat + 2));
  uVar4 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingMUL(uVar7,*(undefined8 *)(mat + 6));
  uVar8 = PackedFloatingMUL(uVar8,*(undefined8 *)(mat + 10));
  uVar7 = PackedFloatingADD(uVar6,*(undefined8 *)(mat + 0xe));
  uVar4 = PackedFloatingADD(uVar2,uVar4);
  uVar3 = PackedFloatingADD(uVar3,uVar8);
  uVar2 = PackedFloatingADD(uVar7,uVar3);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar8 = CONCAT44(uVar1,uVar1);
  uVar7 = FloatingReciprocalAprox(uVar3,uVar8);
  uVar3 = PackedFloatingReciprocalIter1(uVar8,uVar7);
  uVar7 = PackedFloatingReciprocalIter2(uVar3,uVar7);
  uVar4 = PackedFloatingMUL(uVar4,uVar7);
  uVar2 = PackedFloatingMUL(uVar2,uVar7);
  *(undefined8 *)out = uVar4;
  out[2] = (float)uVar2;
  FastExitMediaState();
  return out;
}



