#include "coll.h" 

int collideWith(Ball* this, Paddle* other) {
    if (this->p.x > other->p.x - 4 && this->p.x < other->p.x + other->size.x + 4 && this->p.y > other->p.y && this->p.y < other->p.y + 4) {

        return 1;
    }
    
    return 0;
}
int collideLaserWithTile(Ball* ball, Projectile* this, Tile* other, Mix_Chunk* chunk) {
    if (this->p.x > other->p.x -1 && this->p.x < other->p.x + other->size.x +1 && this->p.y > other->p.y && this->p.y < other->p.y + other->size.y) {
        Mix_PlayChannel(-1, chunk, 0);
            other->hits--;
            if (ball->pen == 0) {
                other->hits = 0;
                return 1;
            }
            if (other->ttype == Explosion) {
                return 2;
            }
            if (other->hits <= 0) {
                return 1;
            }
    }

    return 0;
}
int collidePaddleWithTile(Paddle* other, Tile* this, Mix_Chunk* chunk) {

    if (this->p.x + this->size.x/2 > other->p.x && this->p.x + this->size.x/2 < other->p.x + other->size.x && this->p.y > other->p.y && this->p.y < other->p.y + other->size.y) {
        return this->buff;
    }
    
    return DefBuff;
}
int collideWithTile(Ball* this, Tile* other, Mix_Chunk* chunk) {
    if (other->status == Falling) {
        return 0;          
    }
    if (this->p.x > other->p.x -1 && this->p.x < other->p.x + other->size.x + 1 && this->p.y > other->p.y -1 && this->p.y < other->p.y + other->size.y + 1) {
        Mix_PlayChannel(-1, chunk, 0);
        this->vel += 0.03;
        Vector normal = {0,0};
        if (this->p.x - this->vel * this->dir.x < other->p.x - 3) {
            normal = (Vector) {1,0};
        }
        else if (this->p.x - this->vel * this->dir.x > other->p.x + other->size.x + 3) {
            normal = (Vector){1,0};
        }
        else if (this->p.y - this->vel * this->dir.x < other->p.y + 2) {
            normal = (Vector){0,1};
        }
        else if (this->p.y - this->vel * this->dir.x > other->p.y + other->size.y - 2) {
            normal = (Vector){0,1};
        }
        if (this->pen == 0) {
            bounceV(this, normal);       
        }
        other->hits -= 1;
        if (other->hits <= 0 || this->pen == 1) {
            other->alive = 0; 
        }
        if (this->explosive == 1 || other->ttype == Explosion) {
            return 2;
        }
        return 1;
    }
    return 0;
}
int checkTileStatus(Tile* other) {
        return 0; 
}
