/* console_register_cvar @ 00402350 */

/* registers or updates a console cvar entry (stores string + float value) */

void * __thiscall console_register_cvar(void *this,char *name,char *value)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 *puVar5;
  void *this_00;
  float fVar6;
  
  pvVar3 = console_cvar_find(this,name);
  if (pvVar3 != (void *)0x0) {
    if (*(void **)((int)pvVar3 + 0x10) != (void *)0x0) {
      crt_free(*(void **)((int)pvVar3 + 0x10));
    }
    *(undefined4 *)((int)pvVar3 + 0x10) = 0;
    pcVar4 = strdup_malloc(value);
    *(char **)((int)pvVar3 + 0x10) = pcVar4;
    fVar6 = crt_atof_l(this_00,value);
    *(float *)((int)pvVar3 + 0xc) = fVar6;
    return pvVar3;
  }
  iVar1 = *(int *)this;
  if (iVar1 == 0) {
    puVar5 = operator_new(0x24);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5[6] = 0;
      puVar5[7] = 0;
      puVar5[8] = 0;
      pcVar4 = strdup_malloc(name);
      *puVar5 = pcVar4;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      puVar5[5] = 0;
    }
    *(undefined4 **)this = puVar5;
    pcVar4 = strdup_malloc(value);
    pvVar3 = *(void **)this;
    *(char **)((int)pvVar3 + 0x10) = pcVar4;
    fVar6 = crt_atof_l(pvVar3,value);
    *(float *)(*(int *)this + 0xc) = fVar6;
    return *(void **)this;
  }
  for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    iVar1 = iVar2;
  }
  puVar5 = operator_new(0x24);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[6] = 0;
    puVar5[7] = 0;
    puVar5[8] = 0;
    pcVar4 = strdup_malloc(name);
    *puVar5 = pcVar4;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
  }
  *(undefined4 **)(iVar1 + 4) = puVar5;
  pcVar4 = strdup_malloc(value);
  pvVar3 = *(void **)(iVar1 + 4);
  *(char **)((int)pvVar3 + 0x10) = pcVar4;
  fVar6 = crt_atof_l(pvVar3,value);
  *(float *)(*(int *)(iVar1 + 4) + 0xc) = fVar6;
  return *(void **)(iVar1 + 4);
}



