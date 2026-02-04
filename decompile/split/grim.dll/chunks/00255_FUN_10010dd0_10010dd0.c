/* FUN_10010dd0 @ 10010dd0 */

void FUN_10010dd0(int *param_1)

{
  (**(code **)(*param_1 + 8))(param_1);
                    /* WARNING: Subroutine does not return */
  longjmp((int *)(*param_1 + 0x84),1);
}



