/* FUN_0046d419 @ 0046d419 */

void FUN_0046d419(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_004da280;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_004da164 = 0;
  DAT_004da17c = 0;
  DAT_004da384 = 0;
  DAT_004da170 = 0;
  DAT_004da174 = 0;
  DAT_004da178 = 0;
  return;
}



