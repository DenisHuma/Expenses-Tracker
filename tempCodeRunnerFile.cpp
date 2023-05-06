#include "service.h"

int main()
{
    TranzactieRepository tranzactieRepository;
    Tranzactie test1(100, 18, "food", "in");
    Tranzactie test2(80, 11, "food", "in");
    Tranzactie test3(30, 14, "food", "in");
    tranzactieRepository.addTranzactie(test1);
    tranzactieRepository.addTranzactie(test2);
    tranzactieRepository.addTranzactie(test3);
    tranzactieRepository.showTranzactii();
    Service serviceTest(tranzactieRepository);
    serviceTest.ModifyTranzaction(1);
    tranzactieRepository.showTranzactii();

    return 0;
}