/* mat4_mul @ 0045eb4b */

/* multiplies two 4x4 matrices (SSE) */

float * mat4_mul(float *out,float *lhs,float *rhs)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar1 = (undefined4)((ulonglong)*(undefined8 *)lhs >> 0x20);
  uVar2 = (undefined4)((ulonglong)*(undefined8 *)(lhs + 2) >> 0x20);
  uVar3 = (undefined4)*(undefined8 *)lhs;
  uVar6 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)*(undefined8 *)(lhs + 2);
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar7 = PackedFloatingMUL(*(undefined8 *)rhs,uVar6);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar6,*(undefined8 *)(rhs + 2));
  uVar8 = PackedFloatingMUL(*(undefined8 *)(rhs + 4),uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,*(undefined8 *)(rhs + 6));
  uVar7 = PackedFloatingADD(uVar8,uVar7);
  uVar8 = PackedFloatingMUL(*(undefined8 *)(rhs + 8),uVar9);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar9,*(undefined8 *)(rhs + 10));
  uVar9 = PackedFloatingADD(uVar8,uVar7);
  uVar7 = PackedFloatingMUL(*(undefined8 *)(rhs + 0xc),uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,*(undefined8 *)(rhs + 0xe));
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = *(undefined8 *)(lhs + 4);
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = *(undefined8 *)(lhs + 6);
  *(undefined8 *)out = uVar7;
  uVar4 = *(undefined8 *)rhs;
  *(undefined8 *)(out + 2) = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,*(undefined8 *)(rhs + 2));
  uVar9 = PackedFloatingMUL(*(undefined8 *)(rhs + 4),uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,*(undefined8 *)(rhs + 6));
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(*(undefined8 *)(rhs + 8),uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,*(undefined8 *)(rhs + 10));
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(*(undefined8 *)(rhs + 0xc),uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,*(undefined8 *)(rhs + 0xe));
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = *(undefined8 *)(lhs + 8);
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = *(undefined8 *)(lhs + 10);
  *(undefined8 *)(out + 4) = uVar7;
  uVar4 = *(undefined8 *)rhs;
  *(undefined8 *)(out + 6) = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,*(undefined8 *)(rhs + 2));
  uVar9 = PackedFloatingMUL(*(undefined8 *)(rhs + 4),uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,*(undefined8 *)(rhs + 6));
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(*(undefined8 *)(rhs + 8),uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,*(undefined8 *)(rhs + 10));
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(*(undefined8 *)(rhs + 0xc),uVar6);
  uVar4 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,*(undefined8 *)(rhs + 0xe));
  uVar7 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = *(undefined8 *)(lhs + 0xc);
  uVar9 = PackedFloatingADD(uVar6,uVar4);
  uVar6 = *(undefined8 *)(lhs + 0xe);
  *(undefined8 *)(out + 8) = uVar7;
  uVar4 = *(undefined8 *)rhs;
  *(undefined8 *)(out + 10) = uVar9;
  uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar3 = (undefined4)uVar5;
  uVar9 = CONCAT44(uVar3,uVar3);
  uVar3 = (undefined4)uVar6;
  uVar7 = CONCAT44(uVar3,uVar3);
  uVar8 = PackedFloatingMUL(uVar4,uVar9);
  uVar5 = CONCAT44(uVar1,uVar1);
  uVar4 = PackedFloatingMUL(uVar9,*(undefined8 *)(rhs + 2));
  uVar9 = PackedFloatingMUL(*(undefined8 *)(rhs + 4),uVar5);
  uVar6 = CONCAT44(uVar2,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,*(undefined8 *)(rhs + 6));
  uVar9 = PackedFloatingADD(uVar9,uVar8);
  uVar8 = PackedFloatingMUL(*(undefined8 *)(rhs + 8),uVar7);
  uVar4 = PackedFloatingADD(uVar5,uVar4);
  uVar5 = PackedFloatingMUL(uVar7,*(undefined8 *)(rhs + 10));
  uVar9 = PackedFloatingADD(uVar8,uVar9);
  uVar7 = PackedFloatingMUL(*(undefined8 *)(rhs + 0xc),uVar6);
  uVar5 = PackedFloatingADD(uVar4,uVar5);
  uVar6 = PackedFloatingMUL(uVar6,*(undefined8 *)(rhs + 0xe));
  uVar4 = PackedFloatingADD(uVar7,uVar9);
  uVar5 = PackedFloatingADD(uVar6,uVar5);
  *(undefined8 *)(out + 0xc) = uVar4;
  *(undefined8 *)(out + 0xe) = uVar5;
  FastExitMediaState();
  return out;
}



