#include <M5Stack.h>                                          //untuk memasukkan library M5stack ke dalam sketch
const int Analog = 36;                                        //untuk menginisialisasi data analog output pda pin 26
const int Digtal = 2;                                         //untuk menginisialisasi data digital output pada pin 2
void setup() {                                                //untuk inisialisasi mode pin sebagai input atau sebagai output dan inisialisasi serial {
// put your setup code here, to run once:                     
M5.begin();                                                   //untuk memulai program dengan M5
pinMode(Digtal, INPUT_PULLUP);                                //untuk inisialisasi pin mode digital untuk input high
dacWrite(25, 0);                                              //sebagai output
M5.Lcd.setCursor(100, 0, 4);                                  //perintah yang digunakan untuk mengatur kursor
M5.Lcd.print("MICROPHONE");                                   //untuk melihat tulisan yang tercetak dalam LCD
}
uint16_t a_data;                                              //untuk menyimpan data analog dengan lebar 16 bit
uint16_t d_data;                                              //untuk menyimpan data digital dengan lebar 16 bit
void loop() {                                                 //untuk meneruskan program dan mengulangi program sampai arduino dimatikan {
// put your main code here, to run repeatedly:                
a_data = analogRead(Analog);                                  //untuk membaca data analog
d_data = digitalRead(Digtal);                                 //untuk membaca data digital
Serial.printf("Analog:%0d Digtal:%0d\n", a_data, d_data);     //untuk menampilkan nilai analog dan digital pada serial monitor
M5.Lcd.setCursor(30, 120, 4);                                 //perintah yang digunakan untuk mengatur kursor
M5.Lcd.printf("Analog:%0d Digtal:%0d\n", a_data, d_data);     //untuk menampilkan nilai analog dan digital pada LCD
delay(200);                                                   //untuk memberikan jeda selama 200 ms
}
