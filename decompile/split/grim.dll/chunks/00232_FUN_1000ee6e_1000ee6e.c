/* FUN_1000ee6e @ 1000ee6e */

/* [binja] int32_t __stdcall sub_1000ee6e(int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4,
   int32_t arg5, float arg6) */

int FUN_1000ee6e(int arg1,int arg2,int arg3,int arg4,int arg5,float arg6)

{
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  thunk_FUN_1000ed37((int)local_24,arg2,(float)arg5);
  thunk_FUN_1000ed37((int)local_14,arg3,(float)arg4);
  thunk_FUN_1000ed37(arg1,(int)local_24,(float)local_14);
  return arg1;
}



