#include "offeringsui.h"
#include "ui_offeringsui.h"
#include <utility>
#include "./include/GodGeneratorFactory.hpp"

using namespace Cyclades;

OfferingsUI::OfferingsUI(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::OfferingsUI),
    m_enableTimer(new QTimer),
    m_numberOfPlayers(NumberOfPlayers::Three),
    m_godGenerator(GodGeneratorFactory::createGodGenerator(m_numberOfPlayers)),
    m_gods{std::make_pair(God::Ares, QPixmap(":/Resources/ares.jpg")),
           std::make_pair(God::Athena, QPixmap(":/Resources/athena.jpg")),
           std::make_pair(God::Poseidon, QPixmap(":/Resources/poseidon.jpg")),
           std::make_pair(God::Zeus, QPixmap(":/Resources/zeus.jpg"))}
{
    ui->setupUi(this);

    connect(ui->RandomButton, SIGNAL(released()), this, SLOT(randomGods()));
    connect(m_enableTimer, SIGNAL(timeout()), this, SLOT(enableTimeout()));
}

void OfferingsUI::randomGods()
{
    auto l_gods = m_godGenerator->generateGods();

    switch(m_numberOfPlayers)
    {
    case NumberOfPlayers::Five:
    {
        ui->GodSlot4->setPixmap(m_gods[l_gods[3]]);
    }
    case NumberOfPlayers::Four:
    {
        ui->GodSlot3->setPixmap(m_gods[l_gods[2]]);
    }
    case NumberOfPlayers::Three:
    {
        ui->GodSlot1->setPixmap(m_gods[l_gods[0]]);
        ui->GodSlot2->setPixmap(m_gods[l_gods[1]]);
        break;
    }
    }
    ui->RandomButton->setEnabled(false);
    m_enableTimer->start(2000);
}

void OfferingsUI::enableTimeout()
{
    ui->RandomButton->setEnabled(true);
}

OfferingsUI::~OfferingsUI()
{
    delete m_enableTimer;
    delete ui;
}

