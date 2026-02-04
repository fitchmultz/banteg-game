/* crt_cxx_frame_handler @ 004695fb */

/* MSVC C++ exception frame handler */

int __cdecl
crt_cxx_frame_handler
          (PEXCEPTION_RECORD record,PVOID frame,DWORD context,void *dispatcher,int *func_info,
          int try_level,PVOID handler_data,char is_rethrow)

{
  code *pcVar1;
  int iVar2;
  
  if (*func_info != 0x19930520) {
    crt_invalid_parameter_noinfo_noreturn();
  }
  if ((record->ExceptionFlags & 0x66) == 0) {
    if (func_info[3] != 0) {
      if (((record->ExceptionCode == 0xe06d7363) && (0x19930520 < record->ExceptionInformation[0]))
         && (pcVar1 = *(code **)(record->ExceptionInformation[2] + 8), pcVar1 != (code *)0x0)) {
        iVar2 = (*pcVar1)(record,frame,context,dispatcher,func_info,try_level,handler_data,
                          is_rethrow);
        return iVar2;
      }
      FUN_00469696(record,frame,context,dispatcher,(int)func_info,is_rethrow,try_level,handler_data)
      ;
    }
  }
  else if ((func_info[1] != 0) && (try_level == 0)) {
    FUN_00469950((int)frame,dispatcher,(int)func_info,-1);
  }
  return 1;
}



