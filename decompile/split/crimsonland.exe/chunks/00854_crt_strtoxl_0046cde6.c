/* crt_strtoxl @ 0046cde6 */

/* CRT: shared strto* core (base/sign/overflow) */

ulong __thiscall crt_strtoxl(void *this,void *locale,char *str,char **endptr,int base,uint flags)

{
  byte *pbVar1;
  char **ppcVar2;
  uint uVar3;
  char **ppcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  char **this_00;
  byte bVar8;
  undefined *puVar9;
  char **local_c;
  byte *local_8;
  
  local_c = (char **)0x0;
  bVar8 = *(byte *)locale;
  pbVar1 = locale;
  while( true ) {
    local_8 = pbVar1 + 1;
    if (DAT_0047b3cc < 2) {
      uVar3 = (byte)crt_ctype_table[(uint)bVar8 * 2] & 8;
      this = crt_ctype_table;
    }
    else {
      puVar9 = (undefined *)0x8;
      uVar3 = crt_isctype(this,(uint)bVar8,8);
      this = puVar9;
    }
    if (uVar3 == 0) break;
    bVar8 = *local_8;
    pbVar1 = local_8;
  }
  if (bVar8 == 0x2d) {
    base = base | 2;
LAB_0046ce41:
    bVar8 = *local_8;
    local_8 = pbVar1 + 2;
  }
  else if (bVar8 == 0x2b) goto LAB_0046ce41;
  if ((((int)endptr < 0) || (endptr == (char **)0x1)) || (0x24 < (int)endptr)) {
    if (str != (char *)0x0) {
      *(void **)str = locale;
    }
    return 0;
  }
  this_00 = (char **)0x10;
  if (endptr == (char **)0x0) {
    if (bVar8 != 0x30) {
      endptr = (char **)0xa;
      goto LAB_0046ceab;
    }
    if ((*local_8 != 0x78) && (*local_8 != 0x58)) {
      endptr = (char **)0x8;
      goto LAB_0046ceab;
    }
    endptr = (char **)0x10;
  }
  if (((endptr == (char **)0x10) && (bVar8 == 0x30)) && ((*local_8 == 0x78 || (*local_8 == 0x58))))
  {
    bVar8 = local_8[1];
    local_8 = local_8 + 2;
  }
LAB_0046ceab:
  ppcVar4 = (char **)(0xffffffff / ZEXT48(endptr));
  do {
    uVar3 = (uint)bVar8;
    if (DAT_0047b3cc < 2) {
      uVar5 = (byte)crt_ctype_table[uVar3 * 2] & 4;
    }
    else {
      ppcVar2 = (char **)0x4;
      uVar5 = crt_isctype(this_00,uVar3,4);
      this_00 = ppcVar2;
    }
    if (uVar5 == 0) {
      if (DAT_0047b3cc < 2) {
        uVar3 = *(ushort *)(crt_ctype_table + uVar3 * 2) & 0x103;
      }
      else {
        uVar3 = crt_isctype(this_00,uVar3,0x103);
      }
      if (uVar3 == 0) {
LAB_0046cf57:
        local_8 = local_8 + -1;
        if ((base & 8U) == 0) {
          if (str != (char *)0x0) {
            local_8 = locale;
          }
          local_c = (char **)0x0;
        }
        else if (((base & 4U) != 0) ||
                (((base & 1U) == 0 &&
                 ((((base & 2U) != 0 && ((char **)0x80000000 < local_c)) ||
                  (((base & 2U) == 0 && ((char **)0x7fffffff < local_c)))))))) {
          piVar7 = crt_errno_ptr();
          *piVar7 = 0x22;
          if ((base & 1U) == 0) {
            local_c = (char **)(((base & 2U) != 0) + 0x7fffffff);
          }
          else {
            local_c = (char **)0xffffffff;
          }
        }
        if (str != (char *)0x0) {
          *(byte **)str = local_8;
        }
        if ((base & 2U) == 0) {
          return (ulong)local_c;
        }
        return -(int)local_c;
      }
      iVar6 = crt_toupper((int)(char)bVar8);
      this_00 = (char **)(iVar6 + -0x37);
    }
    else {
      this_00 = (char **)((char)bVar8 + -0x30);
    }
    if (endptr <= this_00) goto LAB_0046cf57;
    if ((local_c < ppcVar4) ||
       ((local_c == ppcVar4 && (this_00 <= (char **)(0xffffffff % ZEXT48(endptr)))))) {
      local_c = (char **)((int)local_c * (int)endptr + (int)this_00);
      base = base | 8;
    }
    else {
      base = base | 0xc;
    }
    bVar8 = *local_8;
    local_8 = local_8 + 1;
  } while( true );
}



