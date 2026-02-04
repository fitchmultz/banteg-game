/* game_build_path @ 00402bd0 */

/* builds a game path by combining game_base_path with filename */

char * game_build_path(char *filename)

{
  crt_sprintf(&game_path_buf,s__s__s_00471324,&game_base_path,filename);
  return &game_path_buf;
}



