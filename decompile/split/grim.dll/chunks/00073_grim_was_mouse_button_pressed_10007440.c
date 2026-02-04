/* grim_was_mouse_button_pressed @ 10007440 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0x5c (provisional): edge-triggered mouse button */

int grim_was_mouse_button_pressed(int button)

{
  char cVar1;
  undefined4 in_EAX;
  uint3 uVar3;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 uVar4;
  
  uVar3 = (uint3)((uint)in_EAX >> 8);
  if (grim_input_cached == '\0') {
    cVar1 = (**(code **)(*in_ECX + 0x58))(button);
    if ((cVar1 == '\0') || ((&grim_mouse_button_latch)[button] == '\0')) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    uVar2 = (**(code **)(*in_ECX + 0x58))(button);
    (&grim_mouse_button_latch)[button] = (char)uVar2 == '\0';
    return CONCAT31((int3)((uint)uVar2 >> 8),uVar4);
  }
  cVar1 = (&grim_mouse_button_cache)[button];
  if ((cVar1 != '\0') && ((&grim_mouse_button_latch)[button] != '\0')) {
    (&grim_mouse_button_latch)[button] = cVar1 == '\0';
    return CONCAT31(uVar3,1);
  }
  (&grim_mouse_button_latch)[button] = cVar1 == '\0';
  return (uint)uVar3 << 8;
}



