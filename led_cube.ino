#include <FastLED.h>
#include "letters.h"
#include <vector>
#include <cstring>

#define NUM_STRIPS 8
#define NUM_LEDS_PER_STRIP 64
#define BRIGHTNESS 255
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

//Letter matrixes
int A_[8][8], B_[8][8], C_[8][8], D_[8][8], E_[8][8], F_[8][8], G_[8][8], H_[8][8], I_[8][8], J_[8][8], K_[8][8], L_[8][8], M_[8][8], N_[8][8], O_[8][8], P_[8][8], R_[8][8], S_[8][8], T_[8][8], U_[8][8], V_[8][8], W_[8][8], X_[8][8], Y_[8][8], Z_[8][8], EX_[8][8], HE_[8][8];


void setup() {
  FastLED.addLeds<WS2811, 23>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 22>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 21>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 19>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 18>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 17>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 16>(leds[6], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2811, 15>(leds[7], NUM_LEDS_PER_STRIP);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxRefreshRate(0);
  Serial.begin(9600);
}



//================Common functions and functions for processing frames=========================

void wave_frame(int i, int dim) {
  //First
  leds[array[0][i]][27] = leds[array[0][i]][28] = leds[array[0][i]][35] = leds[array[0][i]][36] = CHSV((array[0][i]) * 255 / 8, 255, dim);
  //Second
  leds[array[1][i]][19] = leds[array[1][i]][20] = leds[array[1][i]][26] = leds[array[1][i]][29] = leds[array[1][i]][34] = leds[array[1][i]][37] = leds[array[1][i]][43] = leds[array[1][i]][44] = CHSV((array[1][i]) * 255 / 8, 255, dim);
  //Third
  leds[array[2][i]][11] = leds[array[2][i]][12] = leds[array[2][i]][18] = leds[array[2][i]][21] = leds[array[2][i]][25] = leds[array[2][i]][30] = leds[array[2][i]][33] = leds[array[2][i]][38] = CHSV((array[2][i]) * 255 / 8, 255, dim);
  leds[array[2][i]][42] = leds[array[2][i]][45] = leds[array[2][i]][51] = leds[array[2][i]][52] = CHSV((array[2][i]) * 255 / 8, 255, dim);
  //Fourth
  leds[array[3][i]][3] = leds[array[3][i]][4] = leds[array[3][i]][10] = leds[array[3][i]][13] = leds[array[3][i]][17] = leds[array[3][i]][22] = leds[array[3][i]][24] = leds[array[3][i]][31] = CHSV((array[3][i]) * 255 / 8, 255, dim);
  leds[array[3][i]][32] = leds[array[3][i]][39] = leds[array[3][i]][41] = leds[array[3][i]][46] = leds[array[3][i]][50] = leds[array[3][i]][53] = leds[array[3][i]][59] = leds[array[3][i]][60] = CHSV((array[3][i]) * 255 / 8, 255, dim);
  //Fifth
  leds[array[4][i]][2] = leds[array[4][i]][5] = leds[array[4][i]][9] = leds[array[4][i]][14] = leds[array[4][i]][16] = leds[array[4][i]][23] = leds[array[4][i]][40] = leds[array[4][i]][47] = CHSV((array[4][i]) * 255 / 8, 255, dim);
  leds[array[4][i]][49] = leds[array[4][i]][54] = leds[array[4][i]][58] = leds[array[4][i]][61] = CHSV((array[4][i]) * 255 / 8, 255, dim);
  //Sixth
  leds[array[5][i]][1] = leds[array[5][i]][6] = leds[array[5][i]][8] = leds[array[5][i]][15] = leds[array[5][i]][48] = leds[array[5][i]][55] = leds[array[5][i]][57] = leds[array[5][i]][62] = CHSV((array[5][i]) * 255 / 8, 255, dim);
  //Seventh
  leds[array[6][i]][0] = leds[array[6][i]][7] = leds[array[6][i]][56] = leds[array[6][i]][63] = CHSV((array[6][i]) * 255 / 8, 255, dim);
}

void turnoff() {
  for (int j = 0; j < 8; j++)
    for (int i = 0; i < 64; i++) leds[j][i] = CRGB::Black;
  FastLED.show();
}

void matrix_conv(int matrix1[8][8], int matrix2[8][8], int matrix3[8][8]) {
  //Only square matrixes!
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (matrix1[i][j] == 1) matrix3[i][j] = matrix2[i][j];
    }
  }
}

void frame_display(int frame[8][8], int color, int brt, int slice) {
  if (slice >= 0 && slice <= 7) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (frame[i][j] != 0 && frame[i][j] != -1) leds[slice][frame[i][j]] = CHSV(color, 255, brt);
        if (frame[i][j] == -1) leds[slice][0] = CHSV(color, 255, brt);
      }
    }
    FastLED.show();
  }
}


//================Main Loop===================
bool init_matrix = false;

