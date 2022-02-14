#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "quaternion.h"

typedef struct s_imaginaire {
    float b;
    float c;
    float d;
} *Imaginaire;

typedef struct s_quaternion
{
    // ? équivalent au coefficient a
    float re;
    Imaginaire im;
} *Quaternion;

Quaternion quaternion(float a, float b, float c, float d) {
    Quaternion q = (Quaternion)malloc(sizeof(struct s_quaternion));
    q->re = a;

    Imaginaire im = (Imaginaire)malloc(sizeof(struct s_imaginaire));
    im->b = b;
    im->c = c;
    im->d = d;
    q->im = im;

    return q;
}

float Re(Quaternion q) {
    return q->re;
}

Imaginaire Im(Quaternion q) {
    return q->im;
}

float norme(Quaternion q) {
    float norme = 0;
    norme += (q->re * q->re);
    norme += (q->im->b * q->im->b);
    norme += (q->im->c * q->im->c);
    norme += (q->im->d * q->im->d);
    return norme;
}

Quaternion conjugue(Quaternion q) {
    Imaginaire im = Im(q);
    Quaternion q_bar = quaternion(Re(q), -(im->b), -(im->c), -(im->d));
    return q_bar;
}

// 1 := est nul
// 0 := n'est pas nul
int isNull(Quaternion q) {
    Imaginaire im = Im(q);
    if (Re(q) == 0 && im->b == 0 && im->c == 0 && im->d == 0) {
        return 1;
    }
    return 0;
}

Quaternion inverse(Quaternion q) {
    assert(isNull(q) == 0);

    Quaternion q_inverse = conjugue(q);
    q_inverse->re *= (1 / norme(q));
    q_inverse->im->b *= (1 / norme(q));
    q_inverse->im->c *= (1 / norme(q));
    q_inverse->im->d *= (1 / norme(q));

    return q_inverse;
}

// * fonctions auxiliaires

void printf_quaternion(Quaternion q) {
    printf("%f + %fi + %fj + %fk\n", Re(q), q->im->b, q->im->c, q->im->d);
}

void printf_imaginaire(Imaginaire im) {
    printf("%fi + %fj + %fk\n", im->b, im->c, im->d);
}