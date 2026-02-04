/* crt_ehvec_ctor @ 00461981 */

/* MSVC __ehvec_ctor: constructs an array; uses dtor to unwind on exception */

void crt_ehvec_ctor(void *ptr,uint size,int count,void *ctor,void *dtor)

{
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_0046f9e0;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_14;
  for (local_20 = 0; local_20 < count; local_20 = local_20 + 1) {
    (*ctor)();
  }
  local_8 = 0xffffffff;
  FUN_004619eb();
  ExceptionList = local_14;
  return;
}



