/* FUN_004678be @ 004678be */

/* [binja] BOOL sub_4678be(int32_t* arg1) */

BOOL __cdecl FUN_004678be(int *arg1)

{
  undefined *puVar1;
  WINBOOL WVar2;
  
  puVar1 = (undefined *)VirtualFree((LPVOID)arg1[4],0,0x8000);
  if ((int *)PTR_LOOP_0047db10 == arg1) {
    puVar1 = (undefined *)arg1[1];
    PTR_LOOP_0047db10 = puVar1;
  }
  if ((undefined **)arg1 != &PTR_LOOP_0047baf0) {
    *(int *)arg1[1] = *arg1;
    *(int *)(*arg1 + 4) = arg1[1];
    WVar2 = HeapFree(crt_heap_handle,0,arg1);
    return WVar2;
  }
  DAT_0047bb00 = 0xffffffff;
  return (BOOL)puVar1;
}



