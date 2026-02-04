/* sfx_entry_resume @ 0043bf40 */

/* restarts playback for a streaming entry */

void __cdecl sfx_entry_resume(int entry)

{
  if (*(int *)(entry + 0x74) != 0) {
    (**(code **)(**(int **)(entry + 0x24) + 0x30))(*(int **)(entry + 0x24),0,0,1);
  }
  return;
}



