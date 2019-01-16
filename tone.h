/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define N   0u      //for rest
//for tone from C1~B8, with their cycles to match the period of the tone(8Mhz)
#define C1  4929u   
#define C1S 8393u
#define D1  11481u
#define D1S 14253u
#define E1  16755u
#define F1  20081u
#define F1S 22056u
#define G1  24719u
#define G1S 27074u
#define A1  29172u
#define A1S 31053u
#define B1  33277u

#define C2  34766u
#define C2S 36550u
#define D2  38174u
#define D2S 39894u
#define E2  41144u
#define F2  42547u
#define F2S 43795u
#define G2  45127u
#define G2  46305u
#define A2  47354u
#define A2  48441u
#define B2  49275u

#define C3  50277u
#define C3S 51147u
#define D3  51929u
#define D3S 52714u
#define E3  53414u
#define F3  54107u
#define F3S 54725u
#define G3  55331u
#define G3S 55920u
#define A3  56445u
#define A3S 56952u
#define B3  57438u

#define C4  57902u
#define C4S 58315u
#define D4  58733u
#define D4S 59105u
#define E4  59475u
#define F4  59805u
#define F4S 60129u
#define G4  60433u
#define G4S 60716u
#define A4  60990u
#define A4S 61244u
#define B4  61487u

#define C5  61711u
#define C5S 61924u
#define D5  62128u
#define D5S 62320u
#define E5  62500u
#define F5  62669u
#define F5S 62832u
#define G5  62983u
#define G5S 63129u
#define A5  63262u
#define A5S 63390u
#define B5  63511u

#define C6  63625u
#define C6S 63732u
#define D6  63833u
#define D6S 63932u
#define E6  64019u
#define F6  64104u
#define F6S 64184u
#define G6  64260u
#define G6S 64331u
#define A6  64399u
#define A6S 64463u
#define B6  64523u

#define C7  64580u
#define C7S 64633u
#define D7  64685u
#define D7S 64732u
#define E7  64777u
#define F7  64820u
#define F7S 64860u
#define G7  64898u
#define G7S 64933u
#define A7  64967u
#define A7S 64999u
#define B7  65029u

#define C8  65058u
#define C8S 65084u
#define D8  65110u
#define D8S 65134u
#define E8  65155u
#define F8  65178u
#define F8S 65198u
#define G8  65217u
#define G8S 65234u
#define A8  65251u
#define A8S 65267u
#define B8  65282u

//24 for 1 beat
//main melody
const int sine_one_tone[] = {E6, F6S, G6, A6, B6, E7, D7,      B6, E6, B6, A6, B6, A6, G6, F6S,      E6, F6S, G6, A6, B6, A6, G6,      F6S, E6, F6S, G6, F6S, G6, F6S, E6, D6S, F6S,
                             E6, F6S, G6, A6, B6, E7, D7,      B6, E6, B6, A6, B6, A6, G6, F6S,      E6, F6S, G6, A6, B6, A6, G6,      F6S, N, G6, N, A6, N, B6, N,
                             E6, F6S, G6, A6, B6, E7, D7,      B6, E6, B6, A6, B6, A6, G6, F6S,      E6, F6S, G6, A6, B6, A6, G6,      F6S, E6, F6S, G6, F6S, G6, F6S, E6, D6S, F6S,
                             E6, F6S, G6, A6, B6, E7, D7,      B6, E6, B6, A6, B6, A6, G6, F6S,      E6, F6S, G6, A6, B6, A6, G6,      F6S, N, G6, N, A6, N, B6, N,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, A6, B6,      A6, G6, F6S, D6, E6, D6, E6,      F6S, G6, A6, B6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, A6, B6,      A6, G6, F6S, D6, E6, D6, E6,      F6S, G6, A6, B6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, A6, B6,      A6, G6, F6S, D6, E6, D6, E6,      F6S, G6, A6, B6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, E7, F7S,      G7, F7S, E7, D7, B6, A6, B6,      A6, G6, F6S, D6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, A6, B6,      A6, G6, F6S, D6, E6, D6, E6,      F6S, G6, A6, B6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, A6, B6,      A6, G6, F6S, D6, E6, D6, E6,      F6S, G6, A6, B6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, A6, B6,      A6, G6, F6S, D6, E6, D6, E6,      F6S, G6, A6, B6, E6, B6, D7,
                             D7, E7, B6, A6, B6, A6, B6,      D7, E7, B6, A6, B6, E7, F7S,      G7, F7S, E7, D7, B6, A6, B6,      A6, G6, F6S, D6, E6};

