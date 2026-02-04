/* FUN_0046e79e @ 0046e79e */

int __cdecl FUN_0046e79e(uchar *param_1,size_t param_2)

{
  uchar *_Str2;
  int iVar1;
  char **ppcVar2;
  
  _Str2 = (uchar *)*crt_environ;
  ppcVar2 = crt_environ;
  while( true ) {
    if (_Str2 == (uchar *)0x0) {
      return -((int)ppcVar2 - (int)crt_environ >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,_Str2,param_2);
    if ((iVar1 == 0) && (((*ppcVar2)[param_2] == '=' || ((*ppcVar2)[param_2] == '\0')))) break;
    _Str2 = (uchar *)ppcVar2[1];
    ppcVar2 = ppcVar2 + 1;
  }
  return (int)ppcVar2 - (int)crt_environ >> 2;
}



