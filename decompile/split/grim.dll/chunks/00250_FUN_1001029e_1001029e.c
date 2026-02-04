/* FUN_1001029e @ 1001029e */

/* [binja] int32_t __fastcall sub_1001029e(void* arg1) */

int __fastcall FUN_1001029e(void *arg1)

{
  void *pvVar1;
  void *extraout_EAX;
  void *extraout_EAX_00;
  void *extraout_EAX_01;
  void *pvVar2;
  
  if ((*(void **)((int)arg1 + 4) != (void *)0x0) && (*(int *)((int)arg1 + 0x38) != 0)) {
    operator_delete(*(void **)((int)arg1 + 4));
  }
  pvVar2 = *(void **)((int)arg1 + 8);
  if ((pvVar2 != (void *)0x0) && (*(int *)((int)arg1 + 0x3c) != 0)) {
    operator_delete(pvVar2);
    pvVar2 = extraout_EAX;
  }
  pvVar1 = *(void **)((int)arg1 + 0x4c);
  if (pvVar1 != (void *)0x0) {
    FUN_1001029e(pvVar1);
    operator_delete(pvVar1);
    pvVar2 = extraout_EAX_00;
  }
  pvVar1 = *(void **)((int)arg1 + 0x50);
  if (pvVar1 != (void *)0x0) {
    FUN_1001029e(pvVar1);
    operator_delete(pvVar1);
    pvVar2 = extraout_EAX_01;
  }
  return (int)pvVar2;
}



