#include "ScrollTextWindow.h"

ScrollTextWindow::ScrollTextWindow(uint16_t bgColor, uint8_t textWidth, uint8_t textHeight) {
  m_backgroundColor = bgColor;
  m_textWidth = textWidth;
  m_textHeight = textHeight;
  m_scrollableHeight = ((SCREEN_HEIGHT - m_topFixedHeight - m_bottomFixedHeight) / m_textHeight) * m_textHeight;
  m_scrollLimit = m_topFixedHeight + m_scrollableHeight - m_textHeight;

  m_xPos = 0;
  m_yPos = m_topFixedHeight;
  m_bScroll = false;

  setupScrollArea(m_topFixedHeight, SCREEN_HEIGHT - m_topFixedHeight - m_scrollableHeight);
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

size_t ScrollTextWindow::write(uint8_t utf8) {
  if (utf8 == '\r') return 1;
  uint16_t c = utf8;

  if (c == '\n' || m_xPos > (SCREEN_WIDTH - m_textWidth)) {
    m_xPos = 0;
    m_yPos += m_textHeight;

    if (!m_bScroll) {
      m_bScroll = (m_yPos > m_scrollLimit);
      if (m_bScroll) {
        m_yScrollPos = m_topFixedHeight;
      }
    }
    if (m_yPos > m_scrollLimit) {
      m_yPos -= m_scrollableHeight;
    }
    if (m_bScroll) {
      m_yScrollPos += m_textHeight;

      if (m_yScrollPos >= (m_topFixedHeight + m_scrollableHeight)) {
        m_yScrollPos -= m_scrollableHeight;
      }

      scrollAddress(m_yScrollPos);

      M5.Lcd.fillRect(0, m_yPos, SCREEN_WIDTH, m_textHeight, m_backgroundColor);
    }
  }

  if (c > 31 && c < 128) {
    M5.Lcd.drawChar(c, m_xPos, m_yPos);
    m_xPos += m_textWidth;
  } else if (c != '\n') {
    M5.Lcd.drawChar('.', m_xPos, m_yPos);
    m_xPos += m_textWidth;
  }

  return 1;
}
