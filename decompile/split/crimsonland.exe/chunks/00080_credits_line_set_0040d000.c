/* credits_line_set @ 0040d000 */

/* stores a credits line string + flags into the credits line table */

void __cdecl credits_line_set(int index,char *text,int flags)

{
  char *pcVar1;
  
  credits_line_table[index].flags = flags;
  if (credits_line_table[index].text != (char *)0x0) {
    crt_free(credits_line_table[index].text);
  }
  pcVar1 = strdup_malloc(text);
  credits_line_table[index].text = pcVar1;
  DAT_004811b8 = index;
  return;
}



