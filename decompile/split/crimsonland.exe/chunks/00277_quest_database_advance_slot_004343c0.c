/* quest_database_advance_slot @ 004343c0 */

/* advances quest database tier/index (wraps every 10) */

void __cdecl quest_database_advance_slot(int *tier,int *index)

{
  int iVar1;
  
  iVar1 = *index;
  *index = iVar1 + 1;
  if (9 < iVar1 + 1) {
    *tier = *tier + 1;
    *index = 0;
  }
  return;
}



