#include "console.h"
////////////////////////////////////////////////////////////////////////////////
void SetCursorPosition(const int _X, const int _Y)
{ // 设置光标位置
    COORD position;
    position.X = _X * 2;
    position.Y = _Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
////////////////////////////////////////
void SetColor(int _ColorID)
{ // 设置字体颜色 可在cmd输入"color ?“查看详细颜色代号
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _ColorID);
}
////////////////////////////////////////
void SetBackColor(void)
{ // 设置字体背景色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                                BACKGROUND_BLUE |
                                BACKGROUND_GREEN |
                                BACKGROUND_RED);
}
////////////////////////////////////////////////////////////////////////////////
Option Option::choose(void) const
{
    SetCursorPosition(_x, _y);
    SetBackColor();
    std::cout << _content;
    return *this;
}
Option Option::unchoose(void) const
{
    SetCursorPosition(_x, _y);
    SetColor(UNCHOSEN_CONTENT_COLOR_ID);
    std::cout << _content;
    return *this;
}
Option Option::clear(void) const
{
    SetCursorPosition(_x, _y);
    SetColor(UNCHOSEN_CONTENT_COLOR_ID);
    std::cout << std::string(_content.size(), ' ');
    return *this;
}
////////////////////////////////////////////////////////////////////////////////
int selector(std::initializer_list<Option> _Opt)
{ // 高亮选择器
    int choice_cnt = _Opt.size();

    auto last = _Opt.begin(), next = _Opt.begin();
    auto back = _Opt.begin();
    for (int i = 1; i < choice_cnt; ++i)
        ++back;

    char ch = 0;       // 获取键盘映射
    bool flag = false; // 是否选择该选项

    for (auto i = _Opt.begin(); i != _Opt.end(); ++i)
        i->unchoose(); // 打印全部选项

    do
    {
        switch (ch)
        {
        case 72: // UP
        case 75: //RIGHT
            (last != _Opt.begin()) ? next = last - 1 : next = back;
            break;
        case 80: // DOWN
        case 77: // LEFT
            (last != _Opt.begin() + choice_cnt - 1) ? next = last + 1 : next = _Opt.begin();
            break;
        case 13: // ENTER
            flag = true;
            break;
        default:
            break;
        }
        if (flag) // 选中则跳出循环
            break;
        // 设置高亮
        last->unchoose();
        next->choose();
        last = next;
    } while (ch = _getch());

    // 清除选项
    for (auto i = _Opt.begin(); i != _Opt.end(); ++i)
        i->clear();

    return last - _Opt.begin(); // 返回选择项的序号
}
////////////////////////////////////////////////////////////////////////////////