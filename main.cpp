#include "offeringsui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OfferingsUI w;
    w.show();

    return a.exec();
}
