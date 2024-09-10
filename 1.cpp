//SDL_WINDOWPOS_CENTERED 自动居中
#include"SDL.h"
#include"SDL_image.h"
#include<iostream>
#undef main
#define W 800
#define H 600
using namespace std;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_Log("Init failed:%s", SDL_GetError());
        //SDL_CreateWindows()
        return -1;
    }
    //create window
    SDL_Window* win = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,W, H, SDL_WINDOW_RESIZABLE|SDL_WINDOW_SHOWN);
    if (NULL == win)
    {
        SDL_Log("Init failed:%s", SDL_GetError());//判断是否有误
        return -1;
    }
    //wait a minute
    //SDL_Delay(10000);

    //create a item
    SDL_Surface* surf = SDL_GetWindowSurface(win);
    if (NULL == surf)
    {
        SDL_Log("Init failed:%s", SDL_GetError());
        return -1;
    }
    //定义一个区域
    SDL_Rect rect = { 0,0,100,100};
    
    SDL_Rect rectt = {3,3,94,94};
    //在surf上绘制图像
    //SDL_FillRect(surf, &rect, 0xff0000);


    //将更新的矩形更新到屏幕上
    SDL_UpdateWindowSurface(win);
    //暂停一段时间，事件监听与相应
    SDL_Event event;
    int x=0,y=0;
    while (true)
    {
        /*
            code
        */
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                break;
        }
        /*
        SDL_FillRect(surf, &rect1[0], 0x000000);
        SDL_FillRect(surf, &rect1[1], 0x000000);
        SDL_FillRect(surf, &rect1[2], 0x000000);
        rect1[1].x += 10;
        rect1[2].x += 10;
        SDL_FillRect(surf, &rectt[0], 0x0000ff);
        SDL_FillRect(surf, &rectt[1], 0x0000ff);
        SDL_FillRect(surf, &rectt[2], 0x0000ff);

        rectt[1].x += 10;
        rectt[2].x += 10;
        */

        /*for (int i = 0; i < 10; i++)
        {
            SDL_FillRect(surf, &rect1[i], 0x000000);
            rect1[i].y += i;
            rectt[i].y += i;
            rect1[i].x += i;
            rectt[i].x += i;
            SDL_FillRect(surf, &rect1[i], 0x0000ff);
            SDL_FillRect(surf, &rectt[i], 0x000000);

        }*/
        //1
        //SDL_FillRect(surf, &rect, 0x000000);
        //SDL_FillRect(surf, &rectt, 0x000000);
        rect.y = 0;
        rectt.y = 0;
        for (int i = 0; i < 10; i++)
        {
            rectt.x = 3;
            rect.x = 0;
            for (int j = 0; j < 10; j++)
            {
                SDL_FillRect(surf, &rect, 0xff0000);
                SDL_FillRect(surf, &rectt, 0x000000);
                rect.x += 100;
                rectt.x += 100;
            }
            rect.y += 100;
            rectt.y += 100;
        }
            x++;
            y++;
            rect.x = x;
            rect.y = y;
            rectt.x = x + 3;
            rectt.y = y + 3;
        SDL_FillRect(surf, &rect, 0x000000);
        SDL_FillRect(surf, &rectt, 0x000000);
        rect.y++;
        rectt.y++;
        SDL_FillRect(surf, &rect, 0x00ffff);
        SDL_FillRect(surf, &rectt, 0x000000);
        /*
        //2
        rect.y += 100;
        rectt.y += 100;
        //SDL_FillRect(surf, &rect, 0x000000);
        //SDL_FillRect(surf, &rectt, 0x000000);
        rect.x += 100;
        rectt.x += 100;
        SDL_FillRect(surf, &rect, 0xff0000);
        SDL_FillRect(surf, &rectt, 0x000000);
        rect.y -= 100;
        rectt.y -= 100;
        */
        SDL_UpdateWindowSurface(win);
        SDL_Delay(30);

    }
    //delete window
    SDL_DestroyWindow(win);
    //esc
    SDL_FreeSurface(surf);
    SDL_Quit();
    return 0;
}