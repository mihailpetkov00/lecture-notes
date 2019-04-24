#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "rectangle.h"

Rect::Rect(int _x, int _y, int _w, int _h, const char *_s):Shape(_x,_y,_s),w(_w),h(_h)
{

}

void Rect::draw(SDL_Renderer *rend)
{
    SDL_SetRenderDrawColor(rend, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_Rect r = {x, y, w, h};
    SDL_RenderFillRect(rend, &r);
}

void Rect::set_w(int _w)
{
    w=_w;
}
void Rect::set_h(int _h)
{
    h=_h;
}

int Rect::get_w()
{
    return w;
}
int Rect::get_h()
{
    return h;
}

void Rect::set_color(int _r, int _g, int _b)
{
    r=_r;
    g=_g;
    b=_b;
}

Shape *Rect::clone()
{
    return new Rect(*this);
}

void Rect::serialize(std::ostream &out)
{
    out << "Rect " 
        << x 
        << " "
        << y
        << " "
        << w
        << " "
        << h 
        << " "
        << strlen (text)
        << " "
        << text
        << "\n";
}