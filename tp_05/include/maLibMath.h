#ifndef __MALIBMATH_H__
#define __MALIBMATH_H__

typedef struct s_point *Point;
typedef struct s_vecteur Vector;
typedef struct s_equation Equation;

/**
 * @brief crée un "point 3D" à partir des entrées de l'utilisateur
 *
 * @return Point
 */
Point Demande_Point();

/**
 * @brief Crée un "point 3D" à partir des coordonnées données en paramètres
 *
 * @param x
 * @param y
 * @param z
 * @return Point
 */
Point Creer_Point(float x, float y, float z);

/**
 * @brief définit le vecteur AB à partir des points A et B
 *
 * @param A
 * @param B
 * @return Vector
 */
Vector Vectorise(Point A, Point B);

Vector Produit_Vectoriel(Vector, Vector);

float Norme(Vector);



#endif