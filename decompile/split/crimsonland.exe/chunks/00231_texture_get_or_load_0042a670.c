/* texture_get_or_load @ 0042a670 */

/* lookup texture handle; load if missing (name + path) */

int __cdecl texture_get_or_load(char *name,char *path)

{
  int iVar1;
  
  iVar1 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(name);
  if (iVar1 == -1) {
    iVar1 = (*grim_interface_ptr->vtable->grim_load_texture)(name,name);
    if ((char)iVar1 != '\0') {
      if (*(float *)((int)cv_silentloads + 0xc) == 0.0) {
        console_printf(&console_log_queue,s____loading_texture___s__ok_00473ed4,name);
      }
      iVar1 = (*grim_interface_ptr->vtable->grim_get_texture_handle)(name);
      return iVar1;
    }
    console_printf(&console_log_queue,s____loading_texture___s__failed_00473eb4,name);
    iVar1 = -1;
  }
  return iVar1;
}



