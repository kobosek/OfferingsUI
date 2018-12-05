#include "./include/GodGeneratorFactory.hpp"
#include "./include/Types.hpp"
#include "./include/GodGenerator.hpp"

namespace Cyclades
{

std::unique_ptr<IGodGenerator> GodGeneratorFactory::createGodGenerator(NumberOfPlayers p_numberOfPlayers)
{
    switch(p_numberOfPlayers)
    {
    case NumberOfPlayers::Five:
        return std::make_unique<FivePlayersGodGenerator>();
    case NumberOfPlayers::Four:
        return std::make_unique<FourPlayersGodGenerator>();
    case NumberOfPlayers::Three:
        return std::make_unique<ThreePlayersGodGenerator>();
    default:
        throw std::invalid_argument("Invalid Number Of Players!");
    }
}

}
