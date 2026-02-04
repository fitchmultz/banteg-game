/* input_scheme_label @ 00447cf0 */

/* maps control scheme ids to labels (Relative/Static/Dual Action Pad/etc) */

char * __cdecl input_scheme_label(int scheme)

{
  switch(scheme) {
  case 1:
    return s_Relative_00478f34;
  case 2:
    return s_Static_00478f2c;
  case 3:
    return s_Dual_Action_Pad_00478ed8;
  case 4:
    return s_Mouse_point_click_00478f18;
  case 5:
    return s_Computer_00478ecc;
  default:
    return s_Unknown_004714a0;
  }
}



