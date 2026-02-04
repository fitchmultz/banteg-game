/* crt_qsort @ 00462bd4 */

/* CRT: quicksort with callback (cmp) */

void __cdecl crt_qsort(void *base,size_t num,size_t size,void *cmp)

{
  char *pcVar1;
  uint uVar2;
  char *b;
  int iVar3;
  char *hi;
  char *b_00;
  undefined1 local_fc [120];
  undefined1 local_84 [120];
  char *local_c;
  int local_8;
  
  if ((num < 2) || (size == 0)) {
    return;
  }
  local_8 = 0;
  iVar3 = num - 1;
  num = (size_t)local_fc;
  hi = (char *)(iVar3 * size + (int)base);
  b = base;
  base = local_84;
LAB_00462c13:
  uVar2 = (uint)((int)hi - (int)b) / size + 1;
  if (8 < uVar2) {
    crt_swap(b + (uVar2 >> 1) * size,b,size);
    b_00 = hi + size;
    local_c = b;
LAB_00462c6a:
    local_c = local_c + size;
    if (local_c <= hi) goto code_r0x00462c77;
    goto LAB_00462c82;
  }
  crt_shortsort(b,hi,size,cmp);
  goto LAB_00462c32;
code_r0x00462c77:
  iVar3 = (*cmp)(local_c,b);
  if (iVar3 < 1) goto LAB_00462c6a;
LAB_00462c82:
  do {
    b_00 = b_00 + -size;
    if (b_00 <= b) break;
    iVar3 = (*cmp)(b_00,b);
  } while (-1 < iVar3);
  if (local_c <= b_00) {
    crt_swap(local_c,b_00,size);
    goto LAB_00462c6a;
  }
  crt_swap(b,b_00,size);
  pcVar1 = local_c;
  if ((int)(b_00 + (-1 - (int)b)) < (int)hi - (int)local_c) {
    if (local_c < hi) {
      local_8 = local_8 + 1;
      *(char **)num = local_c;
      *(char **)base = hi;
      base = (void *)((int)base + 4);
      num = num + 4;
    }
    if (b + size < b_00) {
      hi = b_00 + -size;
      goto LAB_00462c13;
    }
  }
  else {
    if (b + size < b_00) {
      local_8 = local_8 + 1;
      *(char **)num = b;
      *(size_t *)base = (int)b_00 - size;
      base = (void *)((int)base + 4);
      num = num + 4;
    }
    b = pcVar1;
    if (pcVar1 < hi) goto LAB_00462c13;
  }
LAB_00462c32:
  local_8 = local_8 + -1;
  num = num - 4;
  base = (void *)((int)base + -4);
  if (local_8 < 0) {
    return;
  }
  hi = *(char **)base;
  b = *(char **)num;
  goto LAB_00462c13;
}



