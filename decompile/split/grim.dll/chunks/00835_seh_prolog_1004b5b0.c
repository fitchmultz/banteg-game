/* seh_prolog @ 1004b5b0 */

/* MSVC SEH prolog helper (sets FS:[0]) */

void seh_prolog(void)

{
  undefined1 auStack_c [12];
  
  ExceptionList = auStack_c;
  return;
}



