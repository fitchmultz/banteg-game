/* FUN_1001be91 @ 1001be91 */

/* [binja] int32_t __fastcall sub_1001be91(int32_t* arg1) */

int __fastcall FUN_1001be91(int *arg1)

{
  if ((LPCVOID)arg1[2] != (LPCVOID)0x0) {
    UnmapViewOfFile((LPCVOID)arg1[2]);
    arg1[2] = 0;
    arg1[3] = 0;
  }
  if ((HANDLE)arg1[1] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)arg1[1]);
    arg1[1] = -1;
  }
  if ((HANDLE)*arg1 != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)*arg1);
    *arg1 = -1;
  }
  return 0;
}



