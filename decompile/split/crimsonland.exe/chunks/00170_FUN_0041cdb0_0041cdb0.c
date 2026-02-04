/* FUN_0041cdb0 @ 0041cdb0 */

/* WARNING: Removing unreachable block (ram,0x0041ce9f) */
/* WARNING: Removing unreachable block (ram,0x0041cea7) */
/* WARNING: Removing unreachable block (ram,0x0041cead) */
/* WARNING: Removing unreachable block (ram,0x0041cf52) */
/* WARNING: Removing unreachable block (ram,0x0041cf5a) */
/* WARNING: Enum "tagCALLCONV": Some values do not have unique names */

int FUN_0041cdb0(void)

{
  HRESULT HVar1;
  HRESULT HVar2;
  int iVar3;
  char cVar4;
  int *unaff_EDI;
  undefined4 uStack_74;
  int *piVar5;
  wchar_t *pwStack_64;
  wchar_t *pwStack_60;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined4 lpWideCharStr;
  undefined2 uVar8;
  undefined4 local_3c;
  undefined4 uStack_38;
  _union_2156 local_34;
  undefined4 *puStack_24;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  HVar1 = CoInitialize((LPVOID)0x0);
  local_34._0_4_ = (wchar_t *)0x0;
  local_3c = (uint)(-1 < HVar1) << 0x18;
  HVar2 = CoCreateInstance((IID *)&DAT_0046f5c8,(LPUNKNOWN)0x0,1,(IID *)&DAT_0046f5b8,
                           (LPVOID *)&local_34);
  if (HVar2 < 0) {
    cVar4 = '\0';
  }
  else {
    local_10 = 0x10;
    local_c = 0x6f;
    local_8 = 0;
    local_4 = 0;
    uVar7 = local_34._0_4_;
    iVar3 = (**(code **)(*(int *)local_34._0_4_ + 0xc))();
    if (-1 < iVar3) {
      uStack_38 = (int *)0x0;
      iVar3 = (**(code **)(*(int *)local_3c + 0x10))();
      if (-1 < iVar3) {
        lpWideCharStr = &stack0xffffffc0;
        iVar3 = (**(code **)(iRam00000000 + 0x14))();
        if (iVar3 < 0) {
          cVar4 = (char)lpWideCharStr;
          pwStack_60 = (wchar_t *)0x41cf96;
          (**(code **)(*unaff_EDI + 8))();
          pwStack_60 = (wchar_t *)uVar7;
          pwStack_64 = (wchar_t *)0x41cfa0;
          (**(code **)(*(int *)pwStack_60 + 8))();
        }
        else {
          pwStack_60 = (wchar_t *)0x41ce7f;
          pwStack_64 = (wchar_t *)uVar7;
          VariantInit((VARIANTARG *)&local_34.field0);
          pwStack_60 = u_dwDirectXVersionMajor_00473900;
          uVar7 = pwStack_64;
          (**(code **)(*(int *)pwStack_64 + 0x20))();
          uVar8 = (undefined2)uVar7;
          VariantClear((VARIANTARG *)&stack0xffffffc0);
          piVar5 = (int *)&stack0xffffffc0;
          uVar7 = uStack_38;
          iVar3 = (**(code **)(*(int *)uStack_38 + 0x20))();
          uVar6 = (undefined2)uVar7;
          if (((-1 < iVar3) && (uVar8 == 0x13)) && (puStack_24 != (undefined4 *)0x0)) {
            *puStack_24 = unaff_EDI;
          }
          VariantClear((VARIANTARG *)&stack0xffffffb4);
          iVar3 = (**(code **)(*(int *)pwStack_64 + 0x20))
                            (pwStack_64,u_szDirectXVersionLetter_004738a4,&stack0xffffffb4);
          uStack_74 = uStack_38;
          if (((-1 < iVar3) && (uVar6 == 8)) && ((LPCWCH)lpWideCharStr != (LPCWCH)0x0)) {
            WideCharToMultiByte(0,0,(LPCWCH)lpWideCharStr,-1,(LPSTR)&pwStack_64,10,(LPCCH)0x0,
                                (LPBOOL)0x0);
            if ((undefined1 *)local_34._8_4_ != (undefined1 *)0x0) {
              *(undefined1 *)local_34._8_4_ = pwStack_64._0_1_;
            }
            uStack_74._3_1_ = (undefined1)((uint)uStack_38 >> 0x18);
            uStack_74._0_3_ = CONCAT12(1,(short)uStack_38);
          }
          VariantClear((VARIANTARG *)&stack0xffffffa8);
          cVar4 = (char)uStack_74;
          (**(code **)(u_dwDirectXVersionMinor_004738d4._0_4_ + 8))
                    (u_dwDirectXVersionMinor_004738d4);
          (**(code **)(*piVar5 + 8))(piVar5);
          (**(code **)(*(int *)uStack_74 + 8))(uStack_74);
        }
        goto LAB_0041cfb6;
      }
    }
    cVar4 = (char)unaff_EDI;
    (**(code **)(*(int *)local_3c + 8))();
  }
LAB_0041cfb6:
  if (-1 < HVar1) {
    CoUninitialize();
  }
  return (-(uint)(cVar4 != '\0') & 0x7fffbffb) + 0x80004005;
}



