/* game_sequence_load @ 00412a10 */

/* reads the sequence value from registry */

void game_sequence_load(void)

{
  LONG LVar1;
  HKEY local_8;
  uint local_4;
  
  LVar1 = RegCreateKeyExA((HKEY)0x80000002,(LPCSTR)&DAT_004852d0,0,(LPSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,(PHKEY)&local_8,(LPDWORD)0x0);
  if (LVar1 == 0) {
    reg_read_dword_default(local_8,s_sequence_0047361c,&local_4,0);
    if (game_status_blob.game_sequence_id < local_4) {
      game_status_blob.game_sequence_id = local_4;
    }
    RegCloseKey((HKEY)local_8);
  }
  return;
}



