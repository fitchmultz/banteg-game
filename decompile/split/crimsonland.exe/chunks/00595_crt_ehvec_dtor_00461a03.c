/* crt_ehvec_dtor @ 00461a03 */

/* MSVC __ehvec_dtor: destroys an array with exception handling */

void crt_ehvec_dtor(void *ptr,uint size,int count,void *dtor)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0046f9f0;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    count = count + -1;
    if (count < 0) break;
    (*dtor)();
  }
  local_8 = 0xffffffff;
  FUN_00461a6b();
  ExceptionList = local_14;
  return;
}



