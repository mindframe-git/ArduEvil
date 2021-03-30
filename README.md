# ArduEvil

These are payloads for the Arduino Micro board.

Both payloads will send the information to a WebHook server. You'll need to get your ID at https://webhook.site/

Perhaps, you'll need to tune up the delay time between commands, depending on your computer.

## WiFi

This script will create a file with the SSID and passwords that the machine has stored and send it to your webhook site. Once is sent, it will delete the created files.

## BackDoor

The Backdoor script will create a random user with random password on the machine. This user will be added to the administrator group and you'll receive the credentials on your webhook .

ENJOY!
