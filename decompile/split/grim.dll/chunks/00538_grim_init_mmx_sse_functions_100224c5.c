/* grim_init_mmx_sse_functions @ 100224c5 */

/* fills a function pointer table with MMX/SSE implementations based on CPUID */

void __cdecl grim_init_mmx_sse_functions(undefined4 *table)

{
  ulonglong uVar1;
  
  uVar1 = FUN_100223f0();
  if (((uVar1 & 0x20) != 0) && ((char)uVar1 < '\0')) {
    *table = &LAB_1002dca8;
    table[1] = &LAB_1002d1ea;
    table[2] = &LAB_1002df69;
    table[3] = &LAB_1002943a;
    table[5] = &LAB_1002dcfd;
    table[6] = &LAB_1002d25b;
    table[7] = FUN_1002d2c2;
    table[8] = &LAB_1002dfeb;
    table[9] = &LAB_1002dd36;
    table[10] = &LAB_1002d7a2;
    table[0xb] = &LAB_1002966c;
    table[0xc] = &LAB_1002e393;
    table[0xd] = &LAB_1002e3d6;
    table[0xe] = FUN_1002d7a7;
    table[0xf] = &LAB_1002d92f;
    table[0x10] = &LAB_1002e04a;
    table[0x11] = &LAB_1002dd9a;
    table[0x12] = &LAB_1002d1ce;
    table[0x13] = &LAB_10027ed0;
    table[0x14] = &LAB_10027f69;
    table[0x15] = FUN_1002e578;
    table[0x16] = &LAB_1002e4ba;
    table[0x17] = FUN_10027fc6;
    table[0x18] = &LAB_10028079;
    table[0x19] = &LAB_100284aa;
    table[0x1a] = &LAB_1002973b;
    table[0x1b] = &LAB_1002978b;
    table[0x1c] = &LAB_10029876;
    table[0x1d] = FUN_1002856f;
    table[0x1e] = &LAB_10029952;
    table[0x1f] = &LAB_100299b5;
    table[0x20] = &LAB_10029a13;
    table[0x21] = &LAB_10029a6c;
    table[0x22] = &LAB_1002e5dc;
    table[0x23] = FUN_100285db;
    table[0x24] = FUN_10028712;
    table[0x25] = &LAB_10029ab3;
    table[0x26] = &LAB_10029b5b;
    table[0x27] = FUN_10029ce2;
    table[0x28] = FUN_1002ae7a;
    table[0x29] = &LAB_1002b01f;
    table[0x2a] = FUN_1002b553;
    table[0x2b] = FUN_1002879f;
    table[0x2c] = &LAB_10028831;
    table[0x36] = &LAB_1002e17c;
    table[0x33] = &LAB_1002d321;
    table[0x30] = &LAB_1002de32;
    table[0x2e] = &LAB_1002de7b;
    table[0x34] = &LAB_1002e1ed;
    table[0x31] = &LAB_1002d392;
    table[0x37] = FUN_10028895;
    table[0x38] = &LAB_1002893c;
    table[0x35] = &LAB_1002e2b5;
    table[0x2f] = &LAB_1002debe;
    table[0x32] = &LAB_1002d466;
    table[4] = &LAB_1002caa2;
    table[0x2d] = FUN_100289e1;
    if (((uVar1 & 0x100) != 0) && ((uVar1 & 0x200) != 0)) {
      table[0xf] = FUN_1002db55;
      table[0x12] = FUN_1002c7c0;
      table[0x26] = &LAB_10029c2d;
      table[0x27] = FUN_1002b66c;
      table[0x18] = &LAB_10028295;
    }
  }
  return;
}



