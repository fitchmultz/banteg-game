/* FUN_1000a880 @ 1000a880 */

/* [binja] char* __stdcall sub_1000a880(char* arg1, uint32_t* arg2) */

char * FUN_1000a880(char *arg1,uint *arg2)

{
  uint arg2_00;
  int arg4;
  char *arg3;
  
  if (*arg1 != '\x01') {
    return (char *)0x0;
  }
  arg2_00 = *(uint *)(arg1 + 5);
  arg4 = *(int *)(arg1 + 1);
  arg3 = arg1 + 9;
  *arg2 = arg2_00;
  arg1 = (char *)0x0;
  FUN_1000a840((int *)&arg1,arg2_00,(int)arg3,arg4);
  return arg1;
}



