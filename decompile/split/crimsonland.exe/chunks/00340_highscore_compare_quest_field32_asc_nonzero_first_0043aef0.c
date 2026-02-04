/* highscore_compare_quest_field32_asc_nonzero_first @ 0043aef0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* qsort comparator used by highscore_load_table() for quest mode; sorts ascending by dword at
   offset 0x20, treating 0 as "missing" (sorted last) */

int highscore_compare_quest_field32_asc_nonzero_first(void *a,void *b)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)a + 0x20);
  if (iVar1 == 0) {
    return 1;
  }
  iVar2 = *(int *)((int)b + 0x20);
  if (iVar2 == 0) {
    return -1;
  }
  if (iVar2 < iVar1) {
    return 1;
  }
  return (iVar2 <= iVar1) - 1;
}



