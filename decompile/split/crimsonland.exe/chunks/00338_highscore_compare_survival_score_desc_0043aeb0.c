/* highscore_compare_survival_score_desc @ 0043aeb0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* qsort comparator used by highscore_load_table() for survival mode; sorts descending by dword at
   offset 0x24 */

int highscore_compare_survival_score_desc(void *a,void *b)

{
  if (*(int *)((int)b + 0x24) < *(int *)((int)a + 0x24)) {
    return -1;
  }
  return (uint)(*(int *)((int)a + 0x24) < *(int *)((int)b + 0x24));
}



