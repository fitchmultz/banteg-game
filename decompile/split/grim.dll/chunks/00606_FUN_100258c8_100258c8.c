/* FUN_100258c8 @ 100258c8 */

void __thiscall FUN_100258c8(void *this,int *param_1)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  png_bytep buf;
  int *png_ptr;
  uint uVar4;
  png_uint_32 pVar5;
  char *msg;
  int iVar6;
  void *local_4;
  
  png_ptr = param_1;
  puVar1 = (uint *)(param_1 + 0x35);
  *puVar1 = *puVar1 + 1;
  if ((uint)param_1[0x30] <= *puVar1) {
    local_4 = this;
    if (*(char *)((int)param_1 + 0x113) != '\0') {
      *puVar1 = 0;
      FUN_100247b3((int)param_1,(char)param_1[0x36],0);
      do {
        *(char *)(png_ptr + 0x45) = (char)png_ptr[0x45] + '\x01';
        bVar2 = *(byte *)(png_ptr + 0x45);
        if (6 < bVar2) goto LAB_10025995;
        iVar6 = (uint)bVar2 * 4;
        uVar4 = ((png_ptr[0x2e] - *(int *)(&DAT_1004ea90 + iVar6)) + -1 +
                *(uint *)(&DAT_1004eaac + iVar6)) / *(uint *)(&DAT_1004eaac + iVar6);
        png_ptr[0x34] = uVar4;
        png_ptr[0x33] = (*(byte *)((int)png_ptr + 0x119) * uVar4 + 7 >> 3) + 1;
      } while (((*(byte *)(png_ptr + 0x18) & 2) == 0) &&
              (png_ptr[0x30] =
                    ((png_ptr[0x2f] - *(int *)(&DAT_1004eac8 + iVar6)) + -1 +
                    *(uint *)(&DAT_1004eae4 + iVar6)) / *(uint *)(&DAT_1004eae4 + iVar6),
              png_ptr[0x34] == 0));
      if (bVar2 < 7) {
        return;
      }
    }
LAB_10025995:
    if ((*(byte *)(png_ptr + 0x17) & 0x20) == 0) {
      png_ptr[0x1c] = (int)&param_1;
      png_ptr[0x1d] = 1;
      while( true ) {
        if (png_ptr[0x1a] == 0) {
          if (png_ptr[0x3f] == 0) {
            do {
              png_crc_finish((png_structp)png_ptr,0);
              png_read_data((png_structp)png_ptr,(png_bytep)&local_4,4);
              pVar5 = png_get_uint_32((png_bytep)&local_4);
              png_ptr[0x3f] = pVar5;
              png_reset_crc((png_structp)png_ptr);
              png_crc_read((png_structp)png_ptr,(png_bytep)(png_ptr + 0x43),4);
              if (png_ptr[0x43] != 0x54414449) {
                png_error((png_structp)png_ptr,"Not enough image data");
              }
            } while (png_ptr[0x3f] == 0);
          }
          uVar4 = png_ptr[0x28];
          uVar3 = png_ptr[0x3f];
          buf = (png_bytep)png_ptr[0x27];
          png_ptr[0x1a] = uVar4;
          ((z_streamp)(png_ptr + 0x19))->next_in = buf;
          if (uVar3 < uVar4) {
            png_ptr[0x1a] = uVar3;
          }
          png_crc_read((png_structp)png_ptr,buf,png_ptr[0x1a]);
          png_ptr[0x3f] = png_ptr[0x3f] - png_ptr[0x1a];
        }
        iVar6 = inflate((z_streamp)(png_ptr + 0x19),1);
        if (iVar6 == 1) break;
        if (iVar6 != 0) {
          msg = (char *)png_ptr[0x1f];
          if (msg == (char *)0x0) {
            msg = "Decompression Error";
          }
          png_error((png_structp)png_ptr,msg);
        }
        if (png_ptr[0x1d] == 0) {
          png_error((png_structp)png_ptr,"Extra compressed data");
        }
      }
      if (((png_ptr[0x1d] == 0) || (png_ptr[0x1a] != 0)) || (png_ptr[0x3f] != 0)) {
        png_error((png_structp)png_ptr,"Extra compressed data");
      }
      png_ptr[0x16] = png_ptr[0x16] | 8;
      png_ptr[0x17] = png_ptr[0x17] | 0x20;
      png_ptr[0x1d] = 0;
    }
    if ((png_ptr[0x3f] != 0) || (png_ptr[0x1a] != 0)) {
      png_error((png_structp)png_ptr,"Extra compression data");
    }
    inflateReset((z_streamp)(png_ptr + 0x19));
    png_ptr[0x16] = png_ptr[0x16] | 8;
  }
  return;
}



