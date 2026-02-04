/* resource_close @ 0043bad0 */

/* closes the current resource file handle */

void resource_close(void)

{
  if (resource_fp != (FILE *)0x0) {
    crt_fclose((FILE *)resource_fp);
  }
  return;
}



