/* sfx_release_entry @ 0043c090 */

/* frees a sound entry (sample/voices) */

void __cdecl sfx_release_entry(int entry)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (*(void **)(entry + 0x74) != (void *)0x0) {
    vorbis_mem_close(*(void **)(entry + 0x74));
    crt_free(*(void **)(entry + 0x74));
    piVar3 = *(int **)(entry + 0x24);
    *(undefined4 *)(entry + 0x74) = 0;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    *(undefined4 *)(entry + 0x24) = 0;
    crt_free(*(void **)(entry + 0x14));
    *(undefined4 *)(entry + 0x14) = 0;
    return;
  }
  piVar3 = (int *)(entry + 0x60);
  iVar2 = 0x10;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *piVar3 = 0;
    piVar3 = piVar3 + -1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  crt_free(*(void **)(entry + 0x14));
  *(undefined4 *)(entry + 0x14) = 0;
  return;
}



