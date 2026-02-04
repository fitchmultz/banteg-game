/* ui_element_set_rect @ 00419ba0 */

/* sets element quad vertices/UVs for a size and offset */

void __cdecl ui_element_set_rect(ui_element_t *element,float width,float height,float *offset)

{
  float fVar1;
  float fVar2;
  _func_1 *p_Var3;
  uchar *puVar4;
  int iVar5;
  
  fVar1 = 1.0 / width;
  element->active = '\0';
  element->enabled = '\0';
  element->_pad0[0] = 0x80;
  element->_pad0[1] = '?';
  element->_pad0[2] = '\0';
  element->_pad0[3] = '\0';
  element->_pad0[4] = 0x80;
  element->_pad0[5] = '?';
  p_Var3 = (_func_1 *)(1.0 / height);
  element->pos_y = width - 1.0;
  element->_pad1[0] = '\0';
  element->_pad1[1] = '\0';
  element->_pad1[2] = 0x80;
  element->_pad1[3] = '?';
  element->quad0[6] = 1.0;
  element->quad0[7] = height - 1.0;
  *(float *)element->_pad2 = width - 1.0;
  element->quad0[0] = height - 1.0;
  *(float *)(element->_pad0 + 0x12) = fVar1;
  fVar2 = 1.0 - fVar1;
  element->pos_x = (float)p_Var3;
  *(float *)(element->_pad1 + 0x10) = fVar2;
  element->on_activate = p_Var3;
  element->quad0[0xb] = fVar1;
  element->quad0[4] = fVar2;
  element->quad0[0xc] = fVar2;
  element->quad0[5] = 1.0 - (float)p_Var3;
  iVar5 = 4;
  puVar4 = element->_pad0 + 2;
  do {
    *(float *)(puVar4 + 0xc) = -NAN;
    *(float *)(puVar4 + 4) = 0.5;
    *(float *)(puVar4 + 8) = 1.0;
    iVar5 = iVar5 + -1;
    *(float *)(puVar4 + -4) = *(float *)(puVar4 + -4) + *offset;
    *(float *)puVar4 = *(float *)puVar4 + offset[1];
    puVar4 = puVar4 + 0x1c;
  } while (iVar5 != 0);
  return;
}



