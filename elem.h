#ifndef ELEM_H
#define ELEM_H
#include "elem.h"
#include "math.h"
typedef enum {
        Def,
        Invulnerable,
        Explosion,
        Invisible,
        Three,
        Nonexistent,
} TileType;

typedef enum {
        Stick,
        StickOnce,
        DefBuff,
        Wide,
        Kill,
        Shrink,
        Explosive,
        Soften,
        Double,
        Pen,
        Laser,

} BuffType;
typedef enum {
        Falling,
        DefaultStatus,
} Status;
typedef struct {
        float x;
        float y;
} Point;
typedef struct {
        float x;
        float y;
} Vector;
typedef struct {
        Point p;
        Point size;
        Vector vel;
        float speed;
        int alive;
} Projectile;
typedef struct {
        Point p;
        Point size;
        Vector vel;
        TileType ttype;
        BuffType buff;
        Status status;
        int hits;
        int alive;
} Tile;
typedef struct Ball {
        Point p;
        Point size;
        BuffType buff;
        float vel;
        Vector dir;
        int explosive;
        int pen;
        int alive;

} Ball;

typedef struct Paddle {
        Point p;
        Point size;
        BuffType buff;
        float vel;
        float dir;
        int radius;
        int shoot;
} Paddle;
void fallTile(Tile* tile);
Vector subtractPoints(Point p1, Point p2);
Vector crossProduct(Vector v1, Vector v2);
float dotProduct(Vector v1, Vector v2);
float magnitude(Vector v);
Vector normalize(Vector v);
Vector getNormalVec(Point p1, Point p2);
Vector calcNormal(Paddle* other);
int randI();
#endif
