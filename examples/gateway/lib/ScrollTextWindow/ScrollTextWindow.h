// Borrowed & modified from https://github.com/totsucom/M5Stack_ScrollTextWindow
#ifndef SCROLLTEXTWINDOW_H
#define SCROLLTEXTWINDOW_H

#include <M5Stack.h>

#define SCREEN_WIDTH            320
#define SCREEN_HEIGHT           240

class ScrollTextWindow : public Print {
  public:
    ScrollTextWindow(uint16_t bgColor = TFT_BLACK, uint8_t textWidth = 6, uint8_t textHeight = 8);
    size_t write(uint8_t c);

  private:
    uint16_t textWidth;
    uint16_t textHeight;
    uint16_t scrollableHeight;
    uint16_t scrollLimit;
    uint16_t bgColor;
    uint16_t yScrollPos;
    uint16_t yPos;
    uint16_t xPos;
    bool bScroll;

    void setupScrollArea(uint16_t tfa, uint16_t bfa);
    void scrollAddress(uint16_t vsp);
};
#endif
