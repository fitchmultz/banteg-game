/* FUN_10001a30 @ 10001a30 */

undefined4 FUN_10001a30(void)

{
  FILE *_File;
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  
  _File = fopen(s_crimson_cfg_10053234,&DAT_10053244);
  if (_File == (FILE *)0x0) {
    FUN_100019f0();
    _File = fopen(s_crimson_cfg_10053234,&DAT_10053244);
    if (_File == (FILE *)0x0) {
      return 0;
    }
  }
  fseek(_File,0,2);
  lVar1 = ftell(_File);
  if (lVar1 != 0x480) {
    fclose(_File);
    uVar2 = FUN_100019f0();
    return CONCAT31((int3)((uint)uVar2 >> 8),1);
  }
  fseek(_File,0,0);
  fread(&grim_config_blob,0x480,1,_File);
  iVar3 = fclose(_File);
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}



