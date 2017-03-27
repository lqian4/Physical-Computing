const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int led1 = 3;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int led5 = 7;
 
void setup() 
{
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
   Serial.begin(9600);
}
 
 
void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
 
   Serial.println(volts);

 if (volts>0.4)  {digitalWrite(led1, HIGH);} else {digitalWrite(led1, LOW);}
 if (volts>0.8) {digitalWrite(led2, HIGH);} else {digitalWrite(led2, LOW);}
 if (volts>1.2) {digitalWrite(led3, HIGH);} else {digitalWrite(led3, LOW);}
 if (volts>1.6) {digitalWrite(led4, HIGH);} else {digitalWrite(led4, LOW);}
 if (volts>2) {digitalWrite(led5, HIGH);} else {digitalWrite(led5, LOW);}
}
   


