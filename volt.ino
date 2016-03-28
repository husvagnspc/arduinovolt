/*
DC Voltmätare 
Läser 0-33V för avläsning till Raspberry Pi
Krävs resistorer för att skydda arduinon
Läs readme.md filen för mer information

Skapad av Andreas Olsson för Husvagn/Husbils Pc Projektet
*/
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistansen på R1 (100K)
float R2 = 10000.0; // resistansen på R2 (10K)
int value = 0;
void setup(){
  pinMode(analogInput, INPUT);
  Serial.begin(9600);
}
void loop(){
   // read the value at analog input
   value = analogRead(analogInput);
   vout = (value * 5.0) / 1024.0; // 5.0 justeras beroende på arduino
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;//värde vid låg spänning
} 
Serial.println(vin); //Skriver volten till Raspberry Pi
delay(500);
}
