/* crt_strtok @ 0046135d */

/* CRT: tokenize string, uses TLS for state */

char * __cdecl crt_strtok(char *str,char *delim)

{
  byte bVar1;
  DWORD *pDVar2;
  int iVar3;
  byte *pbVar4;
  byte local_24 [32];
  
  pDVar2 = crt_get_thread_data();
  pbVar4 = local_24;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    pbVar4 = pbVar4 + 4;
  }
  do {
    bVar1 = *delim;
    local_24[bVar1 >> 3] = local_24[bVar1 >> 3] | '\x01' << (bVar1 & 7);
    delim = (char *)((byte *)delim + 1);
  } while (bVar1 != 0);
  if (str == (char *)0x0) {
    str = (char *)pDVar2[6];
  }
  for (; (bVar1 = *str, pbVar4 = (byte *)str, (local_24[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0
         && (bVar1 != 0)); str = (char *)((byte *)str + 1)) {
  }
  do {
    bVar1 = *pbVar4;
    if (bVar1 == 0) {
LAB_004613ec:
      pDVar2[6] = (DWORD)pbVar4;
      return (char *)(-(uint)((byte *)str != pbVar4) & (uint)str);
    }
    if ((local_24[bVar1 >> 3] & (byte)(1 << (bVar1 & 7))) != 0) {
      *pbVar4 = 0;
      pbVar4 = pbVar4 + 1;
      goto LAB_004613ec;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}



