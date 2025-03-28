// Tomado de arduino, like analogWrite

#define LEDC_CHANNEL_0     0                                                        // use first channel of 16 channels (started from zero)
#define LEDC_TIMER_13_BIT  13                                                       // use 13 bit precision for LEDC timer
#define LEDC_BASE_FREQ     5000                                                     // use 5000 Hz as a LEDC base frequency

#define LED_PIN1            2                                                       // Build in
#define LED_PIN2            15
#define LED_PIN3            26

int brightness = 0;                                                                 // how bright the LED is
int fadeAmount = 5;                                                                 // how many points to fade the LED by
int valueMax = 1000; //255;                                                               // Rápido. valuemax = Resolución = 2 ^ 8 - 1 = 255 === Rápido
// int valueMax = 8000; //8191;                                                                // Lento,  valuemax = Resolución = 2 ^ 13 - 1 = 8191 === lento


// value has to be between 0 and valueMax

void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax){               // 255                                                                  
                                                                         uint32_t duty = (8191 / valueMax) * min(value, valueMax); // calculate duty, 8191 from 2 ^ 13 - 1                                                                              
                                                                         ledcWrite(channel, duty);                                 // write duty to LEDC                              C
                                                                        }


void setup() {
                Serial.begin(115200);
                pinMode(LED_PIN1, OUTPUT);
                pinMode(LED_PIN2, OUTPUT);
                pinMode(LED_PIN3, OUTPUT);
               
                ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);       // Setup timer and attach timer to a led pin                                                        A
                ledcAttachPin(LED_PIN1, LEDC_CHANNEL_0);                            //                                                                                                  B
                ledcAttachPin(LED_PIN2, LEDC_CHANNEL_0);
                ledcAttachPin(LED_PIN3, LEDC_CHANNEL_0);
             }


void loop() {
              ledcAnalogWrite(LEDC_CHANNEL_0, brightness, valueMax);                // set the brightness on LEDC channel 0            
              brightness = brightness + fadeAmount;                                 // change the brightness for next time through the loop
              Serial.print(String("brightness = "));
              Serial.println(brightness);
           


              if (brightness <= 0 || brightness >= valueMax){                       // reverse the direction of the fading at the ends of the fade:
                                                            fadeAmount = -fadeAmount;
                                                            }
              delay(30);                                                            // wait for 30 milliseconds to see the dimming effect
            }