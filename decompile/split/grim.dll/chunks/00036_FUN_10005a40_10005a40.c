/* FUN_10005a40 @ 10005a40 */

uint __cdecl FUN_10005a40(char *param_1)

{
  FILE *_File;
  uint extraout_EAX;
  uint uVar1;
  int iVar2;
  
  _File = fopen(param_1,&DAT_10053244);
  if (_File == (FILE *)0x0) {
    DAT_1005bc14 = 0;
    uVar1 = 0;
    if (DAT_1005a670 != (void *)0x0) {
      operator_delete(DAT_1005a670);
      uVar1 = extraout_EAX;
    }
    DAT_1005a670 = (void *)0x0;
    return uVar1 & 0xffffff00;
  }
  fseek(_File,0,2);
  DAT_1005a458 = ftell(_File);
  fseek(_File,0,0);
  DAT_1005a670 = operator_new(DAT_1005a458 + 1);
  fread(DAT_1005a670,DAT_1005a458,1,_File);
  iVar2 = fclose(_File);
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}



