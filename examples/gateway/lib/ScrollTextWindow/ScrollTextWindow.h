#include <M5Stack.h>

#ifndef SCROLLTEXTWINDOW_H
#define SCROLLTEXTWINDOW_H

#define SCREEN_WIDTH            320
#define SCREEN_HEIGHT           240

class ScrollTextWindow : public Print {
  public:
    ScrollTextWindow(uint16_t bgColor = TFT_BLACK, uint8_t textWidth = 6, uint8_t textHeight = 8);
    size_t write(uint8_t utf8);

  private:
    uint16_t m_textWidth;
    uint16_t m_textHeight;
    const uint16_t m_bottomFixedHeight = 0;
    uint16_t m_scrollableHeight;
    uint16_t m_scrollLimit;
    uint16_t m_backgroundColor;
    uint16_t m_yScrollPos;
    uint16_t m_yPos;
    uint16_t m_xPos;
    bool m_bScroll;

    void setupScrollArea(uint16_t tfa, uint16_t bfa);
    void scrollAddress(uint16_t vsp);
};

#endif //SCROLLTEXTWINDOW_H
