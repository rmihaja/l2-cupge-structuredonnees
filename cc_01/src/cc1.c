#include <stdio.h>
#include "quaternion.h"

int main()
{
    Quaternion q1 = quaternion(1, 2.3, 4, 5.7);
    Quaternion q2 = quaternion(6, 4, 2.9, 3.3);

    printf("q1 vaut :\n");
    printf_quaternion(q1);

    printf("q2 vaut :\n");
    printf_quaternion(q2);

    printf("La partie réelle de q2 vaut %f\n", Re(q2));
    printf("La partie imaginaire pur de q2 vaut :\n");
    printf_imaginaire(Im(q2));

    printf("La norme de q1 vaut %f\n", norme(q1));
    printf("Le conjugué de q1 vaut :\n");
    printf_quaternion(conjugue(q1));
    printf("L'inverse de q1 vaut :\n");
    printf_quaternion(inverse(q1));
    return 0;
}
