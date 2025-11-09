#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"

int main() {
    Print("\n\t ========== GÉOMÉTRIE D'UN PLAN 2D (PLANE GEOMETRY) ========== \n\n");

    // =========== Test Points ===========
    Print(" ====== Test Points ====== \n");

    // 1. Création d'un point nul
    Point2f p = MakeNullPoint();
    Print(" Null Point: ", ToString(p));

    // 2. Création d'un point à partir des 2 coordonnées
    Point2f p1 = MakeP2f(2.0f, 3.0f);
    Print(" Point: ", ToString(p1));

    // 3. Translation d'un point à partir de 2 coordonnées 
    float x = -1.0, y = 1.0;
    Point2f p2 = Translate(p1, x, y);
    Print(" Translated: ", ToString(p2));

    // 4. Translation d'un point à partir d'un vecteur
    Vector2f v = MakeV2f(1.0f, -1.0f);
    Point2f p3 = Translate(p1, v);
    Print(" Translated: ", ToString(p3));

    // 5. L'Homothesie d'un point à partir de 2 coordonnées
    Point2f p4 = Scale(p1, x, y); 
    Print(" Scaled: ", ToString(p4));

    // 6. L'Homothesie d'un point à partir d'un vecteur
    Point2f p5 = Scale(p1, v);
    Print(" Scaled: ", ToString(p5));

    // 7. Rotation d'un point à partir d'un angle
    float angleDegree = 90.0f;
    Point2f p6 = Rotate(p1, angleDegree);
    Print(" Rotate: ", ToString(p6));


    // =========== Test Vecteurs ==========
    Print("\n ====== Test Vecteurs ====== \n");

    // 1. Création d'un vecteur null
    Vector2f nul = MakeNullVector();
    Print(" Null Vector: ", ToString(nul));
    // 2. Création d'un vecteur à partir de 2 coordonnées
    Vector2f v1 = MakeV2f(-3.0f, 4.0f);
    Print(" Vector1: ", ToString(v1));

    // 3. Création d'un vecteur à partir de 2 points
    Vector2f v2 = MakeV2f(p1, p2);
    Print(" Vector2: ", ToString(v2));

    // 4. Addition vectorielle
    Vector2f v3 = Add(v1, v2);
    Print(" Addition: ", ToString(v3));

    // 5. Soustraction vectorielle
    v3 = Sub(v1, v2);
    Print(" Substraction: ", ToString(v3));

    // 6. L'Homothesie d'un vecteur par un scalaire k
    float k = 0.5f;
    Vector2f v4 = Scale(v3, k);
    Print(" Scaled: ", ToString(v4));

    // 7. Produit scalaire
    float dot = Dot(v1, v2);
    Print(" Dot Product: ", dot);

    // 8. Longueur d'un vecteur
    float __len = Length(v1);
    Print(" Length: ", __len);

    // 9. Le vecteur unitaire d'un vecteur
    Vector2f v5 = Normalize(v1);
    Print(" Unit vector: ", ToString(v5));

    // 10. L'Interpolation linéaire
    Vector2f U = {0, 0}, V = {10, 10};
    Vector2f v6 = Lerp(U, V, 0.5f);
    Print(" Lerp: ", ToString(v6));

    // 11. Le Determinant de 2 vecteurs
    float Det = Determinant(v1, v2);
    Print(" Determinant: ", Det);

    Print("\n");
    return 0;
}