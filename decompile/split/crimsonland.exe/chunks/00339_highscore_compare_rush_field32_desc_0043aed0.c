/* highscore_compare_rush_field32_desc @ 0043aed0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* qsort comparator used by highscore_load_table() for rush mode; sorts descending by dword at
   offset 0x20 */

int highscore_compare_rush_field32_desc(void *a,void *b)

{
  if (*(int *)((int)b + 0x20) < *(int *)((int)a + 0x20)) {
    return -1;
  }
  return (uint)(*(int *)((int)a + 0x20) < *(int *)((int)b + 0x20));
}



