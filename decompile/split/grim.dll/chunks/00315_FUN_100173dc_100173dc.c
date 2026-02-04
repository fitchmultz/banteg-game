/* FUN_100173dc @ 100173dc */

/* [binja] int32_t __fastcall sub_100173dc(int32_t* arg1) */

int __fastcall FUN_100173dc(int *arg1)

{
  int *piVar1;
  int *piVar2;
  undefined1 local_28 [8];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = arg1[0x416];
  local_14 = arg1[0x419];
  local_18 = arg1[6];
  local_1c = arg1[0xb];
  local_20 = arg1[4];
  arg1[0x419] = arg1[0x41a];
  arg1[0x416] = 1;
  arg1[6] = (int)local_28;
  arg1[0xb] = (int)&DAT_10054398;
  arg1[4] = 0;
  if (arg1[2] != 1) {
    piVar1 = arg1 + 0x412;
    local_8 = *piVar1;
    piVar2 = arg1 + 0x413;
    local_c = *piVar2;
    *piVar1 = 1;
    *piVar2 = (int)(arg1 + 7);
    grim_convert_vertex_space(arg1,(float *)(arg1 + 7));
    *piVar1 = local_8;
    *piVar2 = local_c;
  }
  (**(code **)(*arg1 + 8))(0,0,arg1 + 7);
  (**(code **)(*arg1 + 4))(0,0,arg1 + 7);
  arg1[0x416] = local_10;
  arg1[0x419] = local_14;
  arg1[6] = local_18;
  arg1[0xb] = local_1c;
  arg1[4] = local_20;
  return local_20;
}



