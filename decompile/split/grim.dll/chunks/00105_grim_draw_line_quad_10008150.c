/* grim_draw_line_quad @ 10008150 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Grim2D vtable 0xe4 (provisional): line quad from endpoints + half-width vector */

void grim_draw_line_quad(float *p0,float *p1,float *half_vec)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x138))
            (*p0 - *half_vec,p0[1] - half_vec[1],*p0 + *half_vec,p0[1] + half_vec[1],*p1 + *half_vec
             ,p1[1] + half_vec[1],*p1 - *half_vec,p1[1] - half_vec[1]);
  return;
}



