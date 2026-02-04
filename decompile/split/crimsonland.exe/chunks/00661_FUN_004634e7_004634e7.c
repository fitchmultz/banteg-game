/* FUN_004634e7 @ 004634e7 */

/* [binja] int32_t sub_4634e7(EXCEPTION_RECORD* arg1, void* arg2, DWORD arg3) */

int __cdecl FUN_004634e7(EXCEPTION_RECORD *arg1,void *arg2,DWORD arg3)

{
  int iVar1;
  
  if ((arg1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)arg2 + 0x24) = 1;
    return 1;
  }
  crt_cxx_frame_handler
            (arg1,*(PVOID *)((int)arg2 + 0xc),arg3,(void *)0x0,*(int **)((int)arg2 + 8),
             *(int *)((int)arg2 + 0x10),*(PVOID *)((int)arg2 + 0x14),'\x01');
  if (*(int *)((int)arg2 + 0x24) == 0) {
    FUN_00463333((int)arg2,arg1);
  }
                    /* WARNING: Could not recover jumptable at 0x00463551. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)((int)arg2 + 0x18))();
  return iVar1;
}



