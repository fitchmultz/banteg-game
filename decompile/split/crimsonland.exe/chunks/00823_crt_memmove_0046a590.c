/* crt_memmove @ 0046a590 */

/* CRT: copy memory with overlap handling */

void * __cdecl crt_memmove(void *dst,void *src,size_t size)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((src < dst) && (dst < (void *)(size + (int)src))) {
    puVar3 = (undefined4 *)((size - 4) + (int)src);
    puVar4 = (undefined4 *)((size - 4) + (int)dst);
    if (((uint)puVar4 & 3) == 0) {
      uVar1 = size >> 2;
      uVar2 = size & 3;
      if (7 < uVar1) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + -1;
          puVar4 = puVar4 + -1;
        }
        switch(uVar2) {
        case 0:
          return dst;
        case 2:
          goto switchD_0046a747_caseD_2;
        case 3:
          goto switchD_0046a747_caseD_3;
        }
        goto switchD_0046a747_caseD_1;
      }
    }
    else {
      switch(size) {
      case 0:
        goto switchD_0046a747_caseD_0;
      case 1:
        goto switchD_0046a747_caseD_1;
      case 2:
        goto switchD_0046a747_caseD_2;
      case 3:
        goto switchD_0046a747_caseD_3;
      default:
        uVar1 = size - ((uint)puVar4 & 3);
        switch((uint)puVar4 & 3) {
        case 1:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          puVar3 = (undefined4 *)((int)puVar3 + -1);
          uVar1 = uVar1 >> 2;
          puVar4 = (undefined4 *)((int)puVar4 - 1);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return dst;
            case 2:
              goto switchD_0046a747_caseD_2;
            case 3:
              goto switchD_0046a747_caseD_3;
            }
            goto switchD_0046a747_caseD_1;
          }
          break;
        case 2:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          puVar3 = (undefined4 *)((int)puVar3 + -2);
          puVar4 = (undefined4 *)((int)puVar4 - 2);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return dst;
            case 2:
              goto switchD_0046a747_caseD_2;
            case 3:
              goto switchD_0046a747_caseD_3;
            }
            goto switchD_0046a747_caseD_1;
          }
          break;
        case 3:
          uVar2 = uVar1 & 3;
          *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
          *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
          uVar1 = uVar1 >> 2;
          *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
          puVar3 = (undefined4 *)((int)puVar3 + -3);
          puVar4 = (undefined4 *)((int)puVar4 - 3);
          if (7 < uVar1) {
            for (; uVar1 != 0; uVar1 = uVar1 - 1) {
              *puVar4 = *puVar3;
              puVar3 = puVar3 + -1;
              puVar4 = puVar4 + -1;
            }
            switch(uVar2) {
            case 0:
              return dst;
            case 2:
              goto switchD_0046a747_caseD_2;
            case 3:
              goto switchD_0046a747_caseD_3;
            }
            goto switchD_0046a747_caseD_1;
          }
        }
      }
    }
    switch(uVar1) {
    case 7:
      puVar4[7 - uVar1] = puVar3[7 - uVar1];
    case 6:
      puVar4[6 - uVar1] = puVar3[6 - uVar1];
    case 5:
      puVar4[5 - uVar1] = puVar3[5 - uVar1];
    case 4:
      puVar4[4 - uVar1] = puVar3[4 - uVar1];
    case 3:
      puVar4[3 - uVar1] = puVar3[3 - uVar1];
    case 2:
      puVar4[2 - uVar1] = puVar3[2 - uVar1];
    case 1:
      puVar4[1 - uVar1] = puVar3[1 - uVar1];
      puVar3 = puVar3 + -uVar1;
      puVar4 = puVar4 + -uVar1;
    }
    switch(uVar2) {
    case 1:
switchD_0046a747_caseD_1:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      return dst;
    case 2:
switchD_0046a747_caseD_2:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      return dst;
    case 3:
switchD_0046a747_caseD_3:
      *(undefined1 *)((int)puVar4 + 3) = *(undefined1 *)((int)puVar3 + 3);
      *(undefined1 *)((int)puVar4 + 2) = *(undefined1 *)((int)puVar3 + 2);
      *(undefined1 *)((int)puVar4 + 1) = *(undefined1 *)((int)puVar3 + 1);
      return dst;
    }