void loop() {
  if (!init_matrix) {
    init_matrix = !init_matrix;
    matrix_conv(A, led_adresses, A_);
    matrix_conv(B, led_adresses, B_);
    matrix_conv(C, led_adresses, C_);
    matrix_conv(D, led_adresses, D_);
    matrix_conv(E, led_adresses, E_);
    matrix_conv(F, led_adresses, F_);
    matrix_conv(G, led_adresses, G_);
    matrix_conv(H, led_adresses, H_);
    matrix_conv(I, led_adresses, I_);
    matrix_conv(J, led_adresses, J_);
    matrix_conv(K, led_adresses, K_);
    matrix_conv(L, led_adresses, L_);
    matrix_conv(M, led_adresses, M_);
    matrix_conv(N, led_adresses, N_);
    matrix_conv(O, led_adresses, O_);
    matrix_conv(P, led_adresses, P_);
    matrix_conv(R, led_adresses, R_);
    matrix_conv(S, led_adresses, S_);
    matrix_conv(T, led_adresses, T_);
    matrix_conv(U, led_adresses, U_);
    matrix_conv(V, led_adresses, V_);
    matrix_conv(W, led_adresses, W_);
    matrix_conv(X, led_adresses, X_);
    matrix_conv(Y, led_adresses, Y_);
    matrix_conv(Z, led_adresses, Z_);
    matrix_conv(EX, led_adresses, EX_);
    matrix_conv(HE, led_adresses, HE_);
  }
  letters_slide(100, "victor");
  //wave_side_upgraded(110, 5);
  //chill(75,100);
  //delay(1000);
  //delay(1000);
  //frame_animation(100,A,0,128);
}


//=====================Animation functions======================

void letters_slide(int anim_delay, char word[]) {
  int word_length = strlen(word);
  for (int i = 0; i < word_length; i++) {
    for (int j = 8; j >= 0; j--) {
      switch (word[i]) {
        case 'a':
          frame_display(A_, j * 255 / 8, 255, j);
          frame_display(A_, j * 255 / 8, 255, j - 1);
          break;
        case 'b':
          frame_display(B_, j * 255 / 8, 255, j);
          frame_display(B_, j * 255 / 8, 255, j - 1);
          break;
        case 'c':
          frame_display(C_, j * 255 / 8, 255, j);
          frame_display(C_, j * 255 / 8, 255, j - 1);
          break;
        case 'd':
          frame_display(D_, j * 255 / 8, 255, j);
          frame_display(D_, j * 255 / 8, 255, j - 1);
          break;
        case 'e':
          frame_display(E_, j * 255 / 8, 255, j);
          frame_display(E_, j * 255 / 8, 255, j - 1);
          break;
        case 'f':
          frame_display(F_, j * 255 / 8, 255, j);
          frame_display(F_, j * 255 / 8, 255, j - 1);
          break;
        case 'g':
          frame_display(G_, j * 255 / 8, 255, j);
          frame_display(G_, j * 255 / 8, 255, j - 1);
          break;
        case 'h':
          frame_display(H_, j * 255 / 8, 255, j);
          frame_display(H_, j * 255 / 8, 255, j - 1);
          break;
        case 'i':
          frame_display(I_, j * 255 / 8, 255, j);
          frame_display(I_, j * 255 / 8, 255, j - 1);
          break;
        case 'j':
          frame_display(J_, j * 255 / 8, 255, j);
          frame_display(J_, j * 255 / 8, 255, j - 1);
          break;
        case 'k':
          frame_display(K_, j * 255 / 8, 255, j);
          frame_display(K_, j * 255 / 8, 255, j - 1);
          break;
        case 'l':
          frame_display(L_, j * 255 / 8, 255, j);
          frame_display(L_, j * 255 / 8, 255, j - 1);
          break;
        case 'm':
          frame_display(M_, j * 255 / 8, 255, j);
          frame_display(M_, j * 255 / 8, 255, j - 1);
          break;
        case 'n':
          frame_display(N_, j * 255 / 8, 255, j);
          frame_display(N_, j * 255 / 8, 255, j - 1);
          break;
        case 'o':
          frame_display(O_, j * 255 / 8, 255, j);
          frame_display(O_, j * 255 / 8, 255, j - 1);
          break;
        case 'p':
          frame_display(P_, j * 255 / 8, 255, j);
          frame_display(P_, j * 255 / 8, 255, j - 1);
          break;
        case 'r':
          frame_display(R_, j * 255 / 8, 255, j);
          frame_display(R_, j * 255 / 8, 255, j - 1);
          break;
        case 's':
          frame_display(S_, j * 255 / 8, 255, j);
          frame_display(S_, j * 255 / 8, 255, j - 1);
          break;
        case 't':
          frame_display(T_, j * 255 / 8, 255, j);
          frame_display(T_, j * 255 / 8, 255, j - 1);
          break;
        case 'u':
          frame_display(U_, j * 255 / 8, 255, j);
          frame_display(U_, j * 255 / 8, 255, j - 1);
          break;
        case 'v':
          frame_display(V_, j * 255 / 8, 255, j);
          frame_display(V_, j * 255 / 8, 255, j - 1);
          break;
        case 'w':
          frame_display(W_, j * 255 / 8, 255, j);
          frame_display(W_, j * 255 / 8, 255, j - 1);
          break;
        case 'x':
          frame_display(X_, j * 255 / 8, 255, j);
          frame_display(X_, j * 255 / 8, 255, j - 1);
          break;
        case 'y':
          frame_display(Y_, j * 255 / 8, 255, j);
          frame_display(Y_, j * 255 / 8, 255, j - 1);
          break;
        case 'z':
          frame_display(Z_, j * 255 / 8, 255, j);
          frame_display(Z_, j * 255 / 8, 255, j - 1);
          break;
        case '!':
          frame_display(EX_, j * 255 / 8, 255, j);
          frame_display(EX_, j * 255 / 8, 255, j - 1);
          break;
        case 'L':
          frame_display(HE_, j * 255 / 8, 255, j);
          frame_display(HE_, j * 255 / 8, 255, j - 1);
          break;
      }
      delay(anim_delay);
      turnoff();
    }
  }
}



