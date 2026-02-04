/* FUN_10040070 @ 10040070 */

void __cdecl FUN_10040070(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x48);
  *(undefined4 **)(param_1 + 0x194) = puVar1;
  *puVar1 = &LAB_100400b0;
  puVar1[1] = &LAB_10040200;
  puVar1 = puVar1 + 10;
  iVar2 = 4;
  do {
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



