#pragma once

#include <cstdint>
#include <utility>
#include <string>

namespace rubik_cube
{

    struct face_t
    {
        enum face_type
        {
            top    = 0,
            bottom = 1,
            front  = 2,
            back   = 3,
            left   = 4,
            right  = 5,
        };

        int8_t C[9];
    };

    struct block_t
    {
        int8_t top, bottom, front, back, left, right;
    };

    typedef std::pair<const int8_t*, const int8_t*> block_info_t;

    class cube_t
    {
    public:
        cube_t();
    public:

        block_t getBlock(int level, int x, int y) const;

        block_info_t getCornerBlock() const;
        block_info_t getEdgeBlock() const;

        void save(const std::string& fname) const;
        void load(const std::string& fname);

        bool isValid() const;

        void randomize();

        void print() const;

        void rotate(face_t::face_type, int count = 1);
    private:
        int8_t cp[8], co[8];
        int8_t ep[12], eo[12];
    };
}