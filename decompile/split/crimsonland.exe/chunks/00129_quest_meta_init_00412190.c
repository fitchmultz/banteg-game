/* quest_meta_init @ 00412190 */

/* [binja] int32_t sub_412190() */

int quest_meta_init(void)

{
  int extraout_EAX;
  
  crt_ehvec_ctor(&quest_selected_meta,0x2c,0x32,&LAB_004121b0,&LAB_004121e0);
  return extraout_EAX;
}