void wave_side_upgraded_dimming(int anim_delay, int repeats) {
  int x = 0;
  int dimming_rate = 10;
  for (int r = 0; r < repeats; r++) {
    for (int i = 0; i < 14; i++) {
      //turnoff();
      int dim = 250;
      for (int brt = 0; brt < 255; brt += dimming_rate) {
        //=============Previous frame===============
        if (i > 0) wave_frame(i - 1, dim);
        //=============Next frame===============
        wave_frame(i, brt);
        if (repeats > 0 && i == 0) wave_frame(14, dim);

        dim -= dimming_rate;
        FastLED.show();
      }
      delay(anim_delay);
    }
  }
}


void wave_side_upgraded(int anim_delay, int repeats) {
  int x = 0;
  for (int r = 0; r < repeats; r++) {
    for (int i = 0; i < 14; i++) {
      turnoff();
      //First
      leds[array[0][i]][27] = leds[array[0][i]][28] = leds[array[0][i]][35] = leds[array[0][i]][36] = CHSV((array[0][i]) * 255 / 8, 255, 255);
      //Second
      leds[array[1][i]][19] = leds[array[1][i]][20] = leds[array[1][i]][26] = leds[array[1][i]][29] = leds[array[1][i]][34] = leds[array[1][i]][37] = leds[array[1][i]][43] = leds[array[1][i]][44] = CHSV((array[1][i]) * 255 / 8, 255, 255);
      //Third
      leds[array[2][i]][11] = leds[array[2][i]][12] = leds[array[2][i]][18] = leds[array[2][i]][21] = leds[array[2][i]][25] = leds[array[2][i]][30] = leds[array[2][i]][33] = leds[array[2][i]][38] = CHSV((array[2][i]) * 255 / 8, 255, 255);
      leds[array[2][i]][42] = leds[array[2][i]][45] = leds[array[2][i]][51] = leds[array[2][i]][52] = CHSV((array[2][i]) * 255 / 8, 255, 255);
      //Fourth
      leds[array[3][i]][3] = leds[array[3][i]][4] = leds[array[3][i]][10] = leds[array[3][i]][13] = leds[array[3][i]][17] = leds[array[3][i]][22] = leds[array[3][i]][24] = leds[array[3][i]][31] = CHSV((array[3][i]) * 255 / 8, 255, 255);
      leds[array[3][i]][32] = leds[array[3][i]][39] = leds[array[3][i]][41] = leds[array[3][i]][46] = leds[array[3][i]][50] = leds[array[3][i]][53] = leds[array[3][i]][59] = leds[array[3][i]][60] = CHSV((array[3][i]) * 255 / 8, 255, 255);
      //Fifth
      leds[array[4][i]][2] = leds[array[4][i]][5] = leds[array[4][i]][9] = leds[array[4][i]][14] = leds[array[4][i]][16] = leds[array[4][i]][23] = leds[array[4][i]][40] = leds[array[4][i]][47] = CHSV((array[4][i]) * 255 / 8, 255, 255);
      leds[array[4][i]][49] = leds[array[4][i]][54] = leds[array[4][i]][58] = leds[array[4][i]][61] = CHSV((array[4][i]) * 255 / 8, 255, 255);
      //Sixth
      leds[array[5][i]][1] = leds[array[5][i]][6] = leds[array[5][i]][8] = leds[array[5][i]][15] = leds[array[5][i]][48] = leds[array[5][i]][55] = leds[array[5][i]][57] = leds[array[5][i]][62] = CHSV((array[5][i]) * 255 / 8, 255, 255);
      //Seventh
      leds[array[6][i]][0] = leds[array[6][i]][7] = leds[array[6][i]][56] = leds[array[6][i]][63] = CHSV((array[6][i]) * 255 / 8, 255, 255);

      FastLED.show();
      delay(anim_delay);
    }
  }
}


