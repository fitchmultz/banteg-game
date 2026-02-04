/* grim_draw_circle_outline @ 10007d40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */
/* Grim2D vtable 0xdc (provisional): triangle strip ring/outline */

void grim_draw_circle_outline(float x,float y,float radius)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float10 fVar5;
  float10 fVar6;
  int iVar7;
  float fStack_30;
  float **ppfStack_2c;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if ((grim_batch_active == '\0') && (grim_batch_active = '\x01', DAT_1005c898 != '\0')) {
    ppfStack_2c = (float **)0x10007d72;
    (*grim_d3d_device->lpVtbl->BeginScene)(grim_d3d_device);
    ppfStack_2c = &grim_vertex_write_ptr;
    fStack_30 = 0.0;
    iVar1 = (**(code **)(*grim_vertex_buffer + 0x2c))(grim_vertex_buffer,0);
    if (iVar1 < 0) {
      DAT_1005c898 = '\0';
    }
    grim_vertex_count = grim_vertex_count & 0xffff0000;
    iVar1 = ftol();
    iVar7 = 0;
    if (-1 < iVar1) {
      do {
        iVar2 = 7;
        fVar5 = ((float10)iVar7 * (float10)6.2831855) / (float10)iVar1;
        fVar6 = (float10)fcos(fVar5);
        fStack_30 = (float)(fVar6 * (float10)fStack_8 + (float10)fStack_10);
        fVar5 = (float10)fsin(fVar5);
        ppfStack_2c = (float **)(float)(fVar5 * (float10)fStack_8 + (float10)fStack_c);
        pfVar3 = &fStack_30;
        pfVar4 = grim_vertex_write_ptr;
        for (; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pfVar4 = *pfVar3;
          pfVar3 = pfVar3 + 1;
          pfVar4 = pfVar4 + 1;
        }
        fStack_30 = (float)(((float10)fStack_8 + (float10)2.0) * (float10)(float)fVar6 +
                           (float10)fStack_10);
        grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
        grim_vertex_count._0_2_ = (short)grim_vertex_count + 1;
        ppfStack_2c = (float **)
                      (float)(((float10)fStack_8 + (float10)2.0) * fVar5 + (float10)fStack_c);
        pfVar3 = &fStack_30;
        pfVar4 = grim_vertex_write_ptr;
        for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
          *pfVar4 = *pfVar3;
          pfVar3 = pfVar3 + 1;
          pfVar4 = pfVar4 + 1;
        }
        grim_vertex_write_ptr = grim_vertex_write_ptr + 7;
        grim_vertex_count._0_2_ = (short)grim_vertex_count + 1;
        iVar7 = iVar7 + 1;
      } while (iVar7 <= iVar1);
    }
    (**(code **)(*grim_vertex_buffer + 0x30))(grim_vertex_buffer);
    if (DAT_1005c898 != '\0') {
      (*grim_d3d_device->lpVtbl->DrawPrimitive)
                (grim_d3d_device,D3DPT_TRIANGLESTRIP,0,(grim_vertex_count & 0xffff) - 2);
      (*grim_d3d_device->lpVtbl->EndScene)(grim_d3d_device);
      grim_batch_active = '\0';
    }
  }
  return;
}



