/* vorbis_mem_open @ 0041ddd0 */

/* open OGG/Vorbis data from a memory buffer (sets callbacks) */

int __thiscall vorbis_mem_open(void *this,void *stream,void *buffer,uint size)

{
  OggVorbis_File *vf;
  int iVar1;
  uint uVar2;
  vorbis_info *pvVar3;
  int *piVar4;
  ogg_int64_t oVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  *(code **)this = vorbis_mem_read;
  *(undefined1 **)((int)this + 4) = &LAB_0041dd40;
  *(undefined1 **)((int)this + 8) = &LAB_0041dd90;
  *(code **)((int)this + 0xc) = vorbis_mem_tell;
  *(undefined4 *)((int)this + 0x2e0) = 0;
  *(void **)((int)this + 0x2ec) = stream;
  *(void **)stream = buffer;
  *(undefined4 *)(*(int *)((int)this + 0x2ec) + 4) = 0;
  vf = (OggVorbis_File *)((int)this + 0x10);
  iVar1 = ov_open_callbacks((void *)(*(int *)((int)this + 0x2ec) + 8),vf,(char *)0x0,0,
                            *(ov_callbacks *)this);
  if (iVar1 < 0) {
    uVar2 = FUN_00461fd5((byte *)s_Input_does_not_appear_to_be_an_O_004739d0);
    return uVar2 & 0xffffff00;
  }
  pvVar3 = ov_info(vf,-1);
  piVar4 = (int *)((int)this + 0x2f0);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar4 = pvVar3->version;
    pvVar3 = (vorbis_info *)&pvVar3->channels;
    piVar4 = piVar4 + 1;
  }
  oVar5 = ov_pcm_total(vf,-1);
  lVar6 = __allmul((uint)oVar5,(int)((ulonglong)oVar5 >> 0x20),*(uint *)((int)this + 0x2f4),
                   (int)*(uint *)((int)this + 0x2f4) >> 0x1f);
  lVar6 = __allmul((uint)lVar6,(int)((ulonglong)lVar6 >> 0x20),0x10,0);
  uVar7 = __alldiv((uint)lVar6,(uint)((ulonglong)lVar6 >> 0x20),8,0);
  *(int *)((int)this + 0x2e4) = (int)uVar7;
  iVar1 = vorbis_mem_tell((void *)(*(int *)((int)this + 0x2ec) + 8));
  *(int *)((int)this + 0x2e8) = iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



