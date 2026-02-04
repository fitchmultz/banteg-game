/* FUN_1000a900 @ 1000a900 */

void __cdecl FUN_1000a900(_onexit_t param_1)

{
  if (DAT_1005dbcc == -1) {
    _onexit((_onexit_t)param_1);
    return;
  }
  __dllonexit(param_1,&DAT_1005dbcc,&DAT_1005dbc8);
  return;
}



