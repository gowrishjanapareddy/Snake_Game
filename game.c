#include "raylib.h"
int main(){
    const int sw=900;
    const int sh=800;
    InitWindow(sw,sh,"Snake Game");
    SetTargetFPS(60);
    Vector2 circlepos2={40,780};
    Vector2 circlepos1={40,760};
    Vector2 circlepos={40,740};
    float circlespeed=3;
    Rectangle player={0,0,20,800};
    Rectangle player1={60,80,20,800};
    Rectangle player2={80,400,60,400};
    Rectangle player3={120,0,60,320};
    Rectangle player4={180,0,20,700};
    Rectangle player5={240,50,20,800};
    Rectangle player6={260,50,60,500};
    Rectangle player7={300,600,160,140};
    Rectangle player8={360,0,60,600};
    Rectangle player9={500,550,40,600};
    Rectangle player10={470,30,100,520};
    Rectangle player11={620,0,60,620};
    Rectangle player12={580,600,100,150};
    Rectangle player13={760,300,40,40};
    int circleradius=10;
    bool iscollision=false;
    bool iscollision1=false;
    bool iscollision2=false;
    bool iscollision3=false;
    bool iscollision4=false;
    bool iscollision5=false;
    bool iscollision6=false;
    bool iscollision7=false;
    bool iscollision8=false;
    bool iscollision9=false;
    bool iscollision10=false;
    bool iscollision11=false;
    bool iscollision12=false;
    bool iscollision13=false;
    while(!WindowShouldClose()){
        int a;
        int b;
        int c,d;
        a=circlepos.x;
        b=circlepos.y;
        c=circlepos1.x;
        d=circlepos1.y;
        if(IsKeyDown(KEY_LEFT)){
            circlepos.x-=circlespeed;
            circlepos1.x=a+15;
            circlepos1.y=b;
            circlepos2.x=c+15;
            circlepos2.y=d;
        }
        if(IsKeyDown(KEY_RIGHT)){
            circlepos.x+=circlespeed;
            circlepos1.x=a-15;
            circlepos1.y=b;
            circlepos2.x=c-15;
            circlepos2.y=d;
        }
        if(IsKeyDown(KEY_UP)){
            circlepos.y-=circlespeed;
            circlepos1.x=a;
            circlepos1.y=b+15;
            circlepos2.x=c;
            circlepos2.y=d+15;            
        }
        if(IsKeyDown(KEY_DOWN)){
            circlepos.y+=circlespeed;
            circlepos1.x=a;
            circlepos1.y=b-15;
            circlepos2.x=c;
            circlepos2.y=d-15; 
        }
        if(circlepos.x<10){
            circlepos.x=10;
        }
        if(circlepos.y<10){
            circlepos.y=10;
        }
        if(circlepos.x>sw-15){
            circlepos.x=sw-15;
        }
        if(circlepos.y>sh-15){
            circlepos.y=sh-15;
        }
        iscollision=CheckCollisionCircleRec(circlepos,circleradius,player);
        iscollision1=CheckCollisionCircleRec(circlepos,circleradius,player1);
        iscollision2=CheckCollisionCircleRec(circlepos,circleradius,player2);
        iscollision3=CheckCollisionCircleRec(circlepos,circleradius,player3);
        iscollision4=CheckCollisionCircleRec(circlepos,circleradius,player4);
        iscollision5=CheckCollisionCircleRec(circlepos,circleradius,player5);
        iscollision6=CheckCollisionCircleRec(circlepos,circleradius,player6);
        iscollision7=CheckCollisionCircleRec(circlepos,circleradius,player7);
        iscollision8=CheckCollisionCircleRec(circlepos,circleradius,player8);
        iscollision9=CheckCollisionCircleRec(circlepos,circleradius,player9);
        iscollision10=CheckCollisionCircleRec(circlepos,circleradius,player10);
        iscollision11=CheckCollisionCircleRec(circlepos,circleradius,player11);
        iscollision12=CheckCollisionCircleRec(circlepos,circleradius,player12);
        iscollision13=CheckCollisionCircleRec(circlepos,circleradius,player13);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(circlepos,circleradius,RED);
        DrawCircleV(circlepos1,circleradius,GREEN);
        DrawCircleV(circlepos2,circleradius,BLUE);
        DrawRectangleRec(player,RED);
        DrawRectangleRec(player1,RED);
        DrawRectangleRec(player2,RED);
        DrawRectangleRec(player3,RED);
        DrawRectangleRec(player4,RED);
        DrawRectangleRec(player5,RED);
        DrawRectangleRec(player6,RED);
        DrawRectangleRec(player7,RED);
        DrawRectangleRec(player8,RED);
        DrawRectangleRec(player9,RED);
        DrawRectangleRec(player10,RED);
        DrawRectangleRec(player11,RED);
        DrawRectangleRec(player12,RED);
        DrawRectangleRec(player13,GREEN);
        DrawText("To win the",720,30,20,BLACK);
        DrawText("Game Eat ",720,50,20,BLACK);
        DrawText("Green Square",720,70,20,BLACK);
        if(iscollision==true ||iscollision1==true ||iscollision2==true ||iscollision3==true ||iscollision4==true ||iscollision5==true ||iscollision6==true ||iscollision7==true || iscollision8==true|| iscollision9==true|| iscollision10==true || iscollision11==true|| iscollision12==true){
            EndDrawing();
            CloseWindow();
            InitWindow(sw,sh,"Lost");
            while(!WindowShouldClose()){
                BeginDrawing();
                ClearBackground(WHITE);
                DrawText("YOU LOSE",400,400,50,BLACK);
                EndDrawing();
            }
            CloseWindow();
            return 0;
        }
        if(iscollision13==true){
            EndDrawing();
            CloseWindow();
            InitWindow(sw,sh,"Level Completed");
            while(!WindowShouldClose()){
                BeginDrawing();
                ClearBackground(WHITE);
                DrawText("YOU WON",400,400,50,BLACK);
                EndDrawing();
            }
            CloseWindow();
            return 0;
        }
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