void wave_side1(int anim_delay) {
  int x = 0;


  for (int i = 0; i < 13; i++) {
    turnoff();
    x = 0;
    //First
    if (i > 7) x = i - 7;
    leds[i - x][27] = leds[i - x][28] = leds[i - x][35] = leds[i - x][36] = CHSV((i - x) * 255 / 13, 255, 255);
    //Second
    if (i > 0) x = 1;
    if (i > 8) x = i - 7;
    leds[i - x][19] = leds[i - x][20] = leds[i - x][26] = leds[i - x][29] = leds[i - x][34] = leds[i - x][37] = leds[i - x][43] = leds[i - x][44] = CHSV((i - x) * 255 / 13, 255, 255);
    //Third
    if (i > 1) x = 2;
    if (i > 9) x = i - 7;
    leds[i - x][11] = leds[i - x][12] = leds[i - x][18] = leds[i - x][21] = leds[i - x][25] = leds[i - x][30] = leds[i - x][33] = leds[i - x][38] = CHSV((i - x) * 255 / 13, 255, 255);
    leds[i - x][42] = leds[i - x][45] = leds[i - x][51] = leds[i - x][52] = CHSV((i - x) * 255 / 13, 255, 255);
    //Fourth
    if (i > 2) x = 3;
    if (i > 10) x = i - 7;
    leds[i - x][3] = leds[i - x][4] = leds[i - x][10] = leds[i - x][13] = leds[i - x][17] = leds[i - x][22] = leds[i - x][24] = leds[i - x][31] = CHSV((i - x) * 255 / 13, 255, 255);
    leds[i - x][32] = leds[i - x][39] = leds[i - x][41] = leds[i - x][46] = leds[i - x][50] = leds[i - x][53] = leds[i - x][59] = leds[i - x][60] = CHSV((i - x) * 255 / 13, 255, 255);
    //Fifth
    if (i > 3) x = 4;
    if (i > 11) x = i - 7;
    leds[i - x][2] = leds[i - x][5] = leds[i - x][9] = leds[i - x][14] = leds[i - x][16] = leds[i - x][23] = leds[i - x][40] = leds[i - x][47] = CHSV((i - x) * 255 / 13, 255, 255);
    leds[i - x][49] = leds[i - x][54] = leds[i - x][58] = leds[i - x][61] = CHSV((i - x) * 255 / 13, 255, 255);
    //Sixth
    if (i > 4) x = 5;
    if (i > 12) x = i - 7;
    leds[i - x][1] = leds[i - x][6] = leds[i - x][8] = leds[i - x][15] = leds[i - x][48] = leds[i - x][55] = leds[i - x][57] = leds[i - x][62] = CHSV((i - x) * 255 / 13, 255, 255);
    //Seventh
    if (i > 5) x = 6;
    if (i > 13) x = i - 7;
    leds[i - x][0] = leds[i - x][7] = leds[i - x][56] = leds[i - x][63] = CHSV((i - x) * 255 / 13, 255, 255);

    FastLED.show();
    delay(anim_delay);
  }


  for (int i = 13; i > 0; i--) {
    turnoff();
    x = 0;
    if (i <= 5) x = i;
    //First
    if (i > 5) x = 6;
    if (i > 13) x = i - 7;
    leds[i - x][27] = leds[i - x][28] = leds[i - x][35] = leds[i - x][36] = CHSV((i - x) * 255 / 13, 255, 255);
    //Second
    if (i > 4) x = 5;
    if (i > 12) x = i - 7;
    leds[i - x][19] = leds[i - x][20] = leds[i - x][26] = leds[i - x][29] = leds[i - x][34] = leds[i - x][37] = leds[i - x][43] = leds[i - x][44] = CHSV((i - x) * 255 / 13, 255, 255);
    //Third
    if (i > 3) x = 4;
    if (i > 11) x = i - 7;
    leds[i - x][11] = leds[i - x][12] = leds[i - x][18] = leds[i - x][21] = leds[i - x][25] = leds[i - x][30] = leds[i - x][33] = leds[i - x][38] = CHSV((i - x) * 255 / 13, 255, 255);
    leds[i - x][42] = leds[i - x][45] = leds[i - x][51] = leds[i - x][52] = CHSV((i - x) * 255 / 13, 255, 255);
    //Fourth
    if (i > 2) x = 3;
    if (i > 10) x = i - 7;
    leds[i - x][3] = leds[i - x][4] = leds[i - x][10] = leds[i - x][13] = leds[i - x][17] = leds[i - x][22] = leds[i - x][24] = leds[i - x][31] = CHSV((i - x) * 255 / 13, 255, 255);
    leds[i - x][32] = leds[i - x][39] = leds[i - x][41] = leds[i - x][46] = leds[i - x][50] = leds[i - x][53] = leds[i - x][59] = leds[i - x][60] = CHSV((i - x) * 255 / 13, 255, 255);
    //Fifth
    if (i > 1) x = 2;
    if (i > 9) x = i - 7;
    leds[i - x][2] = leds[i - x][5] = leds[i - x][9] = leds[i - x][14] = leds[i - x][16] = leds[i - x][23] = leds[i - x][40] = leds[i - x][47] = CHSV((i - x) * 255 / 13, 255, 255);
    leds[i - x][49] = leds[i - x][54] = leds[i - x][58] = leds[i - x][61] = CHSV((i - x) * 255 / 13, 255, 255);
    //Sixth
    if (i > 0) x = 1;
    if (i > 8) x = i - 7;
    leds[i - x][1] = leds[i - x][6] = leds[i - x][8] = leds[i - x][15] = leds[i - x][48] = leds[i - x][55] = leds[i - x][57] = leds[i - x][62] = CHSV((i - x) * 255 / 13, 255, 255);
    //Seventh
    if (i > 7) x = i - 7;
    leds[i - x][0] = leds[i - x][7] = leds[i - x][56] = leds[i - x][63] = CHSV((i - x) * 255 / 13, 255, 255);

    FastLED.show();
    delay(anim_delay);
  }
}


void wave(int anim_delay) {
  //First frame
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) leds[i][j] = CRGB::Purple;
  FastLED.show();
  delay(anim_delay);
  //Second frame
  leds[3][3] = leds[3][4] = leds[4][3] = leds[4][4] = CRGB::Black;
  leds[3][11] = leds[3][12] = leds[4][11] = leds[4][12] = CRGB::Purple;
  FastLED.show();
  delay(anim_delay);
  //Third frame
  leds[3][11] = leds[3][12] = leds[4][11] = leds[4][12] = leds[3][2] = leds[3][5] = leds[4][2] = leds[4][5] = CRGB::Black;
  leds[2][3] = leds[2][4] = leds[5][3] = leds[5][4] = CRGB::Black;
  leds[3][19] = leds[3][20] = leds[4][19] = leds[4][20] = CRGB::Purple;  //first
  leds[3][10] = leds[3][13] = leds[4][10] = leds[4][13] = CRGB::Purple;  //second
  leds[2][11] = leds[2][12] = leds[5][11] = leds[5][12] = CRGB::Purple;
  FastLED.show();
  delay(anim_delay);
  //Fourth frame
  leds[3][10] = leds[3][13] = leds[4][10] = leds[4][13] = CRGB::Black;
  leds[3][19] = leds[3][20] = leds[4][19] = leds[4][20] = CRGB::Black;
  leds[2][11] = leds[2][12] = leds[5][11] = leds[5][12] = CRGB::Black;
  leds[1][3] = leds[1][4] = leds[6][3] = leds[6][4] = CRGB::Black;
  leds[3][1] = leds[3][6] = leds[4][1] = leds[4][6] = CRGB::Black;

  leds[3][27] = leds[3][28] = leds[4][27] = leds[4][28] = CRGB::Purple;  //first
  leds[2][19] = leds[2][20] = leds[5][19] = leds[5][20] = CRGB::Purple;  //second
  leds[3][18] = leds[3][21] = leds[4][18] = leds[4][21] = CRGB::Purple;
  leds[1][11] = leds[1][12] = leds[6][11] = leds[6][12] = CRGB::Purple;  //third
  leds[3][9] = leds[3][14] = leds[4][9] = leds[4][14] = CRGB::Purple;

  FastLED.show();
  delay(anim_delay);
}

