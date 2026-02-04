/* grim_flush_input @ 10007330 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x4c (provisional): clear buffered input/device state */

void grim_flush_input(void)

{
  int iVar1;
  undefined4 *puVar2;
  DWORD DStack_4;
  
  DStack_4 = 10;
  puVar2 = &grim_keyboard_state;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  iVar1 = 0;
  do {
    (*grim_keyboard_device->lpVtbl->GetDeviceData)
              (grim_keyboard_device,0x14,(LPDIDEVICEOBJECTDATA)&grim_keyboard_event_buffer,&DStack_4
               ,0);
    if (99 < iVar1) break;
    iVar1 = iVar1 + 1;
  } while (DStack_4 != 0);
  DAT_1005d3e4 = 0;
  puVar2 = &grim_keyboard_state;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}



