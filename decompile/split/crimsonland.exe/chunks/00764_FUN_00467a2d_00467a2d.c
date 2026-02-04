/* FUN_00467a2d @ 00467a2d */

/* [binja] void* sub_467a2d(void* arg1, int32_t arg2, char* arg3) */

void * __cdecl FUN_00467a2d(void *arg1,int arg2,char *arg3)

{
  int *piVar1;
  
  piVar1 = (int *)((int)arg1 + (arg2 - *(int *)((int)arg1 + 0x10) >> 0xc) * 8 + 0x18);
  *piVar1 = *piVar1 + (uint)(byte)*arg3;
  *arg3 = '\0';
  piVar1[1] = 0xf1;
  if ((*piVar1 == 0xf0) && (DAT_004d9a70 = DAT_004d9a70 + 1, DAT_004d9a70 == 0x20)) {
    piVar1 = (int *)FUN_00467914(0x10);
  }
  return piVar1;
}



