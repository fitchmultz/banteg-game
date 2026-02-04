/* FUN_10003c00 @ 10003c00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Enum "_D3DFORMAT": Some values do not have unique names */

undefined4 FUN_10003c00(void)

{
  float fVar1;
  char cVar2;
  WINBOOL WVar3;
  HRESULT HVar4;
  int iVar5;
  float *pfVar6;
  tagMSG *ptVar7;
  tagMSG local_1c;
  
  ptVar7 = &local_1c;
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    ptVar7->hwnd = (HWND)0x0;
    ptVar7 = (tagMSG *)&ptVar7->message;
  }
  PeekMessageA(&local_1c,(HWND)0x0,0,0,0);
  FUN_10004920();
  FUN_10004970();
  FUN_10004920();
  FUN_10004970();
  FUN_10004970();
  FUN_10002fc0(&DAT_1005bbd8);
  SetFocus(DAT_1005d3f8);
  SetForegroundWindow(DAT_1005d3f8);
  if (DAT_1005d3f8 != (HWND)0x0) {
    do {
      while( true ) {
        do {
          while( true ) {
            while( true ) {
              if (local_1c.message == 0x12) goto LAB_10003e30;
              WVar3 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
              if (WVar3 == 0) break;
              TranslateMessage(&local_1c);
              DispatchMessageA(&local_1c);
            }
            if (DAT_1005d804 == '\0') {
              FUN_10004970();
            }
            if ((((grim_paused_flag == '\0') && (DAT_1005d804 == '\0')) && (DAT_1005c898 != '\0'))
               && (DAT_1005a470 == '\0')) {
              if (DAT_1005cc38 != '\0') {
                grim_keyboard_poll();
                pfVar6 = (float *)&DAT_1005a058;
                do {
                  fVar1 = *pfVar6 - _grim_frame_dt;
                  *pfVar6 = fVar1;
                  if (fVar1 < 0.0) {
                    *pfVar6 = 0.0;
                  }
                  pfVar6 = pfVar6 + 1;
                } while ((int)pfVar6 < 0x1005a458);
              }
              grim_joystick_poll();
              _DAT_1005cf14 = &grim_joystick_state;
              if (grim_input_cached == '\0') {
                _grim_mouse_x_cached = grim_mouse_x;
                _grim_mouse_y_cached = grim_mouse_y;
                grim_mouse_poll();
              }
            }
            DAT_1005c898 = '\0';
            if (DAT_1005d804 != '\0') {
              DAT_1005a470 = '\x01';
              FUN_10003090();
            }
            if (DAT_1005a470 == '\0') break;
            if (DAT_1005d804 == '\0') {
              Sleep(0x32);
            }
          }
        } while ((DAT_1005d804 != '\0') || (grim_d3d_device == (LPDIRECT3DDEVICE8)0x0));
        HVar4 = (*grim_d3d_device->lpVtbl->TestCooperativeLevel)(grim_d3d_device);
        DAT_1005c898 = HVar4 == 0;
        if (!(bool)DAT_1005c898) break;
        if (DAT_1005d811 != '\0') {
          (*DAT_10059770)();
          DAT_1005d811 = '\0';
        }
        cVar2 = (*DAT_1005977c)();
        if (cVar2 == '\0') goto LAB_10003e30;
        if (DAT_1005d3b4 != (int *)0x0) {
          (**(code **)(*DAT_1005d3b4 + 0x14))();
        }
        if (grim_render_disabled == '\0') {
          (*grim_d3d_device->lpVtbl->Present)
                    (grim_d3d_device,(RECT *)0x0,(RECT *)0x0,(HWND)0x0,(RGNDATA *)0x0);
        }
      }
      Sleep(500);
      HVar4 = (*grim_d3d_device->lpVtbl->TestCooperativeLevel)(grim_d3d_device);
      DAT_1005c898 = HVar4 == 0;
    } while ((HVar4 != -0x7789f797) || (iVar5 = FUN_10002cf0(), iVar5 != -0x7789f797));
  }
LAB_10003e30:
  timeEndPeriod(1);
  thunk_FUN_10002f60(&DAT_1005bbd8);
  if (grim_input_cached != '\0') {
    ShowCursor(1);
  }
  grim_window_destroy();
  return 0;
}



