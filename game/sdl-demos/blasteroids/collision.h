typedef struct Point
{
  float x;
  float y;
} Point;

typedef struct Box{
  Point pos;
  float height;
  float width;
} Box;


int is_collision(Box*, Box*);
