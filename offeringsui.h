#ifndef OFFERINGSUI_H
#define OFFERINGSUI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <map>
#include <memory>
#include "./include/Types.hpp"
#include "./include/IGodGenerator.hpp"

namespace Ui
{
class OfferingsUI;
}

class OfferingsUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit OfferingsUI(QWidget* parent = 0);
    ~OfferingsUI();

private:
    Ui::OfferingsUI* ui;
    QTimer* m_enableTimer;

    Cyclades::NumberOfPlayers m_numberOfPlayers;
    std::unique_ptr<Cyclades::IGodGenerator> m_godGenerator;
    std::map<Cyclades::God, QPixmap> m_gods;

private slots:
    void randomGods();
    void enableTimeout();
};

#endif // OFFERINGSUI_H
