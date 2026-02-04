/* FID_conflict:`vector_deleting_destructor' @ 1000b348 */

/* Library Function - Multiple Matches With Different Base Names
    public: void * __thiscall ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>
   > >::`vector deleting destructor'(unsigned int)
    public: void * __thiscall ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class
   ATL::ChTraitsCRT<wchar_t> > >::`vector deleting destructor'(unsigned int)
   
   Library: Visual Studio 2003 Release */

int * __thiscall FID_conflict__vector_deleting_destructor_(void *this,byte param_1)

{
  int *piVar1;
  
  if ((param_1 & 2) == 0) {
    thunk_FUN_100161a0(this);
    piVar1 = this;
    if ((param_1 & 1) != 0) {
      operator_delete(this);
    }
  }
  else {
    piVar1 = (int *)((int)this + -4);
    FUN_1004b5cf((int)this,4,*piVar1,0x100165ce);
    if ((param_1 & 1) != 0) {
      operator_delete(piVar1);
    }
  }
  return piVar1;
}