void christmasTree(int anim_delay, int repeats) {
  FastLED.setBrightness(100);
  //Middle
  leds[3][3] = leds[3][4] = leds[4][3] = leds[4][4] = CRGB::Brown;
  for (int i = 8; i <= 15; i++) leds[3][i] = leds[4][i] = CRGB::Green;
  for (int i = 17; i <= 22; i++) leds[3][i] = leds[4][i] = CRGB::Green;
  for (int i = 25; i <= 30; i++) leds[3][i] = leds[4][i] = CRGB::Green;
  for (int i = 34; i <= 37; i++) leds[3][i] = leds[4][i] = CRGB::Green;
  for (int i = 42; i <= 45; i++) leds[3][i] = leds[4][i] = CRGB::Green;
  leds[3][51] = leds[3][52] = leds[3][59] = leds[3][60] = leds[4][51] = leds[4][52] = leds[4][59] = leds[4][60] = CRGB::Green;
  //Middle 90deg
  for (int i = 0; i < 8; i++) leds[i][11] = leds[i][12] = CRGB::Green;
  for (int i = 1; i < 7; i++) leds[i][19] = leds[i][20] = leds[i][27] = leds[i][28] = CRGB::Green;
  leds[2][43] = leds[2][44] = leds[2][35] = leds[2][36] = CRGB::Green;
  leds[5][43] = leds[5][44] = leds[5][35] = leds[5][36] = CRGB::Green;
  FastLED.show();
}

void rainbow(int anim_delay, int repeats) {
  int color = 0;
  int slice = 0;
  for (int i = 0; i < repeats; i++) {
    for (int x = 0; x < 255; x++) {
      for (int y = 0; y < 64; y++) leds[slice][y] = CHSV(color, 255, 255);
      color++;
      slice++;
      if (slice > 7) slice = 0;
      if (color > 255) color = 0;
      FastLED.show();
      delay(anim_delay);
    }
  }
}

void chill(int anim_delay, int repeats) {
  int color = 0;
  for (int i = 0; i < repeats; i++) {
    for (int j = 0; j < 2560*2; j++) {
      for (int x = 0; x < 8; x++)
        for (int y = 0; y < 64; y++) leds[x][y] = CHSV(color, 255, 255);
      if(j%20 == 0) color++;
      FastLED.show();
      //delay(anim_delay);
    }
    for (int j = 2550*2; j > 0; j--) {
      for (int x = 0; x < 8; x++)
        for (int y = 0; y < 64; y++) leds[x][y] = CHSV(color, 255, 255);
      if(j%20 == 0) color--;
      FastLED.show();
      //delay(anim_delay);
    }
  }
}

void rain(int anim_delay, int repeats) {
  int slice, led;
  for (int i = 0; i < repeats; i++) {
    led = random(0, 63);
    //for(int j = 0; j < 8; j++) leds[k][num] = CRGB::Black;
  }
}

void spiral(int anim_delay, int repeats) {
  int num = 0;
  int color, colorprev;
  for (int i = 0; i < repeats; i++) {
    color = random8();
    if (abs(color - colorprev) < 40)
      if (color + 64 > 256) color -= 64;
      else color += 64;
    for (int j = 0; j < 64; j++) {
      for (int k = 0; k < 8; k++) leds[k][num] = CHSV(color, 255, 255);
      if (j < 8) num++;
      if (j >= 8 && j < 14) {
        if (j % 2 == 0) num += 15;
        else num++;
      }
      if (j >= 14 && j < 21) num++;
      if (j >= 21 && j < 27) {
        if (j % 2 == 1) num -= 15;
        else num--;
      }
      if (j >= 27 && j < 33) num--;
      if (j >= 33 && j < 38) {
        if (j % 2 == 1) num += 13;
        else num += 3;
      }
      if (j >= 38 && j < 43) num--;
      if (j >= 43 && j < 47) {
        if (j % 2 == 0) num -= 13;
        else num -= 3;
      }
      if (j >= 47 && j < 51) num++;
      if (j >= 51 && j < 54) {
        if (j % 2 == 0) num += 11;
        else num += 5;
      }
      if (j >= 54 && j < 57) num++;
      if (j >= 57 && j < 59) {
        if (j % 2 == 1) num -= 11;
        else num -= 5;
      }
      if (j >= 59 && j < 61) num--;
      if (j == 61) num = 36;
      if (j == 62) num = 35;
      FastLED.show();
      delay(anim_delay);
    }
    num = 0;
    colorprev = color;
  }
  num = 0;
  for (int j = 0; j < 64; j++) {
    for (int k = 0; k < 8; k++) leds[k][num] = CRGB::Black;
    if (j < 8) num++;
    if (j >= 8 && j < 14) {
      if (j % 2 == 0) num += 15;
      else num++;
    }
    if (j >= 14 && j < 21) num++;
    if (j >= 21 && j < 27) {
      if (j % 2 == 1) num -= 15;
      else num--;
    }
    if (j >= 27 && j < 33) num--;
    if (j >= 33 && j < 38) {
      if (j % 2 == 1) num += 13;
      else num += 3;
    }
    if (j >= 38 && j < 43) num--;
    if (j >= 43 && j < 47) {
      if (j % 2 == 0) num -= 13;
      else num -= 3;
    }
    if (j >= 47 && j < 51) num++;
    if (j >= 51 && j < 54) {
      if (j % 2 == 0) num += 11;
      else num += 5;
    }
    if (j >= 54 && j < 57) num++;
    if (j >= 57 && j < 59) {
      if (j % 2 == 1) num -= 11;
      else num -= 5;
    }
    if (j >= 59 && j < 61) num--;
    if (j == 61) num = 36;
    if (j == 62) num = 35;
    FastLED.show();
    delay(anim_delay);
  }
}

