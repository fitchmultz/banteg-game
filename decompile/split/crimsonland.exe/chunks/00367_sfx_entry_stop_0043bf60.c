/* sfx_entry_stop @ 0043bf60 */

/* stops playback for all voices */

void __cdecl sfx_entry_stop(int entry)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (entry != 0) {
    if (*(int *)(entry + 0x74) == 0) {
      piVar2 = (int *)(entry + 0x24);
      iVar3 = 0x10;
      do {
        piVar1 = (int *)*piVar2;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x48))(piVar1);
        }
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    else {
      piVar2 = *(int **)(entry + 0x24);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x48))(piVar2);
        return;
      }
    }
  }
  return;
}



