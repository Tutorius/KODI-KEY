# KODI-KEY
An ESP32-based Bluetooth-Remote for KODI

This is an ESP32-Code, ready to be compiled inside the ArduinoIDE.
You need to set Arduino-IDE to use your ESP32-module. I am using cheap ESP32-WROOM32-Modules with 38Pins.

You need the ESP-module and 12 Push-Buttons. Additionally you may use  LED and a 300Ohm-resistor. This LED shows how near the Deepsleep-mode is.
For Bluetooth-connection as BLE, you need the BLE-Keyboard-Library installed to your ArduinoIDE.

The keys for this are named and positioned like this

VOLDOWN    UP         VOLUP

LEFT       ENTER      RIGHT

BACK       DOWN       STOP

M(enu)     TAB        C(ontrol)

The keys are connected to the ports 5 12 13 14 15 16 17 25 26 27 32 33 connecting the port to GND when pressed.
You can change the ports and connection to keys in the sourcecode. It is recommended to use the sampe ports cause
other ports may be unuseable by ESP32 internal things.

Function of keys and long-press-functions for some keys:

The VOLDOWN and VOLUP-keys have a repeating-function, you can press it longer and the volume will be lowerd or rised with a half second distance.

The Arrow-Keys Left, Right, Up, Down work as pressing the arrow-keys on a normal keyboard.

Long presses of Arrow-Keys:
LEFT : (Fast) Rewind ('r')
RIGHT : (Fast) Forward ('f')
UP : Zoom-Function ('z') (here y cause german keyboard selected)
DOWN : Options ('o')

ENTER : Select ('ENTER')
Long pressed ENTER : Info ('i')

BACK : Go Back ('BACKSPACE')
Long pressed Back : Escape ('ESC')

STOP : Pause Video, or restart Video
Long pressed STOP : STOP ('x')

M : Menu ('m')
C : Cntrol ('c')

TAB : Tab through screens ('TAB')