void strobe(int anim_delay, int repeats) {
  for (int i = 0; i < repeats; i++) {
    for (int x = 0; x < 8; x++)
      for (int y = 0; y < 64; y++) leds[x][y] = CRGB::White;
    FastLED.show();
    delay(anim_delay);
    for (int x = 0; x < 8; x++)
      for (int y = 0; y < 64; y++) leds[x][y] = CRGB::Black;
    FastLED.show();
    delay(anim_delay);
  }
}

void tetris(int anim_delay, int repeats) {
  for (int i = 0; i < repeats; i++) {
  }
}

void hyperspace(int anim_delay, int repeats) {
  int temp1 = random(0, 63);
  int fade = 0;
  //for(int i = 0; i < random(5,20)) {
  //  leds[0][temp1] = CHSV(color,255,255);
  //  FastLED.show();
  //}
}

void stars(int anim_delay, int repeats, int star_num) {
  FastLED.setBrightness(255);
  //Random sequence of different numbers from 0 to 511
  int temp, rand1, rand2;
  int randC;
  int stars[512], color[512];
  for (int i = 0; i < 512; i++) stars[i] = i;
  for (int i = 0; i < 1000; i++) {
    rand1 = random(0, 511);
    rand2 = random(0, 511);
    temp = stars[rand1];
    stars[rand1] = stars[rand2];
    stars[rand2] = temp;
  }

  for (int i = 0; i < 512; i++) {
    randC = random(-25, 50);
    for (int j = 0; j < 255; j++) {
      leds[stars[i] / 64][stars[i] % 64] = CHSV(50 + randC, 255, j);
      FastLED.show();
      delay(anim_delay);
    }
    if (i > star_num) {
      for (int j = 255; j > 0; j--) {
        leds[stars[i - star_num] / 64][stars[i - star_num] % 64] = CHSV(50 + randC, 255, j);
        FastLED.show();
        delay(anim_delay);
      }
      leds[stars[i - star_num] / 64][stars[i - star_num] % 64] = CHSV(0, 255, 0);
    }
  }
  FastLED.setBrightness(BRIGHTNESS);
}

void random_fill(int fill_delay, int repeats) {
  int random_slice;
  int random_diode;
  int temp, rand1, rand2;
  int random_numbers[512];
  for (int i = 0; i < 512; i++) random_numbers[i] = i;
  for (int i = 0; i < 1000; i++) {
    rand1 = random(0, 511);
    rand2 = random(0, 511);
    temp = random_numbers[rand1];
    random_numbers[rand1] = random_numbers[rand2];
    random_numbers[rand2] = temp;
  }
  for (int i = 0; i < 512; i++) {
    temp = random_numbers[i];
    if (temp < 64) leds[0][temp] = CHSV(random8(), 255, 255);
    else if (temp < 128) leds[1][temp - 64] = CHSV(random8(), 255, 255);
    else if (temp < 192) leds[2][temp - 128] = CHSV(random8(), 255, 255);
    else if (temp < 256) leds[3][temp - 192] = CHSV(random8(), 255, 255);
    else if (temp < 320) leds[4][temp - 256] = CHSV(random8(), 255, 255);
    else if (temp < 384) leds[5][temp - 320] = CHSV(random8(), 255, 255);
    else if (temp < 448) leds[6][temp - 384] = CHSV(random8(), 255, 255);
    else leds[7][temp - 448] = CHSV(random8(), 255, 255);
    FastLED.show();
  }

  delay(500);

  for (int i = 0; i < 512; i++) random_numbers[i] = i;
  for (int i = 0; i < 1000; i++) {
    rand1 = random(0, 511);
    rand2 = random(0, 511);
    temp = random_numbers[rand1];
    random_numbers[rand1] = random_numbers[rand2];
    random_numbers[rand2] = temp;
  }

  for (int i = 0; i < 512; i++) {
    temp = random_numbers[i];
    if (temp < 64) leds[0][temp] = CRGB::Black;
    else if (temp < 128) leds[1][temp - 64] = CRGB::Black;
    else if (temp < 192) leds[2][temp - 128] = CRGB::Black;
    else if (temp < 256) leds[3][temp - 192] = CRGB::Black;
    else if (temp < 320) leds[4][temp - 256] = CRGB::Black;
    else if (temp < 384) leds[5][temp - 320] = CRGB::Black;
    else if (temp < 448) leds[6][temp - 384] = CRGB::Black;
    else leds[7][temp - 448] = CRGB::Black;
    FastLED.show();
  }

  delay(500);
}

