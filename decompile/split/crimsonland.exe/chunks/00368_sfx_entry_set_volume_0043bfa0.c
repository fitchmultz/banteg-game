/* sfx_entry_set_volume @ 0043bfa0 */

/* sets the volume for active voices */

void __cdecl sfx_entry_set_volume(int entry,float volume)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  longlong lVar6;
  
  fVar3 = (volume + 2.0) * 0.33333334;
  if ((*(int *)(entry + 0x74) == 0) || (*(float *)(entry + 0x20) != fVar3)) {
    iVar4 = 0;
    *(float *)(entry + 0x20) = fVar3;
    piVar5 = (int *)(entry + 0x24);
    do {
      piVar1 = (int *)*piVar5;
      if (piVar1 != (int *)0x0) {
        iVar2 = *piVar1;
        lVar6 = __ftol();
        (**(code **)(iVar2 + 0x3c))(piVar1,(int)lVar6);
        if (*(int *)(entry + 0x74) != 0) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < 0x10);
  }
  return;
}



