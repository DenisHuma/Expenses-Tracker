#include <stack>
#include "../Objects/tranzactie.cpp"

class TranzactieRepository
{
private:
    stack<Tranzactie> repoStack;
    stack<Tranzactie> undoStack;

public:
    TranzactieRepository();
    TranzactieRepository(stack<Tranzactie> repoStack);
    TranzactieRepository(TranzactieRepository &t);
    ~TranzactieRepository();
    void addTranzactie(Tranzactie tranzactie);
    void deleteTranzactie(int id);
    void showTranzactii();
    stack<Tranzactie> getStack();
    Tranzactie findTransactionById(int id);
    void setStack(stack<Tranzactie> stack);
    stack<Tranzactie> getUndoStack();
};