if (hasChanged) {
    lcd.clear();
    for (int i = 0; i < 4; i++) {
      lcd.setCursor(0, i);
      for (int j = 0; j < 20; j++) {
        if (lcdBuf[i][j]) {
          lcd.print(lcdBuf[i][j]);
        }
      }
    }
    hasChanged = false;
  }

  if (Serial.available() > 1) {
    String buf = Serial.readString();
    Serial.println(buf);
    if (buf.equalsIgnoreCase("RIGHT")) {
      for (int i = 0; i < 4; i++) {
        for (int j = 20; j > 0; j--) {
          lcdBuf[i][j] = lcdBuf[i][j - 1];
        }
        lcdBuf[i][0] = ' ';
      }
      hasChanged = true;
    } else if (buf.equalsIgnoreCase("LEFT")) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 19; j++) {
          lcdBuf[i][j] = lcdBuf[i][j + 1];
        }
        lcdBuf[i][19] = ' ';
      }
      hasChanged = true;
    }
    else if (buf.equalsIgnoreCase("UP")) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20; j++) {
          lcdBuf[i][j] = lcdBuf[i+1][j];
        }
      }
      for (int j = 0; j < 20; j++) {
        lcdBuf[3][j] = ' ';
      }
      hasChanged = true;
    }
    else if (buf.equalsIgnoreCase("DOWN")) {
      for (int i = 3; i > 0; i--) {
        for (int j = 0; j < 20; j++) {
          lcdBuf[i][j] = lcdBuf[i - 1][j];
        }
      }
      for (int j = 0; j < 20; j++) {
        lcdBuf[0][j] = ' ';
      }
      hasChanged = true;
    } else {
      //Serial.println(buf);
    }
  }
