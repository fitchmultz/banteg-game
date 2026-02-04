/* grim_texture_init @ 10004a50 */

/* allocates/copies texture name and zeroes fields */

void * __thiscall grim_texture_init(void *this,void *texture,char *name)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar3 = 0xffffffff;
  pcVar2 = texture;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = operator_new(~uVar3);
  uVar3 = 0xffffffff;
  *(char **)this = pcVar2;
  do {
    pcVar5 = texture;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = (char *)((int)texture + 1);
    cVar1 = *(char *)texture;
    texture = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar2 = pcVar2 + 1;
  }
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  return this;
}



