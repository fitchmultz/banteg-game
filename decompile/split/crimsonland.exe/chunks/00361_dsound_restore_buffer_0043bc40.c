/* dsound_restore_buffer @ 0043bc40 */

/* restores a lost DirectSound buffer */

int __cdecl dsound_restore_buffer(void *buffer)

{
  void *pvVar1;
  uint in_EAX;
  int iVar2;
  undefined4 extraout_EAX;
  uint unaff_ESI;
  
  pvVar1 = buffer;
  if (((buffer != (void *)0x0) &&
      (in_EAX = (**(code **)(*(int *)buffer + 0x24))(buffer,&buffer), -1 < (int)in_EAX)) &&
     ((unaff_ESI & 2) != 0)) {
    do {
      while (iVar2 = (**(code **)(*(int *)pvVar1 + 0x50))(pvVar1), iVar2 == -0x7787ff6a) {
        Sleep(10);
      }
    } while (iVar2 != 0);
    OutputDebugStringA(s_____SND__Buffer_restored__00477c74);
    return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
  }
  return in_EAX & 0xffffff00;
}



