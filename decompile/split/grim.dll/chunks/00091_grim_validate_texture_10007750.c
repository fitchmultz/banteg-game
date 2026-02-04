/* grim_validate_texture @ 10007750 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xb8: validate texture handle/device */

int grim_validate_texture(int handle)

{
  void *pvVar1;
  int in_stack_00000008;
  
  if ((&grim_texture_slots)[handle] == 0) {
    return 0;
  }
  pvVar1 = FUN_1000c1e8(in_stack_00000008,2,*(int **)((&grim_texture_slots)[handle] + 4),0);
  return CONCAT31((int3)((uint)pvVar1 >> 8),-1 < (int)pvVar1);
}



