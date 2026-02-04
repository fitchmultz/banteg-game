/* crt_exception_filter @ 004668e9 */

/* CRT exception filter/dispatch */

long __cdecl crt_exception_filter(int code,_EXCEPTION_POINTERS *info)

{
  code *pcVar1;
  DWORD DVar2;
  DWORD DVar3;
  DWORD *pDVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  
  pDVar4 = crt_get_thread_data();
  piVar5 = FUN_00466a27(code,(int *)pDVar4[0x14]);
  if ((piVar5 == (int *)0x0) || (pcVar1 = (code *)piVar5[2], pcVar1 == (code *)0x0)) {
    lVar6 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)info);
  }
  else if (pcVar1 == (code *)0x5) {
    piVar5[2] = 0;
    lVar6 = 1;
  }
  else {
    if (pcVar1 != (code *)0x1) {
      DVar2 = pDVar4[0x15];
      pDVar4[0x15] = (DWORD)info;
      if (piVar5[1] == 8) {
        if (DAT_0047bad8 < DAT_0047badc + DAT_0047bad8) {
          iVar7 = DAT_0047bad8 * 0xc;
          iVar8 = DAT_0047bad8;
          do {
            *(undefined4 *)(iVar7 + 8 + pDVar4[0x14]) = 0;
            iVar8 = iVar8 + 1;
            iVar7 = iVar7 + 0xc;
          } while (iVar8 < DAT_0047badc + DAT_0047bad8);
        }
        iVar7 = *piVar5;
        DVar3 = pDVar4[0x16];
        if (iVar7 == -0x3fffff72) {
          pDVar4[0x16] = 0x83;
        }
        else if (iVar7 == -0x3fffff70) {
          pDVar4[0x16] = 0x81;
        }
        else if (iVar7 == -0x3fffff6f) {
          pDVar4[0x16] = 0x84;
        }
        else if (iVar7 == -0x3fffff6d) {
          pDVar4[0x16] = 0x85;
        }
        else if (iVar7 == -0x3fffff73) {
          pDVar4[0x16] = 0x82;
        }
        else if (iVar7 == -0x3fffff71) {
          pDVar4[0x16] = 0x86;
        }
        else if (iVar7 == -0x3fffff6e) {
          pDVar4[0x16] = 0x8a;
        }
        (*pcVar1)(8,pDVar4[0x16]);
        pDVar4[0x16] = DVar3;
      }
      else {
        piVar5[2] = 0;
        (*pcVar1)(piVar5[1]);
      }
      pDVar4[0x15] = DVar2;
    }
    lVar6 = -1;
  }
  return lVar6;
}



