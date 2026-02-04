/* FUN_1004af20 @ 1004af20 */

int __cdecl
FUN_1004af20(uint param_1,uint param_2,int *param_3,uint *param_4,uint *param_5,uint *param_6,
            uint *param_7,int param_8,int param_9)

{
  uint *puVar1;
  int iVar2;
  uint local_4;
  
  local_4 = 0;
  puVar1 = (uint *)(**(code **)(param_9 + 0x20))(*(undefined4 *)(param_9 + 0x28),0x120,4);
  if (puVar1 == (uint *)0x0) {
    return -4;
  }
  iVar2 = FUN_1004aa50(param_3,param_1,0x101,0x100514d0,0x1005154c,param_6,param_4,param_8,&local_4,
                       puVar1);
  if (iVar2 == 0) {
    if (*param_4 != 0) {
      iVar2 = FUN_1004aa50(param_3 + param_1,param_2,0,0x100515c8,0x10051640,param_7,param_5,param_8
                           ,&local_4,puVar1);
      if (iVar2 == 0) {
        if ((*param_5 != 0) || (param_1 < 0x102)) {
          (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
          return 0;
        }
      }
      else {
        if (iVar2 == -3) {
          *(char **)(param_9 + 0x18) = s_oversubscribed_distance_tree_100595e8;
          (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
          return -3;
        }
        if (iVar2 == -5) {
          *(char **)(param_9 + 0x18) = s_incomplete_distance_tree_100595cc;
          (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
          return -3;
        }
        if (iVar2 == -4) goto LAB_1004b053;
      }
      *(char **)(param_9 + 0x18) = s_empty_distance_tree_with_lengths_100595a8;
      iVar2 = -3;
LAB_1004b053:
      (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
      return iVar2;
    }
  }
  else {
    if (iVar2 == -3) {
      *(char **)(param_9 + 0x18) = s_oversubscribed_literal_length_tr_10059584;
      (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
      return -3;
    }
    if (iVar2 == -4) goto LAB_1004b096;
  }
  *(char **)(param_9 + 0x18) = s_incomplete_literal_length_tree_10059564;
  iVar2 = -3;
LAB_1004b096:
  (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),puVar1);
  return iVar2;
}



