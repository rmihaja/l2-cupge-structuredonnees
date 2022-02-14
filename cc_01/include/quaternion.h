#ifndef __QUATERNION_H__
#define __QUATERNION_H__

typedef struct s_imaginaire *Imaginaire;
typedef struct s_quaternion *Quaternion;

Quaternion quaternion(float, float, float, float);

float Re(Quaternion);
Imaginaire Im(Quaternion);

float norme(Quaternion);
Quaternion conjugue(Quaternion);
Quaternion inverse(Quaternion);

// * fonctions auxiliaires
void printf_quaternion(Quaternion);
void printf_imaginaire(Imaginaire);
Quaternion produit_quaternion(Quaternion, Quaternion);
#endif