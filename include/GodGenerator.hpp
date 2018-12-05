#pragma once

#include <functional>

#include "IGodGenerator.hpp"
#include "CardShuffler.hpp"

namespace Cyclades
{
class GodGeneratorBase : public IGodGenerator
{
public:
    GodGeneratorBase();
    virtual ~GodGeneratorBase() = default;
protected:
    void commonGenerate(int);

    std::deque<God> m_lastAvailableGods;
    std::deque<God> m_lastUnavailableGods;

    CardShuffler m_shuffler;
};

class FivePlayersGodGenerator : public GodGeneratorBase
{
public:
    std::deque<God> generateGods() override;
};

class FourPlayersGodGenerator : public GodGeneratorBase
{
public:
    std::deque<God> generateGods() override;
};

using GenerateFunction = std::function<void()>;

class ThreePlayersGodGenerator : public GodGeneratorBase
{
public:
    ThreePlayersGodGenerator();
    std::deque<God> generateGods() override;
private:
    void generateFirstPhase();
    void generateSecondPhase();
    void resetGods();
    void changePhase(const GenerateFunction&);

    GenerateFunction m_currentGenerateFunction;
};
}
