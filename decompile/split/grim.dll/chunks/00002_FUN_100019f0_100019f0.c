/* FUN_100019f0 @ 100019f0 */

undefined4 FUN_100019f0(void)

{
  FILE *_File;
  int iVar1;
  
  _File = fopen(s_crimson_cfg_10053234,&DAT_10053240);
  iVar1 = 0;
  if (_File != (FILE *)0x0) {
    fwrite(&grim_config_blob,0x480,1,_File);
    iVar1 = fclose(_File);
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



