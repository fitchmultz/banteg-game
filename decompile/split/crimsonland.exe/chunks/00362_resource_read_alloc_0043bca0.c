/* resource_read_alloc @ 0043bca0 */

/* reads a resource into a newly allocated buffer */

int __cdecl resource_read_alloc(byte *path,void **out_data,uint *out_size)

{
  FILE *pFVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = resource_open_read(path,(int *)out_size);
  pFVar1 = resource_fp;
  if ((char)iVar2 == '\0') {
    return iVar2;
  }
  pcVar3 = operator_new(*out_size);
  crt_fread(pcVar3,*out_size,1,(int *)pFVar1);
  resource_close();
  *out_data = pcVar3;
  return CONCAT31((int3)((uint)out_data >> 8),1);
}



