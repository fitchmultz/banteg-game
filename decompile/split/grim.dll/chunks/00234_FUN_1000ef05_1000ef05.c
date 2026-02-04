/* FUN_1000ef05 @ 1000ef05 */

/* [binja] int32_t* __stdcall sub_1000ef05(int32_t* arg1, int32_t* arg2, int32_t arg3, int32_t arg4,
   float arg5, float arg6) */

int * FUN_1000ef05(int *arg1,int *arg2,int arg3,int arg4,float arg5,float arg6)

{
  int iVar1;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  iVar1 = float_near_equal(arg5 + arg6,0.0);
  if (iVar1 == 0) {
    thunk_FUN_1000ed37((int)local_24,(int)arg2,(float)arg3);
    thunk_FUN_1000ed37((int)local_14,(int)arg2,(float)arg4);
    thunk_FUN_1000ed37((int)arg1,(int)local_24,(float)local_14);
  }
  else if (arg1 != arg2) {
    *arg1 = *arg2;
    arg1[1] = arg2[1];
    arg1[2] = arg2[2];
    arg1[3] = arg2[3];
  }
  return arg1;
}



