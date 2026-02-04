/* resource_open_read @ 0043b9e0 */

/* opens a resource from the active pack or filesystem and returns its size */

int __cdecl resource_open_read(byte *path,int *size_out)

{
  int *piVar1;
  char cVar2;
  FILE *fp;
  uint uVar3;
  int iVar4;
  
  piVar1 = size_out;
  if (resource_pack_enabled != '\0') {
    fp = (FILE *)crt_fopen((LPCSTR)&DAT_004c3968,&file_mode_read_binary);
    resource_fp = (FILE *)fp;
    if (fp == (FILE *)0x0) {
      return 0;
    }
    crt_fseek((int *)fp,4,0);
    uVar3 = resource_pack_read_cstring((undefined4 *)fp);
    cVar2 = (char)uVar3;
    while (cVar2 != '\0') {
      crt_fread((char *)&size_out,4,1,(int *)fp);
      *piVar1 = (int)size_out;
      uVar3 = FUN_00462de0(size_out,&DAT_004c3a68,path);
      iVar4 = 0;
      if (uVar3 == 0) goto LAB_0043bac3;
      crt_fseek((int *)fp,(int)size_out,1);
      uVar3 = resource_pack_read_cstring((undefined4 *)fp);
      cVar2 = (char)uVar3;
    }
    crt_fclose(fp);
  }
  resource_fp = (FILE *)crt_fopen((LPCSTR)path,&file_mode_read_binary);
  if (resource_fp == (FILE *)0x0) {
    return 0;
  }
  crt_fseek((int *)resource_fp,0,2);
  iVar4 = crt_ftell((char *)resource_fp);
  *piVar1 = iVar4;
  iVar4 = crt_fseek((int *)resource_fp,0,0);
LAB_0043bac3:
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}



