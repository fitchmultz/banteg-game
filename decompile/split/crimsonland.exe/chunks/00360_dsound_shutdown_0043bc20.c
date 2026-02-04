/* dsound_shutdown @ 0043bc20 */

/* releases the DirectSound interface */

void dsound_shutdown(void)

{
  if (dsound_iface != (int *)0x0) {
    (**(code **)(*dsound_iface + 8))(dsound_iface);
  }
  dsound_iface = (int *)0x0;
  return;
}



