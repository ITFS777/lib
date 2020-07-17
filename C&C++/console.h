#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <initializer_list>
#include <windows.h>
#include <conio.h>

class Option;
void SetCursorPosition(const int _X, const int _Y); // 将光标定位到(_X,_Y)的位置
void SetColor(int _ColorID);                        // 设置字体颜色
void SetBackColor(void);                            // 设置字体背景色
int selector(std::initializer_list<Option> _Opt);   // 选项选择器
////////////////////////////////////////////////////////////////////////////////
class Option
{
public:
    Option() = default;
    Option(std::string str, int x, int y) : _content(str), _x(x), _y(y) {}
    Option choose(void) const;   // 高亮自身
    Option unchoose(void) const; // 取消高亮
    Option clear(void) const;    // 在屏幕上清空自身

private:
    int _x, _y;                                         // 首字符在屏幕上的坐标
    std::string _content;                                    // 选项内容
    static constexpr int CHOSEN_CONTENT_COLOR_ID = 0;   // 高亮文字颜色
    static constexpr int CHOSEN_BACK_COLOR_ID = 7;      // 高亮背景颜色
    static constexpr int UNCHOSEN_CONTENT_COLOR_ID = 7; // 普通文字颜色
    static constexpr int UNCHOSEN_BACK_COLOR_ID = 0;    // 普通背景颜色
};

#endif