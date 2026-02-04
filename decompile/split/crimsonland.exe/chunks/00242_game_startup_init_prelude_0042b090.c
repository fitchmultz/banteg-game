/* game_startup_init_prelude @ 0042b090 */

/* prelude called by game_startup_init; handles core init, dates, registry time, and terrain reset
    */

void game_startup_init_prelude(void)

{
  LONG LVar1;
  char *filename;
  HKEY key;
  uint in_stack_ffffffa4;
  undefined4 uStack_58;
  undefined4 in_stack_ffffffe0;
  
  DAT_004aaee4 = strdup_malloc(&s_empty_string);
  (*grim_interface_ptr->vtable->grim_set_config_var)
            (0x12,CONCAT31((int3)((uint)in_stack_ffffffe0 >> 8),1));
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x13,5);
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x14,6);
  effect_uv_tables_init();
  console_flush_log(&console_log_queue,filename);
  uStack_58 = 0x42b10a;
  console_printf(&console_log_queue,s_Entering_Crimsonland___0047465c);
  perks_init_database();
  weapon_table_init();
  game_core_init();
  GetLocalTime((LPSYSTEMTIME)&local_system_time);
  if (local_system_time._2_2_ == 9) {
    if (local_system_day != 0xc) goto LAB_0042b17a;
  }
  else if (local_system_time._2_2_ == 0xb) {
    if (local_system_day != 8) goto LAB_0042b17a;
  }
  else if ((local_system_time._2_2_ != 0xc) || (local_system_day != 0x12)) goto LAB_0042b17a;
  DAT_004aaed8 = 1;
  uStack_58 = 0x42b177;
  texture_get_or_load(s_balloon_00474648,s_balloon_tga_00474650);
LAB_0042b17a:
  DAT_004aaed8 = 0;
  uStack_58 = 0x42b190;
  console_printf(&console_log_queue,s_Unloaded_resource_paq_00474630);
  key = (HKEY)0x10;
  (*grim_interface_ptr->vtable->grim_set_config_var)(0x10,in_stack_ffffffa4);
  uStack_58 = ZEXT24(qpc_timestamp_scratch);
  QueryPerformanceCounter((LARGE_INTEGER *)&stack0xffffffa8);
  crt_srand(uStack_58);
  gameplay_reset_state();
  DAT_004aaed9 = 1;
  terrain_generate_random();
  DAT_004aaed9 = 0;
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_10tons_entertainment_Cr_00474604,0,(LPSTR)0x0,
                          0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,(PHKEY)&stack0xffffffa0,(LPDWORD)0x0)
  ;
  if (LVar1 == 0) {
    reg_read_dword_default((HKEY)key,s_timePlayed_004745f8,(uint *)&stack0xffffffa4,0);
    DAT_0048718c = in_stack_ffffffa4;
    RegCloseKey(key);
  }
  return;
}



