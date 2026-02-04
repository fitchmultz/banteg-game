/* crt_array_unwind @ 00461a83 */

/* destructor loop used for array unwinding (backward walk) */

void crt_array_unwind(void *ptr,uint size,int count,void *dtor)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0046fa00;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  while( true ) {
    count = count + -1;
    if (count < 0) break;
    (*dtor)();
  }
  ExceptionList = local_14;
  return;
}



