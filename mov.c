#include "mov.h"

Point normalizeCircle(Point point, Paddle* paddle) {
    Point normalized;
    normalized.x = (point.x - paddle->p.x + paddle->size.x/2) / paddle->radius;
    normalized.y = (point.y - paddle->p.y + paddle->size.x/2) / paddle->radius;
    return normalized;
}
Vector reflect(Vector incident, Vector normal, float slope) {
    Vector reflection;
    float dot = dotProduct(incident, normal);
    reflection.x = -(incident.x -(2 + slope) * dot * normal.x);
    reflection.y = -(incident.y - 2 * dot * normal.y);
    return reflection;
}
void bounce(Ball *ballp, void* o, int reverse) {
    Ball ball = *ballp;
    struct Paddle *other = (struct Paddle *)o;
    Vector normal = calcNormal(other);
    Vector r = reflect(ball.dir, normal, (ball.p.x - (other->p.x + other->size.x)) /64);
    ballp->dir.y = r.y * reverse;
    ballp->dir.x = r.x;
}
void bounceV(Ball *ballp, Vector normal) {
    Ball ball = *ballp;
    Vector r = reflect(ball.dir, normal, 0.0);
    ballp->dir = r;
}
void moveBall(Ball* ball, Paddle* paddle, Mix_Chunk* chunk, Mix_Chunk* chunk2) {

    int collide = collideWith(ball, paddle);
    if (collide == 0) {
        
    }
    else if (collide == 1) {

        Mix_PlayChannel(-1, chunk, 0);
        bounce(ball, paddle, 1);
    }
    else if (collide == 2) {

        Mix_PlayChannel(-1, chunk2, 0);
        
        bounce(ball, paddle, -1);
    }
    if (ball->p.x > 640 || ball->p.x < 0) {
            Vector normal = {1,0};
            bounceV(ball, normal);       
    }
    if (ball->p.y < 0) {
            Vector normal = {0,1};
            bounceV(ball, normal);       
    }
    float ang = atan2(ball->dir.y, ball->dir.x);
    ball->p.x += sin(ang) * ball->vel;
    ball->p.y += cos(ang) * ball->vel;
}
