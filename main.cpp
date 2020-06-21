#include "algo.h"


#include <iostream>

using namespace rubik_cube;


int main(int argc, char** argv)
{
    cube_t cube;

    cube.save("saved_state.txt");
    cube.load("saved_state.txt");

    cube.rotate(face_t::face_type::front);

    cube.isValid();

    cube.randomize();

    cube.print();

    auto algo = create_krof_algo(8);
    std::cout << "initializing solution algo..." << std::endl;
    algo->init();
    algo->save("koc.algo");
    auto solution = algo->solve(cube);

    std::cout << "print solution" << std::endl;
    for (auto step : solution) {
        std::cout << "rotate face " << step.first << " by " << step.second << std::endl;
    }

    return 0;
}
