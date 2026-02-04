/* crt_exit @ 00462edd */

/* CRT exit path (atexit/onexit + ExitProcess) */

void __cdecl crt_exit(uint code)

{
  crt_doexit(code,0,0);
  return;
}