void running_led(int run_delay, int repeats) {
  for (int x = 0; x < repeats; x++) {
    for (int i = 0; i < 7; i += 2) {
      for (int j = 0; j < 64; j++) {
        leds[i][j] = CHSV(random8(), 255, 255);
        FastLED.show();
        delay(run_delay);
      }
      for (int j = 63; j >= 0; j--) {
        leds[i + 1][j] = CHSV(random8(), 255, 255);
        FastLED.show();
        delay(run_delay);
      }
    }
    //Coming back
    for (int i = 7; i > 0; i -= 2) {
      for (int j = 0; j < 64; j++) {
        leds[i][j] = CRGB::Black;
        FastLED.show();
        delay(run_delay);
      }
      for (int j = 63; j >= 0; j--) {
        leds[i - 1][j] = CRGB::Black;
        FastLED.show();
        delay(run_delay);
      }
    }
  }
  delay(run_delay);
}


void up_down(int floor_delay, int repeats) {
  for (int x = 0; x < repeats; x++) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i * 8] = leds[j][i * 8 + 1] = leds[j][i * 8 + 2] = leds[j][i * 8 + 3] = leds[j][i * 8 + 4] = leds[j][i * 8 + 5] = leds[j][i * 8 + 6] = leds[j][i * 8 + 7] = CRGB::Purple;
        FastLED.show();
      }
      delay(floor_delay);
      turnoff();
    }

    for (int i = 6; i > 0; i--) {
      for (int j = 0; j < 8; j++) {
        leds[j][i * 8] = leds[j][i * 8 + 1] = leds[j][i * 8 + 2] = leds[j][i * 8 + 3] = leds[j][i * 8 + 4] = leds[j][i * 8 + 5] = leds[j][i * 8 + 6] = leds[j][i * 8 + 7] = CRGB::Purple;
        FastLED.show();
      }
      delay(floor_delay);
      turnoff();
    }
  }
  delay(floor_delay);
}




