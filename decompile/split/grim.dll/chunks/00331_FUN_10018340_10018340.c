/* FUN_10018340 @ 10018340 */

/* [binja] void* __thiscall sub_10018340(void* arg1, void* arg2, float arg3, void* arg4) */

void * __thiscall FUN_10018340(void *this,void *arg1,void *arg2,float arg3,void *arg4)

{
  void *pvVar1;
  void *extraout_ECX;
  undefined1 *puVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  
  if (*(int *)((int)this + 0x1048) != 0) {
    arg3 = (float)grim_convert_vertex_space(this,(float *)arg3);
    this = extraout_ECX;
  }
  puVar2 = (undefined1 *)
           (*(int *)((int)this + 0x1050) * (int)arg1 + *(int *)((int)this + 0x1054) * (int)arg2 +
           *(int *)((int)this + 0x18));
  arg1 = (void *)0x0;
  if (*(int *)((int)this + 0x1058) != 0) {
    pfVar4 = (float *)((int)arg3 + 8);
    do {
      fVar3 = 0.0;
      arg2 = (void *)0x7f7fffff;
      arg3 = 0.0;
      pfVar5 = (float *)((int)this + 0x38);
      do {
        pvVar1 = (void *)((pfVar4[-2] - pfVar5[-2]) * (pfVar4[-2] - pfVar5[-2]) +
                         (pfVar4[-1] - pfVar5[-1]) * (pfVar4[-1] - pfVar5[-1]) +
                         (*pfVar4 - *pfVar5) * (*pfVar4 - *pfVar5) +
                         (pfVar4[1] - pfVar5[1]) * (pfVar4[1] - pfVar5[1]));
        if ((float)pvVar1 < (float)arg2) {
          fVar3 = arg3;
          arg2 = pvVar1;
        }
        arg3 = (float)((int)arg3 + 1);
        pfVar5 = pfVar5 + 4;
      } while ((uint)arg3 < 0x100);
      *puVar2 = SUB41(fVar3,0);
      puVar2 = puVar2 + 1;
      arg3 = (float)((int)arg1 + 1);
      pfVar4 = pfVar4 + 4;
      arg1 = (void *)arg3;
    } while ((uint)arg3 < *(float **)((int)this + 0x1058));
  }
  return (void *)arg3;
}