const char sine_one_beat[] = {12, 12, 12, 12, 24, 12, 12,      24, 24, 12, 3, 3, 6, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 3, 3, 6, 12, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      24, 24, 12, 3, 3, 6, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      24, 24, 12, 3, 3, 6, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 3, 3, 6, 12, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      24, 24, 12, 3, 3, 6, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,
                             12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 48};
//counter melody & accompaniment(chord)
const int sine_two_tone[] = {N,      N,      N,      N,
                             N,      N,      N,      N, A5, A5,
                             B5, D6, E6, F6S, G6, B6, A6,      G6, B5, G6, F6S, E6, D6,      C6, D6, E6, F6S, G6, F6S, E6,      D6, C6, D6, E6, N, C6S,
                             B5, D6, E6, F6S, G6, B6, A6,      G6, B5, G6, F6S, E6, D6,      C6, D6, E6, F6S, G6, F6S, E6,      D6, E6, F6S, G6,
                             N,      N,      N,      N,
                             N,      N,      N,      N, G5, F6S,
                             N,      N,      N,      N,
                             N,      N,      N,      N, G5, F6S,
                             G5, A5, B5, B5,
                             G5, A5, B5, B5,
                             G5, A5, B5, B5,
                             G5, A5, B5, N, B5};
//accompaniment(chord)
const char sine_two_beat[] = {96,      96,      96,      96,
                              96,      96,      96,      48, 24, 24,
                              12, 12, 12, 12, 24, 12, 12,      24, 24, 12, 12, 12, 12,      12, 12, 12, 12, 24, 12, 12,      12, 12, 12, 12, 36, 12,
                              12, 12, 12, 12, 24, 12, 12,      24, 24, 12, 12, 12, 12,      12, 12, 12, 12, 24, 12, 12,      24, 24, 24, 24,
                              96,      96,      96,      96,
                              96,      96,      96,      48, 24, 24,
                              96,      96,      96,      96,
                              96,      96,      96,      48, 24, 24,
                              96, 96, 96, 96, 
                              96, 96, 96, 96,
                              96, 96, 96, 96,
                              96, 96, 96, 48, 48};
const int sine_three_tone[] = {E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, B5, E5, B5,      C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5S, A5, D5S, A5,
                               E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, B5, E5, B5,      C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5S, D5S,
                               E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, B5, E5, B5,      C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5S, A5, D5S, A5,
                               E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, B5, E5, B5,      C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5S, D5S,
                               C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5, A5, D5, A5,      E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, B5, D5, A5, 
                               C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5, A5, D5, A5,      E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, D5, 
                               C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5, A5, D5, A5,      E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, B5, D5, A5, 
                               C5, G5, C5, G5, C5, G5, C5, G5,      D5, A5, D5, A5, D5, A5, D5, A5,      E5, B5, E5, B5, E5, B5, E5, B5,      E5, B5, E5, B5, E5, D5,
                               E5, F5S, G5, G5,
                               E5, F5S, G5, G5,
                               E5, F5S, G5, G5,
                               E5, F5S, G5, N, G5};
const char sine_three_beat[] = {12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 24, 24,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 24, 24,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 24, 24,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,
                                12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 12, 12, 12, 12,      12, 12, 12, 12, 24, 24,
                                96, 96, 96, 96, 
                                96, 96, 96, 96,
                                96, 96, 96, 96,
                                96, 96, 96, 48, 48};

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

