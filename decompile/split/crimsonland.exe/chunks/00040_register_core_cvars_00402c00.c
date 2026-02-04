/* register_core_cvars @ 00402c00 */

/* registers built-in cvars */

void register_core_cvars(void)

{
  cv_silentloads = console_register_cvar(&console_log_queue,s_cv_silentloads_00471434,&DAT_0047125c)
  ;
  cv_terrainFilter =
       console_register_cvar(&console_log_queue,s_cv_terrainFilter_00471420,&DAT_0047125c);
  cv_bodiesFade = console_register_cvar(&console_log_queue,s_cv_bodiesFade_00471410,&DAT_0047125c);
  cv_uiTransparency =
       console_register_cvar(&console_log_queue,s_cv_uiTransparency_004713fc,&DAT_0047125c);
  cv_uiPointFilterPanels =
       console_register_cvar(&console_log_queue,s_cv_uiPointFilterPanels_004713e0,&DAT_004713f8);
  cv_enableMousePointAndClickMovement =
       console_register_cvar
                 (&console_log_queue,s_cv_enableMousePointAndClickMovem_004713bc,&DAT_004713f8);
  cv_verbose = console_register_cvar(&console_log_queue,s_cv_verbose_004713b0,&DAT_004713f8);
  cv_terrainBodiesTransparency =
       console_register_cvar
                 (&console_log_queue,s_cv_terrainBodiesTransparency_00471390,&DAT_004713f8);
  cv_uiSmallIndicators =
       console_register_cvar(&console_log_queue,s_cv_uiSmallIndicators_00471378,&DAT_004713f8);
  cv_aimEnhancementFade =
       console_register_cvar(&console_log_queue,s_cv_aimEnhancementFade_00471360,&DAT_00471260);
  cv_friendlyFire =
       console_register_cvar(&console_log_queue,s_cv_friendlyFire_00471350,&DAT_004713f8);
  cv_showFPS = console_register_cvar(&console_log_queue,s_cv_showFPS_00471344,&DAT_004713f8);
  cv_padAimDistMul =
       console_register_cvar(&console_log_queue,s_cv_padAimDistMul_0047132c,&DAT_00471340);
  return;
}



