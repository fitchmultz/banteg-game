/* highscore_save_active @ 0043b510 */

/* saves the active high score record */

void highscore_save_active(void)

{
  highscore_save_record((byte *)&highscore_active_record);
  return;
}



