/* FUN_0046340c @ 0046340c */

/* [binja] int32_t sub_46340c(PEXCEPTION_RECORD arg1, PVOID arg2, DWORD arg3) */

int __cdecl FUN_0046340c(PEXCEPTION_RECORD arg1,PVOID arg2,DWORD arg3)

{
  int iVar1;
  
  iVar1 = crt_cxx_frame_handler
                    (arg1,*(PVOID *)((int)arg2 + 0xc),arg3,(void *)0x0,*(int **)((int)arg2 + 8),
                     *(int *)((int)arg2 + 0x10),arg2,'\0');
  return iVar1;
}



