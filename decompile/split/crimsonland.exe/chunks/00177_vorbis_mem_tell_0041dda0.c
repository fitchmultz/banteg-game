/* vorbis_mem_tell @ 0041dda0 */

/* ov_open_callbacks tell hook (returns current offset) */

int __cdecl vorbis_mem_tell(void *datasource)

{
  return *(int *)((int)datasource + -4);
}



