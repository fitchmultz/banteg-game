/* FUN_10002f60 @ 10002f60 */

/* [binja] BOOL __fastcall sub_10002f60(void* arg1) */

bool __fastcall FUN_10002f60(void *arg1)

{
  undefined1 uVar1;
  WINBOOL WVar2;
  
  uVar1 = 0;
  if (*(HGDIOBJ *)((int)arg1 + 0x1c) != (HGDIOBJ)0x0) {
    WVar2 = DeleteObject(*(HGDIOBJ *)((int)arg1 + 0x1c));
    uVar1 = (undefined1)WVar2;
    *(undefined4 *)((int)arg1 + 0x1c) = 0;
  }
  return (bool)uVar1;
}



