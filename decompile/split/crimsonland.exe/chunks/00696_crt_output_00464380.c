/* crt_output @ 00464380 */

/* CRT: core printf formatter */

int __cdecl crt_output(int *param_1,byte *param_2,undefined4 *param_3)

{
  byte *pbVar1;
  uint uVar2;
  WCHAR *pWVar3;
  void *pvVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  int extraout_EDX;
  byte bVar8;
  int iVar9;
  WCHAR *pWVar10;
  undefined1 *puVar11;
  undefined8 uVar12;
  WCHAR local_250 [255];
  undefined1 local_51;
  undefined4 local_50;
  undefined4 local_4c;
  CHAR local_48 [4];
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  WCHAR *local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined8 local_24;
  char local_1a;
  char local_19;
  int local_18;
  undefined1 *local_14;
  WCHAR *local_10;
  int local_c;
  uint local_8;
  
  local_40 = 0;
  local_14 = (undefined1 *)0x0;
  bVar8 = *param_2;
  local_18 = 0;
  local_34 = (WCHAR *)0x0;
  pbVar1 = param_2;
  do {
    if ((bVar8 == 0) || (param_2 = pbVar1 + 1, local_18 < 0)) {
      return local_18;
    }
    if (((char)bVar8 < ' ') || ('x' < (char)bVar8)) {
      uVar2 = 0;
    }
    else {
      uVar2 = (byte)"e+000"[(char)bVar8] & 0xf;
    }
    local_40 = (int)(char)(&DAT_0046fad8)[uVar2 * 8 + local_40] >> 4;
    switch(local_40) {
    case 0:
switchD_004643fc_caseD_0:
      local_30 = 0;
      if ((crt_ctype_table[(uint)bVar8 * 2 + 1] & 0x80) != 0) {
        crt_putc_nolock((int)(char)bVar8,param_1,&local_18);
        bVar8 = *param_2;
        param_2 = pbVar1 + 2;
      }
      crt_putc_nolock((int)(char)bVar8,param_1,&local_18);
      break;
    case 1:
      local_c = -1;
      local_44 = 0;
      local_3c = 0;
      local_2c = 0;
      local_28 = 0;
      local_8 = 0;
      local_30 = 0;
      break;
    case 2:
      if (bVar8 == 0x20) {
        local_8 = local_8 | 2;
      }
      else if (bVar8 == 0x23) {
        local_8 = local_8 | 0x80;
      }
      else if (bVar8 == 0x2b) {
        local_8 = local_8 | 1;
      }
      else if (bVar8 == 0x2d) {
        local_8 = local_8 | 4;
      }
      else if (bVar8 == 0x30) {
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (bVar8 == 0x2a) {
        local_2c = FUN_00464bbc((int *)&param_3);
        if (local_2c < 0) {
          local_8 = local_8 | 4;
          local_2c = -local_2c;
        }
      }
      else {
        local_2c = (char)bVar8 + -0x30 + local_2c * 10;
      }
      break;
    case 4:
      local_c = 0;
      break;
    case 5:
      if (bVar8 == 0x2a) {
        local_c = FUN_00464bbc((int *)&param_3);
        if (local_c < 0) {
          local_c = -1;
        }
      }
      else {
        local_c = (char)bVar8 + -0x30 + local_c * 10;
      }
      break;
    case 6:
      if (bVar8 == 0x49) {
        if ((*param_2 != 0x36) || (pbVar1[2] != 0x34)) {
          local_40 = 0;
          goto switchD_004643fc_caseD_0;
        }
        param_2 = pbVar1 + 3;
        local_8 = local_8 | 0x8000;
      }
      else if (bVar8 == 0x68) {
        local_8 = local_8 | 0x20;
      }
      else if (bVar8 == 0x6c) {
        local_8 = local_8 | 0x10;
      }
      else if (bVar8 == 0x77) {
        local_8 = local_8 | 0x800;
      }
      break;
    case 7:
      pWVar10 = local_10;
      if ((char)bVar8 < 'h') {
        if ((char)bVar8 < 'e') {
          if ((char)bVar8 < 'Y') {
            if (bVar8 != 0x58) {
              if (bVar8 == 0x43) {
                if ((local_8 & 0x830) == 0) {
                  local_8 = local_8 | 0x800;
                }
                goto LAB_00464651;
              }
              if ((bVar8 != 0x45) && (bVar8 != 0x47)) {
                if (bVar8 == 0x53) {
                  if ((local_8 & 0x830) == 0) {
                    local_8 = local_8 | 0x800;
                  }
                  goto LAB_004645c1;
                }
                goto LAB_004649d4;
              }
              local_44 = 1;
              bVar8 = bVar8 + 0x20;
              goto LAB_00464623;
            }
LAB_00464830:
            local_38 = 7;
LAB_00464837:
            local_14 = (undefined1 *)0x10;
            if ((local_8 & 0x80) != 0) {
              local_1a = '0';
              local_19 = (char)local_38 + 'Q';
              local_28 = 2;
            }
            goto LAB_004648a0;
          }
          if (bVar8 == 0x5a) {
            psVar5 = (short *)FUN_00464bbc((int *)&param_3);
            if ((psVar5 == (short *)0x0) ||
               (pWVar10 = *(WCHAR **)(psVar5 + 2), pWVar10 == (WCHAR *)0x0)) {
              local_10 = (WCHAR *)PTR_DAT_0047b658;
              pWVar10 = (WCHAR *)PTR_DAT_0047b658;
              goto LAB_004647b1;
            }
            if ((local_8 & 0x800) == 0) {
              local_30 = 0;
              local_14 = (undefined1 *)(int)*psVar5;
            }
            else {
              local_30 = 1;
              local_14 = (undefined1 *)((uint)(int)*psVar5 >> 1);
            }
          }
          else if (bVar8 == 99) {
LAB_00464651:
            if ((local_8 & 0x810) == 0) {
              iVar9 = FUN_00464bbc((int *)&param_3);
              local_250[0]._0_1_ = (undefined1)iVar9;
              local_14 = (undefined1 *)0x1;
            }
            else {
              pvVar4 = FUN_00464bd9((int *)&param_3);
              local_14 = (undefined1 *)FUN_0046b0b5((LPSTR)local_250,(WCHAR)pvVar4);
              if ((int)local_14 < 0) {
                local_3c = 1;
              }
            }
            pWVar10 = local_250;
          }
          else if (bVar8 == 100) goto LAB_00464895;
        }
        else {
LAB_00464623:
          local_8 = local_8 | 0x40;
          pWVar10 = local_250;
          pWVar3 = local_250;
          if (local_c < 0) {
            local_c = 6;
          }
          else if (local_c == 0) {
            if (bVar8 == 0x67) {
              local_c = 1;
            }
          }
          else {
            if (0x200 < local_c) {
              local_c = 0x200;
            }
            if ((0xa3 < local_c) &&
               (local_10 = local_250, local_34 = _malloc(local_c + 0x15d), pWVar10 = local_34,
               pWVar3 = local_34, local_34 == (WCHAR *)0x0)) {
              local_c = 0xa3;
              pWVar10 = local_250;
              pWVar3 = local_10;
            }
          }
          local_10 = pWVar3;
          local_50 = *param_3;
          local_4c = param_3[1];
          param_3 = param_3 + 2;
          (*(code *)PTR_FUN_0047b1a8)(&local_50,pWVar10,(int)(char)bVar8,local_c,local_44);
          uVar2 = local_8 & 0x80;
          if ((uVar2 != 0) && (local_c == 0)) {
            (*(code *)PTR_FUN_0047b1b4)(pWVar10);
          }
          if ((bVar8 == 0x67) && (uVar2 == 0)) {
            (*(code *)PTR_FUN_0047b1ac)(pWVar10);
          }
          if ((char)*pWVar10 == '-') {
            local_8 = local_8 | 0x100;
            pWVar10 = (WCHAR *)((int)pWVar10 + 1);
            local_10 = pWVar10;
          }
LAB_004647b1:
          local_14 = (undefined1 *)_strlen((char *)pWVar10);
          pWVar10 = local_10;
        }
LAB_004649d4:
        local_10 = pWVar10;
        uVar2 = local_8;
        if (local_3c == 0) {
          if ((local_8 & 0x40) != 0) {
            if ((local_8 & 0x100) == 0) {
              if ((local_8 & 1) == 0) {
                if ((local_8 & 2) == 0) goto LAB_00464a0c;
                local_1a = ' ';
              }
              else {
                local_1a = '+';
              }
            }
            else {
              local_1a = '-';
            }
            local_28 = 1;
          }
LAB_00464a0c:
          iVar9 = (local_2c - local_28) - (int)local_14;
          if ((local_8 & 0xc) == 0) {
            crt_putc_repeat_nolock(0x20,iVar9,param_1,&local_18);
          }
          crt_putc_buffer_nolock(&local_1a,local_28,param_1,&local_18);
          if (((uVar2 & 8) != 0) && ((uVar2 & 4) == 0)) {
            crt_putc_repeat_nolock(0x30,iVar9,param_1,&local_18);
          }
          if ((local_30 == 0) || (puVar11 = local_14, pWVar10 = local_10, (int)local_14 < 1)) {
            crt_putc_buffer_nolock((char *)local_10,(int)local_14,param_1,&local_18);
          }
          else {
            do {
              puVar11 = puVar11 + -1;
              iVar7 = FUN_0046b0b5(local_48,*pWVar10);
              if (iVar7 < 1) break;
              crt_putc_buffer_nolock(local_48,iVar7,param_1,&local_18);
              pWVar10 = pWVar10 + 1;
            } while (puVar11 != (undefined1 *)0x0);
          }
          if ((local_8 & 4) != 0) {
            crt_putc_repeat_nolock(0x20,iVar9,param_1,&local_18);
          }
        }
      }
      else {
        if (bVar8 == 0x69) {
LAB_00464895:
          local_8 = local_8 | 0x40;
LAB_00464899:
          local_14 = (undefined1 *)0xa;
LAB_004648a0:
          if ((local_8 & 0x8000) == 0) {
            if ((local_8 & 0x20) == 0) {
              if ((local_8 & 0x40) == 0) {
                uVar2 = FUN_00464bbc((int *)&param_3);
                iVar9 = 0;
                goto LAB_004648f3;
              }
              uVar2 = FUN_00464bbc((int *)&param_3);
            }
            else if ((local_8 & 0x40) == 0) {
              uVar2 = FUN_00464bbc((int *)&param_3);
              uVar2 = uVar2 & 0xffff;
            }
            else {
              iVar9 = FUN_00464bbc((int *)&param_3);
              uVar2 = (uint)(short)iVar9;
            }
            iVar9 = (int)uVar2 >> 0x1f;
          }
          else {
            uVar2 = FUN_00464bc9((int *)&param_3);
            iVar9 = extraout_EDX;
          }
LAB_004648f3:
          if ((((local_8 & 0x40) == 0) || (0 < iVar9)) || (-1 < iVar9)) {
            local_24 = CONCAT44(iVar9,uVar2);
          }
          else {
            local_8 = local_8 | 0x100;
            local_24 = CONCAT44(-(iVar9 + (uint)(uVar2 != 0)),-uVar2);
          }
          if ((local_8 & 0x8000) == 0) {
            local_24 = local_24 & 0xffffffff;
          }
          if (local_c < 0) {
            local_c = 1;
          }
          else {
            local_8 = local_8 & 0xfffffff7;
            if (0x200 < local_c) {
              local_c = 0x200;
            }
          }
          if ((uint)local_24 == 0 && local_24._4_4_ == 0) {
            local_28 = 0;
          }
          local_10 = (WCHAR *)&local_51;
          while( true ) {
            puVar11 = local_14;
            iVar9 = local_c + -1;
            if ((local_c < 1) && ((uint)local_24 == 0 && local_24._4_4_ == 0)) break;
            uVar2 = (int)local_14 >> 0x1f;
            local_c = iVar9;
            uVar12 = __aullrem((uint)local_24,local_24._4_4_,(uint)local_14,uVar2);
            iVar9 = (int)uVar12 + 0x30;
            local_24 = __aulldiv((uint)local_24,local_24._4_4_,(uint)puVar11,uVar2);
            if (0x39 < iVar9) {
              iVar9 = iVar9 + local_38;
            }
            pWVar10 = (WCHAR *)((int)local_10 + -1);
            *(char *)local_10 = (char)iVar9;
            local_10 = pWVar10;
          }
          iVar7 = -(int)local_10;
          local_14 = &local_51 + iVar7;
          pWVar10 = (WCHAR *)((int)local_10 + 1);
          local_c = iVar9;
          if (((local_8 & 0x200) != 0) &&
             ((*(char *)pWVar10 != '0' || (local_14 == (undefined1 *)0x0)))) {
            *(char *)local_10 = '0';
            local_14 = (undefined1 *)((int)&local_50 + iVar7);
            pWVar10 = local_10;
          }
          goto LAB_004649d4;
        }
        if (bVar8 != 0x6e) {
          if (bVar8 == 0x6f) {
            local_14 = (undefined1 *)0x8;
            if ((local_8 & 0x80) != 0) {
              local_8 = local_8 | 0x200;
            }
            goto LAB_004648a0;
          }
          if (bVar8 == 0x70) {
            local_c = 8;
            goto LAB_00464830;
          }
          if (bVar8 == 0x73) {
LAB_004645c1:
            iVar9 = 0x7fffffff;
            if (local_c != -1) {
              iVar9 = local_c;
            }
            pWVar3 = (WCHAR *)FUN_00464bbc((int *)&param_3);
            if ((local_8 & 0x810) == 0) {
              pWVar10 = pWVar3;
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_0047b658;
                pWVar10 = (WCHAR *)PTR_DAT_0047b658;
              }
              for (; (iVar9 != 0 && ((char)*pWVar3 != '\0')); pWVar3 = (WCHAR *)((int)pWVar3 + 1)) {
                iVar9 = iVar9 + -1;
              }
              local_14 = (undefined1 *)((int)pWVar3 - (int)pWVar10);
            }
            else {
              if (pWVar3 == (WCHAR *)0x0) {
                pWVar3 = (WCHAR *)PTR_DAT_0047b65c;
              }
              local_30 = 1;
              for (pWVar10 = pWVar3; (iVar9 != 0 && (*pWVar10 != L'\0')); pWVar10 = pWVar10 + 1) {
                iVar9 = iVar9 + -1;
              }
              local_14 = (undefined1 *)((int)pWVar10 - (int)pWVar3 >> 1);
              pWVar10 = pWVar3;
            }
            goto LAB_004649d4;
          }
          if (bVar8 != 0x75) {
            if (bVar8 != 0x78) goto LAB_004649d4;
            local_38 = 0x27;
            goto LAB_00464837;
          }
          goto LAB_00464899;
        }
        piVar6 = (int *)FUN_00464bbc((int *)&param_3);
        if ((local_8 & 0x20) == 0) {
          *piVar6 = local_18;
        }
        else {
          *(undefined2 *)piVar6 = (undefined2)local_18;
        }
        local_3c = 1;
      }
      if (local_34 != (WCHAR *)0x0) {
        crt_free_base(local_34);
        local_34 = (WCHAR *)0x0;
      }
    }
    bVar8 = *param_2;
    pbVar1 = param_2;
  } while( true );
}



