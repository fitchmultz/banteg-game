/* FUN_1000a93e @ 1000a93e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* [binja] int32_t __stdcall sub_1000a93e(int32_t arg1) */

int FUN_1000a93e(int arg1)

{
  int iVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  int in_stack_00000008;
  
  if (in_stack_00000008 == 0) {
    if (0 < DAT_1005db5c) {
      DAT_1005db5c = DAT_1005db5c + -1;
      goto LAB_1000a954;
    }
LAB_1000a97c:
    iVar1 = 0;
  }
  else {
LAB_1000a954:
    _DAT_1005dbc0 = *(undefined4 *)_adjust_fdiv_exref;
    if (in_stack_00000008 == 1) {
      DAT_1005dbcc = malloc(0x80);
      if (DAT_1005dbcc == (undefined4 *)0x0) goto LAB_1000a97c;
      *DAT_1005dbcc = 0;
      DAT_1005dbc8 = DAT_1005dbcc;
      initterm(&DAT_10053000,&DAT_10053034);
      DAT_1005db5c = DAT_1005db5c + 1;
    }
    else if ((in_stack_00000008 == 0) &&
            (_Memory = DAT_1005dbcc, puVar2 = DAT_1005dbc8, DAT_1005dbcc != (undefined4 *)0x0)) {
      while (puVar2 = puVar2 + -1, _Memory <= puVar2) {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          _Memory = DAT_1005dbcc;
        }
      }
      free(_Memory);
      DAT_1005dbcc = (undefined4 *)0x0;
    }
    iVar1 = 1;
  }
  return iVar1;
}



