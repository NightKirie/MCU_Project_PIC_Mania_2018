#pragma config OSC = INTIO67
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP =OFF
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "tone.h"
#define _XTAL_FREQ 8000000

int play_flag = 0;  //flag that wait to start the game by pushing the start button

//some variables for main melody playing
int sine_one_count = 0;     //for beat
int sine_one_index = 0;     //for tone
int sine_one_length = 0;    //for the length of the song

//some variables for counter melody playing
int sine_two_count = 0;     //for beat
int sine_two_index = 0;     //for tone
int sine_two_length = 0;    //for the length of the song

//some variables for accompaniment
int sine_three_count = 0;   //for beat
int sine_three_index = 0;   //for tone
int sine_three_length = 0;  //for the length of the song

void __interrupt() tc_int(void)
{
    //for main melody interrupt
    if(INTCONbits.TMR0IF == 1 && INTCONbits.TMR0IE == 1) {
        LATCbits.LC0 = !LATCbits.LC0;
        TMR0 = sine_one_tone[sine_one_index];
        INTCONbits.TMR0IF = 0;
    }
    
    //for counter melody interrupt
    if(PIR1bits.TMR1IF == 1 && PIE1bits.TMR1IE == 1) {
        LATCbits.LC4 = !LATCbits.LC4;
        TMR1 = sine_two_tone[sine_two_index];
        PIR1bits.TMR1IF = 0;
    }
    
    //for accompaniment interrupt
    if(PIR2bits.TMR3IF == 1 && PIE2bits.TMR3IE == 1) {
        LATDbits.LD1 = !LATDbits.LD1;
        TMR3 = sine_three_tone[sine_three_index];
        PIR2bits.TMR3IF = 0;
    }
    
    //for beat counter interrupt
    if(PIR1bits.TMR2IF == 1 && PIE1bits.TMR2IE == 1) {
        ++sine_one_count;
        //set last 1/24 beat mute to simulate humanoid play style
        if(sine_one_count == sine_one_beat[sine_one_index] - 1 || sine_one_tone[sine_one_index] == N) {
            INTCONbits.TMR0IE = 0;
            LATCbits.LC0 = 0;
        }
        //prev tone's beat reach, set the tone to the next one
        if(sine_one_count == sine_one_beat[sine_one_index] && INTCONbits.TMR0IE == 0) {
            sine_one_count = 0;
            INTCONbits.TMR0IE = 1;
            ++sine_one_index;
        }
        
        ++sine_two_count;
        //set last 1/24 beat mute to simulate humanoid play style
        if(sine_two_count == sine_two_beat[sine_two_index] - 1 || sine_two_tone[sine_two_index] == N) {
            PIE1bits.TMR1IE = 0;
            LATCbits.LC4 = 0;
        }
        //prev tone's beat reach, set the tone to the next one
        if(sine_two_count == sine_two_beat[sine_two_index] && PIE1bits.TMR1IE == 0) {
            sine_two_count = 0;
            PIE1bits.TMR1IE = 1;
            ++sine_two_index;
        }
        
        ++sine_three_count;
        //set last 1/24 beat mute to simulate humanoid play style
        if(sine_three_count == sine_three_beat[sine_three_index] - 1 || sine_three_tone[sine_three_index] == N) {
            PIE2bits.TMR3IE = 0;
            LATDbits.LD1 = 0;
        }
        //prev tone's beat reach, set the tone to the next one
        if(sine_three_count == sine_three_beat[sine_three_index] && PIE2bits.TMR3IE == 0) {
            sine_three_count = 0;
            PIE2bits.TMR3IE = 1;
            ++sine_three_index;
        }
        
        //if the song is finished, disable all the timer
        if(sine_one_index == sine_one_length && sine_two_index == sine_two_length && sine_three_index == sine_three_length) {
            T0CONbits.TMR0ON = 0;
            T1CONbits.TMR1ON = 0;
            T2CONbits.TMR2ON = 0;
            T3CONbits.TMR3ON = 0;
        }    
        
        TMR2 = 30;
        PIR1bits.TMR2IF = 0;
    }
}

void main(void) {
    TRISCbits.RC0 = 0;  //for main melody
    TRISCbits.RC4 = 0;  //for counter melody
    TRISDbits.RD1 = 0;  //for accompaniment
    TRISCbits.RC3 = 1;  //for start button
    LATCbits.LC0 = 0;
    LATCbits.LC4 = 0;
    LATDbits.LD1 = 0;
    PORTCbits.RC3 = 1;
    OSCCONbits.IRCF = 7;   //FOSC=8Mhz  
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    
    //for main melody
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    INTCON2bits.TMR0IP = 1;
    T0CONbits.T08BIT = 0;
    T0CONbits.T0CS = 0;
    T0CONbits.T0SE = 0;
    T0CONbits.PSA = 1;
    T0CONbits.T0PS = 0;  
    T0CONbits.TMR0ON = 0;
    
    //for counter melody
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    IPR1bits.TMR1IP = 1;
    T1CONbits.RD16 = 1;
    T1CONbits.T1CKPS = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.TMR1ON = 0;
    
    //for beat counting
    PIE1bits.TMR2IE = 1;
    PIR1bits.TMR2IF = 0;
    IPR1bits.TMR2IP = 1;
    T2CONbits.T2CKPS = 3;
    T2CONbits.T2OUTPS = 8; 
    T2CONbits.TMR2ON = 0;
    
    //for accompaniment
    PIE2bits.TMR3IE = 1;
    PIR2bits.TMR3IF = 0;
    IPR2bits.TMR3IP = 1;
    T3CONbits.RD16 = 1;
    T3CONbits.T3CKPS = 0;
    T3CONbits.TMR3CS = 0;
    T3CONbits.TMR3ON = 0;
    
    TMR0 = sine_one_tone[sine_one_index];
    TMR1 = sine_two_tone[sine_two_index];
    TMR3 = sine_three_tone[sine_three_index];
    TMR2 = 30;
    sine_one_length = sizeof(sine_one_tone)/sizeof(int);
    sine_two_length = sizeof(sine_two_tone)/sizeof(int);
    sine_three_length = sizeof(sine_three_tone)/sizeof(int);
    while(PORTCbits.RC3 == 1 && play_flag == 0);    //wait for pushing the start button
    __delay_ms(2650);   //for synchronize with the led matrix
    T0CONbits.TMR0ON = 1;
    T1CONbits.TMR1ON = 1;
    T2CONbits.TMR2ON = 1;
    T3CONbits.TMR3ON = 1;
    play_flag = 1;
    while(1);
}

