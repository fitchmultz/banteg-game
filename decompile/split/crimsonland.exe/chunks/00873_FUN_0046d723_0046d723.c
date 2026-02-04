/* FUN_0046d723 @ 0046d723 */

/* [binja] int32_t sub_46d723(void* arg1) */

int __cdecl FUN_0046d723(void *arg1)

{
  bool bVar1;
  DWORD *pDVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  undefined4 *puVar7;
  DWORD local_10;
  DWORD local_c;
  
  bVar1 = false;
  if (arg1 == (void *)0x2) {
    puVar7 = &DAT_004d9cc4;
    pcVar6 = DAT_004d9cc4;
LAB_0046d7a9:
    bVar1 = true;
    crt_lock(1);
    pDVar2 = arg1;
  }
  else {
    if (((arg1 != (void *)0x4) && (arg1 != (void *)0x8)) && (arg1 != (void *)0xb)) {
      if (arg1 == (void *)0xf) {
        puVar7 = &DAT_004d9cd0;
        pcVar6 = DAT_004d9cd0;
      }
      else if (arg1 == (void *)0x15) {
        puVar7 = &DAT_004d9cc8;
        pcVar6 = DAT_004d9cc8;
      }
      else {
        if (arg1 != (void *)0x16) {
          return -1;
        }
        puVar7 = &DAT_004d9ccc;
        pcVar6 = DAT_004d9ccc;
      }
      goto LAB_0046d7a9;
    }
    pDVar2 = crt_get_thread_data();
    uVar3 = FUN_0046d8a5((int)arg1,pDVar2[0x14]);
    puVar7 = (undefined4 *)(uVar3 + 8);
    pcVar6 = (code *)*puVar7;
  }
  if (pcVar6 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    crt_unlock(1);
    return 0;
  }
  if (pcVar6 == (code *)0x0) {
    if (bVar1) {
      crt_unlock(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((arg1 == (void *)0x8) || (arg1 == (void *)0xb)) || (arg1 == (void *)0x4)) {
    local_c = pDVar2[0x15];
    pDVar2[0x15] = 0;
    if (arg1 == (void *)0x8) {
      local_10 = pDVar2[0x16];
      pDVar2[0x16] = 0x8c;
      goto LAB_0046d81d;
    }
  }
  else {
LAB_0046d81d:
    if (arg1 == (void *)0x8) {
      if (DAT_0047bad8 < DAT_0047badc + DAT_0047bad8) {
        iVar4 = DAT_0047bad8 * 0xc;
        iVar5 = DAT_0047bad8;
        do {
          iVar4 = iVar4 + 0xc;
          *(undefined4 *)((pDVar2[0x14] - 4) + iVar4) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < DAT_0047badc + DAT_0047bad8);
      }
      goto LAB_0046d85b;
    }
  }
  *puVar7 = 0;
LAB_0046d85b:
  if (bVar1) {
    crt_unlock(1);
  }
  if (arg1 == (void *)0x8) {
    (*pcVar6)(8,pDVar2[0x16]);
  }
  else {
    (*pcVar6)(arg1);
    if ((arg1 != (void *)0xb) && (arg1 != (void *)0x4)) {
      return 0;
    }
  }
  pDVar2[0x15] = local_c;
  if (arg1 == (void *)0x8) {
    pDVar2[0x16] = local_10;
  }
  return 0;
}



