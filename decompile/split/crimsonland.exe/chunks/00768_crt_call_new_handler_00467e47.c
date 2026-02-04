/* crt_call_new_handler @ 00467e47 */

/* CRT: call new-handler; returns nonzero to retry allocation */

int __cdecl crt_call_new_handler(size_t size)

{
  int iVar1;
  
  if (DAT_004d9a74 != (code *)0x0) {
    iVar1 = (*DAT_004d9a74)(size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



