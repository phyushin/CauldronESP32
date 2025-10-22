class Colour
{
private:


public:
    Colour(uint8_t _r, uint8_t _g, uint8_t _b);
    ~Colour();
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

Colour::Colour(uint8_t _r = 0, uint8_t _g = 0, uint8_t _b = 0){
    r = _r;
    g = _g;
    b = _b;
}


Colour::~Colour()
{
}
