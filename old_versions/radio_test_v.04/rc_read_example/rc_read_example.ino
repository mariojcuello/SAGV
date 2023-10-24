unsigned long now;                        // timing variables to update data at a regular interval                  
unsigned long rc_update;
const int channels = 6;                   // specify the number of receiver channels
float RC_in[channels];                    // an array to store the calibrated input from receiver 

void setup() {
    setup_pwmRead();                      
    Serial.begin(9600);
}

void loop() {  
    
    now = millis();
    
    if(RC_avail() || now - rc_update > 25){   
      
      rc_update = now;                           
      
      Serial.print(PW[0]);                  
      
    }
}
