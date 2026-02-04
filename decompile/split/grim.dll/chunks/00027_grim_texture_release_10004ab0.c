/* grim_texture_release @ 10004ab0 */

/* releases COM objects and frees texture name */

void __fastcall grim_texture_release(void *texture)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)texture + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)((int)texture + 0x14);
  *(undefined4 *)((int)texture + 4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)((int)texture + 0x14) = 0;
  if (*(void **)texture != (void *)0x0) {
    operator_delete(*(void **)texture);
  }
  *(undefined4 *)texture = 0;
  return;
}



