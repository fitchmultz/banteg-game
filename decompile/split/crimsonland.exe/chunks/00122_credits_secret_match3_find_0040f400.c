/* credits_secret_match3_find @ 0040f400 */

/* scans a 6x6 board for a 3-in-a-row match; writes start index (row-major; leftmost/topmost) +
   orientation (0=vertical, 1=horizontal) */

uint __cdecl credits_secret_match3_find(int *board,int *out_idx,uchar *out_dir)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_4;
  
  local_4 = 0;
  iVar4 = 2;
  piVar2 = board;
  do {
    iVar3 = 0;
    piVar5 = piVar2;
    do {
      iVar1 = *piVar5;
      if (-1 < iVar1) {
        iVar6 = 1;
        if (board[iVar4 + iVar3 + -1] == iVar1) {
          iVar6 = 2;
        }
        if (board[iVar4 + iVar3] == iVar1) {
          iVar6 = iVar6 + 1;
        }
        if (iVar6 == 3) {
          *out_idx = iVar3 + local_4 * 6;
          *out_dir = '\x01';
          return CONCAT31((int3)((uint)out_dir >> 8),1);
        }
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar3 < 4);
    iVar4 = iVar4 + 6;
    local_4 = local_4 + 1;
    piVar2 = piVar2 + 6;
    if (0x25 < iVar4) {
      iVar4 = 0;
      do {
        iVar3 = 0;
        piVar2 = board;
        do {
          iVar1 = *piVar2;
          if (-1 < iVar1) {
            iVar6 = 1;
            if (piVar2[6] == iVar1) {
              iVar6 = 2;
            }
            if (piVar2[0xc] == iVar1) {
              iVar6 = iVar6 + 1;
            }
            if (iVar6 == 3) {
              *out_idx = iVar4 + iVar3 * 6;
              *out_dir = '\0';
              return CONCAT31((int3)((uint)out_idx >> 8),1);
            }
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 6;
        } while (iVar3 < 4);
        iVar4 = iVar4 + 1;
        board = board + 1;
        if (5 < iVar4) {
          return (uint)piVar2 & 0xffffff00;
        }
      } while( true );
    }
  } while( true );
}



