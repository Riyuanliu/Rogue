#pragma once

#pragma once

#include "Utility.h"
#include "Image.h"

namespace Rogue
{
    class ROGUE_API Unit
    {
    public:
        Unit(const std::string& image, int x, int y);
        Unit(std::string&& image, int x, int y);

        int GetWidth() const;
        int GetHeight() const;

        int GetXCoord() const;
        int GetYCoord() const;
        void SetCoords(int x, int y);
        void UpdateXCoords(int amount);
        void UpdateYCoords(int amount);

    private:
        Image mImage;
        int mXPosition;
        int mYPosition;

        friend ROGUE_API bool UnitsOverlap(const Unit& a, const Unit& b);
        friend class Renderer;
    };

    ROGUE_API bool UnitsOverlap(const Unit& a, const Unit& b);
}