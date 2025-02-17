int array[7][14] = {
  { 6, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4, 5 },
  { 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3, 4 },
  { 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2, 3 },
  { 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 1, 2 },
  { 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, 1 },
  { 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0 },
  { 0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1 }
};

int led_adresses[8][8] = {
  { 63, 62, 61, 60, 59, 58, 57, 56 },
  { 48, 49, 50, 51, 52, 53, 54, 55 },
  { 47, 46, 45, 44, 43, 42, 41, 40 },
  { 32, 33, 34, 35, 36, 37, 38, 39 },
  { 31, 30, 29, 28, 27, 26, 25, 24 },
  { 16, 17, 18, 19, 20, 21, 22, 23 },
  { 15, 14, 13, 12, 11, 10, 9, 8 },
  { -1, 1, 2, 3, 4, 5, 6, 7 }
};

int A[8][8] = {
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int B[8][8] = {
  { 0, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 }
};

int C[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 }
};

int D[8][8] = {
  { 0, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 1, 1, 1, 0, 0, 0 }
};

int E[8][8] = {
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 }
};

int F[8][8] = {
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 }
};

int G[8][8] = {
  { 0, 0, 0, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 1, 1, 1, 0, 0 }
};

int H[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int I[8][8] = {
  { 0, 0, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 0, 0, 0 }
};

int J[8][8] = {
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 0, 0, 0 }
};

int K[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int L[8][8] = {
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 }
};

int M[8][8] = {
  { 0, 1, 0, 0, 0, 1, 1, 0 },
  { 0, 1, 1, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int N[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int O[8][8] = {
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 }
};

int P[8][8] = {
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 }
};

int R[8][8] = {
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int S[8][8] = {
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 }
};

int T[8][8] = {
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 1, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 }
};

int U[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 1, 1, 1, 0, 0 }
};

int V[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 }
};

int W[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 1, 1, 0, 0 }
};

int X[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 }
};

int Y[8][8] = {
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 }
};

int Z[8][8] = {
  { 0, 1, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 0 }
};

int EX[8][8] = {
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 }
};

int HE[8][8] = {
  { 0, 1, 1, 0, 0, 1, 1, 0 },
  { 1, 0, 0, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 1, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 1, 0, 0, 0 }
};

int nothing[8][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0 }
};

