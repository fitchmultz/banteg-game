/* FUN_1002317a @ 1002317a */

void __fastcall FUN_1002317a(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  
  *(undefined4 *)(*in_EAX + 0x14) = 0x35;
  *(undefined4 *)(*in_EAX + 0x18) = param_2;
  (**(code **)*in_EAX)();
  return;
}



