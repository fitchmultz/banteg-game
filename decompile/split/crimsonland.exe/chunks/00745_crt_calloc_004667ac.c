/* crt_calloc @ 004667ac */

/* CRT: allocate zeroed block (count*size) */

void * __cdecl crt_calloc(uint count,uint size)

{
  int iVar1;
  uint size_00;
  uint uVar2;
  uint _Size;
  LPVOID local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fbe8;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  size_00 = count * size;
  uVar2 = size_00;
  ExceptionList = &local_14;
  if (size_00 < 0xffffffe1) {
    if (size_00 == 0) {
      uVar2 = 1;
    }
    uVar2 = uVar2 + 0xf & 0xfffffff0;
    ExceptionList = &local_14;
  }
  do {
    local_24 = (LPVOID)0x0;
    if (uVar2 < 0xffffffe1) {
      if (crt_heap_mode == 3) {
        if (size_00 <= DAT_004da3a0) {
          crt_lock(9);
          local_8 = 0;
          local_24 = crt_sbh_alloc(size_00);
          local_8 = 0xffffffff;
          FUN_00466845();
          _Size = size_00;
          if (local_24 == (void *)0x0) goto LAB_00466899;
LAB_00466888:
          _memset(local_24,0,_Size);
        }
LAB_00466894:
        if (local_24 != (LPVOID)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((crt_heap_mode != 2) || (DAT_0047db14 < uVar2)) goto LAB_00466894;
        crt_lock(9);
        local_8 = 1;
        local_24 = crt_sbh_alloc_units(uVar2 >> 4);
        local_8 = 0xffffffff;
        FUN_004668ce();
        _Size = uVar2;
        if (local_24 != (void *)0x0) goto LAB_00466888;
      }
LAB_00466899:
      local_24 = HeapAlloc(crt_heap_handle,8,uVar2);
    }
    if (local_24 != (LPVOID)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_004d9a78 == 0) {
      ExceptionList = local_14;
      return (void *)0x0;
    }
    iVar1 = crt_call_new_handler(uVar2);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (void *)0x0;
    }
  } while( true );
}



