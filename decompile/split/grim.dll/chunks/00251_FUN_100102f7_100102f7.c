/* FUN_100102f7 @ 100102f7 */

/* [binja] void* __thiscall sub_100102f7(void* arg1, char arg2) */

void * __thiscall FUN_100102f7(void *this,void *arg1,char arg2)

{
  FUN_1001029e(this);
  if (((uint)arg1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



