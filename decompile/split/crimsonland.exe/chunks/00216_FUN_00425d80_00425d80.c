/* FUN_00425d80 @ 00425d80 */

int __cdecl FUN_00425d80(int param_1)

{
  float fVar1;
  float fVar2;
  creature_t *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  pcVar3 = &creature_pool;
  do {
    if (pcVar3->active != '\0') {
      fVar1 = pcVar3->pos_x - (&creature_pool)[param_1].pos_x;
      fVar2 = pcVar3->pos_y - (&creature_pool)[param_1].pos_y;
      if (SQRT(fVar2 * fVar2 + fVar1 * fVar1) < 45.0) {
        if (((&creature_pool)[iVar4].collision_flag != '\0') &&
           ((&creature_pool)[param_1].health < 150.0)) {
          (&creature_pool)[param_1].collision_flag = '\x01';
        }
        if (((&creature_pool)[param_1].collision_flag != '\0') &&
           ((&creature_pool)[iVar4].health < 150.0)) {
          (&creature_pool)[iVar4].collision_flag = '\x01';
        }
        return iVar4;
      }
    }
    pcVar3 = pcVar3 + 1;
    iVar4 = iVar4 + 1;
  } while ((int)pcVar3 < 0x4aa338);
  return 0;
}



