/* FUN_0046e0d7 @ 0046e0d7 */

int __cdecl FUN_0046e0d7(uchar *param_1)

{
  int iVar1;
  size_t _MaxCount;
  size_t sVar2;
  char **ppcVar3;
  
  if (((DAT_004db4e8 != 0) &&
      ((crt_environ != (char **)0x0 ||
       (((DAT_004d99a8 != 0 && (iVar1 = FUN_0046e301(), iVar1 == 0)) &&
        (crt_environ != (char **)0x0)))))) && (ppcVar3 = crt_environ, param_1 != (uchar *)0x0)) {
    _MaxCount = _strlen((char *)param_1);
    for (; *ppcVar3 != (char *)0x0; ppcVar3 = ppcVar3 + 1) {
      sVar2 = _strlen(*ppcVar3);
      if (((_MaxCount < sVar2) && ((*ppcVar3)[_MaxCount] == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*ppcVar3,param_1,_MaxCount), iVar1 == 0)) {
        return (int)(*ppcVar3 + _MaxCount + 1);
      }
    }
  }
  return 0;
}



