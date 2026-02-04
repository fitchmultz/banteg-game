/* grim_keyboard_key_down @ 1000a370 */

/* reads the cached key state array */

int __cdecl grim_keyboard_key_down(uint key)

{
  return (uint)(*(byte *)((int)&grim_keyboard_state + (key & 0xff)) >> 7);
}



