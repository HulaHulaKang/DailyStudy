static HDC hdc;                  // display device context of owner window

CHOOSEFONT cf;            // common dialog box structure
static LOGFONT lf;        // logical font structure
static DWORD rgbCurrent;  // current text color
HFONT hfont, hfontPrev;
DWORD rgbPrev;

// Initialize CHOOSEFONT
ZeroMemory(&cf, sizeof(cf));
cf.lStructSize = sizeof(cf);
cf.hwndOwner = m_hwnd;
cf.lpLogFont = &lf;
cf.rgbColors = rgbCurrent;
cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

if (ChooseFont(&cf) == TRUE)
{
    hfont = CreateFontIndirect(cf.lpLogFont);
    hfontPrev = (HFONT)SelectObject(hdc, hfont);
    rgbCurrent = cf.rgbColors;
    rgbPrev = SetTextColor(hdc, rgbCurrent);
}