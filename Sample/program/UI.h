#pragma once

class UI
{
public:
    void Init();
    void Update(int coin_num, int game_mode);
    void Render(int coin_num, int game_mode);
    void End();
    bool CheckHitStart();
    int GetPreCount();
    int GetTime();
    void ScoreAdd(int point);

private:
    void DrawTitle();
    void DrawStartButton();
    void DrawPreCount();
    void DrawCoinNum(int num);
    void DrawScore();
    void DrawTime();
    void DrawGameClear();
    void DrawResult();
    int m_score;
    int m_time;
    int m_pre_count;
    int m_frame_count;
};