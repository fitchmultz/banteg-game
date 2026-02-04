/* FUN_10012b47 @ 10012b47 */

/* [binja] int32_t* __thiscall sub_10012b47(int32_t* arg1, char arg2) */

int * __thiscall FUN_10012b47(void *this,int *arg1,char arg2)

{
  int *piVar1;
  
  if (((uint)arg1 & 2) == 0) {
    operator_delete(*(void **)this);
    piVar1 = this;
    if (((uint)arg1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    piVar1 = (int *)((int)this + -4);
    FUN_1004b5cf((int)this,0xc,*piVar1,0x10012881);
    if (((uint)arg1 & 1) != 0) {
      operator_delete(piVar1);
    }
  }
  return piVar1;
}



