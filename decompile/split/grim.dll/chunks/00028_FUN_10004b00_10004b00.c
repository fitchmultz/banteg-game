/* FUN_10004b00 @ 10004b00 */

bool __cdecl FUN_10004b00(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar2 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  uVar3 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  if ((-1 < (int)(uVar2 - 4)) && (-1 < (int)(uVar3 - 4))) {
    if ((param_1[uVar2 - 4] == param_2[uVar3 - 4]) && (param_1[uVar2 - 3] == param_2[uVar3 - 3])) {
      return param_1[uVar2 - 2] == param_2[uVar3 - 2];
    }
  }
  return false;
}



