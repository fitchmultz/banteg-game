/* game_sequence_get @ 0041df60 */

/* returns the saved game_sequence_id */

int game_sequence_get(void)

{
  return game_status_blob.game_sequence_id;
}



