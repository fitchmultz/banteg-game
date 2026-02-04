/* grim_window_create @ 10002680 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* registers the window class and creates the main game window */

BOOL grim_window_create(void)

{
  HWND hWndParent;
  int nHeight;
  int nWidth;
  int iVar1;
  int iVar2;
  uint uVar3;
  WINBOOL WVar4;
  DWORD dwExStyle;
  DWORD dwStyle;
  HMENU hMenu;
  HMODULE hInstance;
  LPVOID lpParam;
  tagRECT local_10;
  
  if (DAT_10059780 == (HMODULE)0x0) {
    DAT_10059780 = GetModuleHandleA((LPCSTR)0x0);
  }
  _DAT_10059dc8 = 0x30;
  _DAT_10059dcc = 3;
  _DAT_10059dd0 = &LAB_100033b0;
  _DAT_10059dd4 = 0;
  _DAT_10059dd8 = 0;
  _DAT_10059de0 = DAT_10059778;
  DAT_10059ddc = DAT_10059780;
  _DAT_10059de4 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_10059de8 = GetStockObject(4);
  _DAT_10059dec = 0;
  DAT_10059df0 = s_Crimson_100535dc;
  _DAT_10059df4 = DAT_10059778;
  RegisterClassExA((WNDCLASSEXA *)&DAT_10059dc8);
  lpParam = (LPVOID)0x0;
  if (DAT_1005cc08 == '\0') {
    hMenu = (HMENU)0x0;
    hInstance = DAT_10059780;
    hWndParent = GetDesktopWindow();
    nHeight = GetSystemMetrics(1);
    nWidth = GetSystemMetrics(0);
    dwStyle = 0x80000000;
    dwExStyle = 8;
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    iVar1 = GetSystemMetrics(0);
    iVar2 = GetSystemMetrics(1);
    local_10.left = iVar1 / 2 - (grim_backbuffer_width >> 1);
    local_10.right = (grim_backbuffer_width >> 1) + iVar1 / 2;
    local_10.top = iVar2 / 2 - (grim_backbuffer_height >> 1);
    local_10.bottom = (grim_backbuffer_height >> 1) + iVar2 / 2;
    AdjustWindowRectEx(&local_10,0xcb0000,0,0x40000);
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hInstance = DAT_10059780;
    hWndParent = GetDesktopWindow();
    nHeight = local_10.bottom - local_10.top;
    nWidth = local_10.right - local_10.left;
    dwStyle = 0xcb0000;
    dwExStyle = 0x40000;
    iVar1 = local_10.left;
    iVar2 = local_10.top;
  }
  DAT_1005d3f8 = CreateWindowExA(dwExStyle,DAT_10059df0,DAT_1005bac8,dwStyle,iVar1,iVar2,nWidth,
                                 nHeight,hWndParent,hMenu,hInstance,lpParam);
  if (DAT_1005d3f8 == (HWND)0x0) {
    grim_error_text = s_WIN__Could_not_create_the_main_w_100535b4;
    uVar3 = grim_window_destroy();
    return uVar3 & 0xffffff00;
  }
  ShowWindow(DAT_1005d3f8,1);
  UpdateWindow(DAT_1005d3f8);
  SetFocus(DAT_1005d3f8);
  ShowWindow(DAT_1005d3f8,1);
  WVar4 = UpdateWindow(DAT_1005d3f8);
  return CONCAT31((int3)((uint)WVar4 >> 8),1);
}



