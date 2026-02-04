/* FUN_004619eb @ 004619eb */

void FUN_004619eb(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x20) == 0) {
    crt_array_unwind(*(void **)(unaff_EBP + 8),*(uint *)(unaff_EBP + 0xc),
                     *(int *)(unaff_EBP + -0x1c),*(void **)(unaff_EBP + 0x18));
  }
  return;
}



