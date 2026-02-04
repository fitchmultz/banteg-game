/* FUN_0046c883 @ 0046c883 */

bool __cdecl FUN_0046c883(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (DAT_0047de74 != 0) {
    uVar5 = param_1[5];
    if ((uVar5 != DAT_0047df08) || (uVar5 != DAT_0047df18)) {
      if (DAT_004d9b90 == 0) {
        FUN_0046ca2f(1,1,uVar5,4,1,0,0,2,0,0,0);
        FUN_0046ca2f(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_004d9c30 != 0) {
          uVar6 = (uint)DAT_004d9c36;
          uVar3 = 0;
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)DAT_004d9c34;
          uVar6 = 0;
          uVar4 = (uint)DAT_004d9c36;
        }
        FUN_0046ca2f(1,(uint)(DAT_004d9c30 == 0),uVar5,(uint)DAT_004d9c32,uVar4,uVar3,uVar6,
                     (uint)DAT_004d9c38,(uint)DAT_004d9c3a,(uint)DAT_004d9c3c,(uint)DAT_004d9c3e);
        if (DAT_004d9bdc != 0) {
          uVar6 = (uint)DAT_004d9be2;
          uVar3 = 0;
          uVar4 = 0;
          uVar5 = param_1[5];
        }
        else {
          uVar3 = (uint)DAT_004d9be0;
          uVar6 = 0;
          uVar4 = (uint)DAT_004d9be2;
          uVar5 = param_1[5];
        }
        FUN_0046ca2f(0,(uint)(DAT_004d9bdc == 0),uVar5,(uint)DAT_004d9bde,uVar4,uVar3,uVar6,
                     (uint)DAT_004d9be4,(uint)DAT_004d9be6,(uint)DAT_004d9be8,(uint)DAT_004d9bea);
      }
    }
    iVar1 = param_1[7];
    if (DAT_0047df0c < DAT_0047df1c) {
      if ((DAT_0047df0c <= iVar1) && (iVar1 <= DAT_0047df1c)) {
        if ((DAT_0047df0c < iVar1) && (iVar1 < DAT_0047df1c)) {
          return true;
        }
LAB_0046c9fb:
        iVar2 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_0047df0c) {
          return DAT_0047df10 <= iVar2;
        }
        return iVar2 < DAT_0047df20;
      }
    }
    else {
      if (iVar1 < DAT_0047df1c) {
        return true;
      }
      if (DAT_0047df0c < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_0047df1c) || (DAT_0047df0c <= iVar1)) goto LAB_0046c9fb;
    }
  }
  return false;
}



