/* crt_realloc @ 004626aa */

/* CRT: realloc with heap mode handling and new-handler retry */

void * __cdecl crt_realloc(void *ptr,size_t size)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  LPVOID pvVar4;
  byte *arg3;
  void *local_3c;
  uint local_38;
  byte *local_34;
  void **local_30;
  int *local_2c;
  byte *local_28;
  void *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_0046fa38;
  puStack_10 = &LAB_00465e70;
  local_14 = ExceptionList;
  arg3 = (byte *)0x0;
  if (ptr == (void *)0x0) {
    ExceptionList = &local_14;
    pvVar1 = _malloc(size);
  }
  else {
    if (size == 0) {
      ExceptionList = &local_14;
      crt_free_base(ptr);
    }
    else {
      ExceptionList = &local_14;
      if (crt_heap_mode == 3) {
        do {
          local_28 = (void *)0x0;
          if (size < (void *)0xffffffe1) {
            crt_lock(9);
            local_8 = 0;
            local_2c = crt_sbh_find_region(ptr);
            if (local_2c != (int *)0x0) {
              if (size <= DAT_004da3a0) {
                iVar2 = FUN_00467484(local_2c,ptr,(void *)size);
                if (iVar2 == 0) {
                  local_28 = crt_sbh_alloc(size);
                  if (local_28 != (void *)0x0) {
                    local_24 = (void *)(*(int *)((int)ptr + -4) - 1);
                    pvVar1 = local_24;
                    if (size <= local_24) {
                      pvVar1 = (void *)size;
                    }
                    crt_bufcpy(local_28,ptr,(size_t)pvVar1);
                    local_2c = crt_sbh_find_region(ptr);
                    FUN_00466ca6(local_2c,ptr);
                  }
                }
                else {
                  local_28 = ptr;
                }
              }
              if (local_28 == (void *)0x0) {
                if ((void *)size == (void *)0x0) {
                  size = 1;
                }
                size = size + 0xf & 0xfffffff0;
                local_28 = HeapAlloc(crt_heap_handle,0,size);
                if (local_28 != (LPVOID)0x0) {
                  local_24 = (void *)(*(int *)((int)ptr + -4) - 1);
                  pvVar1 = local_24;
                  if (size <= local_24) {
                    pvVar1 = (void *)size;
                  }
                  crt_bufcpy(local_28,ptr,(size_t)pvVar1);
                  FUN_00466ca6(local_2c,ptr);
                }
              }
            }
            local_8 = 0xffffffff;
            FUN_00462835();
            if (local_2c == (int *)0x0) {
              if ((void *)size == (void *)0x0) {
                size = 1;
              }
              size = size + 0xf & 0xfffffff0;
              local_28 = HeapReAlloc(crt_heap_handle,0,ptr,size);
            }
          }
          if (local_28 != (void *)0x0) {
            ExceptionList = local_14;
            return local_28;
          }
          if (DAT_004d9a78 == (byte *)0x0) {
            ExceptionList = local_14;
            return (void *)0x0;
          }
          iVar2 = crt_call_new_handler(size);
        } while (iVar2 != 0);
      }
      else {
        ExceptionList = &local_14;
        if (crt_heap_mode == 2) {
          ExceptionList = &local_14;
          if (size < 0xffffffe1) {
            if (size == 0) {
              size = 0x10;
              ExceptionList = &local_14;
            }
            else {
              size = size + 0xf & 0xfffffff0;
              ExceptionList = &local_14;
            }
          }
          do {
            local_28 = arg3;
            if (size < 0xffffffe1) {
              crt_lock(9);
              local_8 = 1;
              arg3 = crt_sbh_find_block(ptr,&local_3c,(uint *)&local_30);
              local_34 = arg3;
              if (arg3 == (byte *)0x0) {
                local_28 = HeapReAlloc(crt_heap_handle,0,ptr,size);
              }
              else {
                if (size < DAT_0047db14) {
                  iVar2 = FUN_00467d9e(local_3c,local_30,(char *)arg3,size >> 4);
                  if (iVar2 == 0) {
                    local_28 = crt_sbh_alloc_units(size >> 4);
                    if (local_28 != (byte *)0x0) {
                      local_38 = (uint)*arg3 << 4;
                      uVar3 = local_38;
                      if (size <= local_38) {
                        uVar3 = size;
                      }
                      crt_bufcpy(local_28,ptr,uVar3);
                      FUN_00467a2d(local_3c,(int)local_30,(char *)arg3);
                    }
                  }
                  else {
                    local_28 = ptr;
                  }
                }
                if ((local_28 == (byte *)0x0) &&
                   (local_28 = HeapAlloc(crt_heap_handle,0,size), local_28 != (byte *)0x0)) {
                  local_38 = (uint)*arg3 << 4;
                  uVar3 = local_38;
                  if (size <= local_38) {
                    uVar3 = size;
                  }
                  crt_bufcpy(local_28,ptr,uVar3);
                  FUN_00467a2d(local_3c,(int)local_30,(char *)arg3);
                }
              }
              local_8 = 0xffffffff;
              FUN_00462983();
            }
            if (local_28 != arg3) {
              ExceptionList = local_14;
              return local_28;
            }
            if (DAT_004d9a78 == arg3) {
              ExceptionList = local_14;
              return local_28;
            }
            iVar2 = crt_call_new_handler(size);
          } while (iVar2 != 0);
        }
        else {
          do {
            pvVar4 = (LPVOID)0x0;
            if (size < 0xffffffe1) {
              if (size == 0) {
                size = 1;
              }
              size = size + 0xf & 0xfffffff0;
              pvVar4 = HeapReAlloc(crt_heap_handle,0,ptr,size);
            }
            if (pvVar4 != (LPVOID)0x0) {
              ExceptionList = local_14;
              return pvVar4;
            }
            if (DAT_004d9a78 == (byte *)0x0) {
              ExceptionList = local_14;
              return (void *)0x0;
            }
            iVar2 = crt_call_new_handler(size);
          } while (iVar2 != 0);
        }
      }
    }
    pvVar1 = (void *)0x0;
  }
  ExceptionList = local_14;
  return pvVar1;
}



