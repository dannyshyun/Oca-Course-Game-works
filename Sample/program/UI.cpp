#include <string>
#include "Main.h"
#include "Game.h"
#include "UI.h"

#define FRAME_PER_SECOND 60

void UI::Init()
{
    m_score = 0;
    m_time = 150 * FRAME_PER_SECOND;
    m_pre_count = 4 * FRAME_PER_SECOND;
}

void UI::Update(int coin_num, int game_mode)
{
    switch (game_mode)
    {
    case GAME_TITLE:
        break;
    case GAME_PRE_COUNT:
        m_pre_count--;
        break;
    case GAME_START:
        m_time--;
        break;
    case GAME_RESULT:
        break;
    }
}

void UI::Render(int coin_num, int game_mode)
{
    switch (game_mode)
    {
    case GAME_TITLE:
        DrawTitle();
        DrawStartButton();
        break;
    case GAME_PRE_COUNT:
        DrawPreCount();
        break;
    case GAME_START:
        DrawTime();
        DrawScore();
        DrawCoinNum(coin_num);
        break;
    case GAME_CLEAR:
        DrawGameClear();
        break;
    case GAME_RESULT:
        DrawResult();
        break;
    }
}

void UI::End()
{
}

bool UI::CheckHitStart()
{
    int x1 = SCREEN_W * 0.5 - 60;
    int x2 = SCREEN_W * 0.5 + 60;
    int y1 = 630;
    int y2 = 660;
    if (CheckMouseInput(MOUSE_INPUT_LEFT))
    {
        int mouse_x = GetMouseX();
        int mouse_y = GetMouseY();
        if (mouse_x > x1 && mouse_x < x2 && mouse_y > y1 && mouse_y < y2)
        {
            return true;
        }
    }
    return false;
}

int UI::GetPreCount()
{
    return m_pre_count;
}

int UI::GetTime()
{
    return m_time;
}

void UI::ScoreAdd(int point)
{
    m_score += point;
}

void UI::DrawTitle()
{
    ChangeFontType(DX_FONTTYPE_EDGE);
    SetFontSize(48);
    std::string name = "FRISBEE MASTER";
    int n_x = (SCREEN_W - GetDrawStringWidth(name.c_str(), -1)) * 0.5;
    DrawString(n_x, 100, name.c_str(), WHITE, BLACK);
    SetFontSize(20);
}

void UI::DrawStartButton()
{
    int x1 = SCREEN_W * 0.5 - 60;
    int x2 = SCREEN_W * 0.5 + 60;
    int y1 = 630;
    int y2 = 660;
    DrawFillBox(x1, y1, x2, y2, GRAY);
    ChangeFontType(DX_FONTTYPE_NORMAL);
    std::string message = "START";
    int m_x = (SCREEN_W - GetDrawStringWidth(message.c_str(), -1)) * 0.5;
    int m_y = y1 + 5;
    DrawString(m_x, m_y, message.c_str(), BLACK);
}

void UI::DrawPreCount()
{
    ChangeFontType(DX_FONTTYPE_EDGE);
    SetFontSize(48);
    if (m_pre_count <= 1 * FRAME_PER_SECOND)
    {
        std::string message = "GO";
        int m_x = (SCREEN_W - GetDrawStringWidth(message.c_str(), -1)) * 0.5;
        int m_y = (SCREEN_H - GetDrawStringWidth(message.c_str(), -1)) * 0.5;
        DrawString(m_x, m_y, message.c_str(), WHITE);
    }
    else
    {
        DrawFormatString2(SCREEN_W * 0.5, SCREEN_H * 0.5, WHITE, GREEN, "%d", m_pre_count / FRAME_PER_SECOND);
    }
    SetFontSize(20);
}

void UI::DrawScore()
{
    std::string message = "SCORE : %05d";
    DrawFormatString2(SCREEN_W - GetDrawStringWidth(message.c_str(), -1) - 30, 30, WHITE, BLUE, message.c_str(), m_score);
}

void UI::DrawCoinNum(int num)
{
    std::string message = "COINS : %02d";
    DrawFormatString2(30, SCREEN_H - 60, WHITE, GRAY, message.c_str(), num);
}

void UI::DrawTime()
{
    int min = m_time / FRAME_PER_SECOND / 60;
    int sec = m_time / FRAME_PER_SECOND % 60;
    DrawFormatString2(30, 30, WHITE, RED, "TIME : %02d:%02d", min, sec);
}

void UI::DrawGameClear()
{
    ChangeFontType(DX_FONTTYPE_EDGE);
    SetFontSize(48);
    std::string name = m_time <= 0 ? "TIME's UP !!" : "ALL CLEAR !!";
    int n_x = (SCREEN_W - GetDrawStringWidth(name.c_str(), -1)) * 0.5;
    DrawString(n_x, 200, name.c_str(), WHITE, GREEN);
    SetFontSize(20);
}

void UI::DrawResult()
{
    ChangeFontType(DX_FONTTYPE_EDGE);
    SetFontSize(48);
    std::string name = "RESULT";
    int n_x = (SCREEN_W - GetDrawStringWidth(name.c_str(), -1)) * 0.5;
    std::string score = "SCORE :            %04d";
    std::string time = "TIME BONUS :       %04d x 100P per sec";
    std::string total = "TOTAL :            %04d";
    DrawString(n_x, 100, name.c_str(), WHITE, BLACK);
    DrawFormatString2(200, 200, WHITE, BLACK, score.c_str(), m_score);
    DrawFormatString2(200, 400, WHITE, BLACK, time.c_str(), m_time / FRAME_PER_SECOND);
    DrawFormatString2(200, 600, WHITE, BLACK, total.c_str(), m_score + m_time * 100 / FRAME_PER_SECOND);
    SetFontSize(20);
}