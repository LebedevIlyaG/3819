#pragma once
#include <iostream>

class TTextNode
{
protected:
  TTextNode* next;
  TTextNode* down;
  char       c;
  int        level;      //1- строка, 2 - слово, 3 - буква;
public:
  TTextNode(int l = 3, char _c = 0);
  TTextNode(char* s = 0); // Конструктор принимает слово
  TTextNode(const TTextNode& node);

  ~TTextNode();

  TTextNode* GetNext();
  TTextNode* GetDown();
  char       GetC();
  int        GetLevel();

  void SetNext (TTextNode* _next);
  void SetDown(TTextNode* _down);
  void SetC(char _c);
  void SetLevel(int _l);

  friend std::ostream& operator << (std::ostream& o, TTextNode& t);
};

//#include "Text.h"

std::ostream& operator<<(std::ostream& o, TTextNode& t)
{
  if (t.level == 3)
  {
    o << t.c;
    if (t.next != nullptr)
      o << *(t.next);
  }
  else
  {
    if (t.down != nullptr)
      o << *(t.down);
    if (t.next != nullptr)
      o << *(t.next);
  }
  return o;
}

TTextNode::TTextNode(int l, char _c)
{
  next = nullptr;
  down = nullptr;
  c = _c;
  level = l;
}

TTextNode::TTextNode(char* s)
{
  next = nullptr;
  level = 2;
  c = 0;
  //...
}

TTextNode::TTextNode(const TTextNode& node)
{
  next = nullptr;
  down = nullptr;
  c = node.c;
  level = node.level;
}

TTextNode::~TTextNode()
{
}

TTextNode* TTextNode::GetNext()
{
  return next;
}

TTextNode* TTextNode::GetDown()
{
  return down;
}

char TTextNode::GetC()
{
  return c;
}

int TTextNode::GetLevel()
{
  return level;
}

void TTextNode::SetNext(TTextNode* _next)
{
  next = _next;
}

void TTextNode::SetDown(TTextNode* _down)
{
  down = _down;
}

void TTextNode::SetC(char _c)
{
  c = _c;
}

void TTextNode::SetLevel(int _l)
{
  if (_l >= 1 && _l <= 3)
    level = _l;
  else
    throw - 1;
}