switchD_0046a747_caseD_0:
    return dst;
  }
  puVar3 = dst;
  if (((uint)dst & 3) == 0) {
    uVar1 = size >> 2;
    uVar2 = size & 3;
    if (7 < uVar1) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *(undefined4 *)src;
        src = (undefined4 *)((int)src + 4);
        puVar3 = puVar3 + 1;
      }
      switch(uVar2) {
      case 0:
        return dst;
      case 2:
        goto switchD_0046a5c5_caseD_2;
      case 3:
        goto switchD_0046a5c5_caseD_3;
      }
      goto switchD_0046a5c5_caseD_1;
    }
  }
  else {
    switch(size) {
    case 0:
      goto switchD_0046a5c5_caseD_0;
    case 1:
      goto switchD_0046a5c5_caseD_1;
    case 2:
      goto switchD_0046a5c5_caseD_2;
    case 3:
      goto switchD_0046a5c5_caseD_3;
    default:
      uVar1 = (size - 4) + ((uint)dst & 3);
      switch((uint)dst & 3) {
      case 1:
        uVar2 = uVar1 & 3;
        *(undefined1 *)dst = *(undefined1 *)src;
        *(undefined1 *)((int)dst + 1) = *(undefined1 *)((int)src + 1);
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)dst + 2) = *(undefined1 *)((int)src + 2);
        src = (void *)((int)src + 3);
        puVar3 = (undefined4 *)((int)dst + 3);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)src;
            src = (undefined4 *)((int)src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return dst;
          case 2:
            goto switchD_0046a5c5_caseD_2;
          case 3:
            goto switchD_0046a5c5_caseD_3;
          }
          goto switchD_0046a5c5_caseD_1;
        }
        break;
      case 2:
        uVar2 = uVar1 & 3;
        *(undefined1 *)dst = *(undefined1 *)src;
        uVar1 = uVar1 >> 2;
        *(undefined1 *)((int)dst + 1) = *(undefined1 *)((int)src + 1);
        src = (void *)((int)src + 2);
        puVar3 = (undefined4 *)((int)dst + 2);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)src;
            src = (undefined4 *)((int)src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return dst;
          case 2:
            goto switchD_0046a5c5_caseD_2;
          case 3:
            goto switchD_0046a5c5_caseD_3;
          }
          goto switchD_0046a5c5_caseD_1;
        }
        break;
      case 3:
        uVar2 = uVar1 & 3;
        *(undefined1 *)dst = *(undefined1 *)src;
        src = (void *)((int)src + 1);
        uVar1 = uVar1 >> 2;
        puVar3 = (undefined4 *)((int)dst + 1);
        if (7 < uVar1) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar3 = *(undefined4 *)src;
            src = (undefined4 *)((int)src + 4);
            puVar3 = puVar3 + 1;
          }
          switch(uVar2) {
          case 0:
            return dst;
          case 2:
            goto switchD_0046a5c5_caseD_2;
          case 3:
            goto switchD_0046a5c5_caseD_3;
          }
          goto switchD_0046a5c5_caseD_1;
        }
      }
    }
  }
  switch(uVar1) {
  case 7:
    puVar3[uVar1 - 7] = *(undefined4 *)((int)src + (uVar1 - 7) * 4);
  case 6:
    puVar3[uVar1 - 6] = *(undefined4 *)((int)src + (uVar1 - 6) * 4);
  case 5:
    puVar3[uVar1 - 5] = *(undefined4 *)((int)src + (uVar1 - 5) * 4);
  case 4:
    puVar3[uVar1 - 4] = *(undefined4 *)((int)src + (uVar1 - 4) * 4);
  case 3:
    puVar3[uVar1 - 3] = *(undefined4 *)((int)src + (uVar1 - 3) * 4);
  case 2:
    puVar3[uVar1 - 2] = *(undefined4 *)((int)src + (uVar1 - 2) * 4);
  case 1:
    puVar3[uVar1 - 1] = *(undefined4 *)((int)src + (uVar1 - 1) * 4);
    src = (void *)((int)src + uVar1 * 4);
    puVar3 = puVar3 + uVar1;
  }
  switch(uVar2) {
  case 1:
switchD_0046a5c5_caseD_1:
    *(undefined1 *)puVar3 = *(undefined1 *)src;
    return dst;
  case 2:
switchD_0046a5c5_caseD_2:
    *(undefined1 *)puVar3 = *(undefined1 *)src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)src + 1);
    return dst;
  case 3:
switchD_0046a5c5_caseD_3:
    *(undefined1 *)puVar3 = *(undefined1 *)src;
    *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)((int)src + 1);
    *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)src + 2);
    return dst;
  }
switchD_0046a5c5_caseD_0:
  return dst;
}



