/* projectile_reset_pools @ 004205d0 */

/* clears projectile and effect pools (DAT_004926b8, DAT_00493eb8) */

void projectile_reset_pools(void)

{
  projectile_t *ppVar1;
  particle_t *ppVar2;
  
  ppVar1 = projectile_pool;
  do {
    ppVar1->active = '\0';
    ppVar1 = ppVar1 + 1;
  } while ((int)ppVar1 < 0x493eb8);
  ppVar2 = &particle_pool;
  do {
    ppVar2->active = '\0';
    ppVar2 = ppVar2 + 1;
  } while ((int)ppVar2 < 0x495ab8);
  return;
}



