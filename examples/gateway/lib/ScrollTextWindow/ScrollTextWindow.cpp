#include "ScrollTextWindow.h"

ScrollTextWindow::ScrollTextWindow(uint16_t bgColor, uint8_t textWidth, uint8_t textHeight) {
  this->bgColor = bgColor;
  this->textWidth = textWidth;
  this->textHeight = textHeight;
  this->scrollableHeight = (SCREEN_HEIGHT / textHeight) * textHeight;
  this->scrollLimit = scrollableHeight - textHeight;
  this->xPos = 0;
  this->yPos = 0;
  this->bScroll = false;

  setupScrollArea(0, SCREEN_HEIGHT - scrollableHeight);
}

void ScrollTextWindow::setupScrollArea(uint16_t tfa, uint16_t bfa) {
  M5.Lcd.writecommand(ILI9341_VSCRDEF); // Vertical scroll definition
  M5.Lcd.writedata(tfa >> 8);           // Top Fixed Area line count
  M5.Lcd.writedata(tfa);
  M5.Lcd.writedata((SCREEN_HEIGHT - tfa - bfa) >> 8);  // Vertical Scrolling Area line count
  M5.Lcd.writedata(SCREEN_HEIGHT - tfa - bfa);
  M5.Lcd.writedata(bfa >> 8);           // Bottom Fixed Area line count
  M5.Lcd.writedata(bfa);
}

void ScrollTextWindow::scrollAddress(uint16_t vsp) {
  M5.Lcd.writecommand(ILI9341_VSCRSADD);
  M5.Lcd.writedata(vsp>>8);
  M5.Lcd.writedata(vsp);
}

size_t ScrollTextWindow::write(uint8_t c) {
  if (c == '\n' || xPos > (SCREEN_WIDTH - textWidth)) {
    xPos = 0;
    yPos += textHeight;

    if (!bScroll) {
      bScroll = (yPos > scrollLimit);

      if (bScroll) {
        yScrollPos = 0;
      }
    }

    if (yPos > scrollLimit) {
      yPos -= scrollableHeight;
    }

    if (bScroll) {
      yScrollPos += textHeight;

      if (yScrollPos >= scrollableHeight) {
        yScrollPos -= scrollableHeight;
      }

      scrollAddress(yScrollPos);

      M5.Lcd.fillRect(0, yPos, SCREEN_WIDTH, textHeight, bgColor);
    }
  }

  if (c > 31 && c < 128) {
    M5.Lcd.drawChar(c, xPos, yPos);
    xPos += textWidth;
  }

  return 1;
}
