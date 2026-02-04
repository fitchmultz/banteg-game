/* grim_keyboard_poll @ 1000a4a0 */

/* polls the keyboard device and updates cached key state */

int grim_keyboard_poll(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  DWORD DStack_4;
  
  uVar2 = 0;
  if (grim_keyboard_device != (LPDIRECTINPUTDEVICE8A)0x0) {
    uVar2 = (*grim_keyboard_device->lpVtbl->Acquire)(grim_keyboard_device);
    while ((uVar2 == 0x8007001e || (uVar2 == 0x80070005))) {
      uVar2 = (*grim_keyboard_device->lpVtbl->Acquire)(grim_keyboard_device);
    }
    if (-1 < (int)uVar2) {
      puVar5 = &grim_keyboard_state;
      for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      (*grim_keyboard_device->lpVtbl->GetDeviceState)
                (grim_keyboard_device,0x100,&grim_keyboard_state);
      DStack_4 = 10;
      piVar3 = (int *)(*grim_keyboard_device->lpVtbl->GetDeviceData)
                                (grim_keyboard_device,0x14,
                                 (LPDIDEVICEOBJECTDATA)&grim_keyboard_event_buffer,&DStack_4,0);
      if ((-1 < (int)piVar3) && (0 < (int)DStack_4)) {
        piVar3 = &grim_keyboard_event_buffer;
        do {
          iVar4 = *piVar3;
          piVar1 = piVar3 + 1;
          piVar3 = piVar3 + 5;
          DStack_4 = DStack_4 - 1;
          *(char *)((int)&grim_keyboard_state + iVar4) = (char)*piVar1;
        } while (DStack_4 != 0);
      }
      return CONCAT31((int3)((uint)piVar3 >> 8),1);
    }
  }
  return uVar2 & 0xffffff00;
}