void cube(int cube_delay, int repeats) {

  for (int x = 0; x < repeats; x++) {
    ///////////
    //1 stage
    ///////////
    for (int i = 0; i < 8; i++) {
      leds[0][i] = CRGB::Cyan;
      leds[0][i + 56] = CRGB::Cyan;
      leds[7][i] = CRGB::Cyan;
      leds[7][i + 56] = CRGB::Cyan;
    }

    leds[0][8] = CRGB::Cyan;
    leds[0][15] = CRGB::Cyan;
    leds[0][16] = CRGB::Cyan;
    leds[0][23] = CRGB::Cyan;
    leds[0][24] = CRGB::Cyan;
    leds[0][31] = CRGB::Cyan;
    leds[0][32] = CRGB::Cyan;
    leds[0][39] = CRGB::Cyan;
    leds[0][40] = CRGB::Cyan;
    leds[0][47] = CRGB::Cyan;
    leds[0][48] = CRGB::Cyan;
    leds[0][55] = CRGB::Cyan;

    leds[7][8] = CRGB::Cyan;
    leds[7][15] = CRGB::Cyan;
    leds[7][16] = CRGB::Cyan;
    leds[7][23] = CRGB::Cyan;
    leds[7][24] = CRGB::Cyan;
    leds[7][31] = CRGB::Cyan;
    leds[7][32] = CRGB::Cyan;
    leds[7][39] = CRGB::Cyan;
    leds[7][40] = CRGB::Cyan;
    leds[7][47] = CRGB::Cyan;
    leds[7][48] = CRGB::Cyan;
    leds[7][55] = CRGB::Cyan;

    for (int i = 1; i < 7; i++) {
      leds[i][0] = CRGB::Cyan;
      leds[i][7] = CRGB::Cyan;
      leds[i][56] = CRGB::Cyan;
      leds[i][63] = CRGB::Cyan;
    }
    FastLED.show();
    delay(cube_delay);
    turnoff();


    ///////////
    //2 stage
    ///////////
    for (int i = 1; i < 7; i++) {
      leds[1][i + 8] = CRGB::Cyan;
      leds[1][i + 48] = CRGB::Cyan;
      leds[6][i + 8] = CRGB::Cyan;
      leds[6][i + 48] = CRGB::Cyan;
    }

    leds[1][17] = CRGB::Cyan;
    leds[1][22] = CRGB::Cyan;
    leds[1][25] = CRGB::Cyan;
    leds[1][30] = CRGB::Cyan;
    leds[1][33] = CRGB::Cyan;
    leds[1][38] = CRGB::Cyan;
    leds[1][41] = CRGB::Cyan;
    leds[1][46] = CRGB::Cyan;

    leds[6][17] = CRGB::Cyan;
    leds[6][22] = CRGB::Cyan;
    leds[6][25] = CRGB::Cyan;
    leds[6][30] = CRGB::Cyan;
    leds[6][33] = CRGB::Cyan;
    leds[6][38] = CRGB::Cyan;
    leds[6][41] = CRGB::Cyan;
    leds[6][46] = CRGB::Cyan;

    for (int i = 2; i < 6; i++) {
      leds[i][9] = CRGB::Cyan;
      leds[i][14] = CRGB::Cyan;
      leds[i][49] = CRGB::Cyan;
      leds[i][54] = CRGB::Cyan;
    }
    FastLED.show();
    delay(cube_delay);
    turnoff();

    ///////////
    //3 stage
    ///////////
    for (int i = 2; i < 6; i++) {
      leds[2][i + 16] = CRGB::Cyan;
      leds[2][i + 40] = CRGB::Cyan;
      leds[5][i + 16] = CRGB::Cyan;
      leds[5][i + 40] = CRGB::Cyan;
    }

    leds[2][26] = CRGB::Cyan;
    leds[2][29] = CRGB::Cyan;
    leds[2][34] = CRGB::Cyan;
    leds[2][37] = CRGB::Cyan;

    leds[5][26] = CRGB::Cyan;
    leds[5][29] = CRGB::Cyan;
    leds[5][34] = CRGB::Cyan;
    leds[5][37] = CRGB::Cyan;

    for (int i = 3; i < 5; i++) {
      leds[i][18] = CRGB::Cyan;
      leds[i][21] = CRGB::Cyan;
      leds[i][42] = CRGB::Cyan;
      leds[i][45] = CRGB::Cyan;
    }
    FastLED.show();
    delay(cube_delay);
    turnoff();

    ///////////
    //4 stage
    ///////////
    leds[3][27] = CRGB::Cyan;
    leds[3][28] = CRGB::Cyan;
    leds[3][35] = CRGB::Cyan;
    leds[3][36] = CRGB::Cyan;
    leds[4][27] = CRGB::Cyan;
    leds[4][28] = CRGB::Cyan;
    leds[4][35] = CRGB::Cyan;
    leds[4][36] = CRGB::Cyan;
    FastLED.show();
    delay(cube_delay);
    turnoff();


    ///////////
    //3 stage
    ///////////
    for (int i = 2; i < 6; i++) {
      leds[2][i + 16] = CRGB::Cyan;
      leds[2][i + 40] = CRGB::Cyan;
      leds[5][i + 16] = CRGB::Cyan;
      leds[5][i + 40] = CRGB::Cyan;
    }

    leds[2][26] = CRGB::Cyan;
    leds[2][29] = CRGB::Cyan;
    leds[2][34] = CRGB::Cyan;
    leds[2][37] = CRGB::Cyan;

    leds[5][26] = CRGB::Cyan;
    leds[5][29] = CRGB::Cyan;
    leds[5][34] = CRGB::Cyan;
    leds[5][37] = CRGB::Cyan;

    for (int i = 3; i < 5; i++) {
      leds[i][18] = CRGB::Cyan;
      leds[i][21] = CRGB::Cyan;
      leds[i][42] = CRGB::Cyan;
      leds[i][45] = CRGB::Cyan;
    }
    FastLED.show();
    delay(cube_delay);
    turnoff();


    ///////////
    //2 stage
    ///////////
    for (int i = 1; i < 7; i++) {
      leds[1][i + 8] = CRGB::Cyan;
      leds[1][i + 48] = CRGB::Cyan;
      leds[6][i + 8] = CRGB::Cyan;
      leds[6][i + 48] = CRGB::Cyan;
    }

    leds[1][17] = CRGB::Cyan;
    leds[1][22] = CRGB::Cyan;
    leds[1][25] = CRGB::Cyan;
    leds[1][30] = CRGB::Cyan;
    leds[1][33] = CRGB::Cyan;
    leds[1][38] = CRGB::Cyan;
    leds[1][41] = CRGB::Cyan;
    leds[1][46] = CRGB::Cyan;

    leds[6][17] = CRGB::Cyan;
    leds[6][22] = CRGB::Cyan;
    leds[6][25] = CRGB::Cyan;
    leds[6][30] = CRGB::Cyan;
    leds[6][33] = CRGB::Cyan;
    leds[6][38] = CRGB::Cyan;
    leds[6][41] = CRGB::Cyan;
    leds[6][46] = CRGB::Cyan;

    for (int i = 2; i < 6; i++) {
      leds[i][9] = CRGB::Cyan;
      leds[i][14] = CRGB::Cyan;
      leds[i][49] = CRGB::Cyan;
      leds[i][54] = CRGB::Cyan;
    }
    FastLED.show();
    delay(cube_delay);
    turnoff();
  }

  ///////////
  //1 stage
  ///////////
  for (int i = 0; i < 8; i++) {
    leds[0][i] = CRGB::Cyan;
    leds[0][i + 56] = CRGB::Cyan;
    leds[7][i] = CRGB::Cyan;
    leds[7][i + 56] = CRGB::Cyan;
  }

  leds[0][8] = CRGB::Cyan;
  leds[0][15] = CRGB::Cyan;
  leds[0][16] = CRGB::Cyan;
  leds[0][23] = CRGB::Cyan;
  leds[0][24] = CRGB::Cyan;
  leds[0][31] = CRGB::Cyan;
  leds[0][32] = CRGB::Cyan;
  leds[0][39] = CRGB::Cyan;
  leds[0][40] = CRGB::Cyan;
  leds[0][47] = CRGB::Cyan;
  leds[0][48] = CRGB::Cyan;
  leds[0][55] = CRGB::Cyan;

  leds[7][8] = CRGB::Cyan;
  leds[7][15] = CRGB::Cyan;
  leds[7][16] = CRGB::Cyan;
  leds[7][23] = CRGB::Cyan;
  leds[7][24] = CRGB::Cyan;
  leds[7][31] = CRGB::Cyan;
  leds[7][32] = CRGB::Cyan;
  leds[7][39] = CRGB::Cyan;
  leds[7][40] = CRGB::Cyan;
  leds[7][47] = CRGB::Cyan;
  leds[7][48] = CRGB::Cyan;
  leds[7][55] = CRGB::Cyan;

  for (int i = 1; i < 7; i++) {
    leds[i][0] = CRGB::Cyan;
    leds[i][7] = CRGB::Cyan;
    leds[i][56] = CRGB::Cyan;
    leds[i][63] = CRGB::Cyan;
  }
  FastLED.show();
  delay(cube_delay);
  turnoff();
  delay(cube_delay);
}
