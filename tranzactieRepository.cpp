#include "tranzactieRepository.h"

TranzactieRepository::TranzactieRepository()
{
}

TranzactieRepository::TranzactieRepository(stack<Tranzactie> repoStack)
{
    this->repoStack = repoStack;
}

TranzactieRepository::TranzactieRepository(TranzactieRepository &t)
{
    this->repoStack = t.repoStack;
}
TranzactieRepository::~TranzactieRepository()
{
    while (!this->repoStack.empty())
    {
        repoStack.pop();
    }
}
void TranzactieRepository::addTranzactie(Tranzactie tranzactie)
{
    if (tranzactie.getId() == 0)
    {
        tranzactie.setId(this->repoStack.size() + 1);
    }
    this->undoStack = repoStack;
    this->repoStack.push(tranzactie);
}

void TranzactieRepository::deleteTranzactie(int id)
{
    int checkID = -1;
    stack<Tranzactie> auxStack;
    this->undoStack = repoStack;
    while (checkID != id && !this->repoStack.empty())
    {
        checkID = this->repoStack.top().getId();
        auxStack.push(this->repoStack.top());
        repoStack.pop();
    }
    if (checkID == id)
    {
        auxStack.pop();
    }
    else
    {
        cout << "No Element Found" << endl;
    }
    while (!auxStack.empty())
    {
        this->repoStack.push(auxStack.top());
        auxStack.pop();
    }
}
void TranzactieRepository::showTranzactii()
{
    stack<Tranzactie> auxStack = this->repoStack;
    while (!auxStack.empty())
    {
        cout << auxStack.top().getDescriere() << ' ' << auxStack.top().getType() << ' ' << auxStack.top().getSuma() << ' ' << auxStack.top().getId() << endl;
        auxStack.pop();
    }
}
Tranzactie TranzactieRepository::findTransactionById(int id)
{
    stack<Tranzactie> auxStack = this->repoStack;
    bool check = false;
    while (!auxStack.empty())
    {
        if (auxStack.top().getId() == id)
        {
            return auxStack.top();
            check = true;
        }
        auxStack.pop();
    }
    if (check == false)
    {
        throw "No Element Found";
    }
    return Tranzactie();
}

stack<Tranzactie> TranzactieRepository::getStack()
{
    return this->repoStack;
}
void TranzactieRepository::setStack(stack<Tranzactie> stack)
{
    this->repoStack = stack;
}

stack<Tranzactie> TranzactieRepository::getUndoStack()
{
    return this->undoStack;
}