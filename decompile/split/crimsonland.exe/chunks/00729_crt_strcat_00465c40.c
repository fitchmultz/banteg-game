/* crt_strcat @ 00465c40 */

/* CRT strcat implementation (seek end, then copy) */

char * __cdecl crt_strcat(char *dst,char *src)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar3 = (uint *)dst;
  do {
    if (((uint)puVar3 & 3) == 0) goto LAB_00465c5c;
    uVar4 = *puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_00465c8f;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar5 = (uint *)((int)puVar5 + 2);
      goto joined_r0x00465cab;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_00465c5c:
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + 1;
    } while (((*puVar5 ^ 0xffffffff ^ *puVar5 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar5;
    if ((char)uVar4 == '\0') goto joined_r0x00465cab;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar5 = (uint *)((int)puVar5 + 1);
      goto joined_r0x00465cab;
    }
  }
LAB_00465c8f:
  puVar5 = (uint *)((int)puVar3 + -1);
joined_r0x00465cab:
  do {
    if (((uint)src & 3) == 0) {
      do {
        uVar2 = *(uint *)src;
        uVar4 = *(uint *)src;
        src = (char *)((int)src + 4);
        if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uVar4 == '\0') {
LAB_00465d18:
            *(byte *)puVar5 = (byte)uVar4;
            return dst;
          }
          if ((char)(uVar4 >> 8) == '\0') {
            *(short *)puVar5 = (short)uVar4;
            return dst;
          }
          if ((uVar4 & 0xff0000) == 0) {
            *(short *)puVar5 = (short)uVar4;
            *(byte *)((int)puVar5 + 2) = 0;
            return dst;
          }
          if ((uVar4 & 0xff000000) == 0) {
            *puVar5 = uVar4;
            return dst;
          }
        }
        *puVar5 = uVar4;
        puVar5 = puVar5 + 1;
      } while( true );
    }
    bVar1 = (byte)*(uint *)src;
    uVar4 = (uint)bVar1;
    src = (char *)((int)src + 1);
    if (bVar1 == 0) goto LAB_00465d18;
    *(byte *)puVar5 = bVar1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while( true );
}



