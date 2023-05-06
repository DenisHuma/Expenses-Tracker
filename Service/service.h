#include "../Repositories/tranzactieRepository.cpp"

class Service
{
private:
    TranzactieRepository &handleRepo;
    stack<Tranzactie> undoStack;

public:
    Service(TranzactieRepository &handleRepo);
    Tranzactie createTransaction();
    void readTransactions();
    void deleteTransaction();
    void ModifyTranzaction(int id);
    stack<Tranzactie> FilterTranzactions(string filter, string type);
    int SumOfType(string type);
    void Undo();
};