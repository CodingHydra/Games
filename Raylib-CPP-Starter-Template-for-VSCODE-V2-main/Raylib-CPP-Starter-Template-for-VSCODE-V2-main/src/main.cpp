#include <raylib.h>
#include <iostream>

class Ball
{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;


    void Draw()
    {
       DrawCircle(x, y, radius, WHITE);  
    }

    void Update()
    {
        x += speed_x;
        y += speed_y;

        if(y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }
        if(x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speed_x *= -1;
        }


    }
};

class Paddle
{
public:
float x , y;
float width, height;
int speed;

void Draw()
{
    DrawRectangle(x, y, width, height, WHITE);


};

void Update()
{
    if(IsKeyDown(KEY_UP))
    {
        y = y - speed;
    }
    if(IsKeyDown(KEY_DOWN))
    {
        y = y + speed;
    }
}

};
Paddle player;
Ball ball;


int main()
{
    std::cout << "The Complier can complie" << std::endl;
    const int screen_height = 800;
    const int screen_width = 1200;

    InitWindow(screen_width, screen_height, " Pong Game");
    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_width / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - screen_width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6; 



    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        //Updating
        ball.Update();
        player.Update();


        //Drawing
        ClearBackground(BLACK);
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
        ball.Draw(); 
        
        player.Draw();
        DrawRectangle(screen_width -35, screen_height /2 -60, 25, 120, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}