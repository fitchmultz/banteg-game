/* inflate @ 1002438b */

/* zlib: inflate compressed data */

int __cdecl inflate(z_streamp strm,int flush)

{
  byte bVar1;
  int iVar2;
  internal_state *piVar3;
  int iVar4;
  
  if (((strm == (z_streamp)0x0) || (piVar3 = strm->state, piVar3 == (internal_state *)0x0)) ||
     (strm->next_in == (Bytef *)0x0)) {
LAB_100245c8:
    return -2;
  }
  iVar2 = -5;
  iVar4 = 0;
  if (flush == 4) {
    iVar4 = iVar2;
  }
LAB_100245bb:
  switch(piVar3->dummy) {
  case 0:
    if (strm->avail_in == 0) {
      return iVar2;
    }
    strm->total_in = strm->total_in + 1;
    strm->avail_in = strm->avail_in - 1;
    strm->state[1].dummy = (uint)*strm->next_in;
    piVar3 = strm->state;
    iVar2 = piVar3[1].dummy;
    strm->next_in = strm->next_in + 1;
    if (((byte)iVar2 & 0xf) == 8) {
      if (((uint)piVar3[1].dummy >> 4) + 8 <= (uint)piVar3[4].dummy) {
        piVar3->dummy = 1;
        iVar2 = iVar4;
        goto switchD_100243c8_caseD_1;
      }
      piVar3->dummy = 0xd;
      strm->msg = "invalid window size";
    }
    else {
      piVar3->dummy = 0xd;
      strm->msg = "unknown compression method";
    }
    goto LAB_100245ae;
  case 1:
switchD_100243c8_caseD_1:
    if (strm->avail_in == 0) {
      return iVar2;
    }
    piVar3 = strm->state;
    strm->total_in = strm->total_in + 1;
    strm->avail_in = strm->avail_in - 1;
    bVar1 = *strm->next_in;
    strm->next_in = strm->next_in + 1;
    if ((piVar3[1].dummy * 0x100 + (uint)bVar1) % 0x1f != 0) {
      piVar3->dummy = 0xd;
      strm->msg = "incorrect header check";
      goto LAB_100245ae;
    }
    if ((bVar1 & 0x20) != 0) {
      strm->state->dummy = 2;
      iVar2 = iVar4;
      goto switchD_100243c8_caseD_2;
    }
    piVar3->dummy = 7;
    iVar2 = iVar4;
    break;
  case 2:
switchD_100243c8_caseD_2:
    if (strm->avail_in == 0) {
      return iVar2;
    }
    strm->total_in = strm->total_in + 1;
    strm->avail_in = strm->avail_in - 1;
    strm->state[2].dummy = (uint)*strm->next_in << 0x18;
    strm->next_in = strm->next_in + 1;
    strm->state->dummy = 3;
    iVar2 = iVar4;
  case 3:
    goto switchD_100243c8_caseD_3;
  case 4:
    goto switchD_100243c8_caseD_4;
  case 5:
    goto switchD_100243c8_caseD_5;
  case 6:
    strm->state->dummy = 0xd;
    strm->msg = "need dictionary";
    strm->state[1].dummy = 0;
    return -2;
  case 7:
    iVar2 = inflate_blocks((void *)strm->state[5].dummy,strm,iVar2);
    if (iVar2 == -3) {
      strm->state->dummy = 0xd;
      strm->state[1].dummy = 0;
      iVar2 = -3;
    }
    else {
      if (iVar2 == 0) {
        iVar2 = iVar4;
      }
      if (iVar2 != 1) {
        return iVar2;
      }
      inflate_blocks_reset((void *)strm->state[5].dummy,strm,(uLongf *)(strm->state + 1));
      piVar3 = strm->state;
      if (piVar3[3].dummy == 0) {
        piVar3->dummy = 8;
        iVar2 = iVar4;
        goto switchD_100243c8_caseD_8;
      }
      piVar3->dummy = 0xc;
      iVar2 = iVar4;
    }
    break;
  case 8:
switchD_100243c8_caseD_8:
    if (strm->avail_in == 0) {
      return iVar2;
    }
    strm->total_in = strm->total_in + 1;
    strm->avail_in = strm->avail_in - 1;
    strm->state[2].dummy = (uint)*strm->next_in << 0x18;
    strm->next_in = strm->next_in + 1;
    strm->state->dummy = 9;
    iVar2 = iVar4;
  case 9:
    if (strm->avail_in == 0) {
      return iVar2;
    }
    strm->total_in = strm->total_in + 1;
    strm->avail_in = strm->avail_in - 1;
    strm->state[2].dummy = strm->state[2].dummy + (uint)*strm->next_in * 0x10000;
    strm->next_in = strm->next_in + 1;
    strm->state->dummy = 10;
    iVar2 = iVar4;
  case 10:
    goto switchD_100243c8_caseD_a;
  case 0xb:
    goto switchD_100243c8_caseD_b;
  case 0xc:
    goto LAB_100245c8;
  case 0xd:
    return -3;
  default:
    goto LAB_100245c8;
  }
LAB_100245b8:
  piVar3 = strm->state;
  goto LAB_100245bb;
switchD_100243c8_caseD_a:
  if (strm->avail_in == 0) {
    return iVar2;
  }
  strm->total_in = strm->total_in + 1;
  strm->avail_in = strm->avail_in - 1;
  strm->state[2].dummy = strm->state[2].dummy + (uint)*strm->next_in * 0x100;
  strm->next_in = strm->next_in + 1;
  strm->state->dummy = 0xb;
  iVar2 = iVar4;
switchD_100243c8_caseD_b:
  if (strm->avail_in == 0) {
    return iVar2;
  }
  strm->total_in = strm->total_in + 1;
  strm->avail_in = strm->avail_in - 1;
  strm->state[2].dummy = strm->state[2].dummy + (uint)*strm->next_in;
  piVar3 = strm->state;
  strm->next_in = strm->next_in + 1;
  if (piVar3[1].dummy == piVar3[2].dummy) {
    strm->state->dummy = 0xc;
LAB_100245c8:
    return 1;
  }
  piVar3->dummy = 0xd;
  strm->msg = "incorrect data check";
LAB_100245ae:
  strm->state[1].dummy = 5;
  iVar2 = iVar4;
  goto LAB_100245b8;
switchD_100243c8_caseD_3:
  if (strm->avail_in == 0) {
    return iVar2;
  }
  strm->total_in = strm->total_in + 1;
  strm->avail_in = strm->avail_in - 1;
  strm->state[2].dummy = strm->state[2].dummy + (uint)*strm->next_in * 0x10000;
  strm->next_in = strm->next_in + 1;
  strm->state->dummy = 4;
  iVar2 = iVar4;
switchD_100243c8_caseD_4:
  if (strm->avail_in == 0) {
    return iVar2;
  }
  strm->total_in = strm->total_in + 1;
  strm->avail_in = strm->avail_in - 1;
  strm->state[2].dummy = strm->state[2].dummy + (uint)*strm->next_in * 0x100;
  strm->next_in = strm->next_in + 1;
  strm->state->dummy = 5;
  iVar2 = iVar4;
switchD_100243c8_caseD_5:
  if (strm->avail_in != 0) {
    strm->total_in = strm->total_in + 1;
    strm->avail_in = strm->avail_in - 1;
    strm->state[2].dummy = strm->state[2].dummy + (uint)*strm->next_in;
    strm->next_in = strm->next_in + 1;
    strm->adler = strm->state[2].dummy;
    strm->state->dummy = 6;
    return 2;
  }
  return iVar2;
}



